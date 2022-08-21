#include <inttypes.h>
#include <glib.h>
#include <purple.h>

#include "chat.h"
#include "pep.h"

#include "axc.h"
#include "libomemo.h"
#include "libomemo_storage.h"

#include "lurch_api.h"
#include "lurch_api_internal.h"
#include "lurch_util.h"

#define MODULE_NAME "lurch-api"

#define DISCO_XMLNS     "http://jabber.org/protocol/disco#info" // see XEP-0030: Service Discovery (https://xmpp.org/extensions/xep-0030.html)

/**
 * Returns a GList of int32_t * containing the devices of the calling account.
 * If the current device is contained in it (which it should be!), it will be first in the list.
 */
static int32_t lurch_api_id_list_get_own(PurpleAccount * acc_p, GList ** list_pp) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  GList * id_list = (void *) 0;
  uint32_t * id_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_user_devicelist_retrieve(uname, db_fn_omemo, &dl_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to access OMEMO DB %s.", db_fn_omemo);
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to create axc ctx.");
    goto cleanup;
  }

  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to access axc db %s. Does the path seem correct?", axc_context_get_db_fn(axc_ctx_p));
    goto cleanup;
  }

  if (!omemo_devicelist_contains_id(dl_p, own_id)) {
    purple_debug_warning(MODULE_NAME, "This device's ID is not contained in your devicelist?");
    goto cleanup;
  }

  ret_val = omemo_devicelist_remove(dl_p, own_id);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to remove the ID from the devicelist.");
    goto cleanup;
  }

  id_list = omemo_devicelist_get_id_list(dl_p);

  id_p = g_malloc(sizeof(uint32_t));
  if (!id_p) {
    ret_val = LURCH_ERR_NOMEM;
    goto cleanup;
  }
  *id_p = own_id;

  id_list = g_list_prepend(id_list, id_p);

cleanup:
  if (!ret_val) {
    *list_pp = id_list;
  }

  g_free(uname);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  axc_context_destroy_all(axc_ctx_p);

  return ret_val;
}

void lurch_api_id_list_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, GList * id_list, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  GList * id_list = (void *) 0;

  ret_val = lurch_api_id_list_get_own(acc_p, &id_list);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to get the own, sorted ID list.");
    goto cleanup;
  }

cleanup:
  cb(ret_val, id_list, user_data_p);

  g_list_free_full(id_list, free);
}

void lurch_api_id_remove_handler(PurpleAccount * acc_p, uint32_t device_id, void (*cb)(int32_t err, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;
  char * exported_devicelist = (void *) 0;
  xmlnode * publish_node_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_user_devicelist_retrieve(uname, db_fn_omemo, &dl_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to access the OMEMO DB %s to retrieve the devicelist.", db_fn_omemo);
    goto cleanup;
  }

  if (!omemo_devicelist_contains_id(dl_p, device_id)) {
    ret_val = LURCH_ERR_DEVICE_NOT_IN_LIST;
    purple_debug_error(MODULE_NAME, "Your devicelist does not contain the device ID %i.", device_id);
    goto cleanup;
  }

  ret_val = omemo_devicelist_remove(dl_p, device_id);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to remove the device ID %i from %s's devicelist.", device_id, uname);
    goto cleanup;
  }

  ret_val = omemo_devicelist_export(dl_p, &exported_devicelist);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to export new devicelist without device ID %i.", device_id);
    goto cleanup;
  }

  publish_node_p = xmlnode_from_str(exported_devicelist, -1);
  jabber_pep_publish(purple_connection_get_protocol_data(purple_account_get_connection(acc_p)), publish_node_p);
  // publish_node_p will be freed by the jabber prpl

cleanup:
  cb(ret_val, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  g_free(exported_devicelist);
}

void lurch_api_enable_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_delete(contact_bare_jid, db_fn_omemo);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to delete %s from the blacklist in OMEMO DB %s.", contact_bare_jid, db_fn_omemo);
  }

  cb(ret_val, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
}

void lurch_api_disable_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_save(contact_bare_jid, db_fn_omemo);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to add %s to the blacklist in OMEMO DB %s.", contact_bare_jid, db_fn_omemo);
  }

  cb(ret_val, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
}

