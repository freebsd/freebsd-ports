--- lib/wp/log.c.orig	2025-12-23 18:48:36 UTC
+++ lib/wp/log.c
@@ -777,7 +777,12 @@ wp_log_fields_write_to_journal (WpLogFields *lf)
   g_autofree gchar *full_message = NULL;
   const gchar *message = lf->message ? lf->message : "";
   g_autofree gchar *pid = g_strdup_printf("%d", getpid());
-  g_autofree gchar *tid = g_strdup_printf("%d", gettid());
+#ifdef __linux__
+  pid_t tid_val = gettid();
+#else
+  pid_t tid_val = -1;
+#endif
+  g_autofree gchar *tid = g_strdup_printf("%d", tid_val);
 #ifdef HAS_SHORT_NAME
   const gchar *syslog_identifier = program_invocation_short_name;
 #else
