--- source/ni_device_api_priv.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_device_api_priv.c
@@ -28,7 +28,7 @@
 
 #ifdef _WIN32
 #include <windows.h>
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #if __linux__
 #include <linux/types.h>
 #include <malloc.h>
@@ -49,6 +49,9 @@
 #include <signal.h>
 #include <dirent.h>
 #include <sched.h>
+#if __FreeBSD__
+#include <pthread_np.h>
+#endif
 #include <sys/syscall.h>
 #include <sys/resource.h>
 #if !defined(_ANDROID) && !defined(__OPENHARMONY__)
@@ -1195,7 +1198,7 @@ static void decoder_dump_dir_open(ni_session_context_t
 static void decoder_dump_dir_open(ni_session_context_t *p_ctx)
 {
 #ifdef _WIN32
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
     FILE *fp = NULL;
     char dir_name[128] = {0};
     char file_name[512] = {0};
@@ -1375,7 +1378,7 @@ static void decoder_dump_dir_open(ni_session_context_t
 #endif
 }
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
 #define MAX_BDF_LEN 16
 
 // dev_name pattern: nvmeXnY
@@ -1420,7 +1423,7 @@ static ni_retcode_t p2p_fill_pcie_address(ni_session_c
 // open netint p2p driver and fill the pcie address to p_ctx
 static ni_retcode_t p2p_fill_pcie_address(ni_session_context_t *p_ctx)
 {
-#if defined(_WIN32) || defined(__APPLE__) || defined(__OPEN_HARMONY__)
+#if defined(_WIN32) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OPEN_HARMONY__)
     (void)p_ctx;
     return NI_RETCODE_FAILURE;
 #else
@@ -1535,7 +1538,7 @@ static ni_retcode_t p2p_fill_pcie_address(ni_session_c
 }
 #endif
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #if !defined(_ANDROID) && !defined(__OPENHARMONY__)
 #ifndef DISABLE_BACKTRACE_PRINT
 void ni_print_backtrace() {
@@ -7144,7 +7147,7 @@ int ni_scaler_session_open(ni_session_context_t* p_ctx
   p_ctx->active_video_height = 0;
   p_ctx->actual_video_width = 0;
 
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
   if (p_ctx->isP2P)
   {
       retval = p2p_fill_pcie_address(p_ctx);
@@ -8398,7 +8401,7 @@ ni_retcode_t ni_query_session_stats(ni_session_context
                p_ctx->active_video_width,
                p_ctx->active_video_height);
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #if !defined(_ANDROID) && !defined(__OPENHARMONY__)
 #ifndef DISABLE_BACKTRACE_PRINT
       ni_print_backtrace(); // log backtrace
@@ -15930,7 +15933,7 @@ void *ni_session_keep_alive_thread(void *arguments)
     //interval(nanoseconds) is equals to ctx.keep_alive_timeout/3(330,000,000ns approximately equal to 1/3 second).
     uint64_t interval = args->keep_alive_timeout * 330000000LL;
 #ifndef _ANDROID
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     struct sched_param sched_param;
 
     // Linux has a wide variety of signals, Windows has a few.
@@ -15949,8 +15952,13 @@ void *ni_session_keep_alive_thread(void *arguments)
      *       being default.
      */
     sched_param.sched_priority = sched_get_priority_max(SCHED_RR);
+#if defined(__FreeBSD__)
     if ((sched_param.sched_priority == -1) ||
+        pthread_setschedparam(pthread_self(), SCHED_RR, &sched_param) != 0)
+#else
+    if ((sched_param.sched_priority == -1) ||
         sched_setscheduler((int)syscall(SYS_gettid), SCHED_RR, &sched_param) < 0)
+#endif
     {
         char errmsg[NI_ERRNO_LEN] = {0};
         ni_strerror(errmsg, NI_ERRNO_LEN, NI_ERRNO);
@@ -15986,6 +15994,8 @@ void *ni_session_keep_alive_thread(void *arguments)
     prctl(PR_SET_NAME, name);
 #elif __APPLE__
     pthread_setname_np(name);
+#elif __FreeBSD__
+    pthread_set_name_np(pthread_self(), name);
 #endif
 #endif
     // Initializes the session context variables that keep alive command and query status command need.
@@ -16319,7 +16329,7 @@ ni_retcode_t ni_uploader_session_open(ni_session_conte
          p_ctx->session_id);
 
   p_ctx->hw_action = NI_CODEC_HW_NONE;
-#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
+#if !defined(_WIN32) && !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__OPEN_HARMONY__) && !defined(_ANDROID)
   // If this is a P2P upload session, open the Netint kernel driver
   if (p_ctx->isP2P)
   {
@@ -19586,7 +19596,7 @@ ni_retcode_t ni_ai_session_write(ni_session_context_t 
                 LRETURN;
             }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
             for (i = 0; (int)i < iovec_batch; i++) {
                 ni_iovec_t *iovec = &p_frame->iovec[iovec_index + i];
                 ni_segment_t *segment = &buffer_info->segment[i];
@@ -20224,7 +20234,7 @@ ni_retcode_t ni_ai_session_open(ni_session_context_t *
     }
 
     //aio
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (ni_aio_setup(NI_MAX_SEGMENT_NUM, &p_ctx->aio_context) != 0) {
         ni_log2(p_ctx, NI_LOG_ERROR, "ERROR %s(): failed to setup aio context\n", __func__);
         retval = NI_RETCODE_ERROR_MEM_ALOC;
@@ -20351,7 +20361,7 @@ END:
 
 END:
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (p_ctx->aio_context != 0) {
         if (ni_aio_destroy(p_ctx->aio_context) != 0) {
             ni_log2(p_ctx, NI_LOG_ERROR, "ERROR %s(): failed to destroy aio context\n", __func__);
