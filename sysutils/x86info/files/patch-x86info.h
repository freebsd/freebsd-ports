diff -urNb x86info.h x86info.h
--- x86info.h.orig     Thu Jul 26 14:40:46 2001
+++ x86info.h          Sun Aug 26 23:12:33 2001
@@ -3,7 +3,12 @@
  * May be used under the terms of the GNU Public License (GPL)
  */
 
+#ifdef linux
 #include <linux/types.h>
+#else
+#include <machine/types.h>
+#define __u32 int
+#endif
 
 typedef __u32 u32;
 