void lurch_api_enable_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_save(full_conversation_name, db_fn_omemo);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to enable OMEMO for chat %s using DB %s.\n", full_conversation_name, db_fn_omemo);
  }

  cb(ret_val, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
}

void lurch_api_disable_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_delete(full_conversation_name, db_fn_omemo);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to disable OMEMO for chat %s using DB %s.\n", full_conversation_name, db_fn_omemo);
  }

  cb(ret_val, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
}

void lurch_api_fp_get_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, const char * fp_printable, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  axc_buf * key_buf_p = (void *) 0;
  char * fp_printable = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to create axc ctx.\n");
    goto cleanup;
  }

  ret_val = axc_key_load_public_own(axc_ctx_p, &key_buf_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to load public key from axc db %s.", axc_context_get_db_fn(axc_ctx_p));
    goto cleanup;
  }

  fp_printable = lurch_util_fp_get_printable(key_buf_p);

cleanup:
  cb(ret_val, fp_printable, user_data_p);

  g_free(fp_printable);
  axc_buf_free(key_buf_p);
  axc_context_destroy_all(axc_ctx_p);
}

/**
 * Given a list of IDs, retrieves the public keys from the libsignal sessions and creates a hash table with ID to fingerprint pairs.
 * If there is an entry in the devicelist, but no session yet, the fingerprint cannot be retrieved this way and the value will be NULL.
 * g_hash_table_destroy() the table when done with it.
 */
static int32_t lurch_api_fp_create_table(const char * jid,  axc_context * axc_ctx_p, const GList * id_list, GHashTable ** id_fp_table_pp) {
  int32_t ret_val = 0;
  GHashTable * id_fp_table = (void *) 0;
  const GList * curr_p = (void *) 0;
  uint32_t curr_device_id = 0;
  axc_buf * key_buf_p = (void *) 0;

  id_fp_table = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, g_free);

  for (curr_p = id_list; curr_p; curr_p = curr_p->next) {
    curr_device_id = omemo_devicelist_list_data(curr_p);

    ret_val = axc_key_load_public_addr(jid, curr_device_id, axc_ctx_p, &key_buf_p);
    if (ret_val < 0) {
      purple_debug_error(MODULE_NAME, "Failed to load key for %s:%i", jid, curr_device_id);
      goto cleanup;
    } else if (ret_val == 0) {
      purple_debug_warning(MODULE_NAME, "Tried to load public key for %s:%i, but no session exists", jid, curr_device_id);
      (void) g_hash_table_insert(id_fp_table, curr_p->data, NULL);
      continue;
    }

    (void) g_hash_table_insert(id_fp_table, curr_p->data, lurch_util_fp_get_printable(key_buf_p));

    axc_buf_free(key_buf_p);
    key_buf_p = (void *) 0;

    ret_val = 0;
  }

cleanup:
  if (ret_val) {
    g_hash_table_destroy(id_fp_table);
  } else {
    *id_fp_table_pp = id_fp_table;
  }

  return ret_val;
}

// returns NULL as hash table if devicelist is empty
void lurch_api_fp_list_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, GHashTable * id_fp_table, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  GList * own_id_list = (void *) 0;
  char * uname = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  GHashTable * id_fp_table = (void *) 0;
  axc_buf * key_buf_p = (void *) 0;

  ret_val = lurch_api_id_list_get_own(acc_p, &own_id_list);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to get the own, sorted ID list.");
    goto cleanup;
  }

  if (g_list_length(own_id_list) == 0) {
    goto cleanup;
  }

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to create axc ctx for %s.", uname);
    goto cleanup;
  }

  ret_val = lurch_api_fp_create_table(uname, axc_ctx_p, own_id_list->next, &id_fp_table);
  if (ret_val) {
    goto cleanup;
  }

  ret_val = axc_key_load_public_own(axc_ctx_p, &key_buf_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to load public key from axc db %s.", axc_context_get_db_fn(axc_ctx_p));
    goto cleanup;
  }

  (void) g_hash_table_insert(id_fp_table, own_id_list->data, lurch_util_fp_get_printable(key_buf_p));

