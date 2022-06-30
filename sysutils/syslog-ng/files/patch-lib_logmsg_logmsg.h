--- lib/logmsg/logmsg.h.orig	2022-06-03 13:40:38 UTC
+++ lib/logmsg/logmsg.h
@@ -315,6 +315,25 @@ gboolean log_msg_is_handle_match(NVHandle handle);
   })
 
 static inline gboolean
+log_msg_is_handle_referencable_from_an_indirect_value(NVHandle handle)
+{
+  if (handle == LM_V_NONE)
+    return FALSE;
+
+  /* macro values should not be referenced as they are dynamic, store the actual value instead */
+  if (log_msg_is_handle_macro(handle))
+    return FALSE;
+
+  /* matches are pretty temporary, so we should not reference them, as the
+   * next matching operation would overwrite them anyway */
+
+  if (log_msg_is_handle_match(handle))
+    return FALSE;
+
+  return TRUE;
+}
+
+static inline gboolean
 log_msg_is_handle_settable_with_an_indirect_value(NVHandle handle)
 {
   return (handle >= LM_V_MAX);
