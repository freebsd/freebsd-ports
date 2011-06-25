--- ./qv4l2/v4l2-api.h.orig	2011-02-09 23:04:27.000000000 +0100
+++ ./qv4l2/v4l2-api.h	2011-06-03 19:08:13.000000000 +0200
@@ -24,6 +24,10 @@
 #include <linux/videodev2.h>
 #include <libv4lconvert.h>
 
+#ifdef __FreeBSD__
+typedef off_t __off64_t;
+#endif
+
 class v4l2
 {
 public:
