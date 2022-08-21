#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <purple.h>
#include "jabber.h"
#include "chat.h"

#include "axc.h"
#include "libomemo.h"

#include "../src/lurch_api.h"
#include "../src/lurch_api_internal.h"

char * __wrap_purple_account_get_username(PurpleAccount * acc_p) {
    char * username;

    username = mock_ptr_type(char *);

    return username;
}

int __wrap_omemo_storage_user_devicelist_retrieve(const char * user, const char * db_fn, omemo_devicelist ** dl_pp) {
    omemo_devicelist * dl_p;
    dl_p = mock_ptr_type(omemo_devicelist *);
    *dl_pp = dl_p;

    int ret_val;
    ret_val = mock_type(int);

    return ret_val;
}

void *__wrap_purple_account_get_connection(PurpleAccount * acc_p) {
    function_called();
    return NULL;
}

void * __wrap_purple_connection_get_protocol_data(const PurpleConnection * connection_p) {
    JabberStream * js_p;

    js_p = mock_ptr_type(JabberStream *);

    return js_p;
}

void __wrap_purple_signal_register() {
    function_called();
}

void __wrap_purple_signal_connect() {
    function_called();
}

void __wrap_purple_signal_unregister() {
    function_called();
}

void __wrap_purple_signal_disconnect() {
    function_called();
}

int __wrap_axc_get_device_id(axc_context * ctx_p, uint32_t * id_p) {
    uint32_t id;
    int ret_val;

    id = mock_type(uint32_t);
    *id_p = id;

    ret_val = mock_type(int);

    return ret_val;
}

PurpleConversation * __wrap_purple_find_conversation_with_account(PurpleConversationType type, const char *name,
		const PurpleAccount *account) {
    check_expected(type);
    check_expected(name);

    PurpleConversation * ret_val;
    ret_val = mock_ptr_type(PurpleConversation *);
    return ret_val;
}

void __wrap_jabber_pep_publish(JabberStream * js_p, xmlnode * publish_node_p) {
    xmlnode * item_node_p = xmlnode_get_child(publish_node_p, "item");
    xmlnode * list_node_p = xmlnode_get_child(item_node_p, "list");

    xmlnode * device_node_p = xmlnode_get_child(list_node_p, "device");
    const char * device_id = xmlnode_get_attrib(device_node_p, "id");
    check_expected(device_id);

    check_expected_ptr(device_node_p->next);
}

JabberChat * __wrap_jabber_chat_find_by_conv(PurpleConversation * conv_p) {
    JabberChat * ret_val;
    ret_val = mock_ptr_type(JabberChat *);
    return ret_val;
}

void __wrap_jabber_iq_send(JabberIq *iq) {
    function_called();

    assert_int_equal(iq->type, JABBER_IQ_GET);
    assert_non_null(xmlnode_get_child_with_namespace(iq->node, "query", "http://jabber.org/protocol/disco#info"));

    lurch_api_status_chat_cb_data * cb_data_p = iq->callback_data;
    void * cb = cb_data_p->cb;
    check_expected_ptr(cb);

    void * user_data_p = cb_data_p->user_data_p;
    check_expected_ptr(user_data_p);

    const char * to = xmlnode_get_attrib(iq->node, "to");
    check_expected(to);
}

int __wrap_omemo_storage_chatlist_delete(const char * chat, const char * db_fn) {
    check_expected(chat);

    int ret_val;
    ret_val = mock_type(int);
    return ret_val;
}

int __wrap_omemo_storage_chatlist_save(const char * chat, const char * db_fn) {
    check_expected(chat);

    int ret_val;
    ret_val = mock_type(int);
    return ret_val;
}

int __wrap_omemo_storage_chatlist_exists(const char * chat, const char * db_fn) {
    check_expected(chat);
    
    int ret_val;
    ret_val = mock_type(int);
    return ret_val;
}

int __wrap_axc_key_load_public_own(axc_context * ctx_p, axc_buf ** pubkey_data_pp) {
    void * pubkey_data_p;
    int ret_val;

    pubkey_data_p = mock_ptr_type(void *);
    *pubkey_data_pp = pubkey_data_p;

    ret_val = mock_type(int);
    return ret_val;
}

int __wrap_axc_key_load_public_addr(const char * name, uint32_t device_id, axc_context * ctx_p, axc_buf ** pubkey_data_pp) {
    void * pubkey_data_p;
    int ret_val;

    check_expected(name);
    check_expected(device_id);

    pubkey_data_p = mock_ptr_type(void *);
    *pubkey_data_pp = pubkey_data_p;

    ret_val = mock_type(int);
    return ret_val;
}

int __wrap_axc_session_exists_any(const char * name, axc_context * ctx_p) {
    int ret_val;

    check_expected(name);

    ret_val = mock_type(int);
    return ret_val;
}

