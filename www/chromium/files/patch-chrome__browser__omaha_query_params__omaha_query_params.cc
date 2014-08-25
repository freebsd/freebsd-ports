--- ./chrome/browser/omaha_query_params/omaha_query_params.cc.orig	2014-08-20 21:02:00.000000000 +0200
+++ ./chrome/browser/omaha_query_params/omaha_query_params.cc	2014-08-22 15:06:25.000000000 +0200
@@ -29,6 +29,8 @@
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
