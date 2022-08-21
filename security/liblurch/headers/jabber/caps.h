/*
 * purple - Jabber Protocol Plugin
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111-1301  USA
 *
 */

#ifndef PURPLE_JABBER_CAPS_H_
#define PURPLE_JABBER_CAPS_H_

typedef struct _JabberCapsClientInfo JabberCapsClientInfo;

#include "jabber.h"

/* Implementation of XEP-0115 - Entity Capabilities */

typedef struct _JabberCapsNodeExts JabberCapsNodeExts;

typedef struct _JabberCapsTuple {
	const char *node;
	const char *ver;
	const char *hash;
} JabberCapsTuple;

struct _JabberCapsClientInfo {
	GList *identities; /* JabberIdentity */
	GList *features; /* char * */
	GList *forms; /* xmlnode * */
	JabberCapsNodeExts *exts;

	const JabberCapsTuple tuple;
};

/*
 * This stores a set of exts "known" for a specific node (which indicates
 * a specific client -- for reference, Pidgin, Finch, Meebo, et al share one
 * node.) In XEP-0115 v1.3, exts are used for features that may or may not be
 * present at a given time (PEP things, buzz might be disabled, etc).
 *
 * This structure is shared among all JabberCapsClientInfo instances matching
 * a specific node (if the capstable key->hash == NULL, which indicates that
 * the ClientInfo is using v1.3 caps as opposed to v1.5 caps).
 *
 * It's only exposed so that jabber_resource_has_capability can use it.
 * Everyone else, STAY AWAY!
 */
struct _JabberCapsNodeExts {
	guint ref;
	GHashTable *exts; /* char *ext_name -> GList *features */
};

typedef void (*jabber_caps_get_info_cb)(JabberCapsClientInfo *info, GList *exts, gpointer user_data);

void jabber_caps_init(void);
void jabber_caps_uninit(void);

/**
 * Check whether all of the exts in a char* array are known to the given info.
 */
gboolean jabber_caps_exts_known(const JabberCapsClientInfo *info, char **exts);

/**
 * Main entity capabilites function to get the capabilities of a contact.
 *
 * The callback will be called synchronously if we already have the
 * capabilities for the specified (node,ver,hash) (and, if exts are specified,
 * if we know what each means)
 *
 * @param exts A g_strsplit'd (NULL-terminated) array of strings. This
 *             function is responsible for freeing it.
 */
void jabber_caps_get_info(JabberStream *js, const char *who, const char *node,
                          const char *ver, const char *hash,
                          char **exts, jabber_caps_get_info_cb cb,
                          gpointer user_data);

/**
 *	Takes a JabberCapsClientInfo pointer and returns the caps hash according to
 *	XEP-0115 Version 1.5.
 *
 *	@param info A JabberCapsClientInfo pointer.
 *	@param hash Hash cipher to be used. Either sha-1 or md5.
 *	@return		The base64 encoded SHA-1 hash; must be freed by caller
 */
gchar *jabber_caps_calculate_hash(JabberCapsClientInfo *info, const char *hash);

/**
 *  Calculate SHA1 hash for own featureset.
 */
void jabber_caps_calculate_own_hash(JabberStream *js);

/** Get the current caps hash.
 * 	@ret hash
**/
const gchar* jabber_caps_get_own_hash(JabberStream *js);

/**
 *  Broadcast a new calculated hash using a <presence> stanza.
 */
void jabber_caps_broadcast_change(void);

/**
 * Parse the <query/> element from an IQ stanza into a JabberCapsClientInfo
 * struct.
 *
 * Exposed for tests
 *
 * @param query The 'query' element from an IQ reply stanza.
 * @returns A JabberCapsClientInfo struct, or NULL on error
 */
JabberCapsClientInfo *jabber_caps_parse_client_info(xmlnode *query);

#endif /* PURPLE_JABBER_CAPS_H_ */
