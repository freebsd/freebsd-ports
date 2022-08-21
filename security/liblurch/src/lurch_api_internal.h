#pragma once

#include <inttypes.h>

#include "lurch_api.h"

// things in here are exposed for testing.

// Bundles the data the MUC feature discovery callback needs.
typedef struct {
  char * db_fn_omemo; // Path to the account's OMEMO DB.
  void (*cb)(int32_t err, lurch_status_chat_t status, void * user_data_p); // The callback for the API call.
  void * user_data_p; // The data to be passed to cb().
} lurch_api_status_chat_cb_data;


void lurch_api_status_chat_discover_cb(JabberStream * js_p, const char * from, JabberIqType type, const char * id, xmlnode * packet_p,  gpointer data_p);
