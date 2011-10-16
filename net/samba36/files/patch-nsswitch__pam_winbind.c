--- ./nsswitch/pam_winbind.c.orig	2011-08-09 13:17:47.000000000 +0200
+++ ./nsswitch/pam_winbind.c	2011-09-06 23:23:18.000000000 +0200
@@ -163,7 +163,6 @@
 }
 #endif
 
-
 /*
  * Work around the pam API that has functions with void ** as parameters
  * These lead to strict aliasing warnings with gcc.
@@ -173,14 +172,20 @@
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
@@ -311,7 +316,7 @@
 	if (item_type != 0) {
 		pam_get_item(ctx->pamh, item_type, &data);
 	} else {
-		pam_get_data(ctx->pamh, key, &data);
+		_pam_get_data(ctx->pamh, key, &data);
 	}
 	if (data != NULL) {
 		const char *type = (item_type != 0) ? "ITEM" : "DATA";
@@ -2835,8 +2840,7 @@
 		ret = PAM_USER_UNKNOWN;
 		goto out;
 	case 0:
-		pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD,
-			     (const void **)&tmp);
+		_pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, &tmp);
 		if (tmp != NULL) {
 			ret = atoi((const char *)tmp);
 			switch (ret) {
