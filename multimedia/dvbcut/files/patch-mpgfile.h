--- src/mpgfile.h~	2007-04-13 19:36:27 +0200
+++ src/mpgfile.h	2007-07-17 01:10:56 +0200
@@ -19,7 +19,9 @@
 #ifndef _DVBCUT_MPGFILE_H
 #define _DVBCUT_MPGFILE_H
 
+extern "C" {
 #include <ffmpeg/avcodec.h>
+}
 #include <string>
 #include <vector>
 #include <list>