cleanup:
  cb(ret_val, id_fp_table, user_data_p);

  g_list_free_full(own_id_list, g_free);
  g_free(uname);
  axc_context_destroy_all(axc_ctx_p);
  g_hash_table_destroy(id_fp_table);
  axc_buf_free(key_buf_p);
}

// returns NULL as hash table if devicelist is empty
void lurch_api_fp_other_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, GHashTable * id_fp_table, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  GHashTable * id_fp_table = (void *) 0;
  GList * id_list = (void *) 0;
  axc_buf * key_buf_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_user_devicelist_retrieve(contact_bare_jid, db_fn_omemo, &dl_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to access OMEMO DB %s.", db_fn_omemo);
    goto cleanup;
  }

  if (omemo_devicelist_is_empty(dl_p)) {
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to create axc ctx for %s.", uname);
    goto cleanup;
  }

  id_list = omemo_devicelist_get_id_list(dl_p);

  ret_val = lurch_api_fp_create_table(contact_bare_jid, axc_ctx_p, id_list, &id_fp_table);

cleanup:
  cb(ret_val, id_fp_table, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  axc_context_destroy_all(axc_ctx_p);
  g_list_free_full(id_list, free);
  axc_buf_free(key_buf_p);

  if (id_fp_table) {
    g_hash_table_destroy(id_fp_table);
  }
}

void lurch_api_status_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, lurch_status_t status, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  lurch_status_t status = LURCH_STATUS_DISABLED;

  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_exists(contact_bare_jid, db_fn_omemo);
  if (ret_val < 0 || ret_val > 1) {
    purple_debug_error(MODULE_NAME, "Failed to look up %s in file %s.", contact_bare_jid, db_fn_omemo);
    goto cleanup;
  } else if (ret_val == 0) {
    // conversation is not on blacklist, continue
  } else if (ret_val == 1) {
    ret_val = 0;
    status = LURCH_STATUS_DISABLED;
    goto cleanup;
  }

  ret_val = omemo_storage_user_devicelist_retrieve(contact_bare_jid, db_fn_omemo, &dl_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to get the devicelist for %s from %s.", contact_bare_jid, db_fn_omemo);
    goto cleanup;
  }

  if (omemo_devicelist_is_empty(dl_p)) {
    ret_val = 0;
    status = LURCH_STATUS_NOT_SUPPORTED;
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    purple_debug_error(MODULE_NAME, "Failed to create axc ctx for %s.", uname);
    goto cleanup;
  }

  ret_val = axc_session_exists_any(contact_bare_jid, axc_ctx_p);
  if (ret_val < 0) {
    purple_debug_error(MODULE_NAME, "Failed to look up session with %s.", contact_bare_jid);
    goto cleanup;
  } else if (ret_val == 0) {
    ret_val = 0;
    status = LURCH_STATUS_NO_SESSION;
  } else {
    ret_val = 0;
    status = LURCH_STATUS_OK;
  }

cleanup:
  cb(ret_val, status, user_data_p);

  g_free(uname);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  axc_context_destroy_all(axc_ctx_p);
}

/**
 * Callback for the discovery request.
 * data_p needs to be a pointer to lurch_api_status_chat_cb_data, which will be freed.
 */
