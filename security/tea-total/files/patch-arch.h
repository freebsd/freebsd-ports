--- arch.h.orig	Sun Dec 31 09:16:53 2000
+++ arch.h	Sun Oct 20 19:01:52 2002
@@ -9,10 +9,14 @@
  * warranties of merchantability and fitness for a particular purpose.
  */
 
+#if defined(ARCH_OPENBSD) || defined(ARCH_FREEBSD)
 #if defined(ARCH_OPENBSD)
-
 #include <machine/types.h>
 #include <machine/endian.h>
+#endif
+#if defined(ARCH_FREEBSD)
+#include <sys/types.h>
+#endif
 typedef uint32_t u32;
 typedef int32_t s32;
 typedef uint16_t u16;
