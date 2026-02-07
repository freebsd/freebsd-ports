--- libgrive/src/util/OS.hh.orig	2018-04-23 17:00:17 UTC
+++ libgrive/src/util/OS.hh
@@ -24,6 +24,10 @@
 
 #include <string>
 
+#if defined(__FreeBSD__)
+#define off64_t off_t
+#endif
+
 namespace gr {
 
 class DateTime ;
