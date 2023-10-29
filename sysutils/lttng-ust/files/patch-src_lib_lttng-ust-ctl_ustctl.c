--- src/lib/lttng-ust-ctl/ustctl.c.orig	2022-03-25 15:37:22 UTC
+++ src/lib/lttng-ust-ctl/ustctl.c
@@ -8,6 +8,11 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/mman.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define NT_GNU_BUILD_ID 3
+#endif
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
