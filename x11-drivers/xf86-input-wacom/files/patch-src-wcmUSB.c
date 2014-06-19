--- src/wcmUSB.c~
+++ src/wcmUSB.c
@@ -23,10 +23,17 @@
 
 #include "xf86Wacom.h"
 
+#ifdef __linux__
 #include <asm/types.h>
+#endif
 #include <linux/input.h>
 #include <sys/utsname.h>
+#ifdef __linux__
 #include <linux/version.h>
+#else
+#define LINUX_VERSION_CODE 1
+#define KERNEL_VERSION(a,b,c) 0
+#endif
 
 #define MAX_USB_EVENTS 32
 
