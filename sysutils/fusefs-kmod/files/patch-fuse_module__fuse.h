--- fuse_module/fuse.h.orig	2008-09-26 12:40:20.000000000 -0400
+++ fuse_module/fuse.h	2008-09-26 12:41:54.000000000 -0400
@@ -49,6 +49,14 @@
 #endif
 #endif
 
+#ifndef VOP_GETATTR_TAKES_THREAD
+#if __FreeBSD_version >= 800046
+#define VOP_GETATTR_TAKES_THREAD 0
+#else
+#define VOP_GETATTR_TAKES_THREAD 1
+#endif
+#endif
+
 #ifndef USE_PRIVILEGE_API
 /*
  * __FreeBSD_version bump was omitted for introduction of