void lurch_api_status_chat_discover_cb(JabberStream * js_p, const char * from, JabberIqType type, const char * id, xmlnode * packet_p,  gpointer data_p) {
  int32_t ret_val = 0;
  lurch_status_chat_t status = LURCH_STATUS_CHAT_DISABLED;

  xmlnode * query_node_p = (void *) 0;
  xmlnode * child_node_p = (void *) 0;
  PurpleConversation * conv_p = (void *) 0;
  JabberChat * muc_p = (void *) 0;
  const char * feature_name = (void *) 0;
  GList * curr_item_p = (void *) 0;
  JabberChatMember * curr_muc_member_p = (void *) 0;
  char * curr_muc_member_bare_jid = (void *) 0;
  omemo_devicelist * curr_dl_p = (void *) 0;

  lurch_api_status_chat_cb_data * cb_data_p = (lurch_api_status_chat_cb_data *) data_p;
  gboolean is_anonymous = TRUE;

  if (type == JABBER_IQ_ERROR) {
    purple_debug_error(MODULE_NAME, "MUC feature discovery request for %s returned an error.\n", from );
    ret_val = EXIT_FAILURE;
    goto cleanup;
  }

  query_node_p = xmlnode_get_child_with_namespace(packet_p, "query", DISCO_XMLNS);
  if (!query_node_p) {
    purple_debug_error(MODULE_NAME, "no 'query' node in feature discovery reply for %s\n", from);
    ret_val = EXIT_FAILURE;
    goto cleanup;
  }

  for (child_node_p = query_node_p->child; child_node_p; child_node_p = child_node_p->next) {
    if (g_strcmp0(child_node_p->name, "feature")) {
      continue;
    }

    feature_name = xmlnode_get_attrib(child_node_p, "var");
    if (!g_strcmp0("muc_nonanonymous", feature_name)) {
      is_anonymous = FALSE;
    } else  if (!g_strcmp0("muc_open", feature_name)) {
      purple_debug_warning(MODULE_NAME, "muc %s is open, this is likely to cause problems for OMEMO\n", from);
    }
  }

  if (is_anonymous) {
    status = LURCH_STATUS_CHAT_ANONYMOUS;
    goto cleanup;
  }

  conv_p = purple_find_conversation_with_account(PURPLE_CONV_TYPE_CHAT, from, js_p->gc->account);
  if (!conv_p) {
    purple_debug_error(MODULE_NAME, "could not find groupchat %s\n", from);
    ret_val = EXIT_FAILURE;
    goto cleanup;
  }

  muc_p = jabber_chat_find_by_conv(conv_p);
  if (!muc_p) {
    purple_debug_error(MODULE_NAME, "Could not find the data for groupchat %s.\n", from);
    ret_val = EXIT_FAILURE;
    goto cleanup;
  }

  for (curr_item_p = g_hash_table_get_values(muc_p->members); curr_item_p; curr_item_p = curr_item_p->next) {
    curr_muc_member_p = (JabberChatMember *) curr_item_p->data;
    curr_muc_member_bare_jid = jabber_get_bare_jid(curr_muc_member_p->jid);

    if (!curr_muc_member_bare_jid) {
      // getting here means that the MUC is not anonymous, but the members' JIDs are not available
      // this can happen when the room is reconfigured to be anonymous while the client is in it
      purple_debug_warning(MODULE_NAME, "Could not access %s's JID even though the room is public. Rejoining will probably fix this.\n", curr_muc_member_p->handle);
      status = LURCH_STATUS_CHAT_NO_JIDS;
      goto cleanup;
    }

    ret_val = omemo_storage_user_devicelist_retrieve(curr_muc_member_bare_jid, cb_data_p->db_fn_omemo, &curr_dl_p);
    if (ret_val) {
      purple_debug_error(MODULE_NAME, "Could not retrieve the devicelist for %s (JID: %s) from %s.\n", curr_muc_member_p->handle, curr_muc_member_bare_jid, cb_data_p->db_fn_omemo);
      goto cleanup;
    }

    if (omemo_devicelist_is_empty(curr_dl_p)) {
      purple_debug_warning(
        MODULE_NAME,
        "Could not find chat %s member %s's devicelist in OMEMO DB %s. This probably means the user is not in this account's contact list.",
        from, curr_muc_member_bare_jid, cb_data_p->db_fn_omemo
      );

      status = LURCH_STATUS_CHAT_NO_DEVICELIST;
      goto cleanup;
    }

    g_free(curr_muc_member_bare_jid);
    curr_muc_member_bare_jid = (void *) 0;

    omemo_devicelist_destroy(curr_dl_p);
    curr_dl_p = (void *) 0;
  }

  status = LURCH_STATUS_CHAT_OK;

cleanup:
  cb_data_p->cb(ret_val, status, cb_data_p->user_data_p);

  g_free(cb_data_p->db_fn_omemo);
  g_free(cb_data_p);

  // if loop was exited early, this needs to be cleaned up here
  g_free(curr_muc_member_bare_jid);
  omemo_devicelist_destroy(curr_dl_p);
}

