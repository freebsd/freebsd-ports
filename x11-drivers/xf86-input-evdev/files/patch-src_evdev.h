--- src/evdev.h.orig	2016-11-21 04:59:44 UTC
+++ src/evdev.h
@@ -36,7 +36,15 @@
 #define EVDEV_H
 
 #include <linux/input.h>
-#include <linux/types.h>
+#include <sys/types.h>
+
+/* XXX Copied from <xf86str.h> for linux */
+/* Tolerate prior #include <linux/input.h> */
+#undef BUS_NONE
+#undef BUS_PCI
+#undef BUS_SBUS
+#undef BUS_PLATFORM
+#undef BUS_last
 
 #include <xorg-server.h>
 #include <xf86Xinput.h>
