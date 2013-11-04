--- src/spamprobe/Command_edit_term.cc.orig	2013-11-04 19:59:38.000000000 +0100
+++ src/spamprobe/Command_edit_term.cc	2013-11-04 20:00:17.000000000 +0100
@@ -28,6 +28,7 @@
 //    http://www.cooldevtools.com/qpl.html
 //
 
+#include <cstdlib>
 #include "SpamFilter.h"
 #include "FrequencyDB.h"
 #include "CommandConfig.h"
