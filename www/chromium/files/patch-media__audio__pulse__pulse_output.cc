--- media/audio/pulse/pulse_output.cc.orig	2012-07-18 10:01:11.000000000 +0300
+++ media/audio/pulse/pulse_output.cc	2012-07-25 21:23:04.000000000 +0300
@@ -8,7 +8,7 @@
 #include "base/message_loop.h"
 #include "media/audio/audio_parameters.h"
 #include "media/audio/audio_util.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "media/audio/linux/audio_manager_linux.h"
 #elif defined(OS_OPENBSD)
 #include "media/audio/openbsd/audio_manager_openbsd.h"
@@ -372,7 +372,7 @@
     int chunk_size;
 
     // Stop writing if there is no more data available.
-    if (!client_buffer_->GetCurrentChunk(&chunk, &chunk_size))
+    if (!client_buffer_->GetCurrentChunk(&chunk, (int*) &chunk_size))
       break;
 
     // Write data to stream.
