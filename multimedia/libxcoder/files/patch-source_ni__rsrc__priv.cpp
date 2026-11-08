--- source/ni_rsrc_priv.cpp.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_priv.cpp
@@ -35,7 +35,7 @@
 #include <ctype.h>
 #include <setjmp.h>
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #ifdef __OPENHARMONY__
 #include <sys/ipc.h>
 #include <sys/shm.h>
@@ -67,12 +67,43 @@
 #include "ni_host_ts.h"
 #endif
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #ifndef _ANDROID
-jmp_buf env;
+sigjmp_buf env;
 #endif
 #endif
 
+#if __FreeBSD__
+/*
+ * FreeBSD shm_open() requires the name to begin with '/', while Linux simply
+ * maps "NAME" to /dev/shm/NAME. libxcoder uses bare names (NI_SHM_CODERS),
+ * so add the slash here.
+ */
+static int ni_fbsd_shm_open(const char *name, int flags, mode_t mode)
+{
+  char buf[NAME_MAX + 2];
+
+  if (snprintf(buf, sizeof(buf), "/%s", name) >= (int)sizeof(buf)) {
+    errno = ENAMETOOLONG;
+    return -1;
+  }
+  return shm_open(buf, flags, mode);
+}
+
+static int ni_fbsd_shm_unlink(const char *name)
+{
+  char buf[NAME_MAX + 2];
+
+  if (snprintf(buf, sizeof(buf), "/%s", name) >= (int)sizeof(buf)) {
+    errno = ENAMETOOLONG;
+    return -1;
+  }
+  return shm_unlink(buf);
+}
+#define shm_open ni_fbsd_shm_open
+#define shm_unlink ni_fbsd_shm_unlink
+#endif
+
 uint32_t g_xcoder_stop_process = 0;
 
 
@@ -1025,7 +1056,7 @@ int ni_rsrc_init_priv(const int should_match_rev,
     return NI_RETCODE_SUCCESS;
 }
 
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 
 
 typedef struct {
@@ -2086,6 +2117,10 @@ ni_retcode_t ni_rsrc_remove_all_shm()
     return NI_RETCODE_FAILURE;
   }
 
+#if __FreeBSD__
+  /* shm objects are not files in LOCK_DIR on FreeBSD: remove them explicitly */
+  (void)shm_unlink(CODERS_SHM_NAME);
+#endif
   while ((dirent = readdir(dir)) != NULL) { // NOLINT(concurrency-mt-unsafe) - thread-local dir, no shared DIR*
     if (strncmp(dirent->d_name, "NI_", 3) != 0) {
       continue;
