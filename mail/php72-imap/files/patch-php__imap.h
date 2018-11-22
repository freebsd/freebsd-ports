--- php_imap.h.orig	2018-09-11 22:12:36 UTC
+++ php_imap.h
@@ -214,6 +214,7 @@ ZEND_BEGIN_MODULE_GLOBALS(imap)
 #endif
 	/* php_stream for php_mail_gets() */
 	php_stream *gets_stream;
+	zend_bool enable_rsh;
 ZEND_END_MODULE_GLOBALS(imap)
 
 #ifdef ZTS
