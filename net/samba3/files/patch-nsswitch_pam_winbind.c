--- nsswitch/pam_winbind.c.orig	Sat Apr 21 03:48:07 2007
+++ nsswitch/pam_winbind.c	Mon Jun  4 02:56:34 2007
@@ -14,13 +14,13 @@
 
 #define _PAM_LOG_FUNCTION_ENTER(function, pamh, ctrl, flags) \
 	do { \
-		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%08x] ENTER: " function " (flags: 0x%04x)", (uint32) pamh, flags); \
+		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%p] ENTER: " function " (flags: 0x%04x)", pamh, flags); \
 		_pam_log_state(pamh, ctrl); \
 	} while (0)
 
 #define _PAM_LOG_FUNCTION_LEAVE(function, pamh, ctrl, retval) \
 	do { \
-		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%08x] LEAVE: " function " returning %d", (uint32) pamh, retval); \
+		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%p] LEAVE: " function " returning %d", pamh, retval); \
 		_pam_log_state(pamh, ctrl); \
 	} while (0)
 
@@ -32,16 +32,16 @@
  * Work around the pam API that has functions with void ** as parameters.
  * These lead to strict aliasing warnings with gcc.
  */
-static int _pam_get_item(const pam_handle_t *pamh, int item_type,
+static int _pam_get_item(pam_handle_t *pamh, int item_type,
 			 const void *_item)
 {
 	const void **item = (const void **)_item;
 	return pam_get_item(pamh, item_type, item);
 }
-static int _pam_get_data(const pam_handle_t *pamh,
-			 const char *module_data_name, const void *_data)
+static int _pam_get_data(pam_handle_t *pamh,
+			 const char *module_data_name, void *_data)
 {
-	const void **data = (const void **)_data;
+	void **data = (void **)_data;
 	return pam_get_data(pamh, module_data_name, data);
 }
 
@@ -53,7 +53,7 @@
 	pam_vsyslog(pamh, err, format, args);
 }
 #else
-static void _pam_log_int(const pam_handle_t *pamh, int err, const char *format, va_list args)
+static void _pam_log_int(pam_handle_t *pamh, int err, const char *format, va_list args)
 {
 	char *format2 = NULL;
 	const char *service;
@@ -78,8 +78,8 @@
 	return on(ctrl, WINBIND_SILENT);
 }
 
-static void _pam_log(const pam_handle_t *pamh, int ctrl, int err, const char *format, ...) PRINTF_ATTRIBUTE(4,5);
-static void _pam_log(const pam_handle_t *pamh, int ctrl, int err, const char *format, ...)
+static void _pam_log(pam_handle_t *pamh, int ctrl, int err, const char *format, ...) PRINTF_ATTRIBUTE(4,5);
+static void _pam_log(pam_handle_t *pamh, int ctrl, int err, const char *format, ...)
 {
 	va_list args;
 
@@ -118,8 +118,8 @@
 	return _pam_log_is_debug_enabled(ctrl);
 }
 
-static void _pam_log_debug(const pam_handle_t *pamh, int ctrl, int err, const char *format, ...) PRINTF_ATTRIBUTE(4,5);
-static void _pam_log_debug(const pam_handle_t *pamh, int ctrl, int err, const char *format, ...)
+static void _pam_log_debug(pam_handle_t *pamh, int ctrl, int err, const char *format, ...) PRINTF_ATTRIBUTE(4,5);
+static void _pam_log_debug(pam_handle_t *pamh, int ctrl, int err, const char *format, ...)
 {
 	va_list args;
 
@@ -132,20 +132,20 @@
 	va_end(args);
 }
 
