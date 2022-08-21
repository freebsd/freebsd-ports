#include <glib.h>

#include <inttypes.h>
#include <string.h>
#include <time.h>

#include <purple.h>

#include "chat.h"
#include "jabber.h"
#include "jutil.h"
#include "pep.h"

#include "libomemo.h"
#include "libomemo_storage.h"

#include "axc.h"
#include "axc_store.h"

// included for error codes
#include "signal_protocol.h"

#include "lurch.h"
#include "lurch_addr.h"
#include "lurch_api.h"
#include "lurch_cmd_ui.h"
#include "lurch_crypto.h"
#include "lurch_util.h"

#ifdef _WIN32
#define strnlen(a, b) (MIN(strlen(a), (b)))
#endif

#define LURCH_ERR_STRING_ENCRYPT "There was an error encrypting the message and it was not sent. " \
                                 "You can try again, or try to find the problem by looking at the debug log."
#define LURCH_ERR_STRING_DECRYPT "There was an error decrypting an OMEMO message addressed to this device. " \
                                 "See the debug log for details."

typedef struct lurch_queued_msg {
  omemo_message * om_msg_p;
  GList * recipient_addr_l_p;
  GList * no_sess_l_p;
  GHashTable * sess_handled_p;
} lurch_queued_msg;

int topic_changed = 0;
int uninstall = 0;

PurpleCmdId lurch_cmd_handle_id = 0;

/**
 * Creates a queued msg.
 * Note that it just saves the pointers, so make sure they are not freed during
 * the lifetime of this struct and instead use the destroy function when done.
 *
 * @param om_msg_p Pointer to the omemo_message.
 * @param recipient_addr_l_p Pointer to the list of recipient addresses.
 * @param no_sess_l_p Pointer to the list that contains the addresses that do
 *                    not have sessions, i.e. for which bundles were requested.
 * @param cmsg_pp Will point to the pointer of the created queued msg struct.
 * @return 0 on success, negative on error.
 */
static int lurch_queued_msg_create(omemo_message * om_msg_p,
                                   GList * recipient_addr_l_p,
                                   GList * no_sess_l_p,
                                   lurch_queued_msg ** qmsg_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  lurch_queued_msg * qmsg_p = (void *) 0;
  GHashTable * sess_handled_p = (void *) 0;

  qmsg_p = malloc(sizeof(lurch_queued_msg));
  if (!qmsg_p) {
    ret_val = LURCH_ERR_NOMEM;
    err_msg_dbg = g_strdup_printf("failed to malloc space for queued msg struct");
    goto cleanup;
  }

  sess_handled_p = g_hash_table_new(g_str_hash, g_str_equal);

  qmsg_p->om_msg_p = om_msg_p;
  qmsg_p->recipient_addr_l_p = recipient_addr_l_p;
  qmsg_p->no_sess_l_p = no_sess_l_p;
  qmsg_p->sess_handled_p = sess_handled_p;

  *qmsg_pp = qmsg_p;

cleanup:
  if (ret_val) {
    free(qmsg_p);
  }
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  return ret_val;
}

static int lurch_queued_msg_is_handled(const lurch_queued_msg * qmsg_p) {
  return (g_list_length(qmsg_p->no_sess_l_p) == g_hash_table_size(qmsg_p->sess_handled_p)) ? 1 : 0;
}

/**
 * Frees all the memory used by the queued msg.
 */
static void lurch_queued_msg_destroy(lurch_queued_msg * qmsg_p) {
  if (qmsg_p) {
    omemo_message_destroy(qmsg_p->om_msg_p);
    g_list_free_full(qmsg_p->recipient_addr_l_p, free);
    g_hash_table_destroy(qmsg_p->sess_handled_p);
    free(qmsg_p);
  }
}

static char * lurch_queue_make_key_string_s(const char * name, const char * device_id) {
  return g_strconcat(name, "/", device_id, NULL);
}

/**
 * Does the first-time install of the axc DB.
 * As specified in OMEMO, it checks if the generated device ID already exists.
 * Therefore, it should be called at a point in time when other entries exist.
 * 
 * If an initialized DB already exists, this function exits with success without doing anything.
 * This is checked by trying to retrieve the device ID from it.
 *
 * @param uname The username.
 * @return 0 on success, negative on error.
 */
static int lurch_axc_prepare(char * uname) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  axc_context * axc_ctx_p = (void *) 0;
  uint32_t device_id = 0;
  char * db_fn_omemo = (void *) 0;

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get init axc ctx");
    goto cleanup;
  }

  ret_val = axc_get_device_id(axc_ctx_p, &device_id);
  if (!ret_val) {
    // already installed
    goto cleanup;
  }

  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  while (1) {
    ret_val = axc_install(axc_ctx_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to install axc");
      goto cleanup;
    }

    ret_val = axc_get_device_id(axc_ctx_p, &device_id);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to get own device id");
      goto cleanup;
    }

    ret_val = omemo_storage_global_device_id_exists(device_id, db_fn_omemo);
    if (ret_val == 1)  {
      ret_val = axc_db_init_status_set(AXC_DB_NEEDS_ROLLBACK, axc_ctx_p);
      if (ret_val) {
        err_msg_dbg = g_strdup_printf("failed to set axc db to rollback");
        goto cleanup;
      }
    } else if (ret_val < 0) {
      err_msg_dbg = g_strdup_printf("failed to access the db %s", db_fn_omemo);
      goto cleanup;
    } else {
      break;
    }
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  axc_context_destroy_all(axc_ctx_p);
  g_free(db_fn_omemo);

  return ret_val;
}

/**
 * Collects the information needed for a bundle and publishes it.
 *
 * @param uname The username.
 * @param js_p Pointer to the connection to use for publishing.
 */
static int lurch_bundle_publish_own(JabberStream * js_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  char * uname = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  axc_bundle * axcbundle_p = (void *) 0;
  omemo_bundle * omemobundle_p = (void *) 0;
  axc_buf * curr_buf_p = (void *) 0;
  axc_buf_list_item * next_p = (void *) 0;
  char * bundle_xml = (void *) 0;
  xmlnode * publish_node_bundle_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(js_p->gc)));

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to init axc ctx");
    goto cleanup;
  }

  ret_val = axc_bundle_collect(AXC_PRE_KEYS_AMOUNT, axc_ctx_p, &axcbundle_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to collect axc bundle");
    goto cleanup;
  }

  ret_val = omemo_bundle_create(&omemobundle_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to create omemo_bundle");
    goto cleanup;
  }

  ret_val = omemo_bundle_set_device_id(omemobundle_p, axc_bundle_get_reg_id(axcbundle_p));
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to set device id in omemo bundle");
    goto cleanup;
  }

  curr_buf_p = axc_bundle_get_signed_pre_key(axcbundle_p);
  ret_val = omemo_bundle_set_signed_pre_key(omemobundle_p,
                                            axc_bundle_get_signed_pre_key_id(axcbundle_p),
                                            axc_buf_get_data(curr_buf_p),
                                            axc_buf_get_len(curr_buf_p));
  if(ret_val) {
    err_msg_dbg = g_strdup_printf("failed to set signed pre key in omemo bundle");
    goto cleanup;
  }

  curr_buf_p = axc_bundle_get_signature(axcbundle_p);
  ret_val = omemo_bundle_set_signature(omemobundle_p,
                                       axc_buf_get_data(curr_buf_p),
                                       axc_buf_get_len(curr_buf_p));
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to set signature in omemo bundle");
    goto cleanup;
  }

  curr_buf_p = axc_bundle_get_identity_key(axcbundle_p);
  ret_val = omemo_bundle_set_identity_key(omemobundle_p,
                                          axc_buf_get_data(curr_buf_p),
                                          axc_buf_get_len(curr_buf_p));
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to set public identity key in omemo bundle");
    goto cleanup;
  }

  next_p = axc_bundle_get_pre_key_list(axcbundle_p);
  while (next_p) {
    curr_buf_p = axc_buf_list_item_get_buf(next_p);
    ret_val = omemo_bundle_add_pre_key(omemobundle_p,
                                       axc_buf_list_item_get_id(next_p),
                                       axc_buf_get_data(curr_buf_p),
                                       axc_buf_get_len(curr_buf_p));
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to add public pre key to omemo bundle");
      goto cleanup;
    }
    next_p = axc_buf_list_item_get_next(next_p);
  }

  ret_val = omemo_bundle_export(omemobundle_p, &bundle_xml);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to export omemo bundle to xml");
    goto cleanup;
  }

  publish_node_bundle_p = xmlnode_from_str(bundle_xml, -1);
  jabber_pep_publish(js_p, publish_node_bundle_p);

  purple_debug_info("lurch", "%s: published own bundle for %s\n", __func__, uname);

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  g_free(uname);
  axc_context_destroy_all(axc_ctx_p);
  axc_bundle_destroy(axcbundle_p);
  omemo_bundle_destroy(omemobundle_p);
  g_free(bundle_xml);

  return ret_val;
}

