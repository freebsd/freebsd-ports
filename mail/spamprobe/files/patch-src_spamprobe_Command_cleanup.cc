--- src/spamprobe/Command_cleanup.cc.orig	2013-11-04 19:59:51.000000000 +0100
+++ src/spamprobe/Command_cleanup.cc	2013-11-04 20:00:38.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "CleanupManager.h"
 #include "SpamFilter.h"
 #include "FrequencyDB.h"
