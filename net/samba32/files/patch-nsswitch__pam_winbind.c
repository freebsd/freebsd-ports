--- ./nsswitch/pam_winbind.c.orig	2009-06-22 21:05:38.000000000 +0000
+++ ./nsswitch/pam_winbind.c	2009-06-25 20:49:35.000000000 +0000
@@ -39,14 +39,14 @@
 			 const void *_item)
 {
 	const void **item = (const void **)_item;
-	return pam_get_item(pamh, item_type, item);
+	return pam_get_item((pam_handle_t *)pamh, item_type, item);
 }
 static int _pam_get_data(const pam_handle_t *pamh,
 			 const char *module_data_name,
 			 const void *_data)
 {
-	const void **data = (const void **)_data;
-	return pam_get_data(pamh, module_data_name, data);
+	void **data = (void **)_data;
+	return pam_get_data((pam_handle_t *)pamh, module_data_name, data);
 }
 
 /* some syslogging */
@@ -177,7 +177,7 @@
 	if (item_type != 0) {
 		pam_get_item(ctx->pamh, item_type, &data);
 	} else {
-		pam_get_data(ctx->pamh, key, &data);
+		_pam_get_data(ctx->pamh, key, data);
 	}
 	if (data != NULL) {
 		const char *type = (item_type != 0) ? "ITEM" : "DATA";
@@ -2203,8 +2203,7 @@
 		ret = PAM_USER_UNKNOWN;
 		goto out;
 	case 0:
-		pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD,
-			     (const void **)&tmp);
+		_pam_get_data(pamh, PAM_WINBIND_NEW_AUTHTOK_REQD, tmp);
 		if (tmp != NULL) {
 			ret = atoi((const char *)tmp);
 			switch (ret) {
