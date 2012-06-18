--- src/xf86WacomDefs.h.orig
+++ src/xf86WacomDefs.h
@@ -24,7 +24,9 @@
  * General Defines
  ****************************************************************************/
 #include <wacom-util.h>
+#ifndef __FreeBSD__
 #include <asm/types.h>
+#endif
 #include <linux/input.h>
 #define MAX_USB_EVENTS 32
 
