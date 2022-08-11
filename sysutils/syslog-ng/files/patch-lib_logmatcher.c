--- lib/logmatcher.c.orig	2022-06-03 13:40:38 UTC
+++ lib/logmatcher.c
@@ -30,14 +30,6 @@
 #include "compat/string.h"
 #include "compat/pcre.h"
 
-static gboolean
-_shall_set_values_indirectly(NVHandle value_handle)
-{
-  return value_handle != LM_V_NONE &&
-         !log_msg_is_handle_macro(value_handle) &&
-         !log_msg_is_handle_match(value_handle);
-}
-
 static void
 log_matcher_store_pattern(LogMatcher *self, const gchar *pattern)
 {
@@ -416,7 +408,9 @@ log_matcher_pcre_re_feed_value(LogMatcherPcreRe *self,
                                LogMatcherPcreMatchResult *result,
                                gint begin_index, gint end_index)
 {
-  gboolean indirect = _shall_set_values_indirectly(result->source_handle);
+  gboolean indirect = result->source_handle != LM_V_NONE &&
+                      log_msg_is_handle_settable_with_an_indirect_value(target_handle) &&
+                      log_msg_is_handle_referencable_from_an_indirect_value(result->source_handle);
 
   if (target_handle == result->source_handle)
     {
