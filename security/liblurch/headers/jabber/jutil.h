/**
 * @file jutil.h utility functions
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
#ifndef PURPLE_JABBER_JUTIL_H_
#define PURPLE_JABBER_JUTIL_H_

typedef struct _JabberID {
	char *node;
	char *domain;
	char *resource;
} JabberID;

typedef enum {
	JABBER_BUDDY_STATE_UNKNOWN = -2,
	JABBER_BUDDY_STATE_ERROR = -1,
	JABBER_BUDDY_STATE_UNAVAILABLE = 0,
	JABBER_BUDDY_STATE_ONLINE,
	JABBER_BUDDY_STATE_CHAT,
	JABBER_BUDDY_STATE_AWAY,
	JABBER_BUDDY_STATE_XA,
	JABBER_BUDDY_STATE_DND
} JabberBuddyState;

#include "jabber.h"

JabberID* jabber_id_new(const char *str);

/**
 * Compare two JIDs for equality. In addition to the node and domain,
 * the resources of the two JIDs must also be equal (or both absent).
 */
gboolean jabber_id_equal(const JabberID *jid1, const JabberID *jid2);

void jabber_id_free(JabberID *jid);

char *jabber_get_domain(const char *jid);
char *jabber_get_resource(const char *jid);
char *jabber_get_bare_jid(const char *jid);
char *jabber_id_get_bare_jid(const JabberID *jid);
char *jabber_id_get_full_jid(const JabberID *jid);
JabberID *jabber_id_to_bare_jid(const JabberID *jid);

gboolean jabber_jid_is_domain(const char *jid);

const char *jabber_normalize(const PurpleAccount *account, const char *in);

/* Returns true if JID is the bare JID of our server. */
gboolean jabber_is_own_server(JabberStream *js, const char *jid);

/* Returns true if JID is the bare JID of our account. */
gboolean jabber_is_own_account(JabberStream *js, const char *jid);

gboolean jabber_nodeprep_validate(const char *);
gboolean jabber_domain_validate(const char *);
gboolean jabber_resourceprep_validate(const char *);

/**
 * Apply the SASLprep profile of stringprep to the string passed in.
 *
 * @returns A newly allocated string containing the normalized version
 *          of the input, or NULL if an error occurred (the string could
 *          not be normalized)
 */
char *jabber_saslprep(const char *);

/* state -> readable name */
const char *jabber_buddy_state_get_name(JabberBuddyState state);
/* state -> core id */
const char *jabber_buddy_state_get_status_id(JabberBuddyState state);
/* state -> show attr (for presence stanza) */
const char *jabber_buddy_state_get_show(JabberBuddyState state);
/* core id -> state */
JabberBuddyState jabber_buddy_status_id_get_state(const char *id);
/* show attr (presence stanza) -> state */
JabberBuddyState jabber_buddy_show_get_state(const char *id);

char *jabber_calculate_data_hash(gconstpointer data, size_t len,
    const gchar *hash_algo);
#endif /* PURPLE_JABBER_JUTIL_H_ */
