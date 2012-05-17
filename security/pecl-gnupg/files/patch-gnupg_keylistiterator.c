--- gnupg_keylistiterator.c	2006/11/03 12:38:35	222719
+++ gnupg_keylistiterator.c	2012/01/29 02:38:33	322911
@@ -23,6 +23,7 @@
 #include "php_ini.h"
 #include "ext/standard/info.h"
 #include "zend_interfaces.h"
+#include "zend_exceptions.h"
 #include "php_gnupg.h"
 #include "php_gnupg_keylistiterator.h"
 
@@ -148,7 +149,7 @@
 		gpgme_key_release(intern->gpgkey);
 	}
 
-	if(intern->err = gpgme_op_keylist_next(intern->ctx, &intern->gpgkey)){
+	if((intern->err = gpgme_op_keylist_next(intern->ctx, &intern->gpgkey))){
 		gpgme_key_release(intern->gpgkey);
 		intern->gpgkey = NULL;
 	}
@@ -159,7 +160,7 @@
 	GNUPG_GET_ITERATOR();
 
 	if((intern->err = gpgme_op_keylist_start(intern->ctx, Z_STRVAL(intern->pattern), 0)) != GPG_ERR_NO_ERROR){
-		zend_throw_exception(zend_exception_get_default(),gpg_strerror(intern->err),1 TSRMLS_CC);
+		zend_throw_exception(zend_exception_get_default(TSRMLS_C),gpg_strerror(intern->err),1 TSRMLS_CC);
 	}
 	if((intern->err = gpgme_op_keylist_next(intern->ctx, &intern->gpgkey))!=GPG_ERR_NO_ERROR){
 		RETURN_FALSE;
