#pragma once

#include "axc.h"

#define JABBER_PROTOCOL_ID "prpl-jabber"

// see https://www.ietf.org/rfc/rfc3920.txt
#define JABBER_MAX_LEN_NODE 1023
#define JABBER_MAX_LEN_DOMAIN 1023
#define JABBER_MAX_LEN_BARE JABBER_MAX_LEN_NODE + JABBER_MAX_LEN_DOMAIN + 1

#define LURCH_PREF_ROOT              "/plugins/core/lurch"
#define LURCH_PREF_AXC_LOGGING       LURCH_PREF_ROOT "/axc_logging"
#define LURCH_PREF_AXC_LOGGING_LEVEL LURCH_PREF_AXC_LOGGING "/level"

#define LURCH_DB_SUFFIX     "_db.sqlite"
#define LURCH_DB_NAME_OMEMO "omemo"
#define LURCH_DB_NAME_AXC   "axc"


/**
 * Creates and initializes the axc context.
 *
 * @param uname The username.
 * @param ctx_pp Will point to an initialized axc context on success.
 * @return 0 on success, negative on error.
 */
int lurch_util_axc_get_init_ctx(char * uname, axc_context ** ctx_pp);

/**
 * For some reason pidgin returns account names with a trailing "/".
 * This function removes it.
 * All other functions asking for the username assume the "/" is already stripped.
 * jabber_get_bare_jid returns null for some reason or other.
 *
 * @param uname The username.
 * @return A duplicated string with the trailing "/" removed. free() when done with it.
 */
char * lurch_util_uname_strip(const char * uname);

/**
 * Returns the db name, has to be g_free()d.
 *
 * @param uname The username.
 * @param which Either LURCH_DB_NAME_OMEMO or LURCH_DB_NAME_AXC
 * @return The path string. free() when done with it.
 */
char * lurch_util_uname_get_db_fn(const char * uname, const char * which);

/**
 * Creates a fingerprint which resembles the one displayed by Conversations etc.
 * Also useful for avoiding the smileys produced by ':d'...
 *
 * @param key_buf_p The buffer containing the public key data.
 * @return A newly allocated string which contains the fingerprint in printable format, or NULL. g_free() when done.
 */
char * lurch_util_fp_get_printable(axc_buf * key_buf_p);
