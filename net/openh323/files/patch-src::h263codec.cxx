Index: src/h263codec.cxx
diff -u src/h263codec.cxx.orig src/h263codec.cxx
--- src/h263codec.cxx.orig	Fri Jun  6 15:32:08 2003
+++ src/h263codec.cxx	Sat Nov 22 23:17:45 2003
@@ -109,7 +109,7 @@
 #include "rtp.h"
 
 extern "C" {
-#include <avcodec.h>
+#include <ffmpeg/avcodec.h>
 };
 
 