char * __wrap_lurch_util_fp_get_printable(axc_buf * key_buf_p) {
    function_called();

    check_expected(key_buf_p);

    char * ret_val;
    ret_val = mock_ptr_type(char *);
    return ret_val;
}

void lurch_api_id_list_handler_cb_mock(int32_t err, GList * id_list, void * user_data_p) {
    check_expected(err);

    int32_t first_id = omemo_devicelist_list_data(id_list);
    check_expected(first_id);

    int32_t second_id = omemo_devicelist_list_data(id_list->next);
    check_expected(second_id);

    GList * third_item = id_list->next->next;
    check_expected(third_item);

    check_expected(user_data_p);
}

void lurch_api_id_list_handler_cb_err_mock(int32_t err, GList * id_list, void * user_data_p) {
    check_expected(err);

    check_expected(user_data_p);
}

/**
 * Calls the supplied callback with the devicelist and the supplied user data, making sure the own ID comes first.
 */
static void test_lurch_api_id_list_handler(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                   "<device id='1337' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, test_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    uint32_t test_own_id = 1337;
    will_return(__wrap_axc_get_device_id, test_own_id);
    will_return(__wrap_axc_get_device_id, EXIT_SUCCESS);

    expect_value(lurch_api_id_list_handler_cb_mock, err, 0);
    expect_value(lurch_api_id_list_handler_cb_mock, first_id, test_own_id);
    expect_value(lurch_api_id_list_handler_cb_mock, second_id, 4223);
    expect_value(lurch_api_id_list_handler_cb_mock, third_item, NULL);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_id_list_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_id_list_handler(NULL, lurch_api_id_list_handler_cb_mock, test_user_data);
}

/**
 * When an error occurs, the supplied callback is called with the error code and the supplied user data.
 */
static void test_lurch_api_id_list_handler_error(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    int test_errcode = -12345;
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, NULL);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, test_errcode);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_id_list_handler_cb_err_mock, err, test_errcode);
    expect_value(lurch_api_id_list_handler_cb_err_mock, user_data_p, test_user_data);

    lurch_api_id_list_handler(NULL, lurch_api_id_list_handler_cb_err_mock, test_user_data);
}

static void lurch_api_id_remove_handler_cb_mock(int32_t err, void * user_data_p) {
    check_expected(err);
    check_expected(user_data_p);
}

/**
 * Success case for removing a device ID from the own device list.
 */
static void test_lurch_api_id_remove_handler(void ** state) {
    (void) state;
    PurpleAccount p = { 0 };

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                   "<device id='1337' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, test_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_function_call(__wrap_purple_account_get_connection);
    will_return(__wrap_purple_connection_get_protocol_data, NULL);
    expect_string(__wrap_jabber_pep_publish, device_id, "4223");
    expect_value(__wrap_jabber_pep_publish, device_node_p->next, NULL);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_id_remove_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_id_remove_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_id_remove_handler(&p, 1337, lurch_api_id_remove_handler_cb_mock, test_user_data);
}

/**
 * Fails when the device ID to remove is not in the own devicelist, and call the callback with the correct error code.
 */
