/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/ocmbFwImage.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __OCMBFWIMAGE_H
#define __OCMBFWIMAGE_H

/**
 * @file ocmbFwImage.H
 *
 * Interface for validating the OCMB firmware image from PNOR
 *
 */

#include <errl/errlentry.H>

namespace expupd
{

constexpr uint32_t HEADER_SHA512_SIZE = 64;

/**
 * @brief Parameters pertaining to an unpackaged (raw) OCMB firmware image
 */
typedef struct rawImageInfo
{
    const uint8_t* imagePtr;
    size_t         imageSize;
    const uint8_t* imageSHA512HashPtr;
}rawImageInfo_t;

/**
 * @brief Validates OCMB firmware header of packaged image
 *
 * @param[in] i_imageStart Start address of packaged image
 * @param[in] i_imageSize Size of packaged image
 * @param[out] o_imageInfo Information pertaining to image after
 *             being stripped of OCMB firmware header
 * @return errlHndl_t indicating success or failure
 *
 */
errlHndl_t ocmbFwValidateImage(const uint64_t i_imageStart,
                               const uint64_t i_imageSize,
                               rawImageInfo_t& o_imageInfo);

}//namespace expupd

#endif
