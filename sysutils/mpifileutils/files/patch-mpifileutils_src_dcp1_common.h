--- mpifileutils/src/dcp1/common.h.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dcp1/common.h
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #include <utime.h>
 
-#if DCOPY_USE_XATTRS
+#if defined(__linux__) && DCOPY_USE_XATTRS
 #include <sys/xattr.h>
 /*
  * Newer versions of attr deprecated attr/xattr.h which defines ENOATTR as a
