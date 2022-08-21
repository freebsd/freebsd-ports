#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <glib.h>

#include "axc.h"

#include "../src/lurch.h"
#include "../src/lurch_util.h"

void __wrap_purple_debug_error(const char * category, const char * format, ...) {
    function_called();
}

void __wrap_purple_debug_info(const char * category, const char * format, ...) {
    function_called();
}

void __wrap_purple_debug_misc(const char * category, const char * format, ...) {
}

int __wrap_axc_context_create(axc_context ** axc_ctx_pp) {
    int ret_val;
    ret_val = mock_type(int);
    return ret_val;
}

const char * __wrap_purple_user_dir(void) {
    char * user_dir;
    user_dir = mock_ptr_type(char *);
    return user_dir;
}

gboolean __wrap_purple_prefs_get_bool(const char * pref_name) {
    check_expected(pref_name);

    gboolean pref_val;
    pref_val = mock_type(gboolean);
    return pref_val;
}

int __wrap_purple_prefs_get_int(const char * pref_name) {
    check_expected(pref_name);

    int pref_val;
    pref_val = mock_type(int);
    return pref_val;
}

char * __wrap_purple_base16_encode_chunked(const guchar *data, gsize len) {
    char * fp;
    fp = mock_ptr_type(char *);
    return fp;
}

/**
 * Log only errors when log level is set to AXC_LOG_ERROR, using purple_debug_error().
 */
