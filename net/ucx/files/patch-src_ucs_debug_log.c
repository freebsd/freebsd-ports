--- src/ucs/debug/log.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/debug/log.c
@@ -78,7 +78,11 @@ static int __thread ucs_log_current_indent   = 0;
 static unsigned ucs_log_handlers_count       = 0;
 static int ucs_log_initialized               = 0;
 static int __thread ucs_log_current_indent   = 0;
+#if defined(__FreeBSD__)
+static char ucs_log_hostname[UCS_HOST_NAME_MAX] = {0};
+#else
 static char ucs_log_hostname[HOST_NAME_MAX]  = {0};
+#endif
 static int ucs_log_pid                       = 0;
 static FILE *ucs_log_file                    = NULL;
 static char *ucs_log_file_base_name          = NULL;
