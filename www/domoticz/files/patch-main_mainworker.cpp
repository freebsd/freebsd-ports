--- main/mainworker.cpp.orig	2020-04-26 13:49:25 UTC
+++ main/mainworker.cpp
@@ -125,7 +125,9 @@
 #include "../hardware/ZiBlueTCP.h"
 #include "../hardware/Yeelight.h"
 #include "../hardware/XiaomiGateway.h"
+#ifdef ENABLE_PYTHON
 #include "../hardware/plugins/Plugins.h"
+#endif
 #include "../hardware/Arilux.h"
 #include "../hardware/OpenWebNetUSB.h"
 #include "../hardware/InComfort.h"
