--- libtest/msg_parse_lib.h.orig	2022-06-03 13:40:39 UTC
+++ libtest/msg_parse_lib.h
@@ -34,6 +34,8 @@ void deinit_syslogformat_module(void);
 
 void assert_log_messages_equal(LogMessage *log_message_a, LogMessage *log_message_b);
 
+void assert_log_message_value_is_direct(LogMessage *self, NVHandle handle);
+void assert_log_message_value_is_indirect(LogMessage *self, NVHandle handle);
 void assert_log_message_value_unset(LogMessage *self, NVHandle handle);
 void assert_log_message_value_unset_by_name(LogMessage *self, const gchar *name);
 void assert_log_message_value(LogMessage *self, NVHandle handle, const gchar *expected_value);
