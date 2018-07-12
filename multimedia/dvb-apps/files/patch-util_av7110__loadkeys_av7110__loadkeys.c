--- util/av7110_loadkeys/av7110_loadkeys.c.orig	2014-03-21 19:26:36 UTC
+++ util/av7110_loadkeys/av7110_loadkeys.c
@@ -1,4 +1,3 @@
-#include <asm/types.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/mman.h>
@@ -10,6 +9,15 @@
 
 #include "input_keynames.h"
 
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __u64 uint64_t
+#define __s16 int16_t
+#define __s32 int32_t
+#endif
+
 
 static
 void print_error (const char *action, const char *file)
