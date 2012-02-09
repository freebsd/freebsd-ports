--- media/audio/pulse/pulse_output.h.orig	2012-02-05 15:04:15.000000000 +0200
+++ media/audio/pulse/pulse_output.h	2012-02-05 15:11:25.000000000 +0200
@@ -31,7 +31,7 @@
 class SeekableBuffer;
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 class AudioManagerLinux;
 typedef AudioManagerLinux AudioManagerPulse;
 #elif defined(OS_OPENBSD)
