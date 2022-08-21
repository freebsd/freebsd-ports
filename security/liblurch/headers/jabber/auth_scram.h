/**
 * @file auth_scram.h Implementation of SASL-SCRAM authentication
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
#ifndef PURPLE_JABBER_AUTH_SCRAM_H_
#define PURPLE_JABBER_AUTH_SCRAM_H_

/*
 * Every function in this file is ONLY exposed for tests.
 * DO NOT USE ANYTHING HERE OR YOU WILL BE SENT TO THE PIT OF DESPAIR.
 */

/* Per-connection state stored between messages.
 * This is stored in js->auth_data_mech.
 */
typedef struct {
	const char *mech_substr;
	const char *name;
	guint size;
} JabberScramHash;

typedef struct {
	const JabberScramHash *hash;
	char *cnonce;
	GString *auth_message;

	GString *client_proof;
	GString *server_signature;

	gchar *password;
	gboolean channel_binding;
	int step;
} JabberScramData;

#include "auth.h"

/**
 * Implements the Hi() function as described in the SASL-SCRAM I-D.
 *
 * @param hash The struct corresponding to the hash function to be used.
 * @param str  The string to perform the PBKDF2 operation on.
 * @param salt The salt.
 * @param iterations The number of iterations to perform.
 *
 * @returns A newly allocated string containing the result. The string is
 *          NOT null-terminated and its length is the length of the binary
 *          output of the hash function in-use.
 */
guchar *jabber_scram_hi(const JabberScramHash *hash, const GString *str,
                        GString *salt, guint iterations);

/**
 * Calculates the proofs as described in Section 3 of the SASL-SCRAM I-D.
 *
 * @param data A JabberScramData structure. hash and auth_message must be
 *             set. client_proof and server_signature will be set as a result
 *             of this function.
 * @param salt       The salt (as specified by the server)
 * @param iterations The number of iterations to perform.
 *
 * @returns TRUE if the proofs were successfully calculated. FALSE otherwise.
 */
gboolean jabber_scram_calc_proofs(JabberScramData *data, GString *salt,
                                  guint iterations);

/**
 * Feed the algorithm with the data from the server.
 */
gboolean jabber_scram_feed_parser(JabberScramData *data, gchar *in, gchar **out);

/**
 * Clean up and destroy the data struct
 */
void jabber_scram_data_destroy(JabberScramData *data);

#endif /* PURPLE_JABBER_AUTH_SCRAM_H_ */
