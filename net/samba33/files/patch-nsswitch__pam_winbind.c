--- ./nsswitch/pam_winbind.c.orig	2009-06-23 09:35:13.000000000 +0000
+++ ./nsswitch/pam_winbind.c	2009-06-26 00:41:37.000000000 +0000
@@ -161,7 +161,6 @@
 }
 #endif
 
-
 /*
  * Work around the pam API that has functions with void ** as parameters
  * These lead to strict aliasing warnings with gcc.
@@ -171,14 +170,20 @@
 			 const void *_item)
 {
 	const void **item = (const void **)_item;
-	return pam_get_item(pamh, item_type, item);
+	return pam_get_item((pam_handle_t *)pamh, item_type, item);
 }
+
 static int _pam_get_data(const pam_handle_t *pamh,
 			 const char *module_data_name,
 			 const void *_data)
 {
+#if PAM_GET_DATA_ARG3_CONST_VOID_PP
 	const void **data = (const void **)_data;
-	return pam_get_data(pamh, module_data_name, data);
+	return pam_get_data((pam_handle_t *)pamh, module_data_name, data);
+#else
+	void **data = (void **)_data;
+	return pam_get_data((pam_handle_t *)pamh, module_data_name, data);
+#endif
 }
 
 /* some syslogging */
@@ -309,7 +314,7 @@
 	if (item_type != 0) {
 		pam_get_item(ctx->pamh, item_type, &data);
 	} else {
-		pam_get_data(ctx->pamh, key, &data);
+		_pam_get_data(ctx->pamh, key, data);
 	}
 	if (data != NULL) {
 		const char *type = (item_type != 0) ? "ITEM" : "DATA";
@@ -1298,12 +1303,12 @@
 static bool _pam_check_remark_auth_err(struct pwb_context *ctx,
 				       const struct wbcAuthErrorInfo *e,
 				       const char *nt_status_string,
-				       int *pam_error)
+				       int *pam_err)
 {
 	const char *ntstatus = NULL;
 	const char *error_string = NULL;
 
-	if (!e || !pam_error) {
+	if (!e || !pam_err) {
 		return false;
 	}
 
@@ -1317,18 +1322,18 @@
 		error_string = _get_ntstatus_error_string(nt_status_string);
 		if (error_string) {
 			_make_remark(ctx, PAM_ERROR_MSG, error_string);
-			*pam_error = e->pam_error;
+			*pam_err = e->pam_error;
 			return true;
 		}
 
 		if (e->display_string) {
 			_make_remark(ctx, PAM_ERROR_MSG, e->display_string);
-			*pam_error = e->pam_error;
+			*pam_err = e->pam_error;
 			return true;
 		}
 
 		_make_remark(ctx, PAM_ERROR_MSG, nt_status_string);
-		*pam_error = e->pam_error;
+		*pam_err = e->pam_error;
 
 		return true;
 	}
@@ -2695,8 +2700,7 @@
 		ret = PAM_USER_UNKNOWN;
 		goto out;
 	case 0:
-		pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD,
-			     (const void **)&tmp);
+		_pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, tmp);
 		if (tmp != NULL) {
 			ret = atoi((const char *)tmp);
 			switch (ret) {
