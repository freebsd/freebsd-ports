--- va/va_trace.c.orig	2016-06-21 01:29:25 UTC
+++ va/va_trace.c
@@ -48,6 +48,9 @@
 #include <sys/stat.h>
 #include <sys/syscall.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 #include <unistd.h>
 #include <time.h>
 #include <errno.h>
@@ -294,7 +297,11 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -318,7 +325,11 @@ static void delete_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -663,7 +674,11 @@ static struct trace_log_file *start_trac
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -702,7 +717,11 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1226,7 +1245,11 @@ static void internal_TraceUpdateContext 
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;
