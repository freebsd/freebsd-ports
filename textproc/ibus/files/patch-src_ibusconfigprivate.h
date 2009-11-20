--- src/ibusconfigprivate.h.orig	2009-11-14 11:44:58.000000000 +0800
+++ src/ibusconfigprivate.h	2009-11-14 11:45:31.000000000 +0800
@@ -28,7 +28,7 @@
     g_assert (iter != NULL);
     g_assert (value != NULL);
 
-    gint type;
+    GType type;
     IBusMessageIter sub_iter;
 
     type = ibus_message_iter_get_arg_type (iter);
@@ -83,7 +83,7 @@
         if (type == IBUS_TYPE_ARRAY) {
             GValue v = { 0 };
             IBusMessageIter sub_iter;
-            gint sub_type;
+            GType sub_type;
             GValueArray *array;
 
 
