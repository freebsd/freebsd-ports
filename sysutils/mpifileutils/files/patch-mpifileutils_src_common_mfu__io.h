--- mpifileutils/src/common/mfu_io.h.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/common/mfu_io.h
@@ -42,12 +42,15 @@ extern "C" {
 
 #include "mfu_param_path.h"
 
+#ifdef __FreeBSD__
+#define stat64  stat
+#define lstat64 lstat
+#endif
+
 /* Intent is to wrap all POSIX I/O routines used by mfu tools.  May
  * abort on fatal conditions to avoid checking condition at every call.
  * May also automatically retry on things like EINTR. */
 
-/* TODO: fix this */
-/* do this to avoid warning about undefined stat64 struct */
 struct stat64;
 
 /*****************************
