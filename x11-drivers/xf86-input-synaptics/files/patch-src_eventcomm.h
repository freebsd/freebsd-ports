--- src/eventcomm.h.orig	2015-11-24 23:47:05 UTC
+++ src/eventcomm.h
@@ -30,7 +30,15 @@
 #include <xorg-server.h>
 
 #include <linux/input.h>
+#ifdef __linux__
 #include <linux/version.h>
+#else
+#undef BUS_NONE
+#undef BUS_PCI
+#undef BUS_SBUS
+#undef BUS_PLATFORM
+#undef BUS_last
+#endif
 #include <xf86Xinput.h>
 #include "synproto.h"
 
