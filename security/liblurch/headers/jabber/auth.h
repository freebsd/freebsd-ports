/**
 * @file auth.h Authentication routines
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
#ifndef PURPLE_JABBER_AUTH_H_
#define PURPLE_JABBER_AUTH_H_

typedef struct _JabberSaslMech JabberSaslMech;

#include "jabber.h"
#include "xmlnode.h"

typedef enum {
	JABBER_SASL_STATE_FAIL = -1,    /* Abort, Retry, Fail? */
	JABBER_SASL_STATE_OK = 0,       /* Hooray! */
	JABBER_SASL_STATE_CONTINUE = 1  /* More authentication required */
} JabberSaslState;

struct _JabberSaslMech {
	gint8 priority; /* Higher priority will be tried before lower priority */
	const gchar *name;
	JabberSaslState (*start)(JabberStream *js, xmlnode *mechanisms, xmlnode **reply, char **msg);
	JabberSaslState (*handle_challenge)(JabberStream *js, xmlnode *packet, xmlnode **reply, char **msg);
	JabberSaslState (*handle_success)(JabberStream *js, xmlnode *packet, char **msg);
	JabberSaslState (*handle_failure)(JabberStream *js, xmlnode *packet, xmlnode **reply, char **msg);
	void (*dispose)(JabberStream *js);
};

void jabber_auth_start(JabberStream *js, xmlnode *packet);
void jabber_auth_start_old(JabberStream *js);
void jabber_auth_handle_challenge(JabberStream *js, xmlnode *packet);
void jabber_auth_handle_success(JabberStream *js, xmlnode *packet);
void jabber_auth_handle_failure(JabberStream *js, xmlnode *packet);

JabberSaslMech *jabber_auth_get_plain_mech(void);
JabberSaslMech *jabber_auth_get_digest_md5_mech(void);
JabberSaslMech **jabber_auth_get_scram_mechs(gint *count);
#ifdef HAVE_CYRUS_SASL
JabberSaslMech *jabber_auth_get_cyrus_mech(void);
#endif

void jabber_auth_add_mech(JabberSaslMech *);
void jabber_auth_remove_mech(JabberSaslMech *);

void jabber_auth_init(void);
void jabber_auth_uninit(void);

#endif /* PURPLE_JABBER_AUTH_H_ */