/**
 * Parses the device ID from a received bundle update.
 *
 * @param bundle_node_ns The node name.
 * @return The ID.
 */
static uint32_t lurch_bundle_name_get_device_id(const char * bundle_node_name) {
  char ** split = (void *) 0;
  uint32_t id = 0;

  split = g_strsplit(bundle_node_name, ":", -1);
  id = strtol(split[5], (void *) 0, 0);

  g_strfreev(split);

  return id;
}

/**
 * Creates an axc session from a received bundle.
 *
 * @param uname The own username.
 * @param from The sender of the bundle.
 * @param items_p The bundle update as received in the PEP request handler.
 */
static int lurch_bundle_create_session(const char * uname,
                                       const char * from,
                                       const xmlnode * items_p,
                                       axc_context * axc_ctx_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;
  char * tempxml = (void *) 0;
  int len;
  omemo_bundle * om_bundle_p = (void *) 0;
  axc_address remote_addr = {0};
  uint32_t pre_key_id = 0;
  uint8_t * pre_key_p = (void *) 0;
  size_t pre_key_len = 0;
  uint32_t signed_pre_key_id = 0;
  uint8_t * signed_pre_key_p = (void *) 0;
  size_t signed_pre_key_len = 0;
  uint8_t * signature_p = (void *) 0;
  size_t signature_len = 0;
  uint8_t * identity_key_p = (void *) 0;
  size_t identity_key_len = 0;
  axc_buf * pre_key_buf_p = (void *) 0;
  axc_buf * signed_pre_key_buf_p = (void *) 0;
  axc_buf * signature_buf_p = (void *) 0;
  axc_buf * identity_key_buf_p = (void *) 0;

  purple_debug_info("lurch", "%s: creating a session between %s and %s from a received bundle\n", __func__, uname, from);

  tempxml = xmlnode_to_str(items_p, &len);
  ret_val = omemo_bundle_import(tempxml, &om_bundle_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to import xml into bundle");
    goto cleanup;
  }

  remote_addr.name = from;
  remote_addr.name_len = strnlen(from, JABBER_MAX_LEN_BARE);
  remote_addr.device_id = omemo_bundle_get_device_id(om_bundle_p);

  purple_debug_info("lurch", "%s: bundle's device id is %i\n", __func__, remote_addr.device_id);

  ret_val = omemo_bundle_get_random_pre_key(om_bundle_p, &pre_key_id, &pre_key_p, &pre_key_len);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed get a random pre key from the bundle");
    goto cleanup;
  }
  ret_val = omemo_bundle_get_signed_pre_key(om_bundle_p, &signed_pre_key_id, &signed_pre_key_p, &signed_pre_key_len);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get the signed pre key from the bundle");
    goto cleanup;
  }
  ret_val = omemo_bundle_get_signature(om_bundle_p, &signature_p, &signature_len);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get the signature from the bundle");
    goto cleanup;
  }
  ret_val = omemo_bundle_get_identity_key(om_bundle_p, &identity_key_p, &identity_key_len);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get the public identity key from the bundle");
    goto cleanup;
  }

  pre_key_buf_p = axc_buf_create(pre_key_p, pre_key_len);
  signed_pre_key_buf_p = axc_buf_create(signed_pre_key_p, signed_pre_key_len);
  signature_buf_p = axc_buf_create(signature_p, signature_len);
  identity_key_buf_p = axc_buf_create(identity_key_p, identity_key_len);

  if (!pre_key_buf_p || !signed_pre_key_buf_p || !signature_buf_p || !identity_key_buf_p) {
    ret_val = LURCH_ERR;
    err_msg_dbg = g_strdup_printf("failed to create one of the buffers");
    goto cleanup;
  }

  ret_val = axc_session_from_bundle(pre_key_id, pre_key_buf_p,
                                    signed_pre_key_id, signed_pre_key_buf_p,
                                    signature_buf_p,
                                    identity_key_buf_p,
                                    &remote_addr,
                                    axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to create a session from a bundle");
    goto cleanup;
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  omemo_bundle_destroy(om_bundle_p);
  g_free(tempxml);
  free(pre_key_p);
  free(signed_pre_key_p);
  free(signature_p);
  free(identity_key_p);
  axc_buf_free(pre_key_buf_p);
  axc_buf_free(signed_pre_key_buf_p);
  axc_buf_free(signature_buf_p);
  axc_buf_free(identity_key_buf_p);

  return ret_val;
}

/**
 * Wraps the omemo_message_export_encrypted message, so that it is called with the same options throughout.
 */
static int lurch_export_encrypted(omemo_message * om_msg_p, char ** xml_pp) {
  return omemo_message_export_encrypted(om_msg_p, OMEMO_ADD_MSG_EME, xml_pp);
}

/**
 * Implements JabberIqCallback.
 * Callback for a bundle request.
 */
static void lurch_bundle_request_cb(JabberStream * js_p, const char * from,
                                    JabberIqType type, const char * id,
                                    xmlnode * packet_p, gpointer data_p) {
  int ret_val = 0;
  char * err_msg_conv = (void *) 0;
  const char * err_msg_dbg = (void *) 0;

  char * uname = (void *) 0;
  char ** split = (void *) 0;
  const char * device_id_str = (void *) 0;
  axc_address addr = {0};
  axc_context * axc_ctx_p = (void *) 0;
  char * recipient = (void *) 0;
  xmlnode * pubsub_node_p = (void *) 0;
  xmlnode * items_node_p = (void *) 0;
  int msg_handled = 0;
  char * addr_key = (void *) 0;
  char * msg_xml = (void *) 0;
  xmlnode * msg_node_p = (void *) 0;
  lurch_queued_msg * qmsg_p = (lurch_queued_msg *) data_p;

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(js_p->gc)));
  recipient = omemo_message_get_recipient_name_bare(qmsg_p->om_msg_p);

  if (!from) {
    // own user
    from = uname;
  }

  split = g_strsplit(id, "#", 3);
  device_id_str = split[1];

  purple_debug_info("lurch", "%s: %s received bundle update from %s:%s\n", __func__, uname, from, device_id_str);

  addr.name = from;
  addr.name_len = strnlen(from, JABBER_MAX_LEN_BARE);
  addr.device_id = strtol(device_id_str, (void *) 0, 10);

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = "failed to get axc ctx";
    goto cleanup;
  }

  if (type == JABBER_IQ_ERROR) {
    err_msg_conv = g_strdup_printf("The device %s owned by %s does not have a bundle and will be skipped. "
                                   "The owner should fix this, or remove the device from the list.", device_id_str, from);

  } else {
    pubsub_node_p = xmlnode_get_child(packet_p, "pubsub");
    if (!pubsub_node_p) {
      ret_val = LURCH_ERR;
      err_msg_dbg = "no <pubsub> node in response";
      goto cleanup;
    }

    items_node_p = xmlnode_get_child(pubsub_node_p, "items");
    if (!items_node_p) {
      ret_val = LURCH_ERR;
      err_msg_dbg = "no <items> node in response";
      goto cleanup;
    }

    ret_val = axc_session_exists_initiated(&addr, axc_ctx_p);
    if (!ret_val) {
      ret_val = lurch_bundle_create_session(uname, from, items_node_p, axc_ctx_p);
      if (ret_val) {
        err_msg_dbg = "failed to create a session";
        goto cleanup;
      }
    } else if (ret_val < 0) {
      err_msg_dbg = "failed to check if session exists";
      goto cleanup;
    }
  }

  addr_key = lurch_queue_make_key_string_s(from, device_id_str);
  if (!addr_key) {
    err_msg_dbg = "failed to make a key string";
    ret_val = LURCH_ERR;
    goto cleanup;
  }

  (void) g_hash_table_replace(qmsg_p->sess_handled_p, addr_key, addr_key);

  if (!lurch_queued_msg_is_handled(qmsg_p)) {
    goto cleanup;
  }

  ret_val = lurch_crypto_encrypt_msg_for_addrs(qmsg_p->om_msg_p, qmsg_p->recipient_addr_l_p, qmsg_p->no_sess_l_p, axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = "failed to encrypt the symmetric key";
    goto cleanup;
  }

  ret_val = lurch_export_encrypted(qmsg_p->om_msg_p, &msg_xml);
  if (ret_val) {
    err_msg_dbg = "failed to export the message to xml";
    goto cleanup;
  }

  msg_node_p = xmlnode_from_str(msg_xml, -1);
  if (!msg_node_p) {
    err_msg_dbg = "failed to parse xml from string";
    ret_val = LURCH_ERR;
    goto cleanup;
  }

  purple_debug_info("lurch", "sending encrypted msg\n");
  purple_signal_emit(purple_plugins_find_with_id("prpl-jabber"), "jabber-sending-xmlnode", js_p->gc, &msg_node_p);

  lurch_queued_msg_destroy(qmsg_p);

