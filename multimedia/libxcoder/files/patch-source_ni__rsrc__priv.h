--- source/ni_rsrc_priv.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_priv.h
@@ -36,7 +36,7 @@ extern "C" {
 
 // The macro definition in libxcoder_FFmpeg3.1.1only/source/ni_rsrc_priv.h need to be synchronized with libxcoder
 // If you change this,you should also change LOCK_DIR in libxcoder_FFmpeg3.1.1only/source/ni_rsrc_priv.h
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define LOCK_DIR        "/tmp"
 #else
 #define LOCK_DIR        "/dev/shm"
@@ -92,7 +92,7 @@ ni_retcode_t ni_rsrc_create_retry_lck();
 
 ni_retcode_t ni_rsrc_create_retry_lck();
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 typedef enum _ni_rsrc_shm_state
 {
   NI_RSRC_SHM_IS_INVALID = -1,
