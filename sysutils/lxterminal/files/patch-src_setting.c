--- src/setting.c.orig	2014-10-21 15:29:18 UTC
+++ src/setting.c
@@ -162,7 +162,7 @@ void save_setting()
 /* Deep copy settings. */
 Setting * copy_setting(Setting * setting)
 {
-    g_return_if_fail (setting != NULL);
+    g_return_val_if_fail (setting != NULL, NULL);
 
     /* Allocate structure. */
     Setting * new_setting = g_slice_new0(Setting);
