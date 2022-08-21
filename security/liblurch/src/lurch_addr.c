#include <glib.h>
#include <purple.h>

#include "axc.h"
#include "libomemo.h"

#include "lurch_addr.h"
#include "lurch_api.h"
#include "lurch_util.h"

GList * lurch_addr_list_add(GList * addrs_p, const omemo_devicelist * dl_p, const uint32_t * exclude_id_p) {
  int ret_val = 0;

  GList * new_l_p = addrs_p;
  GList * dl_l_p = (void *) 0;
  GList * curr_p = (void *) 0;
  lurch_addr curr_addr = {0};
  uint32_t curr_id = 0;
  lurch_addr * temp_addr_p = (void *) 0;

  curr_addr.jid = g_strdup(omemo_devicelist_get_owner(dl_p));

  dl_l_p = omemo_devicelist_get_id_list(dl_p);

  for (curr_p = dl_l_p; curr_p; curr_p = curr_p->next) {
    curr_id = omemo_devicelist_list_data(curr_p);
    if (exclude_id_p && *exclude_id_p == curr_id) {
      continue;
    }

    curr_addr.device_id = curr_id;

    temp_addr_p = malloc(sizeof(lurch_addr));
    if (!temp_addr_p) {
      ret_val = LURCH_ERR_NOMEM;
      goto cleanup;
    }

    memcpy(temp_addr_p, &curr_addr, sizeof(lurch_addr));

    new_l_p = g_list_prepend(new_l_p, temp_addr_p);
  }

cleanup:
  g_list_free_full(dl_l_p, free);

  if (ret_val) {
    lurch_addr_list_destroy(new_l_p);
    return (void *) 0;
  } else {
    return new_l_p;
  }
}

static void lurch_addr_list_destroy_func(gpointer data) {
  lurch_addr * addr_p = (lurch_addr *) data;
  free(addr_p->jid);
  free(addr_p);
}

void lurch_addr_list_destroy(GList * addr_l_p) {
    g_list_free_full(addr_l_p, lurch_addr_list_destroy_func);
}

int lurch_addr_sessions_exist(GList * addr_l_p, axc_context * axc_ctx_p, GList ** no_sess_l_pp){
  int ret_val = 0;

  GList * no_sess_l_p = (void *) 0;

  GList * curr_p;
  lurch_addr * curr_addr_p;
  axc_address curr_axc_addr = {0};
  for (curr_p = addr_l_p; curr_p; curr_p = curr_p->next) {
    curr_addr_p = (lurch_addr *) curr_p->data;

    curr_axc_addr.name = curr_addr_p->jid;
    curr_axc_addr.name_len = strnlen(curr_axc_addr.name, JABBER_MAX_LEN_BARE);
    curr_axc_addr.device_id = curr_addr_p->device_id;

    ret_val = axc_session_exists_initiated(&curr_axc_addr, axc_ctx_p);
    if (ret_val < 0) {
      purple_debug_error("lurch", "%s: %s (%i)\n", __func__, "failed to see if session exists", ret_val);
      goto cleanup;
    } else if (ret_val > 0) {
      ret_val = 0;
      continue;
    } else {
      no_sess_l_p = g_list_prepend(no_sess_l_p, curr_addr_p);
      ret_val = 0;
    }
  }

  *no_sess_l_pp = no_sess_l_p;

cleanup:
  return ret_val;
}