cleanup:
  if (err_msg_conv) {
    purple_conv_present_error(recipient, purple_connection_get_account(js_p->gc), err_msg_conv);
    g_free(err_msg_conv);
  }
  if (err_msg_dbg) {
    purple_conv_present_error(recipient, purple_connection_get_account(js_p->gc), LURCH_ERR_STRING_ENCRYPT);
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
  }

  g_free(uname);
  g_strfreev(split);
  axc_context_destroy_all(axc_ctx_p);
  g_free(addr_key);
  g_free(recipient);
  free(msg_xml);
  if (msg_node_p) {
    xmlnode_free(msg_node_p);
  }
}

/**
 * Requests a bundle.
 *
 * @param js_p Pointer to the JabberStream to use.
 * @param to The recipient of this request.
 * @param device_id The ID of the device whose bundle is needed.
 * @param qmsg_p Pointer to the queued message waiting on (at least) this bundle.
 * @return 0 on success, negative on error.
 */
static int lurch_bundle_request_do(JabberStream * js_p,
                                   const char * to,
                                   uint32_t device_id,
                                   lurch_queued_msg * qmsg_p) {
  int ret_val = 0;

  JabberIq * jiq_p = (void *) 0;
  xmlnode * pubsub_node_p = (void *) 0;
  char * device_id_str = (void *) 0;
  char * rand_str = (void *) 0;
  char * req_id = (void *) 0;
  char * bundle_node_name = (void *) 0;
  xmlnode * items_node_p = (void *) 0;

  purple_debug_info("lurch", "%s: %s is requesting bundle from %s:%i\n", __func__,
                    purple_account_get_username(purple_connection_get_account(js_p->gc)), to, device_id);

  jiq_p = jabber_iq_new(js_p, JABBER_IQ_GET);
  xmlnode_set_attrib(jiq_p->node, "to", to);

  pubsub_node_p = xmlnode_new_child(jiq_p->node, "pubsub");
  xmlnode_set_namespace(pubsub_node_p, "http://jabber.org/protocol/pubsub");

  device_id_str = g_strdup_printf("%i", device_id);
  rand_str = g_strdup_printf("%i", g_random_int());
  req_id = g_strconcat(to, "#", device_id_str, "#", rand_str, NULL);

  ret_val = omemo_bundle_get_pep_node_name(device_id, &bundle_node_name);
  if (ret_val) {
    purple_debug_error("lurch", "%s: failed to get bundle pep node name for %s:%i\n", __func__, to, device_id);
    goto cleanup;
  }

  items_node_p = xmlnode_new_child(pubsub_node_p, "items");
  xmlnode_set_attrib(items_node_p, "node", bundle_node_name);
  xmlnode_set_attrib(items_node_p, "max_items", "1");

  jabber_iq_set_id(jiq_p, req_id);
  jabber_iq_set_callback(jiq_p, lurch_bundle_request_cb, qmsg_p);

  jabber_iq_send(jiq_p);

  purple_debug_info("lurch", "%s: ...request sent\n", __func__);

cleanup:
  g_free(device_id_str);
  g_free(rand_str);
  g_free(req_id);
  free(bundle_node_name);

  return ret_val;
}

/**
 * A JabberPEPHandler function.
 * When a prekey message containing an invalid key ID is received,
 * the bundle of the sender is requested and a KeyTransport message is sent
 * in response so that a session can still be established.
 */
static void lurch_pep_bundle_for_keytransport(JabberStream * js_p, const char * from, xmlnode * items_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  char * uname = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  omemo_message * msg_p = (void *) 0;
  axc_address addr = {0};
  lurch_addr laddr = {0};
  axc_buf * key_ct_buf_p = (void *) 0;
  char * msg_xml = (void *) 0;
  xmlnode * msg_node_p = (void *) 0;
  void * jabber_handle_p = purple_plugins_find_with_id("prpl-jabber");

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(js_p->gc)));

  addr.name = from;
  addr.name_len = strnlen(from, JABBER_MAX_LEN_BARE);
  addr.device_id = lurch_bundle_name_get_device_id(xmlnode_get_attrib(items_p, "node"));

  purple_debug_info("lurch", "%s: %s received bundle from %s:%i\n", __func__, uname, from, addr.device_id);

  laddr.jid = g_strndup(addr.name, addr.name_len);
  laddr.device_id = addr.device_id;

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to init axc ctx");
    goto cleanup;
  }

  // make sure it's gonna be a pre_key_message
  ret_val = axc_session_delete(addr.name, addr.device_id, axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to delete possibly existing session");
    goto cleanup;
  }

  ret_val = lurch_bundle_create_session(uname, from, items_p, axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to create session");
    goto cleanup;
  }

  purple_debug_info("lurch", "%s: %s created session with %s:%i\n", __func__, uname, from, addr.device_id);

  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get own device id");
    goto cleanup;
  }

  ret_val = omemo_message_create(own_id, &crypto, &msg_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to create omemo msg");
    goto cleanup;
  }

  ret_val = lurch_crypto_encrypt_key(&laddr,
                              omemo_message_get_key(msg_p),
                              omemo_message_get_key_len(msg_p),
                              axc_ctx_p,
                              &key_ct_buf_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to encrypt key for %s:%i", addr.name, addr.device_id);
    goto cleanup;
  }

  ret_val = omemo_message_add_recipient_w_prekey(msg_p, addr.device_id, axc_buf_get_data(key_ct_buf_p), axc_buf_get_len(key_ct_buf_p));
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to add %s:%i as recipient to message", addr.name, addr.device_id);
    goto cleanup;
  }

  // don't call wrapper function here as EME is not necessary
  ret_val = omemo_message_export_encrypted(msg_p, OMEMO_ADD_MSG_NONE, &msg_xml);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to export encrypted msg");
    goto cleanup;
  }

  msg_node_p = xmlnode_from_str(msg_xml, -1);
  if (!msg_node_p) {
    err_msg_dbg = g_strdup_printf("failed to create xml node from xml string");
    goto cleanup;
  }

  purple_signal_emit(jabber_handle_p, "jabber-sending-xmlnode", js_p->gc, &msg_node_p);
  purple_debug_info("lurch", "%s: %s sent keytransportmsg to %s:%i\n", __func__, uname, from, addr.device_id);


cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  g_free(laddr.jid);
  g_free(uname);
  axc_context_destroy_all(axc_ctx_p);
  omemo_message_destroy(msg_p);
  axc_buf_free(key_ct_buf_p);
  free(msg_xml);
  if (msg_node_p) {
    xmlnode_free(msg_node_p);
  }
}

/**
 * Processes a devicelist by updating the database with it.
 *
 * @param uname The username.
 * @param dl_in_p Pointer to the incoming devicelist.
 * @param js_p Pointer to the JabberStream.
 * @return 0 on success, negative on error.
 */
static int lurch_devicelist_process(char * uname, omemo_devicelist * dl_in_p, JabberStream * js_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  const char * from = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  omemo_devicelist * dl_db_p = (void *) 0;
  GList * add_l_p = (void *) 0;
  GList * del_l_p = (void *) 0;
  GList * curr_p = (void *) 0;
  uint32_t curr_id = 0;
  char * bundle_node_name = (void *) 0;

  char * debug_str = (void *) 0;

  from = omemo_devicelist_get_owner(dl_in_p);
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  purple_debug_info("lurch", "%s: processing devicelist from %s for %s\n", __func__, from, uname);

  ret_val = omemo_storage_user_devicelist_retrieve(from, db_fn_omemo, &dl_db_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to retrieve cached devicelist for %s from db %s", from, db_fn_omemo);
    goto cleanup;
  }

  omemo_devicelist_export(dl_db_p, &debug_str);
  purple_debug_info("lurch", "%s: %s\n%s\n", __func__, "cached devicelist is", debug_str);

  ret_val = omemo_devicelist_diff(dl_in_p, dl_db_p, &add_l_p, &del_l_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to diff devicelists");
    goto cleanup;
  }

  for (curr_p = add_l_p; curr_p; curr_p = curr_p->next) {
    curr_id = omemo_devicelist_list_data(curr_p);
    purple_debug_info("lurch", "%s: saving %i for %s to db %s\n", __func__, curr_id, from, db_fn_omemo);
    ret_val = omemo_storage_user_device_id_save(from, curr_id, db_fn_omemo);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to save %i for %s to %s", curr_id, from, db_fn_omemo);
      goto cleanup;
    }
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to init axc ctx");
    goto cleanup;
  }

  for (curr_p = del_l_p; curr_p; curr_p = curr_p->next) {
    curr_id = omemo_devicelist_list_data(curr_p);
    purple_debug_info("lurch", "%s: deleting %i for %s to db %s\n", __func__, curr_id, from, db_fn_omemo);

    ret_val = omemo_storage_user_device_id_delete(from, curr_id, db_fn_omemo);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to delete %i for %s from %s", curr_id, from, db_fn_omemo);
      goto cleanup;
    }
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_db_p);
  axc_context_destroy_all(axc_ctx_p);
  g_list_free_full(add_l_p, free);
  g_list_free_full(del_l_p, free);
  free(bundle_node_name);
  free(debug_str);

  return ret_val;
}

