--- libtest/msg_parse_lib.c.orig	2022-06-03 13:40:39 UTC
+++ libtest/msg_parse_lib.c
@@ -73,6 +73,20 @@ assert_log_message_value_unset_by_name(LogMessage *sel
 }
 
 void
+assert_log_message_value_is_indirect(LogMessage *self, NVHandle handle)
+{
+  NVEntry *entry = nv_table_get_entry(self->payload, handle, NULL, NULL);
+  cr_assert(entry->indirect);
+}
+
+void
+assert_log_message_value_is_direct(LogMessage *self, NVHandle handle)
+{
+  NVEntry *entry = nv_table_get_entry(self->payload, handle, NULL, NULL);
+  cr_assert(!entry->indirect);
+}
+
+void
 assert_log_message_value_and_type(LogMessage *self, NVHandle handle,
                                   const gchar *expected_value, LogMessageValueType expected_type)
 {
