--- util/dib3000-watch/dib-i2c.h.orig	2014-03-21 19:26:36 UTC
+++ util/dib3000-watch/dib-i2c.h
@@ -8,6 +8,14 @@
 #ifndef _DIB_I2C_H
 #define _DIB_I2C_H
 
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __u64 uint64_t
+#define __s16 int16_t
+#define __s32 int32_t
+#endif
 
 /* from <linux/i2c.h> */
 #define I2C_SLAVE       0x0703