static void test_lurch_api_id_remove_handler_id_not_in_list(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                   "<device id='1337' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, test_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_id_remove_handler_cb_mock, err, LURCH_ERR_DEVICE_NOT_IN_LIST);
    expect_value(lurch_api_id_remove_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_id_remove_handler((void *) "ignored", 7331, lurch_api_id_remove_handler_cb_mock, test_user_data);
}

static void lurch_api_enable_disable_handler_cb_mock(int32_t err, void * user_data_p) {
    check_expected(err);
    check_expected(user_data_p);
}

/**
 * Deletes contact from 'the list' in the OMEMO DB when the signal is received, enabling OMEMO for this contact.
 */
static void test_lurch_api_enable_im_handler(void ** state) {
    (void) state;

    const char * contact_bare_jid = "contact_bare_jid";
    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    expect_string(__wrap_omemo_storage_chatlist_delete, chat, contact_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_delete, EXIT_SUCCESS);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_enable_im_handler((void *) "ignored", contact_bare_jid, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Calls the callback with the return code in case of an error.
 */
static void test_lurch_api_enable_im_handler_err(void ** state) {
    (void) state;

    const char * contact_bare_jid = "contact_bare_jid";
    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    expect_string(__wrap_omemo_storage_chatlist_delete, chat, contact_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_delete, EXIT_FAILURE);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_FAILURE);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_enable_im_handler((void *) "ignored", contact_bare_jid, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Adds conversation name to 'the list' to enable OMEMO for it.
 */
static void test_lurch_api_enable_chat_handler(void ** state) {
    (void) state;

    const char * conv_name = "conversation name";
    const char * user_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, user_jid);

    expect_string(__wrap_omemo_storage_chatlist_save, chat, conv_name);
    will_return(__wrap_omemo_storage_chatlist_save, EXIT_SUCCESS);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_enable_chat_handler((void *) "ignored", conv_name, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Calls the callback with the return value in case of an error.
 */
static void test_lurch_api_enable_chat_handler_err(void ** state) {
    (void) state;

    const char * conv_name = "conversation name";
    const char * user_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, user_jid);

    expect_string(__wrap_omemo_storage_chatlist_save, chat, conv_name);
    will_return(__wrap_omemo_storage_chatlist_save, EXIT_FAILURE);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_FAILURE);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_enable_chat_handler((void *) "ignored", conv_name, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Saves contact to 'the list' in the OMEMO DB when the signal is received, disabling OMEMO for this contact.
 */
static void test_lurch_api_disable_im_handler(void ** state) {
    (void) state;

    const char * contact_bare_jid = "contact_bare_jid";
    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    expect_string(__wrap_omemo_storage_chatlist_save, chat, contact_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_save, EXIT_SUCCESS);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_disable_im_handler((void *) "ignored", contact_bare_jid, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Calls the callback with the return code in case of an error.
 */
static void test_lurch_api_disable_im_handler_err(void ** state) {
    (void) state;

    const char * contact_bare_jid = "contact_bare_jid";
    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    expect_string(__wrap_omemo_storage_chatlist_save, chat, contact_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_save, 12345);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, 12345);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_disable_im_handler((void *) "ignored", contact_bare_jid, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Removes the specified conversation name from 'the list' to disable OMEMO for it.
 */
static void test_lurch_api_disable_chat_handler(void ** state) {
    (void) state;

    const char * conv_name = "conversation name";
    const char * user_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, user_jid);

    expect_string(__wrap_omemo_storage_chatlist_delete, chat, conv_name);
    will_return(__wrap_omemo_storage_chatlist_delete, EXIT_SUCCESS);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_disable_chat_handler((void *) "ignoed", conv_name, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

/**
 * Calls the callback with a non-zero return value as well.
 */
static void test_lurch_api_disable_chat_handler_err(void ** state) {
    (void) state;

    const char * conv_name = "conversation name";
    const char * user_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, user_jid);

    expect_string(__wrap_omemo_storage_chatlist_delete, chat, conv_name);
    will_return(__wrap_omemo_storage_chatlist_delete, EXIT_FAILURE);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_enable_disable_handler_cb_mock, err, EXIT_FAILURE);
    expect_value(lurch_api_enable_disable_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_disable_chat_handler((void *) "ignoed", conv_name, lurch_api_enable_disable_handler_cb_mock, test_user_data);
}

void lurch_api_fp_get_handler_cb_mock(int32_t err, const char * fp_printable, void * user_data_p) {
    check_expected(err);
    check_expected(fp_printable);
    check_expected(user_data_p);
}

/**
 * Loads the account's public identity key and returns a fingerprint suitable for display.
 */
static void test_lurch_api_fp_get_handler(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    axc_buf * mock_key_buf_own = axc_buf_create(NULL, 0);
    will_return(__wrap_axc_key_load_public_own, mock_key_buf_own);
    will_return(__wrap_axc_key_load_public_own, EXIT_SUCCESS);

    expect_function_call(__wrap_lurch_util_fp_get_printable);
    expect_value(__wrap_lurch_util_fp_get_printable, key_buf_p, mock_key_buf_own);
    char * mock_fp_own = g_strdup("MOCK FINGERPRINT");
    will_return(__wrap_lurch_util_fp_get_printable, mock_fp_own);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_fp_get_handler_cb_mock, err, EXIT_SUCCESS);
    expect_string(lurch_api_fp_get_handler_cb_mock, fp_printable, mock_fp_own);
    expect_value(lurch_api_fp_get_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_fp_get_handler(NULL, lurch_api_fp_get_handler_cb_mock, test_user_data);
}

/**
 * Calls the callback with the return code in case of an error.
 */
static void test_lurch_api_fp_get_handler_err(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return(__wrap_purple_account_get_username, test_jid);

    will_return(__wrap_axc_key_load_public_own, NULL);
    will_return(__wrap_axc_key_load_public_own, EXIT_FAILURE);

    char * test_user_data = "TEST USER DATA";
    expect_value(lurch_api_fp_get_handler_cb_mock, err, EXIT_FAILURE);
    expect_value(lurch_api_fp_get_handler_cb_mock, fp_printable, NULL);
    expect_value(lurch_api_fp_get_handler_cb_mock, user_data_p, test_user_data);

    lurch_api_fp_get_handler(NULL, lurch_api_fp_get_handler_cb_mock, test_user_data);
}

/**
 * Mock callback that checks whether the given table is the same as the expected table passed through the user data. 
 */
static void list_handling_cb_mock(int32_t err, GHashTable * id_fp_table, void * user_data_p) {
    check_expected(err);

    if (err) {
        return;
    }

    GHashTable * expected_table = (GHashTable *) user_data_p;

    if (!expected_table) {
        assert_null(id_fp_table);
        return;
    }

    GHashTableIter iter;
    gpointer key, value;
    char * generated_fp = (void *) 0;

    g_hash_table_iter_init (&iter, expected_table);
    while (g_hash_table_iter_next (&iter, &key, &value)) {
        generated_fp = g_hash_table_lookup(id_fp_table, key);
        // assert_non_null(generated_fp);
        assert_ptr_equal(generated_fp, value);

        generated_fp = (void *) 0;
    }
}

/**
 * Loads the devicelist, then each device's public key, then gets their fingerprints, and finally puts everything
 * into a single table of device ID to fingerprint.
 */
static void test_lurch_api_fp_list_handler(void ** state) {
    (void) state;

    const char * bare_jid = "me-testing@test.org";
    const char * test_jid = "me-testing@test.org/resource";
    will_return_always(__wrap_purple_account_get_username, test_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                   "<device id='1337' />"
                                   "<device id='1338' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, test_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    uint32_t test_own_id = 1337;
    will_return(__wrap_axc_get_device_id, test_own_id);
    will_return(__wrap_axc_get_device_id, EXIT_SUCCESS);

    int id_4223 = 4223;
    expect_string(__wrap_axc_key_load_public_addr, name, bare_jid);
    expect_value(__wrap_axc_key_load_public_addr, device_id, id_4223);
    char * mock_key_4223 = "FAKE KEY 4223";
    axc_buf * mock_key_buf_4223 = axc_buf_create((unsigned char *) mock_key_4223, strlen(mock_key_4223));
    will_return(__wrap_axc_key_load_public_addr, mock_key_buf_4223);
    will_return(__wrap_axc_key_load_public_addr, 1);
    expect_function_call(__wrap_lurch_util_fp_get_printable);
    expect_value(__wrap_lurch_util_fp_get_printable, key_buf_p, mock_key_buf_4223);
    char * mock_fp_4223 = g_strdup("FAKE FP 4223");
    will_return(__wrap_lurch_util_fp_get_printable, mock_fp_4223);

    int id_1338 = 1338;
    expect_string(__wrap_axc_key_load_public_addr, name, bare_jid);
    expect_value(__wrap_axc_key_load_public_addr, device_id, id_1338);
    char * mock_key_1338 = "FAKE KEY 1338";
    axc_buf * mock_key_buf_1338 = axc_buf_create((unsigned char *) mock_key_1338, strlen(mock_key_1338));
    will_return(__wrap_axc_key_load_public_addr, mock_key_buf_1338);
    will_return(__wrap_axc_key_load_public_addr, 0);

    axc_buf * mock_key_buf_own = axc_buf_create(NULL, 0);
    will_return(__wrap_axc_key_load_public_own, mock_key_buf_own);
    will_return(__wrap_axc_key_load_public_own, EXIT_SUCCESS);
    char * mock_fp_own = g_strdup("MOCK FINGERPRINT");
    expect_function_call(__wrap_lurch_util_fp_get_printable);
    expect_value(__wrap_lurch_util_fp_get_printable, key_buf_p, mock_key_buf_own);
    will_return(__wrap_lurch_util_fp_get_printable, mock_fp_own);

    GHashTable * expected_table = g_hash_table_new(g_int_hash, g_int_equal);
    g_hash_table_insert(expected_table, &test_own_id, mock_fp_own);
    g_hash_table_insert(expected_table, &id_4223, mock_fp_4223);
    g_hash_table_insert(expected_table, &id_1338, NULL);

    expect_value(list_handling_cb_mock, err, EXIT_SUCCESS);

    lurch_api_fp_list_handler(NULL, list_handling_cb_mock, expected_table);
}

/**
 * Calls the callback with the return code in case of an error.
 */
static void test_lurch_api_fp_list_handler_err(void ** state) {
    (void) state;

    const char * test_jid = "me-testing@test.org/resource";
    will_return_always(__wrap_purple_account_get_username, test_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, test_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    uint32_t id_which_does_not_matter = 123;
    will_return(__wrap_axc_get_device_id, id_which_does_not_matter);
    will_return(__wrap_axc_get_device_id, EXIT_FAILURE);

    expect_value(list_handling_cb_mock, err, EXIT_FAILURE);
    lurch_api_fp_list_handler(NULL, list_handling_cb_mock, NULL);
}

/**
 * Generates the same table, but for a contact.
 */
static void test_lurch_api_fp_other_handler(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    int id_4223 = 4223;
    expect_string(__wrap_axc_key_load_public_addr, name, other_bare_jid);
    expect_value(__wrap_axc_key_load_public_addr, device_id, id_4223);
    char * mock_key_4223 = "FAKE KEY 4223";
    axc_buf * mock_key_buf_4223 = axc_buf_create((unsigned char *) mock_key_4223, strlen(mock_key_4223));
    will_return(__wrap_axc_key_load_public_addr, mock_key_buf_4223);
    will_return(__wrap_axc_key_load_public_addr, 1);
    expect_function_call(__wrap_lurch_util_fp_get_printable);
    expect_value(__wrap_lurch_util_fp_get_printable, key_buf_p, mock_key_buf_4223);
    char * mock_fp_4223 = g_strdup("FAKE FP 4223");
    will_return(__wrap_lurch_util_fp_get_printable, mock_fp_4223);

    GHashTable * expected_table = g_hash_table_new(g_int_hash, g_int_equal);
    g_hash_table_insert(expected_table, &id_4223, mock_fp_4223);

    expect_value(list_handling_cb_mock, err, EXIT_SUCCESS);
    lurch_api_fp_other_handler(NULL, other_bare_jid, list_handling_cb_mock, expected_table);
}

/**
 * Correctly handles a key retrieval error when building the table.
 */
static void test_lurch_api_fp_other_handler_keyerr(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                   "<device id='4223' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    int id_4223 = 4223;
    expect_string(__wrap_axc_key_load_public_addr, name, other_bare_jid);
    expect_value(__wrap_axc_key_load_public_addr, device_id, id_4223);
    char * mock_key_4223 = "FAKE KEY 4223";
    axc_buf * mock_key_buf_4223 = axc_buf_create((unsigned char *) mock_key_4223, strlen(mock_key_4223));
    will_return(__wrap_axc_key_load_public_addr, mock_key_buf_4223);
    will_return(__wrap_axc_key_load_public_addr, -11);

    expect_value(list_handling_cb_mock, err, -11);
    lurch_api_fp_other_handler(NULL, other_bare_jid, list_handling_cb_mock, NULL);
}

/**
 * Hands over NULL as the table if the contact's devicelist is empty.
 */
static void test_lurch_api_fp_other_handler_empty(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(list_handling_cb_mock, err, EXIT_SUCCESS);
    lurch_api_fp_other_handler(NULL, other_bare_jid, list_handling_cb_mock, NULL);
}

/**
 * Calls the callback with the return code in case of an error.
 */
static void test_lurch_api_fp_other_handler_err(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    int test_errcode = -1234;
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, NULL);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, test_errcode);

    expect_value(list_handling_cb_mock, err, test_errcode);
    lurch_api_fp_other_handler(NULL, other_bare_jid, list_handling_cb_mock, NULL);
}

static void lurch_api_status_im_handler_cb_mock(int32_t err, lurch_status_t status, void * user_data_p) {
    check_expected(err);
    check_expected(status);
    check_expected(user_data_p);
}

/**
 * Passes the "disabled" status if the chat is found in the blacklist.
 */
static void test_lurch_api_status_im_handler_disabled(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, other_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_exists, 1);

    expect_value(lurch_api_status_im_handler_cb_mock, err, 0);
    expect_value(lurch_api_status_im_handler_cb_mock, status, LURCH_STATUS_DISABLED);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_im_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_im_handler(NULL, other_bare_jid, lurch_api_status_im_handler_cb_mock, mock_user_data);
}

/**
 * Passes the "not supported" status if the contact does not have a devicelist.
 */
static void test_lurch_api_status_im_handler_not_supported(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, other_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_exists, 0);


    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(lurch_api_status_im_handler_cb_mock, err, 0);
    expect_value(lurch_api_status_im_handler_cb_mock, status, LURCH_STATUS_NOT_SUPPORTED);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_im_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_im_handler(NULL, other_bare_jid, lurch_api_status_im_handler_cb_mock, mock_user_data);
}

/**
 * Passes the "no session" status if the contact has a devicelist, but there is no libsignal session.
 */
static void test_lurch_api_status_im_handler_no_session(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, other_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_exists, 0);


    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                    "<device id='4223' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(__wrap_axc_session_exists_any, name, other_bare_jid);
    will_return(__wrap_axc_session_exists_any, 0);

    expect_value(lurch_api_status_im_handler_cb_mock, err, 0);
    expect_value(lurch_api_status_im_handler_cb_mock, status, LURCH_STATUS_NO_SESSION);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_im_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_im_handler(NULL, other_bare_jid, lurch_api_status_im_handler_cb_mock, mock_user_data);
}

/**
 * Passes the "OK" status if contact has a devicelist and a session exists.
 */
static void test_lurch_api_status_im_handler_ok(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_jid = "other-guy-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, other_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_exists, 0);


    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                              "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                    "<device id='4223' />"
                                "</list>"
                              "</item>"
                            "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, other_jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(__wrap_axc_session_exists_any, name, other_bare_jid);
    will_return(__wrap_axc_session_exists_any, 1);

    expect_value(lurch_api_status_im_handler_cb_mock, err, 0);
    expect_value(lurch_api_status_im_handler_cb_mock, status, LURCH_STATUS_OK);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_im_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_im_handler(NULL, other_bare_jid, lurch_api_status_im_handler_cb_mock, mock_user_data);
}

/**
 * Passes "disabled" and the exact error code if something goes wrong.
 */ 
static void test_lurch_api_status_im_handler_err(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * other_bare_jid = "other-guy-testing@test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    int fake_errcode = -1337;

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, other_bare_jid);
    will_return(__wrap_omemo_storage_chatlist_exists, fake_errcode);

    expect_value(lurch_api_status_im_handler_cb_mock, err, fake_errcode);
    expect_value(lurch_api_status_im_handler_cb_mock, status, LURCH_STATUS_DISABLED);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_im_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_im_handler(NULL, other_bare_jid, lurch_api_status_im_handler_cb_mock, mock_user_data);
}

static void lurch_api_status_chat_handler_cb_mock(int32_t err, lurch_status_chat_t status, void * user_data_p) {
    check_expected(err);
    check_expected(status);
    check_expected(user_data_p);
}

/**
 * Returns the 'disabled' status if the chat is not on 'the list' and does not send a query.
 */
static void test_lurch_api_status_chat_handler_disabled(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * test_conversation_name = "test-room@conference.test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, test_conversation_name);
    will_return(__wrap_omemo_storage_chatlist_exists, 0);

    expect_value(lurch_api_status_chat_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_status_chat_handler_cb_mock, status, LURCH_STATUS_CHAT_DISABLED);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_chat_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_chat_handler(NULL, test_conversation_name, lurch_api_status_chat_handler_cb_mock, mock_user_data);

    // does not expect a jabber_iq_send, so cmocka would fail if there was one
}

/**
 * If OMEMO is enabled for a chat, the server must be queried to correctly determine the status.
 */
static void test_lurch_api_status_chat_handler_enabled(void ** state) {
    (void) state;

    const char * own_jid = "me-testing@test.org/resource";
    const char * test_conversation_name = "test-room@conference.test.org";
    will_return(__wrap_purple_account_get_username, own_jid);

    expect_value(__wrap_omemo_storage_chatlist_exists, chat, test_conversation_name);
    will_return(__wrap_omemo_storage_chatlist_exists, 1);

    expect_function_call(__wrap_purple_account_get_connection);
    JabberStream fake_js = {.next_id = 1}; // needed so an iq can be created
    will_return(__wrap_purple_connection_get_protocol_data, &fake_js); 

    expect_function_call(__wrap_jabber_iq_send);
    expect_value(__wrap_jabber_iq_send, cb, lurch_api_status_chat_handler_cb_mock);
    expect_string(__wrap_jabber_iq_send, to, test_conversation_name);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(__wrap_jabber_iq_send, user_data_p, mock_user_data);

    lurch_api_status_chat_handler(NULL, test_conversation_name, lurch_api_status_chat_handler_cb_mock, mock_user_data);
}

/**
 * Return the "anonymous" status if the returned features do not contain "muc_nonanomyous".
 */
static void test_lurch_api_status_chat_discover_cb_anonymous(void ** state) {
    (void) state;

    // from the XEP-0045 (MUC), example 9, minus the "nonanonymous"
    const char * disco_info_result =
        "<iq from='coven@chat.shakespeare.lit' "
                "id='ik3vs715' "
                "to='hag66@shakespeare.lit/pda' "
                "type='result'>"
            "<query xmlns='http://jabber.org/protocol/disco#info'>"
                "<identity "
                    "category='conference' "
                    "name='A Dark Cave' "
                    "type='text'/>"
                "<feature var='http://jabber.org/protocol/muc'/>"
                "<feature var='http://jabber.org/protocol/muc#stable_id'/>"
                "<feature var='muc_passwordprotected'/>"
                "<feature var='muc_hidden'/>"
                "<feature var='muc_temporary'/>"
                "<feature var='muc_open'/>"
                "<feature var='muc_unmoderated'/>"
            "</query>"
        "</iq>";
    xmlnode * disco_info_node = xmlnode_from_str(disco_info_result, -1);

    expect_value(lurch_api_status_chat_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_status_chat_handler_cb_mock, status, LURCH_STATUS_CHAT_ANONYMOUS);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_chat_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_chat_cb_data * cb_data = g_malloc0(sizeof(lurch_api_status_chat_cb_data));
    cb_data->cb = lurch_api_status_chat_handler_cb_mock;
    cb_data->user_data_p = mock_user_data;

    lurch_api_status_chat_discover_cb(NULL, "does not matter", JABBER_IQ_RESULT, "does not matter", disco_info_node, cb_data);
}

/**
 * Return the "no devicelist" status if one of the chat members' devcelists is empty.
 */
static void test_lurch_api_status_chat_discover_cb_no_devicelist(void ** state) {
    (void) state;

    // from the XEP-0045 (MUC), example 9
    const char * disco_info_result =
        "<iq from='coven@chat.shakespeare.lit' "
                "id='ik3vs715' "
                "to='hag66@shakespeare.lit/pda' "
                "type='result'>"
            "<query xmlns='http://jabber.org/protocol/disco#info'>"
                "<identity "
                    "category='conference' "
                    "name='A Dark Cave' "
                    "type='text'/>"
                "<feature var='http://jabber.org/protocol/muc'/>"
                "<feature var='http://jabber.org/protocol/muc#stable_id'/>"
                "<feature var='muc_passwordprotected'/>"
                "<feature var='muc_hidden'/>"
                "<feature var='muc_temporary'/>"
                "<feature var='muc_open'/>"
                "<feature var='muc_unmoderated'/>"
                "<feature var='muc_nonanonymous'/>"
            "</query>"
        "</iq>";
    xmlnode * disco_info_node = xmlnode_from_str(disco_info_result, -1);

    expect_value(lurch_api_status_chat_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_status_chat_handler_cb_mock, status, LURCH_STATUS_CHAT_NO_DEVICELIST);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_chat_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_chat_cb_data * cb_data = g_malloc0(sizeof(lurch_api_status_chat_cb_data));
    cb_data->cb = lurch_api_status_chat_handler_cb_mock;
    cb_data->user_data_p = mock_user_data;

    PurpleConnection gc_fake = {
        .account = NULL
    };
    JabberStream js_fake = {
        .gc = &gc_fake
    };

    const char * test_conversation_name = "test-room@conference.test.org";
    PurpleConversation conversation_fake = {
        .name = test_conversation_name
    };

    JabberChatMember member = {
        .handle = "n0t4fr13nd",
        .jid = "not-a-contact@test.org/phone"
    };

    // keys do not really matter as the tests function loops over the values
    GHashTable * member_table_mock = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(member_table_mock, "non-contact member", &member);

    JabberChat muc_mock = {
        .members = member_table_mock
    };

    will_return(__wrap_jabber_chat_find_by_conv, &muc_mock);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                            "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                "</list>"
                            "</item>"
                        "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, member.jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(__wrap_purple_find_conversation_with_account, type, PURPLE_CONV_TYPE_CHAT);
    expect_value(__wrap_purple_find_conversation_with_account, name, test_conversation_name);
    will_return(__wrap_purple_find_conversation_with_account, &conversation_fake);

    lurch_api_status_chat_discover_cb(&js_fake, test_conversation_name, JABBER_IQ_RESULT, "does not matter", disco_info_node, cb_data);
}

/**
 * Returns the "ok" status if the chat is not anonymous and all members' devicelists could be found.
 */
static void test_lurch_api_status_chat_discover_cb_ok(void ** state) {
    (void) state;

    // from the XEP-0045 (MUC), example 9
    const char * disco_info_result =
        "<iq from='coven@chat.shakespeare.lit' "
                "id='ik3vs715' "
                "to='hag66@shakespeare.lit/pda' "
                "type='result'>"
            "<query xmlns='http://jabber.org/protocol/disco#info'>"
                "<identity "
                    "category='conference' "
                    "name='A Dark Cave' "
                    "type='text'/>"
                "<feature var='http://jabber.org/protocol/muc'/>"
                "<feature var='http://jabber.org/protocol/muc#stable_id'/>"
                "<feature var='muc_passwordprotected'/>"
                "<feature var='muc_hidden'/>"
                "<feature var='muc_temporary'/>"
                "<feature var='muc_open'/>"
                "<feature var='muc_unmoderated'/>"
                "<feature var='muc_nonanonymous'/>"
            "</query>"
        "</iq>";
    xmlnode * disco_info_node = xmlnode_from_str(disco_info_result, -1);

    expect_value(lurch_api_status_chat_handler_cb_mock, err, EXIT_SUCCESS);
    expect_value(lurch_api_status_chat_handler_cb_mock, status, LURCH_STATUS_CHAT_OK);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_chat_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_chat_cb_data * cb_data = g_malloc0(sizeof(lurch_api_status_chat_cb_data));
    cb_data->cb = lurch_api_status_chat_handler_cb_mock;
    cb_data->user_data_p = mock_user_data;

    PurpleConnection gc_fake = {
        .account = NULL
    };
    JabberStream js_fake = {
        .gc = &gc_fake
    };

    const char * test_conversation_name = "test-room@conference.test.org";
    PurpleConversation conversation_fake = {
        .name = test_conversation_name
    };

    JabberChatMember member = {
        .handle = "perfect-contact",
        .jid = "perfect-contact@test.org/lurch"
    };

    // keys do not really matter as the tests function loops over the values
    GHashTable * member_table_mock = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(member_table_mock, "non-contact member", &member);

    JabberChat muc_mock = {
        .members = member_table_mock
    };

    will_return(__wrap_jabber_chat_find_by_conv, &muc_mock);

    char * devicelist = "<items node='urn:xmpp:omemo:0:devicelist'>"
                            "<item>"
                                "<list xmlns='urn:xmpp:omemo:0'>"
                                    "<device id='4223' />"
                                "</list>"
                            "</item>"
                        "</items>";

    omemo_devicelist * dl_p;
    omemo_devicelist_import(devicelist, member.jid, &dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, dl_p);
    will_return(__wrap_omemo_storage_user_devicelist_retrieve, EXIT_SUCCESS);

    expect_value(__wrap_purple_find_conversation_with_account, type, PURPLE_CONV_TYPE_CHAT);
    expect_value(__wrap_purple_find_conversation_with_account, name, test_conversation_name);
    will_return(__wrap_purple_find_conversation_with_account, &conversation_fake);

    lurch_api_status_chat_discover_cb(&js_fake, test_conversation_name, JABBER_IQ_RESULT, "does not matter", disco_info_node, cb_data);
}

/**
 * Returns "disabled" and an error when an error happens during discovery.
 */
static void test_lurch_api_status_chat_discover_cb_error(void ** state) {
    (void) state;

    expect_value(lurch_api_status_chat_handler_cb_mock, err, EXIT_FAILURE);
    expect_value(lurch_api_status_chat_handler_cb_mock, status, LURCH_STATUS_CHAT_DISABLED);
    const char * mock_user_data = "MOCK_USER_DATA";
    expect_value(lurch_api_status_chat_handler_cb_mock, user_data_p, mock_user_data);

    lurch_api_status_chat_cb_data * cb_data = g_malloc0(sizeof(lurch_api_status_chat_cb_data));
    cb_data->cb = lurch_api_status_chat_handler_cb_mock;
    cb_data->user_data_p = mock_user_data;

    lurch_api_status_chat_discover_cb(NULL, "does not matter", JABBER_IQ_ERROR, "does not matter", NULL, cb_data);
}

/**
 * Registers and connects all signals.
 */
static void test_lurch_api_init(void ** state) {
    (void) state;

    size_t signals = 11;

    for (int i = 0; i < signals; i++) {
        expect_function_call(__wrap_purple_signal_register);
        expect_function_call(__wrap_purple_signal_connect);
    }

    lurch_api_init();
}

/**
 * Disconnects and unregisters all signals.
 */
static void test_lurch_api_unload(void ** state) {
    (void) state;

    size_t signals = 11;

    for (int i = 0; i < signals; i++) {
        expect_function_call(__wrap_purple_signal_disconnect);
        expect_function_call(__wrap_purple_signal_unregister);
    }

    lurch_api_unload();
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_lurch_api_id_list_handler),
        cmocka_unit_test(test_lurch_api_id_list_handler_error),
        cmocka_unit_test(test_lurch_api_id_remove_handler),
        cmocka_unit_test(test_lurch_api_id_remove_handler_id_not_in_list),
        cmocka_unit_test(test_lurch_api_enable_im_handler),
        cmocka_unit_test(test_lurch_api_enable_im_handler_err),
        cmocka_unit_test(test_lurch_api_enable_chat_handler),
        cmocka_unit_test(test_lurch_api_enable_chat_handler_err),
        cmocka_unit_test(test_lurch_api_disable_im_handler),
        cmocka_unit_test(test_lurch_api_disable_im_handler_err),
        cmocka_unit_test(test_lurch_api_disable_chat_handler),
        cmocka_unit_test(test_lurch_api_disable_chat_handler_err),
        cmocka_unit_test(test_lurch_api_fp_get_handler),
        cmocka_unit_test(test_lurch_api_fp_get_handler_err),
        cmocka_unit_test(test_lurch_api_fp_list_handler),
        cmocka_unit_test(test_lurch_api_fp_list_handler_err),
        cmocka_unit_test(test_lurch_api_fp_other_handler),
        cmocka_unit_test(test_lurch_api_fp_other_handler_keyerr),
        cmocka_unit_test(test_lurch_api_fp_other_handler_empty),
        cmocka_unit_test(test_lurch_api_fp_other_handler_err),
        cmocka_unit_test(test_lurch_api_status_im_handler_disabled),
        cmocka_unit_test(test_lurch_api_status_im_handler_not_supported),
        cmocka_unit_test(test_lurch_api_status_im_handler_no_session),
        cmocka_unit_test(test_lurch_api_status_im_handler_ok),
        cmocka_unit_test(test_lurch_api_status_im_handler_err),
        cmocka_unit_test(test_lurch_api_status_chat_handler_disabled),
        cmocka_unit_test(test_lurch_api_status_chat_handler_enabled),
        cmocka_unit_test(test_lurch_api_status_chat_discover_cb_anonymous),
        cmocka_unit_test(test_lurch_api_status_chat_discover_cb_no_devicelist),
        cmocka_unit_test(test_lurch_api_status_chat_discover_cb_ok),
        cmocka_unit_test(test_lurch_api_status_chat_discover_cb_error),
        cmocka_unit_test(test_lurch_api_init),
        cmocka_unit_test(test_lurch_api_unload)
    };

    return cmocka_run_group_tests_name("lurch_api", tests, NULL, NULL);
}
