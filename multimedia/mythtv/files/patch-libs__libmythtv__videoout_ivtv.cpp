--- libs/libmythtv/videoout_ivtv.cpp.orig	2009-11-15 13:10:38.000000000 +0100
+++ libs/libmythtv/videoout_ivtv.cpp	2009-11-15 13:11:08.000000000 +0100
@@ -19,7 +19,9 @@
 #include <sys/param.h>
 
 // Linux headers
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 
 // C++ headers
 #include <map>
