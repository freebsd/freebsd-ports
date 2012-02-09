--- media/audio/pulse/pulse_output.cc.orig	2012-02-05 15:13:12.000000000 +0200
+++ media/audio/pulse/pulse_output.cc	2012-02-05 15:13:41.000000000 +0200
@@ -8,7 +8,7 @@
 #include "base/message_loop.h"
 #include "media/audio/audio_parameters.h"
 #include "media/audio/audio_util.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "media/audio/linux/audio_manager_linux.h"
 #elif defined(OS_OPENBSD)
 #include "media/audio/openbsd/audio_manager_openbsd.h"
