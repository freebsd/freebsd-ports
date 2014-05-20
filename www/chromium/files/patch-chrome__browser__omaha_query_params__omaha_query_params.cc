--- ./chrome/browser/omaha_query_params/omaha_query_params.cc.orig	2014-04-30 22:42:02.000000000 +0200
+++ ./chrome/browser/omaha_query_params/omaha_query_params.cc	2014-05-04 14:38:46.000000000 +0200
@@ -29,6 +29,8 @@
     "linux";
 #elif defined(OS_OPENBSD)
     "openbsd";
+#elif defined(OS_FREEBSD)
+    "freebsd";
 #else
 #error "unknown os"
 #endif
