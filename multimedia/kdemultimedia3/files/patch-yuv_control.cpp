Index: mpeglib/example/yaf/yafyuv/yuv_control.cpp
===================================================================
RCS file: /home/kde/kdemultimedia/mpeglib/example/yaf/yafyuv/yuv_control.cpp,v
retrieving revision 1.3
diff -u -3 -p -r1.3 yuv_control.cpp
--- mpeglib/example/yaf/yafyuv/yuv_control.cpp	2002/11/22 21:52:54	1.3
+++ mpeglib/example/yaf/yafyuv/yuv_control.cpp	2002/11/28 08:58:03
@@ -28,7 +28,7 @@ using namespace std;
 // we include our plugin here
 #include "../../../lib/yuv/yuvPlugin.h"
 
-#if defined(HAVE_GETOPT_H) 
+#if defined(HAVE_GETOPT_H) && !defined(__FreeBSD__)
 #include <getopt.h>
 #endif
 
