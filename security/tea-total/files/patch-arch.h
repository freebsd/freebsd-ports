--- arch.h.orig	Fri Jan 12 02:20:52 2001
+++ arch.h	Fri Jan 12 02:24:00 2001
@@ -11,6 +11,9 @@
 
+#if defined(ARCH_OPENBSD) || defined(ARCH_FREEBSD)
 #if defined(ARCH_OPENBSD)
-
 #include <machine/types.h>
 #include <machine/endian.h>
+#else
+#include <sys/inttypes.h>
+#endif
 typedef uint32_t u32;
