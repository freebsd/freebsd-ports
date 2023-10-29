--- src/common/elf.h.orig	2022-03-25 15:37:17 UTC
+++ src/common/elf.h
@@ -10,6 +10,11 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <stdio.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define NT_GNU_BUILD_ID 3
+#endif
 #include <elf.h>
 
 #include <lttng/ust-endian.h>
