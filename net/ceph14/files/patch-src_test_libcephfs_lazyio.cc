--- src/test/libcephfs/lazyio.cc.orig	2020-03-02 17:49:20 UTC
+++ src/test/libcephfs/lazyio.cc
@@ -21,7 +21,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <dirent.h>
+#ifdef __linux__
 #include <sys/xattr.h>
+#endif
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#endif
 
 rados_t cluster;
 
