--- src/xf86WacomDefs.h~
+++ src/xf86WacomDefs.h
@@ -24,7 +24,9 @@
  * General Defines
  ****************************************************************************/
 #include <wacom-util.h>
+#ifdef __linux__
 #include <asm/types.h>
+#endif
 #include <linux/input.h>
 #define MAX_USB_EVENTS 32
 
