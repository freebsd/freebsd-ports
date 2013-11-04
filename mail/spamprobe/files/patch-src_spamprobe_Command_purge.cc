--- src/spamprobe/Command_purge.cc.orig	2013-11-04 20:01:56.000000000 +0100
+++ src/spamprobe/Command_purge.cc	2013-11-04 20:02:10.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "CleanupManager.h"
 #include "SpamFilter.h"
 #include "FrequencyDB.h"
