--- libnemo-private/nemo-action.c.orig	2013-11-25 10:51:16.047414327 +0000
+++ libnemo-private/nemo-action.c	2013-11-25 10:53:12.539547401 +0000
@@ -1083,7 +1083,7 @@
     const gchar *orig_label = nemo_action_get_orig_label (action);
 
     if (orig_label == NULL)
-        return;
+        return NULL;
 
     action->escape_underscores = TRUE;
 
@@ -1106,7 +1106,7 @@
     const gchar *orig_tt = nemo_action_get_orig_tt (action);
 
     if (orig_tt == NULL)
-        return;
+        return NULL;
 
     action->escape_underscores = FALSE;
 
@@ -1350,4 +1350,4 @@
 out:
 
     return selection_type_show && extension_type_show && condition_type_show;
-}
\ No newline at end of file
+}
