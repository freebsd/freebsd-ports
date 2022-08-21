/**
 * @file auth_digest_md5.h Implementation of SASL DIGEST-MD5 authentication
 *
 * purple
 *
 * Purple is the legal property of its developers, whose names are too numerous
 * to list here.  Please refer to the COPYRIGHT file distributed with this
 * source distribution.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 */
#ifndef PURPLE_JABBER_AUTH_DIGEST_MD5_H_
#define PURPLE_JABBER_AUTH_DIGEST_MD5_H_

#include "internal.h"

/*
 * Every function in this file is ONLY exposed for tests.
 * DO NOT USE ANYTHING HERE OR YOU WILL BE SENT TO THE PIT OF DESPAIR.
 */

/*
 * Parse a DIGEST-MD5 challenge.
 */
GHashTable *jabber_auth_digest_md5_parse(const char *challenge);

#endif /* PURPLE_JABBER_AUTH_DIGEST_MD5_H_ */
