--- include/lttng/ust-elf.h.orig	2016-10-18 22:44:06 UTC
+++ include/lttng/ust-elf.h
@@ -21,7 +21,19 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <stdio.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#define __bswap_64 bswap64
+#define NT_GNU_BUILD_ID 3
+#else
 #include <byteswap.h>
+#endif
 #include <elf.h>
 #include <lttng/ust-endian.h>
 