// Send a discovery request to a MUC to learn its properties, e.g. for determining whether it is set to anonymous.
// See https://xmpp.org/extensions/xep-0045.html#disco-roominfo
static void lurch_api_status_chat_discover(PurpleAccount * acc_p, const char * full_conversation_name, lurch_api_status_chat_cb_data * data_p) {
  JabberIq * jiq_p = (void *) 0;
  xmlnode * query_node_p = (void *) 0;

  JabberStream * js_p = purple_connection_get_protocol_data(purple_account_get_connection(acc_p));

  jiq_p = jabber_iq_new(js_p, JABBER_IQ_GET);
  xmlnode_set_attrib(jiq_p->node, "to", full_conversation_name);
  query_node_p = xmlnode_new_child(jiq_p->node, "query");
  xmlnode_set_namespace(query_node_p, DISCO_XMLNS);

  jabber_iq_set_callback(jiq_p, lurch_api_status_chat_discover_cb, data_p);
  jabber_iq_send(jiq_p); // this also frees the memory

  purple_debug_info(MODULE_NAME, "sent feature discovery request to MUC %s\n", full_conversation_name);
}

void lurch_api_status_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, lurch_status_chat_t status, void * user_data_p), void * user_data_p) {
  int32_t ret_val = 0;
  lurch_status_chat_t status = LURCH_STATUS_CHAT_DISABLED;
  gboolean early_exit = FALSE; // call the provided callback directly in this function instead of in the iq query callback

  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_exists(full_conversation_name, db_fn_omemo);
  if (ret_val < 0 || ret_val > 1) {
    purple_debug_error(MODULE_NAME, "Failed to look up %s in file %s.", full_conversation_name, db_fn_omemo);
    early_exit = TRUE;
    goto cleanup;
  } else if (ret_val == 0) {
    ret_val = 0;
    status = LURCH_STATUS_CHAT_DISABLED;
    early_exit = TRUE;
    goto cleanup;
  } else if (ret_val == 1) {
    // omemo enabled for chat, continue
    ret_val = 0;
  }

  lurch_api_status_chat_cb_data * cb_data_p = (void *) 0;
  cb_data_p = g_malloc0(sizeof(lurch_api_status_chat_cb_data));
  if (!cb_data_p) {
    ret_val = LURCH_ERR_NOMEM;
    early_exit = TRUE;
    goto cleanup;
  }
  cb_data_p->db_fn_omemo = db_fn_omemo;
  cb_data_p->cb = cb;
  cb_data_p->user_data_p = user_data_p;

  lurch_api_status_chat_discover(acc_p, full_conversation_name, cb_data_p);

cleanup:
  g_free(uname);

  if (early_exit) {
    // in other cases, db_fn_omemo will be freed when the cb data is destroyed
    g_free(db_fn_omemo); 

    // in the regular case, the callback is passed on and called later
    cb(ret_val, status, user_data_p);
  }
}

static void lurch_api_marshal_VOID__POINTER_INT_POINTER_POINTER(PurpleCallback cb, va_list args, void * data, void ** return_val) {
	void * arg1 = va_arg(args, void *);
	gint32 arg2 = va_arg(args, guint);
  void * arg3 = va_arg(args, void *);
  void * arg4 = va_arg(args, void *);

	((void (*)(void *, guint, void *, void *, void *))cb)(arg1, arg2, arg3, arg4, data);
}

typedef enum {
  LURCH_API_HANDLER_ACC_CB_DATA = 0,
  LURCH_API_HANDLER_ACC_JID_CB_DATA,
  LURCH_API_HANDLER_ACC_DID_CB_DATA
} lurch_api_handler_t;

typedef struct {
  const char * name;
  void * handler;
  lurch_api_handler_t handler_type;
} lurch_signal_info;

