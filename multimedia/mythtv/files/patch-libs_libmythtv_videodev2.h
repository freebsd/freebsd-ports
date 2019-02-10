--- libs/libmythtv/videodev2.h.orig      2018-01-11 12:39:22 UTC
+++ libs/libmythtv/videodev2.h
@@ -60,6 +60,32 @@
 #ifdef __FreeBSD__
 #include <linux/input.h>	// For __[us][0-9]+ types
+#ifndef __u64
+typedef uint64_t __u64;
+#endif
+#ifndef __u32
+typedef uint32_t __u32;
+#endif
+#ifndef __u16
+typedef uint16_t __u16;
+#endif
+#ifndef __u8
+typedef uint8_t __u8;
+#endif
+
+#ifndef __s64
+typedef int64_t __s64;
+#endif
+#ifndef __s32
+typedef int32_t __s32;
+#endif
+#ifndef __s16
+typedef int16_t __s16;
+#endif
+#ifndef __s8
+typedef int8_t __s8;
+#endif
+
 #define __le64 __u64
 #define __le32 __u32
 #define __le16 __u16
