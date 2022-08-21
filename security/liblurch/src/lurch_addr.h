#pragma once

#include <glib.h>
#include <inttypes.h>

#include "axc.h"
#include "libomemo.h"

/**
 * Contains the information necessary to adress a device via OMEMO: the jabber ID and the OMEMO device ID.
 */
typedef struct lurch_addr {
  char * jid;
  uint32_t device_id;
} lurch_addr;

/**
 * Adds an each entry of an omemo devicelist to a GList of lurch_addrs.
 *
 * @param addrs_p Pointer to the list to add to. Remember NULL is a valid GList *.
 * @param dl_p Pointer to the omemo devicelist to add.
 * @param exclude_id_p Pointer to an ID that is not to be added. Useful when adding the own devicelist. Can be NULL.
 * @return Pointer to the updated GList on success, NULL on error.
 */
GList * lurch_addr_list_add(GList * addrs_p, const omemo_devicelist * dl_p, const uint32_t * exclude_id_p);

/**
 * Frees all memory allocated by the list itself and each of its items.
 */
void lurch_addr_list_destroy(GList * addr_l_p);

/**
 * For a list of lurch_addrs, checks which ones do not have an active session.
 * Note that the structs are not copied, the returned list is just a subset
 * of the pointers of the input list.
 *
 * @param addr_l_p A list of pointers to lurch_addr structs.
 * @param axc_ctx_p The axc_context to use.
 * @param no_sess_l_pp Will point to a list that contains pointers to those
 *                     addresses that do not have a session.
 * @return 0 on success, negative on error.
 */
int lurch_addr_sessions_exist(GList * addr_l_p, axc_context * axc_ctx_p, GList ** no_sess_l_pp);
