--- x86info.h.orig	Sun Aug 24 10:59:27 2003
+++ x86info.h	Sun Aug 24 11:00:47 2003
@@ -1,15 +1,10 @@
 #ifndef _X86INFO_H
 #define _X86INFO_H
 
-#ifdef linux
-#include <linux/types.h>
-typedef unsigned char u8;
-typedef unsigned short u16;
-typedef unsigned int u32;
-#else
-#include <machine/types.h>
-#define __u32 int
-#endif /* linux */
+#include <sys/types.h>
+typedef u_int8_t u8;
+typedef u_int16_t u16;
+typedef u_int32_t u32;
 
 #define VENDOR_AMD	1
 #define VENDOR_CENTAUR 2
