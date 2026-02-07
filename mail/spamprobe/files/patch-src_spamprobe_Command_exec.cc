--- src/spamprobe/Command_exec.cc.orig	2013-11-04 19:54:52.000000000 +0100
+++ src/spamprobe/Command_exec.cc	2013-11-04 19:55:14.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "SpamFilter.h"
 #include "CommandConfig.h"
 #include "ConfigManager.h"
