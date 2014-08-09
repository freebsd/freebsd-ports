///
///	@file iatomic.h @brief Misc function header file
///
///	Copyright (c) 2014 by Johns.  All Rights Reserved.
///
///	Contributor(s):
///
///	License: AGPLv3
///
///	This program is free software: you can redistribute it and/or modify
///	it under the terms of the GNU Affero General Public License as
///	published by the Free Software Foundation, either version 3 of the
///	License.
///
///	This program is distributed in the hope that it will be useful,
///	but WITHOUT ANY WARRANTY; without even the implied warranty of
///	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
///	GNU Affero General Public License for more details.
///
///	$Id$
//////////////////////////////////////////////////////////////////////////////

/// @addtogroup iatomic
/// @{

#define GCC_VERSION (__GNUC__ * 10000 \
	+ __GNUC_MINOR__ * 100 \
	+ __GNUC_PATCHLEVEL__)

//	gcc before 4.7 didn't support atomic builtins,
//	use alsa atomic functions.
#if 0 // GCC_VERSION < 40700

#include <alsa/iatomic.h>

#else

//////////////////////////////////////////////////////////////////////////////
//	Defines
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//	Declares
//////////////////////////////////////////////////////////////////////////////

///
///	atomic type, 24 bit useable,
///
typedef volatile int atomic_t;

//////////////////////////////////////////////////////////////////////////////
//	Prototypes
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//	Inlines
//////////////////////////////////////////////////////////////////////////////

///
///	Set atomic value.
///
#define atomic_set(ptr, val) \
    __atomic_store_n(ptr, val, __ATOMIC_SEQ_CST)

///
///	Read atomic value.
///
#define atomic_read(ptr) \
    __atomic_load_n(ptr, __ATOMIC_SEQ_CST)

///
///	Increment atomic value.
///
#define atomic_inc(ptr) \
    __atomic_add_fetch(ptr, 1, __ATOMIC_SEQ_CST)

///
///	Decrement atomic value.
///
#define atomic_dec(ptr) \
    __atomic_sub_fetch(ptr, 1, __ATOMIC_SEQ_CST)

///
///	Add to atomic value.
///
#define atomic_add(val, ptr) \
    __atomic_add_fetch(ptr, val, __ATOMIC_SEQ_CST)

///
///	Subtract from atomic value.
///
#define atomic_sub(val, ptr) \
    __atomic_sub_fetch(ptr, val, __ATOMIC_SEQ_CST)

#endif

/// @}