-static void _pam_log_state_datum(const pam_handle_t *pamh, int ctrl, int item_type, const char *key, int is_string)
+static void _pam_log_state_datum(pam_handle_t *pamh, int ctrl, int item_type, const char *key, int is_string)
 {
-	const void *data = NULL;
+	void *data = NULL;
 	if (item_type != 0) {
-		pam_get_item(pamh, item_type, &data);
+		_pam_get_item(pamh, item_type, &data);
 	} else {
 		pam_get_data(pamh, key, &data);
 	}
 	if (data != NULL) {
 		const char *type = (item_type != 0) ? "ITEM" : "DATA";
 		if (is_string != 0) {
-			_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%08x] STATE: %s(%s) = \"%s\" (0x%08x)", (uint32) pamh, type, key, (const char *) data, (uint32) data);
+			_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%p] STATE: %s(%s) = \"%s\" (0x%p)", pamh, type, key, (const char *) data, data);
 		} else {
-			_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%08x] STATE: %s(%s) = 0x%08x", (uint32) pamh, type, key, (uint32) data);
+			_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%p] STATE: %s(%s) = 0x%p", pamh, type, key, data);
 		}
 	}
 }
@@ -171,7 +171,7 @@
 #define _PAM_LOG_STATE_ITEM_PASSWORD(pamh, ctrl, item_type) \
 	_pam_log_state_datum(pamh, ctrl, item_type, #item_type, _LOG_PASSWORD_AS_STRING)
 
-static void _pam_log_state(const pam_handle_t *pamh, int ctrl)
+static void _pam_log_state(pam_handle_t *pamh, int ctrl)
 {
 	if (!_pam_log_is_debug_state_enabled(ctrl)) {
 		return;
@@ -202,7 +202,7 @@
 	_PAM_LOG_STATE_DATA_POINTER(pamh, ctrl, PAM_WINBIND_PWD_LAST_SET);
 }
 
-static int _pam_parse(const pam_handle_t *pamh, int flags, int argc, const char **argv, dictionary **result_d)
+static int _pam_parse(pam_handle_t *pamh, int flags, int argc, const char **argv, dictionary **result_d)
 {
 	int ctrl = 0;
 	const char *config_file = NULL;
@@ -313,7 +313,7 @@
 {
 	int ctrl = _pam_parse(pamh, 0, 0, NULL, NULL);
 	if (_pam_log_is_debug_state_enabled(ctrl)) {
-		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%08x] CLEAN: cleaning up PAM data 0x%08x (error_status = %d)", (uint32) pamh, (uint32) data, error_status);
+		_pam_log_debug(pamh, ctrl, LOG_DEBUG, "[pamh: 0x%p] CLEAN: cleaning up PAM data 0x%p (error_status = %d)", pamh, data, error_status);
 	}
 	SAFE_FREE(data);
 }
@@ -1441,7 +1441,7 @@
 	return PAM_SUCCESS;
 }
 
-const char *get_conf_item_string(const pam_handle_t *pamh,
+const char *get_conf_item_string(pam_handle_t *pamh,
 				 int argc, 
 				 const char **argv, 
 				 int ctrl,
@@ -1490,12 +1490,12 @@
 	return parm_opt;
 }
 
-const char *get_krb5_cc_type_from_config(const pam_handle_t *pamh, int argc, const char **argv, int ctrl, dictionary *d)
+const char *get_krb5_cc_type_from_config(pam_handle_t *pamh, int argc, const char **argv, int ctrl, dictionary *d)
 {
 	return get_conf_item_string(pamh, argc, argv, ctrl, d, "krb5_ccache_type", WINBIND_KRB5_CCACHE_TYPE);
 }
 
-const char *get_member_from_config(const pam_handle_t *pamh, int argc, const char **argv, int ctrl, dictionary *d)
+const char *get_member_from_config(pam_handle_t *pamh, int argc, const char **argv, int ctrl, dictionary *d)
 {
 	const char *ret = NULL;
 	ret = get_conf_item_string(pamh, argc, argv, ctrl, d, "require_membership_of", WINBIND_REQUIRED_MEMBERSHIP);
@@ -1735,7 +1735,7 @@
 		ret = PAM_USER_UNKNOWN;
 		goto out;
 	case 0:
-		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (const void **)&tmp);
+		pam_get_data( pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, (void **)&tmp);
 		if (tmp != NULL) {
 			ret = atoi((const char *)tmp);
 			switch (ret) {
