--- va/va_trace.c.orig	2017-10-21 04:49:28 UTC
+++ va/va_trace.c
@@ -50,6 +50,9 @@
 #include <sys/stat.h>
 #include <sys/syscall.h>
 #include <pthread.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#endif
 #include <unistd.h>
 #include <time.h>
 #include <errno.h>
@@ -291,7 +294,13 @@ static void add_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -315,7 +324,13 @@ static void delete_trace_config_info(
 {
     struct trace_config_info *pconfig_info;
     int idx = 0;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     LOCK_RESOURCE(pva_trace);
 
@@ -662,7 +677,13 @@ static struct trace_log_file *start_tracing2log_file(
 {
     struct trace_log_files_manager *plog_files_mgr = NULL;
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     LOCK_RESOURCE(pva_trace);
@@ -701,7 +722,13 @@ static void refresh_log_file(
     struct trace_context *ptra_ctx)
 {
     struct trace_log_file *plog_file = NULL;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
     int i = 0;
 
     plog_file = ptra_ctx->plog_file;
@@ -1224,7 +1251,13 @@ static void internal_TraceUpdateContext (
 {
     struct trace_context *trace_ctx = NULL;
     int i = 0, delete = 1;
+#ifdef __FreeBSD__
+    pid_t thd_id = pthread_getthreadid_np();
+#elif defined __DragonFly__
+    pid_t thd_id = syscall(SYS_lwp_gettid);
+#else
     pid_t thd_id = syscall(__NR_gettid);
+#endif
 
     if(tra_ctx_idx >= MAX_TRACE_CTX_NUM)
         return;
