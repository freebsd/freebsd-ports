--- lib/common/utils.c.orig	2016-01-14 21:43:08 UTC
+++ lib/common/utils.c
@@ -2270,7 +2270,8 @@ find_library_function(void **handle, con
     }
 
     a_function = dlsym(*handle, fn);
-    if ((error = dlerror()) != NULL) {
+    if (a_function == NULL) {
+        error = dlerror();
         crm_err("%sCould not find %s in %s: %s", fatal ? "Fatal: " : "", fn, lib, error);
         if (fatal) {
             crm_exit(DAEMON_RESPAWN_STOP);
