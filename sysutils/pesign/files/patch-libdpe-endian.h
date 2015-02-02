--- libdpe/endian.h.orig	2015-01-16 09:47:58.000000000 +0100
+++ libdpe/endian.h	2015-01-16 09:48:53.000000000 +0100
@@ -19,7 +19,7 @@
 #ifndef ENDIAN_H
 #define ENDIAN_H
 
-#include <endian.h>
+#include <sys/endian.h>
 #include <stdint.h>
 #include <string.h>
 
@@ -30,32 +30,34 @@
 #define le16_to_cpu(x) (x)
 #define le32_to_cpu(x) (x)
 #define le64_to_cpu(x) (x)
-#define cpu_to_be16(x) __bswap_16(x)
-#define cpu_to_be32(x) __bswap_32(x)
-#define cpu_to_be64(x) __bswap_64(x)
-#define be16_to_cpu(x) __bswap_16(x)
-#define be32_to_cpu(x) __bswap_32(x)
-#define be64_to_cpu(x) __bswap_64(x)
-#else
+#define cpu_to_be16(x) bswap16(x)
+#define cpu_to_be32(x) bswap32(x)
+#define cpu_to_be64(x) bswap64(x)
+#define be16_to_cpu(x) bswap16(x)
+#define be32_to_cpu(x) bswap32(x)
+#define be64_to_cpu(x) bswap64(x)
+#elif __BYTE_ORDER == __BIG_ENDIAN
 #define cpu_to_be16(x) (x)
 #define cpu_to_be32(x) (x)
 #define cpu_to_be64(x) (x)
 #define be16_to_cpu(x) (x)
 #define be32_to_cpu(x) (x)
 #define be64_to_cpu(x) (x)
-#define cpu_to_le16(x) __bswap_16(x)
-#define cpu_to_le32(x) __bswap_32(x)
-#define cpu_to_le64(x) __bswap_64(x)
-#define le16_to_cpu(x) __bswap_16(x)
-#define le32_to_cpu(x) __bswap_32(x)
-#define le64_to_cpu(x) __bswap_64(x)
+#define cpu_to_le16(x) bswap16(x)
+#define cpu_to_le32(x) bswap32(x)
+#define cpu_to_le64(x) bswap64(x)
+#define le16_to_cpu(x) bswap16(x)
+#define le32_to_cpu(x) bswap32(x)
+#define le64_to_cpu(x) bswap64(x)
+#else
+#error "Unknown endianess"
 #endif
 
 static inline uint32_t
 __attribute__((unused))
 SwapBytes32(uint32_t x)
 {
-	return __bswap_32(x);
+	return bswap32(x);
 }
 
 static inline int
