--- post_handler.c.orig	2012-02-09 17:17:35.000000000 +0100
+++ post_handler.c	2012-02-09 17:17:58.000000000 +0100
@@ -165,6 +165,7 @@
 void suhosin_unhook_post_handlers()
 {
 	zend_ini_entry *ini_entry;
+	TSRMLS_FETCH();
 
 	/* Restore to an empty destructor */
 	SG(known_post_content_types).pDestructor = NULL;
