--- fuse_module/fuse.h.orig	2008-02-05 00:25:57.000000000 -0500
+++ fuse_module/fuse.h	2009-05-13 18:40:19.000000000 -0400
@@ -25,6 +25,22 @@
 #endif
 #endif
 
+#ifndef VFSOPS_TAKES_THREAD
+#if __FreeBSD_version >= 800087
+#define VFSOPS_TAKES_THREAD 0
+#else
+#define VFSOPS_TAKES_THREAD 1
+#endif
+#endif
+
+#ifndef VOP_ACCESS_TAKES_ACCMODE_T
+#if __FreeBSD_version >= 800052
+#define VOP_ACCESS_TAKES_ACCMODE_T 1
+#else
+#define VOP_ACCESS_TAKES_ACCMODE_T 0
+#endif
+#endif
+
 #ifndef VOP_OPEN_TAKES_FP
 #if __FreeBSD_version >= 700044
 #define VOP_OPEN_TAKES_FP 1
@@ -49,6 +65,14 @@
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
