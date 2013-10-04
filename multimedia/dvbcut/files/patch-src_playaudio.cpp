--- src/playaudio.cpp.orig	2010-06-06 16:19:25.000000000 +0200
+++ src/playaudio.cpp	2013-10-03 13:56:54.373309704 +0200
@@ -19,6 +19,7 @@
 /* $Id: playaudio.cpp 58 2007-07-23 07:03:07Z too-tired $ */
 
 #include <stdint.h>
+#include <string.h>
 #include <algorithm>
 #include <string>
 #include <sstream>
@@ -55,6 +56,7 @@
 
       ao_sample_format format;
 
+      memset(&format, 0, sizeof(format));
       format.bits = 16;
       format.channels = channels;
       format.rate = samplerate;
