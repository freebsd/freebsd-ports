--- gcalctool/display.c.orig	Sat Jan  3 13:44:50 2004
+++ gcalctool/display.c	Sat Jan  3 14:01:31 2004
@@ -88,8 +88,8 @@
  * definitions are potentially in read-only memory, and shouldn't be adjusted.
  */
 
-    if (strstr(str, v->tsep) != NULL) {
-        tsep_len = strlen(v->tsep);
+    tsep_len = strlen(v->tsep);
+    if (tsep_len && strstr(str, v->tsep) != NULL) {
         while (*srcp != '\0') {
             if (memcmp(srcp, v->tsep, tsep_len) == 0) {
                 srcp += tsep_len;
