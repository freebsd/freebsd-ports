--- src/h263codec.cxx.orig	Fri Jun  6 08:32:08 2003
+++ src/h263codec.cxx	Sat Feb 19 11:19:36 2005
@@ -109,7 +109,7 @@
 #include "rtp.h"
 
 extern "C" {
-#include <avcodec.h>
+#include <ffmpeg/avcodec.h>
 };
 
 
@@ -836,7 +836,7 @@
 }
 
 
-void H323_H263Codec::RtpCallback(void *data, int size, int /*packetNumber*/)
+void H323_H263Codec::RtpCallback(AVCodecContext* /*s*/, void *data, int size, int /*packetNumber*/)
 {
   encodedPackets.AppendH263Packet(data, size);
 }