/**
 * A JabberPEPHandler function.
 * Is used to handle the own devicelist and also perform install-time functions.
 */
static void lurch_pep_own_devicelist_request_handler(JabberStream * js_p, const char * from, xmlnode * items_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;
  char * tempxml = (void *) 0;
  int len = 0;
  PurpleAccount * acc_p = (void *) 0;
  char * uname = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  int needs_publishing = 1;
  omemo_devicelist * dl_p = (void *) 0;
  char * dl_xml = (void *) 0;
  xmlnode * publish_node_dl_p = (void *) 0;

  acc_p = purple_connection_get_account(js_p->gc);
  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));

  if (!uninstall) {
    purple_debug_info("lurch", "%s: %s\n", __func__, "preparing installation...");
    ret_val = lurch_axc_prepare(uname);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to prepare axc");
      goto cleanup;
    }
    purple_debug_info("lurch", "%s: %s\n", __func__, "...done");
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to init axc ctx");
    goto cleanup;
  }
  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get own id");
    goto cleanup;
  }

  if (!items_p) {
    purple_debug_info("lurch", "%s: %s\n", __func__, "no devicelist yet, creating it");
    ret_val = omemo_devicelist_create(uname, &dl_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to create devicelist");
      goto cleanup;
    }
    ret_val = omemo_devicelist_add(dl_p, own_id);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to add own id %i to devicelist", own_id);
      goto cleanup;
    }
  } else {
    purple_debug_info("lurch", "%s: %s\n", __func__, "comparing received devicelist with cached one");
    tempxml = xmlnode_to_str(items_p, &len);
    ret_val = omemo_devicelist_import(tempxml, uname, &dl_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to import received devicelist");
      goto cleanup;
    }

    ret_val = omemo_devicelist_contains_id(dl_p, own_id);
    if (ret_val == 1) {
      purple_debug_info("lurch", "%s: %s\n", __func__, "own id was already contained in received devicelist, doing nothing");
      needs_publishing = 0;
    } else if (ret_val == 0) {
      if (!uninstall) {
        purple_debug_info("lurch", "%s: %s\n", __func__, "own id was missing, adding it");
        ret_val = omemo_devicelist_add(dl_p, own_id);
        if (ret_val) {
          err_msg_dbg = g_strdup_printf("failed to add own id %i to devicelist", own_id);
          goto cleanup;
        }
      } else {
        needs_publishing = 0;
      }

    } else {
      err_msg_dbg = g_strdup_printf("failed to look up if the devicelist contains the own id");
      goto cleanup;
    }
  }

  if (needs_publishing) {
    purple_debug_info("lurch", "%s: %s\n", __func__, "devicelist needs publishing...");
    ret_val = omemo_devicelist_export(dl_p, &dl_xml);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to export new devicelist");
      goto cleanup;
    }

    publish_node_dl_p = xmlnode_from_str(dl_xml, -1);
    jabber_pep_publish(js_p, publish_node_dl_p);

    purple_debug_info("lurch", "%s: \n%s:\n", __func__, "...done");
  }

  ret_val = lurch_bundle_publish_own(js_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to publish own bundle");
    goto cleanup;
  }

  ret_val = lurch_devicelist_process(uname, dl_p, js_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to process the devicelist");
    goto cleanup;
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  g_free(tempxml);
  g_free(uname);
  axc_context_destroy_all(axc_ctx_p);
  omemo_devicelist_destroy(dl_p);
  free(dl_xml);
}

/**
 * A JabberPEPHandler function.
 * On receiving a devicelist PEP updates the database entry.
 */
static void lurch_pep_devicelist_event_handler(JabberStream * js_p, const char * from, xmlnode * items_p) {
  int ret_val = 0;
  int len = 0;
  char * err_msg_dbg = (void *) 0;
  char * tempxml = (void *) 0;
  char * uname = (void *) 0;
  omemo_devicelist * dl_in_p = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(js_p->gc)));
  if (!strncmp(uname, from, strnlen(uname, JABBER_MAX_LEN_BARE))) {
    //own devicelist is dealt with in own handler
    lurch_pep_own_devicelist_request_handler(js_p, from, items_p);
    goto cleanup;
  }

  purple_debug_info("lurch", "%s: %s received devicelist update from %s\n", __func__, uname, from);

  tempxml = xmlnode_to_str(items_p, &len);
  ret_val = omemo_devicelist_import(tempxml, from, &dl_in_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to import devicelist");
    goto cleanup;
  }

  ret_val = lurch_devicelist_process(uname, dl_in_p, js_p);
  if(ret_val) {
    err_msg_dbg = g_strdup_printf("failed to process devicelist");
    goto cleanup;
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  g_free(tempxml);
  g_free(uname);
  omemo_devicelist_destroy(dl_in_p);
}

/**
 * Set as callback for the "account connected" signal.
 * Requests the own devicelist, as that requires an active connection (as opposed to just registering PEP handlers).
 */
static void lurch_account_connect_cb(PurpleAccount * acc_p) {
  int ret_val = 0;

  JabberStream * js_p = (void *) 0;
  char * uname = (void *) 0;
  char * dl_ns = (void *) 0;

  js_p = purple_connection_get_protocol_data(purple_account_get_connection(acc_p));

  if (strncmp(purple_account_get_protocol_id(acc_p), JABBER_PROTOCOL_ID, strlen(JABBER_PROTOCOL_ID))) {
    return;
  }

  // remove unused account preferences
  purple_account_remove_setting(acc_p, "lurch_initialised");

  ret_val = omemo_devicelist_get_pep_node_name(&dl_ns);
  if (ret_val) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, "failed to get devicelist pep node name", ret_val);
    goto cleanup;
  }
  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  jabber_pep_request_item(js_p, uname, dl_ns, (void *) 0, lurch_pep_own_devicelist_request_handler);

cleanup:
  g_free(uname);
  free(dl_ns);
}

/**
 * Does the final steps of encrypting the message.
 * If all devices have sessions, does the actual encrypting.
 * If not, saves it and sends bundle request to the missing devices so that the message can be sent at a later time.
 *
 * Note that if msg_stanza_pp points to NULL, both om_msg_p and addr_l_p must not be freed by the calling function.
 *
 * @param js_p          Pointer to the JabberStream to use.
 * @param axc_ctx_p     Pointer to the axc_context to use.
 * @param om_msg_p      Pointer to the omemo message.
 * @param addr_l_p      Pointer to a GList of lurch_addr structs that are supposed to receive the message.
 * @param msg_stanza_pp Pointer to the pointer to the <message> stanza.
 *                      Is either changed to point to the encrypted message, or to NULL if the message is to be sent later.
 * @return 0 on success, negative on error.
 *
 */
static int lurch_msg_finalize_encryption(JabberStream * js_p, axc_context * axc_ctx_p, omemo_message * om_msg_p, GList * addr_l_p, xmlnode ** msg_stanza_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  GList * no_sess_l_p = (void *) 0;
  char * xml = (void *) 0;
  xmlnode * temp_node_p = (void *) 0;
  lurch_queued_msg * qmsg_p = (void *) 0;
  GList * curr_item_p = (void *) 0;
  lurch_addr curr_addr = {0};

  ret_val = lurch_addr_sessions_exist(addr_l_p, axc_ctx_p, &no_sess_l_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to check if sessions exist");
    goto cleanup;
  }

  if (!no_sess_l_p) {
    ret_val = lurch_crypto_encrypt_msg_for_addrs(om_msg_p, addr_l_p, no_sess_l_p, axc_ctx_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to encrypt symmetric key for addrs");
      goto cleanup;
    }

    ret_val = lurch_export_encrypted(om_msg_p, &xml);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to export omemo msg to xml");
      goto cleanup;
    }

    omemo_message_destroy(om_msg_p);
    temp_node_p = xmlnode_from_str(xml, -1);
    *msg_stanza_pp = temp_node_p;
  } else {
    ret_val = lurch_queued_msg_create(om_msg_p, addr_l_p, no_sess_l_p, &qmsg_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to create queued message");
      goto cleanup;
    }

    for (curr_item_p = no_sess_l_p; curr_item_p; curr_item_p = curr_item_p->next) {
      curr_addr.jid = ((lurch_addr *)curr_item_p->data)->jid;
      curr_addr.device_id = ((lurch_addr *)curr_item_p->data)->device_id;

      purple_debug_info("lurch", "%s: %s has device without session %i, requesting bundle\n", __func__, curr_addr.jid, curr_addr.device_id);

      lurch_bundle_request_do(js_p,
                              curr_addr.jid,
                              curr_addr.device_id,
                              qmsg_p);

    }
    *msg_stanza_pp = (void *) 0;
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
    *msg_stanza_pp = (void *) 0;
  }
  if (!qmsg_p || ret_val) {
    free(qmsg_p);
  }

  free(xml);

  return ret_val;
}


