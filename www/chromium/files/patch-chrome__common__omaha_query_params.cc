--- chrome/common/omaha_query_params.cc.orig	2013-05-07 22:43:58.000000000 +0300
+++ chrome/common/omaha_query_params.cc	2013-05-07 22:44:41.000000000 +0300
@@ -28,6 +28,8 @@
   "linux";
 #elif defined(OS_OPENBSD)
   "openbsd";
+#elif defined(OS_FREEBSD)
+  "freebsd";
 #else
     #error "unknown os"
 #endif
