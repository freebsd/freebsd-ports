--- src/modules/extra/mod_charset.c.orig	2007-07-12 07:51:10.000000000 +0400
+++ src/modules/extra/mod_charset.c	2007-07-12 07:53:36.000000000 +0400
@@ -1201,6 +1201,8 @@
 
 #endif
 
+#if ! defined(__FreeBSD_cc_version) || __FreeBSD_cc_version < 700003
+
 /*
   Case-insensitive strstr()
 */
@@ -1227,7 +1229,7 @@
   
 }
 
-
+#endif
 
 static void 
 add_redirect_to_table(array_header *h, charset_redirect_t *rd) 
