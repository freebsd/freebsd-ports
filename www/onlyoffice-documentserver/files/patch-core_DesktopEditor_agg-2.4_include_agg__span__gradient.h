--- core/DesktopEditor/agg-2.4/include/agg_span_gradient.h.orig	2021-09-30 12:13:32 UTC
+++ core/DesktopEditor/agg-2.4/include/agg_span_gradient.h
@@ -24,7 +24,7 @@
 
 namespace agg
 {
-#if !defined(_LINUX) && !(defined(_WIN32) || defined (_WIN64)) && !defined(__APPLE__)
+#if !defined(_LINUX) && !defined(__FreeBSD__) && !(defined(_WIN32) || defined (_WIN64)) && !defined(__APPLE__)
     double _hypot(double x, double y)
     {
         return sqrt(x*x + y*y);
