
#include <glib.h>
#include <purple.h>

#include "axc.h"
#include "libomemo.h"

#include "lurch_addr.h"
#include "lurch_crypto.h"
#include "lurch_util.h"

int lurch_crypto_encrypt_key(const lurch_addr * recipient_addr_p,
                             const uint8_t * key_p,
                             size_t key_len,
                             axc_context * axc_ctx_p,
                             axc_buf ** key_ct_buf_pp) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  axc_buf * key_buf_p = (void *) 0;
  axc_buf * key_ct_buf_p = (void *) 0;
  axc_address axc_addr = {0};

  purple_debug_info("lurch", "%s: encrypting key for %s:%i\n", __func__, recipient_addr_p->jid, recipient_addr_p->device_id);

  key_buf_p = axc_buf_create(key_p, key_len);
  if (!key_buf_p) {
    err_msg_dbg = g_strdup_printf("failed to create buffer for the key");
    goto cleanup;
  }

  axc_addr.name = recipient_addr_p->jid;
  axc_addr.name_len = strnlen(axc_addr.name, JABBER_MAX_LEN_BARE);
  axc_addr.device_id = recipient_addr_p->device_id;

  ret_val = axc_message_encrypt_and_serialize(key_buf_p, &axc_addr, axc_ctx_p, &key_ct_buf_p);
  if (ret_val) {
    err_msg_dbg = g_strdup_printf("failed to encrypt the key");
    goto cleanup;
  }

  *key_ct_buf_pp = key_ct_buf_p;

cleanup:
  if (ret_val) {
    axc_buf_free(key_ct_buf_p);
  }
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  axc_buf_free(key_buf_p);

  return ret_val;
}

int lurch_crypto_encrypt_msg_for_addrs(omemo_message * om_msg_p, GList * addr_l_p, GList * no_sess_l_p, axc_context * axc_ctx_p) {
  int ret_val = 0;
  char * err_msg_dbg = (void *) 0;

  GList * curr_l_p = (void *) 0;
  lurch_addr * curr_addr_p = (void *) 0;
  axc_address addr = {0};
  axc_buf * curr_key_ct_buf_p = (void *) 0;

  purple_debug_info("lurch", "%s: trying to encrypt key for %i devices\n", __func__, g_list_length(addr_l_p));

  for (curr_l_p = addr_l_p; curr_l_p; curr_l_p = curr_l_p->next) {
    curr_addr_p = (lurch_addr *) curr_l_p->data;
    addr.name = curr_addr_p->jid;
    addr.name_len = strnlen(addr.name, JABBER_MAX_LEN_BARE);
    addr.device_id = curr_addr_p->device_id;

    ret_val = axc_session_exists_initiated(&addr, axc_ctx_p);
    if (ret_val < 0) {
      err_msg_dbg = g_strdup_printf("failed to check if session exists, aborting");
      goto cleanup;
    } else if (!ret_val) {
      purple_debug_warning("lurch", "%s: no initiated session for recipient %s:%d, skipping\n", __func__, addr.name, addr.device_id);
      continue;
    } else {
      ret_val = lurch_crypto_encrypt_key(curr_addr_p,
                                  omemo_message_get_key(om_msg_p),
                                  omemo_message_get_key_len(om_msg_p),
                                  axc_ctx_p,
                                  &curr_key_ct_buf_p);
      if (ret_val) {
        err_msg_dbg = g_strdup_printf("failed to encrypt key for %s:%i", curr_addr_p->jid, curr_addr_p->device_id);
        goto cleanup;
      }

      if (g_list_find(no_sess_l_p, curr_addr_p)) {
        ret_val = omemo_message_add_recipient_w_prekey(om_msg_p,
                                                       curr_addr_p->device_id,
                                                       axc_buf_get_data(curr_key_ct_buf_p),
                                                       axc_buf_get_len(curr_key_ct_buf_p));
      } else {
        ret_val = omemo_message_add_recipient(om_msg_p,
                                              curr_addr_p->device_id,
                                              axc_buf_get_data(curr_key_ct_buf_p),
                                              axc_buf_get_len(curr_key_ct_buf_p));
      }
      if (ret_val) {
        err_msg_dbg = g_strdup_printf("failed to add recipient to omemo msg");
        goto cleanup;
      }

      axc_buf_free(curr_key_ct_buf_p);
      curr_key_ct_buf_p = (void *) 0;
    }
  }

cleanup:
  if (err_msg_dbg) {
    purple_debug_error("lurch", "%s: %s (%i)\n", __func__, err_msg_dbg, ret_val);
    g_free(err_msg_dbg);
  }
  axc_buf_free(curr_key_ct_buf_p);

  return ret_val;
}
