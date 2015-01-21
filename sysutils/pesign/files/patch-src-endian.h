--- src/endian.h.orig	2015-01-16 09:45:30.000000000 +0100
+++ src/endian.h	2015-01-16 09:46:28.000000000 +0100
@@ -18,7 +18,7 @@
 #ifndef ENDIAN_H
 #define ENDIAN_H
 
-#include <endian.h>
+#include <sys/endian.h>
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define cpu_to_le16(x) (x)
@@ -27,25 +27,27 @@
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
+#define cpu_to_be16(x) bswap_16(x)
+#define cpu_to_be32(x) bswap_32(x)
+#define cpu_to_be64(x) bswap_64(x)
+#define be16_to_cpu(x) bswap_16(x)
+#define be32_to_cpu(x) bswap_32(x)
+#define be64_to_cpu(x) bswap_64(x)
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
+#define cpu_to_le16(x) bswap_16(x)
+#define cpu_to_le32(x) bswap_32(x)
+#define cpu_to_le64(x) bswap_64(x)
+#define le16_to_cpu(x) bswap_16(x)
+#define le32_to_cpu(x) bswap_32(x)
+#define le64_to_cpu(x) bswap_64(x)
+#else
+#error "Unknown endianess"
 #endif
 
 #endif /* ENDIAN_H */