/**
 * Set as callback for the "sending xmlnode" signal.
 * Encrypts the message body, if applicable.
 */
static void lurch_message_encrypt_im(PurpleConnection * gc_p, xmlnode ** msg_stanza_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;
  int len = 0;

  PurpleAccount * acc_p = (void *) 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  const char * to = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;
  GList * recipient_dl_p = (void *) 0;
  omemo_devicelist * user_dl_p = (void *) 0;
  GList * own_dl_p = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  omemo_message * msg_p = (void *) 0;
  GList * addr_l_p = (void *) 0;
  char * recipient = (void *) 0;
  char * tempxml = (void *) 0;

  recipient = jabber_get_bare_jid(xmlnode_get_attrib(*msg_stanza_pp, "to"));

  acc_p = purple_connection_get_account(gc_p);
  uname = lurch_util_uname_strip(purple_account_get_username(acc_p));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_exists(recipient, db_fn_omemo);
  if (ret_val < 0) {
    err_msg_dbg = g_strdup_printf("failed to look up %s in DB %s", recipient, db_fn_omemo);
    goto cleanup;
  } else if (ret_val == 1) {
    purple_debug_info("lurch", "%s: %s is on blacklist, skipping encryption\n", __func__, recipient);
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get axc ctx for %s", uname);
    goto cleanup;
  }

  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get device id");
    goto cleanup;
  }
  tempxml = xmlnode_to_str(*msg_stanza_pp, &len);
  ret_val = omemo_message_prepare_encryption(tempxml, own_id, &crypto, OMEMO_STRIP_ALL, &msg_p);
  g_free(tempxml);
  tempxml = (void *) 0;
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to construct omemo message");
    goto cleanup;
  }

  to = omemo_message_get_recipient_name_bare(msg_p);

  // determine if recipient is omemo user
  ret_val = omemo_storage_user_devicelist_retrieve(to, db_fn_omemo, &dl_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to retrieve devicelist for %s", to);
    goto cleanup;
  }

  ret_val = omemo_devicelist_export(dl_p, &tempxml);
  if(ret_val) {
    err_msg_dbg = g_strdup_printf("failed to export devicelist for %s", to);
    goto cleanup;
  }
  purple_debug_info("lurch", "retrieved devicelist for %s:\n%s\n", to, tempxml);

  recipient_dl_p = omemo_devicelist_get_id_list(dl_p);
  if (!recipient_dl_p) {
    ret_val = axc_session_exists_any(to, axc_ctx_p);
    if (ret_val < 0) {
      err_msg_dbg = g_strdup_printf("failed to check if session exists for %s in %s's db\n", to, uname);
      goto cleanup;
    } else if (ret_val == 1) {
      purple_conv_present_error(recipient, purple_connection_get_account(gc_p), "Even though an encrypted session exists, the recipient's devicelist is empty."
                                                                                "The user probably uninstalled OMEMO, so you can add this conversation to the blacklist.");
    } else {
      goto cleanup;
    }
  }

  ret_val = omemo_storage_user_devicelist_retrieve(uname, db_fn_omemo, &user_dl_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to retrieve devicelist for %s", uname);
    goto cleanup;
  }
  free(tempxml);
  tempxml = (void *) 0;
  omemo_devicelist_export(user_dl_p, &tempxml);
  purple_debug_info("lurch", "retrieved own devicelist:\n%s\n", tempxml);
  own_dl_p = omemo_devicelist_get_id_list(user_dl_p);
  if (!own_dl_p) {
    err_msg_dbg = g_strdup_printf("no own devicelist");
    goto cleanup;
  }

  addr_l_p = lurch_addr_list_add(addr_l_p, user_dl_p, &own_id);
  if (g_strcmp0(uname, to)) {
    addr_l_p = lurch_addr_list_add(addr_l_p, dl_p, (void *) 0);
  }

  ret_val = lurch_msg_finalize_encryption(purple_connection_get_protocol_data(gc_p), axc_ctx_p, msg_p, addr_l_p, msg_stanza_pp);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to finalize omemo message");
    goto cleanup;
  }

cleanup:
  if (err_msg_dbg) {
    purple_conv_present_error(recipient, purple_connection_get_account(gc_p), LURCH_ERR_STRING_ENCRYPT);
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
    *msg_stanza_pp = (void *) 0;
  }
  if (ret_val) {
    omemo_message_destroy(msg_p);
    lurch_addr_list_destroy(addr_l_p);
  }
  g_free(recipient);
  g_free(uname);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  g_list_free_full(recipient_dl_p, free);
  omemo_devicelist_destroy(user_dl_p);
  g_list_free_full(own_dl_p, free);
  axc_context_destroy_all(axc_ctx_p);
  free(tempxml);
}

static void lurch_message_encrypt_groupchat(PurpleConnection * gc_p, xmlnode ** msg_stanza_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;
  int len;

  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  char * tempxml = (void *) 0;
  omemo_message * om_msg_p = (void *) 0;
  omemo_devicelist * user_dl_p = (void *) 0;
  GList * addr_l_p = (void *) 0;
  PurpleConversation * conv_p = (void *) 0;
  PurpleConvChat * chat_p = (void *) 0;
  JabberChat * muc_p = (void *) 0;
  JabberChatMember * curr_muc_member_p = (void *) 0;
  xmlnode * body_node_p = (void *) 0;
  char * body_data = (void *) 0;
  GList * curr_item_p = (void *) 0;
  char * curr_muc_member_jid = (void *) 0;
  omemo_devicelist * curr_dl_p = (void *) 0;

  const char * to = xmlnode_get_attrib(*msg_stanza_pp, "to");

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(gc_p)));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = omemo_storage_chatlist_exists(to, db_fn_omemo);
  if (ret_val < 0) {
    err_msg_dbg = g_strdup_printf("failed to access db %s", db_fn_omemo);
    goto cleanup;
  } else if (ret_val == 0) {
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get axc ctx for %s", uname);
    goto cleanup;
  }

  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get device id");
    goto cleanup;
  }
  tempxml = xmlnode_to_str(*msg_stanza_pp, &len);
  ret_val = omemo_message_prepare_encryption(tempxml, own_id, &crypto, OMEMO_STRIP_ALL, &om_msg_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to construct omemo message");
    goto cleanup;
  }

  ret_val = omemo_storage_user_devicelist_retrieve(uname, db_fn_omemo, &user_dl_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to retrieve devicelist for %s", uname);
    goto cleanup;
  }

  addr_l_p = lurch_addr_list_add(addr_l_p, user_dl_p, &own_id);

  conv_p = purple_find_conversation_with_account(PURPLE_CONV_TYPE_CHAT, to, purple_connection_get_account(gc_p));
  if (!conv_p) {
    err_msg_dbg = g_strdup_printf("could not find groupchat %s", to);
    goto cleanup;
  }

  chat_p = purple_conversation_get_chat_data(conv_p);
  muc_p = jabber_chat_find_by_conv(conv_p);
  if (!muc_p) {
    err_msg_dbg = g_strdup_printf("could not find muc struct for groupchat %s", to);
    goto cleanup;
  }

  for (curr_item_p = g_hash_table_get_values(muc_p->members); curr_item_p; curr_item_p = curr_item_p->next) {
    curr_muc_member_p = (JabberChatMember *) curr_item_p->data;
    curr_muc_member_jid = jabber_get_bare_jid(curr_muc_member_p->jid);

    if (!curr_muc_member_jid) {
      err_msg_dbg = g_strdup_printf("Could not find the JID for %s - the channel needs to be non-anonymous!", curr_muc_member_p->handle);
      purple_conv_present_error(purple_conversation_get_name(conv_p), purple_connection_get_account(gc_p), err_msg_dbg);
      g_free(err_msg_dbg);
      err_msg_dbg = (void *) 0;
      continue;
    }

    // libpurple (rightly) assumes that in MUCs the message will come back anyway so it's not written to the chat
    // but encrypting and decrypting for yourself should not be done with the double ratchet, so the own device is skipped
    // and the typed message written to the chat window manually without sending
    if (!g_strcmp0(curr_muc_member_jid, uname)) {
      body_node_p = xmlnode_get_child(*msg_stanza_pp, "body");
      body_data = xmlnode_get_data(body_node_p);
      purple_conv_chat_write(chat_p, curr_muc_member_p->handle, body_data, PURPLE_MESSAGE_SEND, time((void *) 0));
      g_free(body_data);
      body_data = (void *) 0;
      continue;
    }

    ret_val = omemo_storage_user_devicelist_retrieve(curr_muc_member_jid, db_fn_omemo, &curr_dl_p);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("Could not retrieve the devicelist for %s from %s", curr_muc_member_jid, db_fn_omemo);
      goto cleanup;
    }

    if (omemo_devicelist_is_empty(curr_dl_p)) {
      err_msg_dbg = g_strdup_printf("User %s is no OMEMO user (does not have a devicelist). "
                                    "This user cannot read any incoming encrypted messages and will send his own messages in the clear!",
                                    curr_muc_member_jid);
      purple_conv_present_error(purple_conversation_get_name(conv_p), purple_connection_get_account(gc_p), err_msg_dbg);
      g_free(err_msg_dbg);
      err_msg_dbg = (void *) 0;
      continue;
    }

    addr_l_p = lurch_addr_list_add(addr_l_p, curr_dl_p, (void *) 0);
    omemo_devicelist_destroy(curr_dl_p);
    curr_dl_p = (void *) 0;
  }

  ret_val = lurch_msg_finalize_encryption(purple_connection_get_protocol_data(gc_p), axc_ctx_p, om_msg_p, addr_l_p, msg_stanza_pp);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to finalize msg");
    goto cleanup;
  }

  //TODO: properly handle this instead of removing the body completely, necessary for full EME support
  body_node_p = xmlnode_get_child(*msg_stanza_pp, "body");
  xmlnode_free(body_node_p);

