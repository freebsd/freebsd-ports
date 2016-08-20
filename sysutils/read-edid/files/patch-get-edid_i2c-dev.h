--- get-edid/i2c-dev.h.orig	2011-10-04 19:57:18 UTC
+++ get-edid/i2c-dev.h
@@ -25,9 +25,17 @@
 #ifndef LIB_I2CDEV_H
 #define LIB_I2CDEV_H
 
-#include <linux/types.h>
+#include <sys/types.h>
 #include <sys/ioctl.h>
 
+#if defined(__FreeBSD__)
+typedef int8_t __s8;
+typedef int16_t __s16;
+typedef int32_t __s32;
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+#endif
 
 /* -- i2c.h -- */
 
