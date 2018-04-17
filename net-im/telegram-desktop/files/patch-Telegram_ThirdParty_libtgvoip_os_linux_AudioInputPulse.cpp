--- Telegram/ThirdParty/libtgvoip/os/linux/AudioInputPulse.cpp.orig	2018-02-07 04:48:22 UTC
+++ Telegram/ThirdParty/libtgvoip/os/linux/AudioInputPulse.cpp
@@ -8,6 +8,7 @@
 #include <assert.h>
 #include <dlfcn.h>
 #include <unistd.h>
+#include <libgen.h>
 #include "AudioInputPulse.h"
 #include "../../logging.h"
 #include "../../VoIPController.h"