cleanup:
  if (err_msg_dbg) {
    purple_conv_present_error(purple_conversation_get_name(conv_p), purple_connection_get_account(gc_p), LURCH_ERR_STRING_ENCRYPT);
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
    *msg_stanza_pp = (void *) 0;
  }
  if (ret_val) {
    omemo_message_destroy(om_msg_p);
    lurch_addr_list_destroy(addr_l_p);
  }

  g_free(uname);
  g_free(db_fn_omemo);
  axc_context_destroy_all(axc_ctx_p);
  g_free(tempxml);
  g_free(body_data);
  omemo_devicelist_destroy(user_dl_p);
}

static void lurch_xml_sent_cb(PurpleConnection * gc_p, xmlnode ** stanza_pp) {
  xmlnode * body_node_p      = (void *) 0;
  xmlnode * encrypted_node_p = (void *) 0;
  const char * node_name     = (void *) 0;
  const char * type          = (void *) 0;

  if (uninstall) {
    return;
  }

  if (!stanza_pp || !*stanza_pp) {
    return;
  }

  node_name = (*stanza_pp)->name;
  type = xmlnode_get_attrib(*stanza_pp, "type");

  if (!g_strcmp0(node_name, "message")) {
    body_node_p = xmlnode_get_child(*stanza_pp, "body");
    if (!body_node_p) {
      return;
    }

    encrypted_node_p = xmlnode_get_child(*stanza_pp, "encrypted");
    if (encrypted_node_p) {
      return;
    }

    if (!g_strcmp0(type, "chat")) {
      lurch_message_encrypt_im(gc_p, stanza_pp);
    } else if (!g_strcmp0(type, "groupchat")) {
      lurch_message_encrypt_groupchat(gc_p, stanza_pp);
    }
  }
}

/**
 * Callback for the "receiving xmlnode" signal.
 * Decrypts message, if applicable.
 */
static void lurch_message_decrypt(PurpleConnection * gc_p, xmlnode ** msg_stanza_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;
  int len;

  omemo_message * msg_p = (void *) 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  uint32_t own_id = 0;
  uint8_t * key_p = (void *) 0;
  size_t key_len = 0;
  axc_buf * key_buf_p = (void *) 0;
  axc_buf * key_decrypted_p = (void *) 0;
  char * sender_name = (void *) 0;
  axc_address sender_addr = {0};
  char * bundle_node_name = (void *) 0;
  omemo_message * keytransport_msg_p = (void *) 0;
  char * xml = (void *) 0;
  char * sender = (void *) 0;
  char ** split = (void *) 0;
  const char * room_name = (void *) 0;
  const char * buddy_nick = (void *) 0;
  xmlnode * plaintext_msg_node_p = (void *) 0;
  char * recipient_bare_jid = (void *) 0;
  char * body_data = (void *) 0;
  PurpleConversation * conv_p = (void *) 0;
  JabberChat * muc_p = (void *) 0;
  JabberChatMember * muc_member_p = (void *) 0;

  const char * type = xmlnode_get_attrib(*msg_stanza_pp, "type");
  const char * from = xmlnode_get_attrib(*msg_stanza_pp, "from");
  const char * to   = xmlnode_get_attrib(*msg_stanza_pp, "to");

  if (uninstall) {
    goto cleanup;
  }

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(gc_p)));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  // on prosody and possibly other servers, messages to the own account do not have a recipient
  if (!to) {
    recipient_bare_jid = g_strdup(uname);
  } else {
    recipient_bare_jid = jabber_get_bare_jid(to);
  }

  if (!g_strcmp0(type, "chat")) {
    sender = jabber_get_bare_jid(from);

    ret_val = omemo_storage_chatlist_exists(sender, db_fn_omemo);
    if (ret_val < 0) {
      err_msg_dbg = g_strdup_printf("failed to look up %s in %s", sender, db_fn_omemo);
      goto cleanup;
    } else if (ret_val == 1) {
      purple_conv_present_error(sender, purple_connection_get_account(gc_p), "Received encrypted message in blacklisted conversation.");
    }
  } else if (!g_strcmp0(type, "groupchat")) {
    split = g_strsplit(from, "/", 2);
    room_name = split[0];
    buddy_nick = split[1];

    ret_val = omemo_storage_chatlist_exists(room_name, db_fn_omemo);
    if (ret_val < 0) {
      err_msg_dbg = g_strdup_printf("failed to look up %s in %s", room_name, db_fn_omemo);
      goto cleanup;
    } else if (ret_val == 0) {
      purple_conv_present_error(room_name, purple_connection_get_account(gc_p), "Received encrypted message in non-OMEMO room.");
    }

    conv_p = purple_find_conversation_with_account(PURPLE_CONV_TYPE_CHAT, room_name, purple_connection_get_account(gc_p));
    if (!conv_p) {
      err_msg_dbg = g_strdup_printf("could not find groupchat %s", room_name);
      goto cleanup;
    }

    muc_p = jabber_chat_find_by_conv(conv_p);
    if (!muc_p) {
      err_msg_dbg = g_strdup_printf("could not find muc struct for groupchat %s", room_name);
      goto cleanup;
    }

    muc_member_p = g_hash_table_lookup(muc_p->members, buddy_nick);
    if (!muc_member_p) {
      purple_debug_misc("lurch", "Received OMEMO message in MUC %s, but the sender %s is not present in the room, which can happen during history catchup. Skipping.\n", room_name, buddy_nick);
      goto cleanup;
    }

    if (!muc_member_p->jid) {
      err_msg_dbg = g_strdup_printf("jid for user %s in muc %s not found, is the room anonymous?", buddy_nick, room_name);
      goto cleanup;
    }

    sender = jabber_get_bare_jid(muc_member_p->jid);
  }
  xml = xmlnode_to_str(*msg_stanza_pp, &len);
  ret_val = omemo_message_prepare_decryption(xml, &msg_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed import msg for decryption");
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get axc ctx for %s", uname);
    goto cleanup;
  }

  ret_val = axc_get_device_id(axc_ctx_p, &own_id);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get own device id");
    goto cleanup;
  }

  ret_val = omemo_message_get_encrypted_key(msg_p, own_id, &key_p, &key_len);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to get key for own id %i", own_id);
    goto cleanup;
  }
  if (!key_p) {
    const char *to = room_name ?: sender;

    purple_debug_info("lurch", "received omemo message that does not contain a key for this device, skipping\n");
    purple_conv_present_error(to, purple_connection_get_account(gc_p),
			      "Received omemo message that does not contain a key for this device");
    goto cleanup;
  }

  key_buf_p = axc_buf_create(key_p, key_len);
  if (!key_buf_p) {
    err_msg_dbg = g_strdup_printf("failed to create buf for key");
    goto cleanup;
  }

  sender_addr.name = sender;
  sender_addr.name_len = strnlen(sender_addr.name, JABBER_MAX_LEN_BARE);
  sender_addr.device_id = omemo_message_get_sender_id(msg_p);

  ret_val = axc_pre_key_message_process(key_buf_p, &sender_addr, axc_ctx_p, &key_decrypted_p);
  if (ret_val == AXC_ERR_NOT_A_PREKEY_MSG) {
    if (axc_session_exists_initiated(&sender_addr, axc_ctx_p)) {
      ret_val = axc_message_decrypt_from_serialized(key_buf_p, &sender_addr, axc_ctx_p, &key_decrypted_p);
      if (ret_val) {
        if (ret_val == SG_ERR_DUPLICATE_MESSAGE && !g_strcmp0(sender, uname) && !g_strcmp0(recipient_bare_jid, uname)) {
          // in combination with message carbons, sending a message to your own account results in it arriving twice
          purple_debug_warning("lurch", "ignoring decryption error due to a duplicate message from own account to own account\n");
          *msg_stanza_pp = (void *) 0;
          goto cleanup;
        } else {
          err_msg_dbg = g_strdup_printf("failed to decrypt key");
          goto cleanup;
        }
      }
    } else {
      purple_debug_info("lurch", "received omemo message but no session with the device exists, ignoring\n");
      goto cleanup;
    }
  } else if (ret_val == AXC_ERR_INVALID_KEY_ID) {
    ret_val = omemo_bundle_get_pep_node_name(sender_addr.device_id, &bundle_node_name);
    if (ret_val) {
      err_msg_dbg = g_strdup_printf("failed to get bundle pep node name");
      goto cleanup;
    }

    jabber_pep_request_item(purple_connection_get_protocol_data(gc_p),
                            sender_addr.name, bundle_node_name,
                            (void *) 0,
                            lurch_pep_bundle_for_keytransport);

  } else if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to process incoming encrypted key");
    goto cleanup;
  } else {
    lurch_bundle_publish_own(purple_connection_get_protocol_data(gc_p));
  }

  if (!omemo_message_has_payload(msg_p)) {
    purple_debug_info("lurch", "received keytransportmsg\n");
    goto cleanup;
  }

  g_free(xml);
  xml = (void *) 0;
  ret_val = omemo_message_export_decrypted(msg_p, axc_buf_get_data(key_decrypted_p), axc_buf_get_len(key_decrypted_p), &crypto, &xml);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to decrypt payload");
    goto cleanup;
  }

  plaintext_msg_node_p = xmlnode_from_str(xml, -1);

  // libpurple doesn't know what to do with incoming messages addressed to someone else, so they need to be written to the conversation manually
  // incoming messages from the own account in MUCs are fine though
  if (!g_strcmp0(sender, uname) && !g_strcmp0(type, "chat")) {
    conv_p = purple_find_conversation_with_account(PURPLE_CONV_TYPE_IM, recipient_bare_jid, purple_connection_get_account(gc_p));
    if (!conv_p) {
      conv_p = purple_conversation_new(PURPLE_CONV_TYPE_IM, purple_connection_get_account(gc_p), recipient_bare_jid);
    }
    body_data = xmlnode_get_data(xmlnode_get_child(plaintext_msg_node_p, "body"));
    purple_conversation_write(conv_p, uname, body_data, PURPLE_MESSAGE_SEND, time((void *) 0));
    *msg_stanza_pp = (void *) 0;
  } else {
    *msg_stanza_pp = plaintext_msg_node_p;
  }