const lurch_signal_info signal_infos[] = {
  {
    .name = "lurch-id-list",
    .handler = lurch_api_id_list_handler,
    .handler_type = LURCH_API_HANDLER_ACC_CB_DATA,
  },
  {
    .name = "lurch-id-remove",
    .handler = lurch_api_id_remove_handler,
    .handler_type = LURCH_API_HANDLER_ACC_DID_CB_DATA,
  },
  {
    .name = "lurch-enable-im",
    .handler = lurch_api_enable_im_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-disable-im",
    .handler = lurch_api_disable_im_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-enable-chat",
    .handler = lurch_api_enable_chat_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-disable-chat",
    .handler = lurch_api_disable_chat_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-fp-get",
    .handler = lurch_api_fp_get_handler,
    .handler_type = LURCH_API_HANDLER_ACC_CB_DATA,
  },
  {
    .name = "lurch-fp-list",
    .handler = lurch_api_fp_list_handler,
    .handler_type = LURCH_API_HANDLER_ACC_CB_DATA,
  },
  {
    .name = "lurch-fp-other",
    .handler = lurch_api_fp_other_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-status-im",
    .handler = lurch_api_status_im_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
  {
    .name = "lurch-status-chat",
    .handler = lurch_api_status_chat_handler,
    .handler_type = LURCH_API_HANDLER_ACC_JID_CB_DATA,
  },
};

static int get_num_of_signals() {
  return (sizeof signal_infos) / (sizeof signal_infos[0]);
}

void lurch_api_init() {
  void * plugins_handle_p = purple_plugins_get_handle();

  for (int i = 0; i < get_num_of_signals(); i++) {
    lurch_signal_info signal_info = signal_infos[i];
    const char * signal_name = signal_info.name;

    switch (signal_info.handler_type) {
      case LURCH_API_HANDLER_ACC_CB_DATA:
        purple_signal_register(
          plugins_handle_p,
          signal_name,
          purple_marshal_VOID__POINTER_POINTER_POINTER,
          NULL,
          3,
          purple_value_new(PURPLE_TYPE_SUBTYPE, PURPLE_SUBTYPE_ACCOUNT),
          purple_value_new(PURPLE_TYPE_POINTER),
          purple_value_new(PURPLE_TYPE_POINTER)
        );
        break;
      case LURCH_API_HANDLER_ACC_JID_CB_DATA:
        purple_signal_register(
          plugins_handle_p,
          signal_name,
          purple_marshal_VOID__POINTER_POINTER_POINTER_POINTER,
          NULL,
          4,
          purple_value_new(PURPLE_TYPE_SUBTYPE, PURPLE_SUBTYPE_ACCOUNT),
          purple_value_new(PURPLE_TYPE_STRING),
          purple_value_new(PURPLE_TYPE_POINTER),
          purple_value_new(PURPLE_TYPE_POINTER)
        );
        break;
      case LURCH_API_HANDLER_ACC_DID_CB_DATA:
        purple_signal_register(
          plugins_handle_p,
          signal_name,
          lurch_api_marshal_VOID__POINTER_INT_POINTER_POINTER,
          NULL,
          4,
          purple_value_new(PURPLE_TYPE_SUBTYPE, PURPLE_SUBTYPE_ACCOUNT),
          purple_value_new(PURPLE_TYPE_INT),
          purple_value_new(PURPLE_TYPE_POINTER),
          purple_value_new(PURPLE_TYPE_POINTER)
        );
        break;
      default:
        purple_debug_fatal(MODULE_NAME, "Unknown handler function type, aborting initialization.");
    }

    purple_signal_connect(
      plugins_handle_p,
      signal_name,
      MODULE_NAME,
      PURPLE_CALLBACK(signal_info.handler),
      NULL
    );
  }
}

void lurch_api_unload() {
  void * plugins_handle_p = purple_plugins_get_handle();

  for (int i = 0; i < get_num_of_signals(); i++) {
    lurch_signal_info signal_info = signal_infos[i];
    const char * signal_name = signal_info.name;

    purple_signal_disconnect(
      plugins_handle_p,
      signal_name,
      MODULE_NAME,
      PURPLE_CALLBACK(signal_info.handler)
    );

    purple_signal_unregister(plugins_handle_p, signal_name);
  }
}
