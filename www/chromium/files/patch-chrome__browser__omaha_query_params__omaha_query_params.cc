--- ./chrome/browser/omaha_query_params/omaha_query_params.cc.orig	2014-08-12 21:01:47.000000000 +0200
+++ ./chrome/browser/omaha_query_params/omaha_query_params.cc	2014-08-13 09:56:56.000000000 +0200
@@ -29,6 +29,8 @@
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