cleanup:
  if (err_msg_dbg) {
    purple_conv_present_error(sender, purple_connection_get_account(gc_p), LURCH_ERR_STRING_DECRYPT);
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }

  g_strfreev(split);
  g_free(sender);
  free(xml);
  free(bundle_node_name);
  free(sender_name);
  axc_buf_free(key_decrypted_p);
  axc_buf_free(key_buf_p);
  free(key_p);
  axc_context_destroy_all(axc_ctx_p);
  g_free(uname);
  g_free(db_fn_omemo);
  g_free(recipient_bare_jid);
  g_free(body_data);
  omemo_message_destroy(keytransport_msg_p);
  omemo_message_destroy(msg_p);
}

static void lurch_message_warn(PurpleConnection * gc_p, xmlnode ** msg_stanza_pp) {
  int ret_val = 0;

  xmlnode * temp_node_p = (void *) 0;
  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  char * conv_name = (void *) 0;
  char ** split = (void *) 0;
  const char * room_name = (void *) 0;

  const char * type = xmlnode_get_attrib(*msg_stanza_pp, "type");
  const char * from = xmlnode_get_attrib(*msg_stanza_pp, "from");

  uname = lurch_util_uname_strip(purple_account_get_username(purple_connection_get_account(gc_p)));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    goto cleanup;
  }

  temp_node_p = xmlnode_get_child(*msg_stanza_pp, "body");
  if (!temp_node_p) {
    goto cleanup;
  }

  if (!g_strcmp0(type, "chat")) {
    conv_name = jabber_get_bare_jid(from);

    ret_val = axc_session_exists_any(conv_name, axc_ctx_p);
    if (ret_val < 0) {
      goto cleanup;
    } else if (ret_val == 0) {
      goto cleanup;
    } else if (ret_val == 1) {
      ret_val = omemo_storage_chatlist_exists(conv_name, db_fn_omemo);
      if (ret_val == 0) {
        purple_conv_present_error(conv_name, purple_connection_get_account(gc_p),
                                  "Even though you have an encryption session with this user, you received a plaintext message.");
      }
    }
  } else if (!g_strcmp0(type, "groupchat")) {
    split = g_strsplit(from, "/", 2);
    room_name = split[0];

    ret_val = omemo_storage_chatlist_exists(room_name, db_fn_omemo);
    if (ret_val < 0) {
      goto cleanup;
    } else if (ret_val == 0) {
      goto cleanup;
    } else if (ret_val == 1) {
      purple_conv_present_error(room_name, purple_connection_get_account(gc_p),
                                "This groupchat is set to encrypted, but you received a plaintext message.");
    }
  }

cleanup:
  g_free(uname);
  g_free(db_fn_omemo);
  g_free(conv_name);
  g_strfreev(split);
  axc_context_destroy_all(axc_ctx_p);
}

static void lurch_xml_received_cb(PurpleConnection * gc_p, xmlnode ** stanza_pp) {
  xmlnode * temp_node_p  = (void *) 0;
  const char * node_name = (void *) 0;

  if (uninstall) {
    return;
  }

  if (!stanza_pp || !*stanza_pp) {
    return;
  }

  node_name = (*stanza_pp)->name;

  if (!g_strcmp0(node_name, "message")) {
    temp_node_p = xmlnode_get_child(*stanza_pp, "encrypted");
    if (temp_node_p) {
      lurch_message_decrypt(gc_p, stanza_pp);
    } else {
      lurch_message_warn(gc_p, stanza_pp);
    }
  }
}

static int lurch_topic_update_im(PurpleConversation * conv_p) {
  int ret_val = 0;

  char * uname = (void *) 0;
  const char * partner_name = purple_conversation_get_name(conv_p);
  char * partner_name_bare = (void *) 0;
  axc_context * axc_ctx_p = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  omemo_devicelist * dl_p = (void *) 0;

  char * new_title = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(purple_conversation_get_account(conv_p)));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);
  partner_name_bare = jabber_get_bare_jid(partner_name);

  if (uninstall) {
    goto cleanup;
  }

  ret_val = omemo_storage_chatlist_exists(partner_name_bare, db_fn_omemo);
  if (ret_val < 0 || ret_val > 0) {
    goto cleanup;
  }

  ret_val = lurch_util_axc_get_init_ctx(uname, &axc_ctx_p);
  if (ret_val) {
    goto cleanup;
  }

  ret_val = axc_session_exists_any(partner_name_bare, axc_ctx_p);
  if (ret_val < 0) {
    goto cleanup;
  } else if (ret_val) {
    new_title = g_strdup_printf("%s (%s)", partner_name, "OMEMO");

  } else {
    ret_val = omemo_storage_user_devicelist_retrieve(partner_name_bare, db_fn_omemo, &dl_p);
    if (ret_val) {
      goto cleanup;
    }

    if (!omemo_devicelist_is_empty(dl_p)) {
      new_title = g_strdup_printf("%s (%s)", partner_name, "OMEMO available");
    }
  }

  if (new_title) {
    purple_conversation_set_title(conv_p, new_title);
  }

cleanup:
  g_free(uname);
  g_free(new_title);
  axc_context_destroy_all(axc_ctx_p);
  g_free(db_fn_omemo);
  omemo_devicelist_destroy(dl_p);
  free(partner_name_bare);

  return ret_val;
}

static int lurch_topic_update_chat(PurpleConversation * conv_p) {
  int ret_val = 0;

  char * uname = (void *) 0;
  char * db_fn_omemo = (void *) 0;
  char * new_title = (void *) 0;

  uname = lurch_util_uname_strip(purple_account_get_username(purple_conversation_get_account(conv_p)));
  db_fn_omemo = lurch_util_uname_get_db_fn(uname, LURCH_DB_NAME_OMEMO);

  if (uninstall) {
    goto cleanup;
  }

  ret_val = omemo_storage_chatlist_exists(purple_conversation_get_name(conv_p), db_fn_omemo);
  if (ret_val < 1) {
    goto cleanup;
  }

  new_title = g_strdup_printf("%s (%s)", purple_conversation_get_title(conv_p), "OMEMO");
  purple_conversation_set_title(conv_p, new_title);

cleanup:
  g_free(uname);
  g_free(db_fn_omemo);
  g_free(new_title);

  return ret_val;
}

