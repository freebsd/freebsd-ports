--- pHash.cpp.orig	2013-04-23 18:54:02 UTC
+++ pHash.cpp
@@ -36,12 +36,14 @@ struct ph_text_hash
 
 /* {{{ phpinfo logo definitions */
 
+#if PHP_VERSION_ID < 50500
 #include "php_logos.h"
 
 
 static unsigned char pHash_logo[] = {
 #include "pHash_logos.h"
 }; 
+#endif
 /* }}} */
 
 /* {{{ Resource destructors */
@@ -145,7 +147,9 @@ ZEND_GET_MODULE(pHash)
 /* {{{ PHP_MINIT_FUNCTION */
 PHP_MINIT_FUNCTION(pHash)
 {
+#if PHP_VERSION_ID < 50500
 	php_register_info_logo("PHASH_LOGO_ID", "", pHash_logo, 49651);
+#endif
 	le_ph_video_hash = zend_register_list_destructors_ex(ph_video_hash_dtor, 
 						   NULL, "ph_video_hash", module_number);
 	le_ph_image_hash = zend_register_list_destructors_ex(ph_image_hash_dtor, 
@@ -165,7 +169,9 @@ PHP_MINIT_FUNCTION(pHash)
 /* {{{ PHP_MSHUTDOWN_FUNCTION */
 PHP_MSHUTDOWN_FUNCTION(pHash)
 {
+#if PHP_VERSION_ID < 50500
 	php_unregister_info_logo("PHASH_LOGO_ID");
+#endif
 
 	/* add your stuff here */
 
@@ -203,7 +209,9 @@ PHP_MINFO_FUNCTION(pHash)
 	if (SG(request_info).request_uri) {
 		php_printf("%s", (SG(request_info).request_uri));
 	}   
+#if PHP_VERSION_ID < 50500
 	php_printf("?=%s", "PHASH_LOGO_ID");
+#endif
 	php_printf("' align='right' alt='image' border='0'>\n");
 
 	php_printf("pHash\n");
