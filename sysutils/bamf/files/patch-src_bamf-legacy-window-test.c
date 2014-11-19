--- src/bamf-legacy-window-test.c.orig	2014-11-07 00:14:52.553284416 +0100
+++ src/bamf-legacy-window-test.c	2014-11-07 00:15:06.966209374 +0100
@@ -427,7 +427,8 @@
   g_return_if_fail (BAMF_IS_LEGACY_WINDOW_TEST (window));
   BamfLegacyWindowTest *self = BAMF_LEGACY_WINDOW_TEST (window);
 
-  return g_hash_table_insert (self->hints, g_strdup (name), g_strdup (value));
+  g_hash_table_insert (self->hints, g_strdup (name), g_strdup (value));
+  return;
 }
 
 static char *
