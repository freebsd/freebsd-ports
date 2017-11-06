--- src/bin/lttng-crash/lttng-crash.c.orig	2016-11-29 22:48:37 UTC
+++ src/bin/lttng-crash/lttng-crash.c
@@ -21,17 +21,29 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <dirent.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#include <inttypes.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#define __bswap_64 bswap64
+#define NT_GNU_BUILD_ID 3
+#else
 #include <byteswap.h>
 #include <inttypes.h>
+#endif
 #include <stdbool.h>
 
 #include <version.h>
