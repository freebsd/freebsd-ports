--- Telegram/ThirdParty/libtgvoip/os/linux/AudioOutputPulse.cpp.orig	2018-02-07 04:48:32 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/AudioOutputPulse.cpp
@@ -8,6 +8,7 @@
 #include <assert.h>
 #include <dlfcn.h>
 #include <unistd.h>
+#include <libgen.h>
 #include "AudioOutputPulse.h"
 #include "../../logging.h"
 #include "../../VoIPController.h"
