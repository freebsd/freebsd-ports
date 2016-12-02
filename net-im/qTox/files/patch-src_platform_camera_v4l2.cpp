Fix build with GCC 4.9
src/platform/camera/v4l2.cpp:204:24: error: 'printf' was not declared in this scope
         printf("BAD!\n");

--- src/platform/camera/v4l2.cpp.orig	2016-12-02 20:44:09 UTC
+++ src/platform/camera/v4l2.cpp
@@ -29,6 +29,7 @@
 #include <linux/videodev2.h>
 #include <dirent.h>
 #include <map>
+#include <cstdio>
 
 /**
  * Most of this file is adapted from libavdevice's v4l2.c,
