- workaround for https://github.com/ZoneMinder/zoneminder/issues/3330

--- src/zm_local_camera.cpp.orig	2021-08-16 21:01:02 UTC
+++ src/zm_local_camera.cpp
@@ -24,6 +24,7 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
+#include <unistd.h>
 
 #if ZM_HAS_V4L
 
