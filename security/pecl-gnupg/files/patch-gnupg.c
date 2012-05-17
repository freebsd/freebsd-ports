--- gnupg.c	2010/07/20 19:27:25	301426
+++ gnupg.c	2012/05/06 07:43:30	325553
@@ -18,6 +18,7 @@
 
 #include "php.h"
 #include "php_ini.h"
+#include "zend_exceptions.h"
 #include "ext/standard/info.h"
 #include "php_gnupg.h"
 
@@ -53,7 +54,7 @@
 				php_error_docref(NULL TSRMLS_CC, E_WARNING, (char*)error); \
 				break; \
 			case 2: \
-				zend_throw_exception(zend_exception_get_default(), (char*) error, 0 TSRMLS_CC); \
+				zend_throw_exception(zend_exception_get_default(TSRMLS_C), (char*) error, 0 TSRMLS_CC); \
 				break; \
 			default: \
 				intern->errortxt = (char*)error; \
@@ -136,6 +137,9 @@
 	gpgme_ctx_t	ctx;
 	gpgme_check_version			(NULL);
 	gpgme_new					(&ctx);
+#ifdef GNUPG_PATH
+	gpgme_ctx_set_engine_info(ctx, GPGME_PROTOCOL_OpenPGP, GNUPG_PATH, NULL);
+#endif
 	gpgme_set_armor				(ctx,1);
 	intern->ctx				=	ctx;
 	intern->encryptkeys		=	NULL;
@@ -170,16 +174,22 @@
 /* {{{ objects_new */
 zend_object_value gnupg_obj_new(zend_class_entry *class_type TSRMLS_DC){
 	gnupg_object *intern;
+#if PHP_VERSION_ID < 50399
 	zval *tmp;
+#endif
 	zend_object_value retval;
 	
-	intern					=	emalloc(sizeof(gnupg_object));
+	intern					=	ecalloc(1, sizeof(gnupg_object));
 	intern->zo.ce			=	class_type;
+
+#if PHP_VERSION_ID < 50399
 	intern->zo.properties	=	NULL;
-	
 	ALLOC_HASHTABLE	(intern->zo.properties);
 	zend_hash_init	(intern->zo.properties, 0, NULL, ZVAL_PTR_DTOR, 0);
 	zend_hash_copy	(intern->zo.properties, &class_type->default_properties, (copy_ctor_func_t) zval_add_ref, (void *) &tmp, sizeof(zval *));
+#else	
+	object_properties_init(&intern->zo, class_type);
+#endif
 	
 	retval.handle		=	zend_objects_store_put(intern,NULL,(zend_objects_free_object_storage_t) gnupg_obj_dtor,NULL TSRMLS_CC);
 	retval.handlers		=	(zend_object_handlers *) & gnupg_object_handlers;
@@ -379,7 +389,7 @@
 /* {{{ callback func for setting the passphrase */
 
 gpgme_error_t passphrase_cb (gnupg_object *intern, const char *uid_hint, const char *passphrase_info,int last_was_bad, int fd TSRMLS_DC){
-	char uid[16];
+	char uid[17];
 	int idx;
 	char *passphrase = NULL;
 	zval *return_value = NULL;
@@ -407,7 +417,7 @@
 }
 
 gpgme_error_t passphrase_decrypt_cb (gnupg_object *intern, const char *uid_hint, const char *passphrase_info,int last_was_bad, int fd TSRMLS_DC){
-    char uid[16];
+    char uid[17];
     int idx;
     char *passphrase = NULL;
 	zval *return_value = NULL;
@@ -1244,7 +1254,6 @@
     gpgme_data_t            in, out;
 	gpgme_decrypt_result_t	decrypt_result;
 	gpgme_verify_result_t	verify_result;
-	gpgme_signature_t       gpg_signatures;
 
 	GNUPG_GETOBJ();
 
@@ -1472,13 +1481,12 @@
 /* {{{ proto array gnupg_listsignatures(string keyid) */
 PHP_FUNCTION(gnupg_listsignatures){
 	char	*keyid;
-	char	keyid_len;
+	int	keyid_len;
 
 	zval	*sub_arr;
 	zval	*sig_arr;
 
 	gpgme_key_t		gpgme_key;
-	gpgme_subkey_t	gpgme_subkey;
 	gpgme_user_id_t	gpgme_userid;
 	gpgme_key_sig_t	gpgme_signature;
 
