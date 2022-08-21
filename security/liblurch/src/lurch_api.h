#pragma once

#define LURCH_ERR                    -1000000
#define LURCH_ERR_NOMEM              -1000001
#define LURCH_ERR_NO_BUNDLE          -1000010
#define LURCH_ERR_DEVICE_NOT_IN_LIST -1000100

typedef enum {
    LURCH_STATUS_DISABLED = 0,  // manually disabled
    LURCH_STATUS_NOT_SUPPORTED, // no OMEMO support, i.e. there is no devicelist node
    LURCH_STATUS_NO_SESSION,    // OMEMO is supported, but there is no libsignal session yet
    LURCH_STATUS_OK             // OMEMO is supported and session exists
} lurch_status_t;

typedef enum {
    LURCH_STATUS_CHAT_DISABLED = 0,  // OMEMO was not manually enabled
    LURCH_STATUS_CHAT_ANONYMOUS,     // chat is anonymous, i.e. a member's JID could not be accessed
    LURCH_STATUS_CHAT_NO_DEVICELIST, // a member's devicelist could not be accessed, probably because s/he is not a contact
    LURCH_STATUS_CHAT_OK,            // in theory, OMEMO should work
    LURCH_STATUS_CHAT_NO_JIDS        // the chat is not anonymous, but the JIDs are still not visible
} lurch_status_chat_t;

/**
 * Initializes the API by registering the signals and signal handlers.
 */
void lurch_api_init();

/**
* Unregisters the signals and disconnects the signal handlers.
*/
void lurch_api_unload();

/**
 * USAGE
 * 
 * Some functions users might be interested in can be called via libpurple signals.
 * Thus, the libpurple commands interface uses these as well and lurch_cmd_ui.c is therefore full of examples.
 * Generally, the workflow is as follows:
 *
 * - Find the signal you need and check the handler function's parameters.
 *   Generally, you will need to pass the user's PurpleAccount, a callback, and the data to be passed to the callback.
 *   For some functions, the conversation partner's or chat's JID is also required.
 * 
 * - Write the callback function needed by the handler.
 *   The first parameter is an error value. It is generally the return value from the called functions.
 *   If it is non-zero, an error occured somewhere and there should be more information in the debug log.
 *   Otherwise, the call succeeded and the following parameters will be set.
 *   The last parameter is the data given when emitting the signal.
 * 
 * - Emit the signal using the plugin system handle as the instance and pass the necessary data.
 *   If you do it wrong, there will be no compiler errors and the pointers are gibberish, so take care.
 *   You can easily get the plugin system handle anywhere by calling purple_plugins_get_handle().
 */

/**
 * SIGNAL: lurch-id-list
 *
 * Gets the specified account's OMEMO devicelist and passes it to the callback as a GList containing uint32_t *.
 * To access the actual ID, cast the data member to a uint32_t * and dereference it.
 * This device's ID will be the first item in the list.
 */
void lurch_api_id_list_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, GList * id_list, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-id-remove
 *
 * Removes the specified OMEMO device ID from the specified account's devicelist.
 */
void lurch_api_id_remove_handler(PurpleAccount * acc_p, uint32_t device_id, void (*cb)(int32_t err, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-enable-im
 *
 * Enables OMEMO for the specified contact.
 */
void lurch_api_enable_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-disable-im
 *
 * Disables OMEMO for the specified contact.
 */
void lurch_api_disable_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-enable-chat
 * 
 * Enables OMEMO for the specified chat. The conversation name can be obtained by simply calling purple_conversation_get_name().
 */
void lurch_api_enable_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-disable-chat
 * 
 * Disables OMEMO for the specified chat.
 */
void lurch_api_disable_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-fp-get
 *
 * Gets the this device's fingerprint in a printable format.
 */
void lurch_api_fp_get_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, const char * fp_printable, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-fp-list
 *
 * Gets the fingerprints of all devices belonging to the specified account and creates a device-ID-to-fingerprint table.
 * This is based on sessions, so if there is an entry in the OMEMO devicelist, but no libsignal session yet, the value will be NULL.
 * If the whole devicelist is empty, i.e. the account is not an OMEMO user, the whole table will be NULL.
 * Watch out as this is not a valid GHashTable.
 */
void lurch_api_fp_list_handler(PurpleAccount * acc_p, void (*cb)(int32_t err, GHashTable * id_fp_table, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-fp-other
 *
 * Same as above, but for the specified contact.
 */
void lurch_api_fp_other_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, GHashTable * id_fp_table, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-status-im
 *
 * Checks the OMEMO status for the given contact. Result is one of lurch_status_t.
 */
void lurch_api_status_im_handler(PurpleAccount * acc_p, const char * contact_bare_jid, void (*cb)(int32_t err, lurch_status_t status, void * user_data_p), void * user_data_p);

/**
 * SIGNAL: lurch-status-chat
 * 
 * Checks the OMEMO status for a MUC.
 * It not only looks up whether OMEMO was enabled, but also checks the preconditions for this feature, i.e.
 * whether all chat members' JIDs are visible (non-anonymous) and their devicelists accessible (in contact list). 
 */
void lurch_api_status_chat_handler(PurpleAccount * acc_p, const char * full_conversation_name, void (*cb)(int32_t err, lurch_status_chat_t status, void * user_data_p), void * user_data_p);
