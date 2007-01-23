--- src/hourglass.h.orig	Wed Oct  8 20:26:08 2003
+++ src/hourglass.h	Tue Jan 23 05:28:40 2007
@@ -38,6 +38,11 @@
 #include <pthread.h>
 #include <assert.h>
 
+#ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+#include <machine/atomic.h>
+#endif
+
 #include "config.h"
 
 #define DBGPrint(lev,str) do {      \
@@ -197,6 +202,8 @@
   cycle_time start, end;
 };
 
+#ifndef __FreeBSD__
+
 #ifdef CPU_586
 /*
  * a bit of documentation since the rdrsc function seems to often be
@@ -228,7 +235,7 @@
 
 static inline int my_InterlockedIncrement (long *dest)
 {
-    return my_InterlockedExchangeAdd (dest, 1) + 1;
+    return my_InterlockedExchangeAdd (dest, 1L) + 1;
 }
 
 #endif  /* defined CPU_586 */
@@ -275,6 +282,16 @@
 }
 
 #endif /* defined CPU_PPC */
+
+#else
+
+static inline long my_InterlockedIncrement (long *dest)
+{
+    atomic_add_long(dest, 1L);
+    return *dest;
+}
+
+#endif /* !__FreeBSD__ */
 
 static inline sec_time cycle_to_sec (cycle_time c)
 {