static void lurch_conv_created_cb(PurpleConversation * conv_p) {
  if (strncmp(purple_account_get_protocol_id(purple_conversation_get_account(conv_p)), JABBER_PROTOCOL_ID, strlen(JABBER_PROTOCOL_ID))) {
    return;
  }

  if (purple_conversation_get_type(conv_p) == PURPLE_CONV_TYPE_IM) {
    lurch_topic_update_im(conv_p);
  } else if (purple_conversation_get_type(conv_p) == PURPLE_CONV_TYPE_CHAT) {
    lurch_topic_update_chat(conv_p);
  }
}

static void lurch_conv_updated_cb(PurpleConversation * conv_p, PurpleConvUpdateType type) {
  if (strncmp(purple_account_get_protocol_id(purple_conversation_get_account(conv_p)), JABBER_PROTOCOL_ID, strlen(JABBER_PROTOCOL_ID))) {
    return;
  }

  if (type == PURPLE_CONV_UPDATE_TITLE) {
    if (!topic_changed) {
      topic_changed = 1;
      if (purple_conversation_get_type(conv_p) == PURPLE_CONV_TYPE_IM) {
        lurch_topic_update_im(conv_p);
      } else if (purple_conversation_get_type(conv_p) == PURPLE_CONV_TYPE_CHAT) {
        lurch_topic_update_chat(conv_p);
      }

      topic_changed = 0;
    } else {
      topic_changed = 0;
    }
  }
}

/**
 * Actions to perform on plugin load.
 * Inits the crypto and registers signal and PEP handlers.
 */
static gboolean lurch_plugin_load(PurplePlugin * plugin_p) {
  int ret_val = 0;
  const char * err_msg_dbg = (void *) 0;
  char * dl_ns = (void *) 0;
  void * jabber_handle_p = (void *) 0;
  GList * accs_l_p = (void *) 0;
  GList * curr_p = (void *) 0;
  PurpleAccount * acc_p = (void *) 0;

  omemo_default_crypto_init();
  lurch_api_init();

  ret_val = omemo_devicelist_get_pep_node_name(&dl_ns);
  if (ret_val) {
    err_msg_dbg = "failed to get devicelist pep node name";
    goto cleanup;
  }

  lurch_cmd_handle_id = purple_cmd_register("lurch",
                      "wwws",
                      PURPLE_CMD_P_PLUGIN,
                      PURPLE_CMD_FLAG_IM | PURPLE_CMD_FLAG_CHAT | PURPLE_CMD_FLAG_PRPL_ONLY | PURPLE_CMD_FLAG_ALLOW_WRONG_ARGS,
                      JABBER_PROTOCOL_ID,
                      lurch_cmd_func,
                      "lurch &lt;help&gt;:  "
                      "Interface to the lurch plugin. For details, use the 'help' argument.",
                      (void *) 0);

  // register handlers
  jabber_handle_p = purple_plugins_find_with_id(JABBER_PROTOCOL_ID);

  (void) purple_signal_connect_priority(jabber_handle_p, "jabber-receiving-xmlnode", plugin_p, PURPLE_CALLBACK(lurch_xml_received_cb), NULL, PURPLE_PRIORITY_HIGHEST - 100);
  (void) purple_signal_connect_priority(jabber_handle_p, "jabber-sending-xmlnode", plugin_p, PURPLE_CALLBACK(lurch_xml_sent_cb), NULL, PURPLE_PRIORITY_HIGHEST - 100);

  jabber_pep_register_handler(dl_ns, lurch_pep_devicelist_event_handler);
  jabber_add_feature(dl_ns, jabber_pep_namespace_only_when_pep_enabled_cb);

  // manually call init code if there are already accounts connected, e.g. when plugin is loaded manually
  accs_l_p = purple_accounts_get_all_active();
  for (curr_p = accs_l_p; curr_p; curr_p = curr_p->next) {
    acc_p = (PurpleAccount *) curr_p->data;
    if (purple_account_is_connected(acc_p)) {
      if (!g_strcmp0(purple_account_get_protocol_id(acc_p), JABBER_PROTOCOL_ID)) {
        lurch_account_connect_cb(acc_p);
      }
    }
  }

  // register install callback
  (void) purple_signal_connect(purple_accounts_get_handle(), "account-signed-on", plugin_p, PURPLE_CALLBACK(lurch_account_connect_cb), NULL);
  (void) purple_signal_connect(purple_conversations_get_handle(), "conversation-created", plugin_p, PURPLE_CALLBACK(lurch_conv_created_cb), NULL);
  (void) purple_signal_connect(purple_conversations_get_handle(), "conversation-updated", plugin_p, PURPLE_CALLBACK(lurch_conv_updated_cb), NULL);

cleanup:
  free(dl_ns);
  g_list_free(accs_l_p);
  if (ret_val) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    omemo_default_crypto_teardown();
    return FALSE;
  }

  return TRUE;
}

static gboolean lurch_plugin_unload(PurplePlugin * plugin_p) {
  purple_cmd_unregister(lurch_cmd_handle_id);

  lurch_api_unload();

  omemo_default_crypto_teardown();

  return TRUE;
}

static PurplePluginPrefFrame * lurch_get_plugin_pref_frame(PurplePlugin * plugin_p) {
  PurplePluginPrefFrame * frame_p;
  PurplePluginPref * ppref_p;

  frame_p = purple_plugin_pref_frame_new();
  ppref_p = purple_plugin_pref_new_with_label("Extended logging");
  purple_plugin_pref_frame_add(frame_p, ppref_p);

  ppref_p = purple_plugin_pref_new_with_name_and_label(
                  LURCH_PREF_AXC_LOGGING,
                  "Show log output from underlying libraries");
  purple_plugin_pref_frame_add(frame_p, ppref_p);

  ppref_p = purple_plugin_pref_new_with_name_and_label(
                    LURCH_PREF_AXC_LOGGING_LEVEL,
                    "Log level");
  purple_plugin_pref_set_type(ppref_p, PURPLE_PLUGIN_PREF_CHOICE);
  purple_plugin_pref_add_choice(ppref_p, "ERROR", GINT_TO_POINTER(AXC_LOG_ERROR));
  purple_plugin_pref_add_choice(ppref_p, "WARNING", GINT_TO_POINTER(AXC_LOG_WARNING));
  purple_plugin_pref_add_choice(ppref_p, "NOTICE", GINT_TO_POINTER(AXC_LOG_NOTICE));
  purple_plugin_pref_add_choice(ppref_p, "INFO", GINT_TO_POINTER(AXC_LOG_INFO));
  purple_plugin_pref_add_choice(ppref_p, "DEBUG", GINT_TO_POINTER(AXC_LOG_DEBUG));
  purple_plugin_pref_frame_add(frame_p, ppref_p);

  return frame_p;
}

static PurplePluginUiInfo prefs_info = {
  lurch_get_plugin_pref_frame,
  0,    /* page_num (Reserved) */
  NULL, /* frame (Reserved) */

  /* padding */
  NULL,
  NULL,
  NULL,
  NULL
};

static PurplePluginInfo info = {
    PURPLE_PLUGIN_MAGIC,
    PURPLE_MAJOR_VERSION,
    PURPLE_MINOR_VERSION,
    PURPLE_PLUGIN_STANDARD,
    NULL,
    0,
    NULL,
    PURPLE_PRIORITY_DEFAULT,

    "core-riba-lurch",
    "lurch",
    LURCH_VERSION,

    "Implements OMEMO for libpurple.",
    "End-to-end encryption using the Signal protocol, adapted for XMPP.",
    LURCH_AUTHOR,
    "https://github.com/gkdr/lurch",

    lurch_plugin_load,
    lurch_plugin_unload,
    NULL,

    NULL,
    NULL,
    &prefs_info, // plugin config, see libpurple/plugins/pluginpref_example.c
    NULL,        // plugin actions, see https://developer.pidgin.im/wiki/CHowTo/PluginActionsHowTo
    NULL,
    NULL,
    NULL,
    NULL
};

static void
lurch_plugin_init(PurplePlugin * plugin_p) {
  PurplePluginInfo * info_p = plugin_p->info;

  info_p->dependencies = g_list_prepend(info_p->dependencies, "prpl-jabber");

  purple_prefs_add_none(LURCH_PREF_ROOT);
  purple_prefs_add_bool(LURCH_PREF_AXC_LOGGING, FALSE);
  purple_prefs_add_int(LURCH_PREF_AXC_LOGGING_LEVEL, AXC_LOG_INFO);
}

PURPLE_INIT_PLUGIN(lurch, lurch_plugin_init, info)
