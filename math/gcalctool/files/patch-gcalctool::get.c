--- gcalctool/get.c.orig	Tue Jan  6 19:18:44 2004
+++ gcalctool/get.c	Tue Jan  6 19:19:01 2004
@@ -234,7 +234,7 @@
         tsep = g_locale_to_utf8(tsep, -1, NULL, NULL, NULL);
     }
 
-    if (tsep == NULL || tsep[0] == '\0') {
+    if (tsep == NULL) {
         return(",");
     } else {
         return(tsep);