static void test_lurch_util_axc_log_func_error(void ** state) {
    (void) state;

    axc_context * axc_ctx_p = (void *) 0;

    (void) axc_context_create(&axc_ctx_p);
    axc_context_set_log_level(axc_ctx_p, AXC_LOG_ERROR);
    expect_function_call(__wrap_purple_debug_error);

    lurch_util_axc_log_func(AXC_LOG_ERROR, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_WARNING, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_NOTICE, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_INFO, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_DEBUG, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(-1, "test", 4, axc_ctx_p);

    axc_context_destroy_all(axc_ctx_p);
}

/**
 * Log level info and above, but not below.
 */
static void test_lurch_util_axc_log_func_info(void ** state) {
    (void) state;

    axc_context * axc_ctx_p = (void *) 0;

    (void) axc_context_create(&axc_ctx_p);
    axc_context_set_log_level(axc_ctx_p, AXC_LOG_INFO);
    expect_function_call(__wrap_purple_debug_error);
    expect_function_calls(__wrap_purple_debug_info, 2);

    lurch_util_axc_log_func(AXC_LOG_ERROR, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_WARNING, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_NOTICE, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_INFO, "test", 4, axc_ctx_p);
    lurch_util_axc_log_func(AXC_LOG_DEBUG, "test", 4, axc_ctx_p);

    axc_context_destroy_all(axc_ctx_p);
}


static void test_lurch_util_axc_get_init_ctx_w_logging(void ** state) {
    (void) state;

    will_return(__wrap_purple_user_dir, "/home/testuser/.purple");

    expect_string_count(__wrap_purple_prefs_get_bool, pref_name, LURCH_PREF_AXC_LOGGING, 2);
    will_return_count(__wrap_purple_prefs_get_bool, TRUE, 2);

    expect_string(__wrap_purple_prefs_get_int, pref_name, LURCH_PREF_AXC_LOGGING_LEVEL);
    will_return(__wrap_purple_prefs_get_int, AXC_LOG_NOTICE);

    char * test_jid = "test-user@example.com";

    axc_context * test_axc_ctx_p = (void *) 0;
    lurch_util_axc_get_init_ctx(test_jid, &test_axc_ctx_p);

    assert_string_equal(axc_context_get_db_fn(test_axc_ctx_p), "/home/testuser/.purple/test-user@example.com_axc_db.sqlite");
    assert_int_equal(axc_context_get_log_level(test_axc_ctx_p), AXC_LOG_NOTICE);
}

static void test_lurch_util_axc_get_init_ctx_wo_logging(void ** state) {
    (void) state;

    will_return(__wrap_purple_user_dir, "/home/testuser/.purple");

    expect_string_count(__wrap_purple_prefs_get_bool, pref_name, LURCH_PREF_AXC_LOGGING, 2);
    will_return_count(__wrap_purple_prefs_get_bool, FALSE, 2);

    char * test_jid = "test-user@example.com";

    axc_context * test_axc_ctx_p = (void *) 0;
    lurch_util_axc_get_init_ctx(test_jid, &test_axc_ctx_p);

    assert_string_equal(axc_context_get_db_fn(test_axc_ctx_p), "/home/testuser/.purple/test-user@example.com_axc_db.sqlite");
    assert_int_equal(axc_context_get_log_level(test_axc_ctx_p), -1);
}

static void test_lurch_util_uname_strip(void ** state) {
    (void) state;

    assert_string_equal(lurch_util_uname_strip("node@domain/resource"), "node@domain");
}

static void test_lurch_util_uname_strip_no_resource(void ** state) {
    (void) state;

    assert_string_equal(lurch_util_uname_strip("node@domain/"), "node@domain");
    assert_string_equal(lurch_util_uname_strip("node@domain"), "node@domain");
}

static void test_lurch_util_uname_strip_empty(void ** state) {
    (void) state;

    assert_null(lurch_util_uname_strip(""));
    assert_null(lurch_util_uname_strip(NULL));
}

static void test_lurch_util_uname_get_db_fn(void ** state) {
    (void) state;

    will_return(__wrap_purple_user_dir, "/home/testuser/.purple");

    assert_string_equal(lurch_util_uname_get_db_fn("test-uname@example.com", "TESTTYPE"),
    "/home/testuser/.purple/test-uname@example.com_TESTTYPE_db.sqlite");
}

static void test_lurch_util_fp_get_printable(void ** state) {
    (void) state;

    const char * fp_as_returned_by_pidgin =
        "12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:ab:cd:ef:gh";

    will_return(__wrap_purple_base16_encode_chunked, g_strdup(fp_as_returned_by_pidgin));

    char * printable_fp = lurch_util_fp_get_printable((void *) &"fake non-null pointer");
    assert_non_null(printable_fp);
    assert_string_equal(printable_fp, "34567812 34567812 34567812 34567812 34567812 34567812 34567812 abcdefgh");
}

static void test_lurch_util_fp_get_printable_invalid(void ** state) {
    (void) state;

    assert_null(lurch_util_fp_get_printable(NULL));

    will_return(__wrap_purple_base16_encode_chunked, NULL);
    assert_null(lurch_util_fp_get_printable((void *) &"fake non-null pointer"));

    const char * too_short =
        "12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:ab:cd:efgh";
    will_return(__wrap_purple_base16_encode_chunked, g_strdup(too_short));
    assert_null(lurch_util_fp_get_printable((void *) &"fake non-null pointer"));

    const char * too_long =
        "12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:34:56:78:12:ab:cd:ef:gh:";
    will_return(__wrap_purple_base16_encode_chunked, g_strdup(too_long));

    assert_null(lurch_util_fp_get_printable((void *) &"fake non-null pointer"));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_lurch_util_axc_log_func_error),
        cmocka_unit_test(test_lurch_util_axc_log_func_info),
        cmocka_unit_test(test_lurch_util_axc_get_init_ctx_w_logging),
        cmocka_unit_test(test_lurch_util_axc_get_init_ctx_wo_logging),
        cmocka_unit_test(test_lurch_util_uname_strip),
        cmocka_unit_test(test_lurch_util_uname_strip_no_resource),
        cmocka_unit_test(test_lurch_util_uname_strip_empty),
        cmocka_unit_test(test_lurch_util_uname_get_db_fn),
        cmocka_unit_test(test_lurch_util_fp_get_printable),
        cmocka_unit_test(test_lurch_util_fp_get_printable_invalid)
    };

    return cmocka_run_group_tests_name("lurch_util", tests, NULL, NULL);
}