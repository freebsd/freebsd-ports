--- lsusb.c.orig	2007-10-23 23:04:32.000000000 +0200
+++ lsusb.c	2007-11-14 20:50:37.000000000 +0100
@@ -35,13 +35,29 @@
 #include <errno.h>
 #include <stdio.h>
 #include <stdarg.h>
+
+#if defined(HAVE_ASM_BYTEORDER_H)
 #include <asm/byteorder.h>
 #define le16_to_cpu	__le16_to_cpu
+
+#elif defined(HAVE_MACHINE_ENDIAN_H)
+#include <machine/endian.h>
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+#define le16_to_cpu(x) (x)
+#else
+#define le16_to_cpu	__bswap16
+#endif
+
+#else
+#error no le16_to_cpu implementation is available
+#endif
+
 #include <usb.h>
 
 /* NOTE:  that should be <libusb.h> and it should include
- * <linux/usb_ch9.h> ... without it, we keep accumulating
+ * <linux/usb/ch9.h> ... without it, we keep accumulating
  * potentially broken variants of standard types ...
+ * also <linux/usb/cdc.h>, <linux/usb/audio.h>, etc
  */
 
 #include "names.h"
