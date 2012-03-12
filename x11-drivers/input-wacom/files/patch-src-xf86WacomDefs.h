--- xf86-input-wacom-0.11.1/src/xf86WacomDefs.h.orig
+++ xf86-input-wacom-0.11.1/src/xf86WacomDefs.h
@@ -23,7 +23,9 @@
 /*****************************************************************************
  * General Defines
  ****************************************************************************/
+#ifndef __FreeBSD__
 #include <asm/types.h>
+#endif
 #include <linux/input.h>
 #define MAX_USB_EVENTS 32
 
