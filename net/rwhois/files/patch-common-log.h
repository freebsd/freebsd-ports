--- common/log.h.orig	Tue Oct 28 02:25:55 2003
+++ common/log.h	Tue Oct 28 02:29:55 2003
@@ -95,8 +95,8 @@
 /* old prototypes for backward compatibility */
 
 #define l_strerror strerror
-void log_error PROTO(());
-void log_warning PROTO(());
+void log_error PROTO((char *format, ...));
+void log_warning PROTO((char *format, ...));
 char *get_client_hostname PROTO((int sock));
 char *timestamp PROTO(());
 
@@ -106,7 +106,8 @@
      (L_LOG_EMERG, L_LOG_ALERT, etc. [see internal_log_level in
      types.h) and SECTION is one of (NETWORK, QUERY, CONFIG, etc [see
      log_section in types.h) */
-void log PROTO(());
+#define log Log
+void log PROTO((internal_log_levels level, int section, char *format, ...));
 
 void setup_logging PROTO((void));
 
