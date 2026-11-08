--- src/hourglass.h.orig	2003-10-08 20:26:08 UTC
+++ src/hourglass.h
@@ -39,6 +39,11 @@
 #include <assert.h>
 #include <stdint.h>
 
+#ifdef __FreeBSD__
+#include <machine/cpufunc.h>
+#include <machine/atomic.h>
+#endif
+
 #include "config.h"
 
 #define DBGPrint(lev,str) do {      \
@@ -211,7 +216,7 @@
   cycle_time start, end, gap;   // rjd -- added thread id dependent gap for SMP
 };
 
-#ifdef CPU_586
+#if defined(CPU_586) && !defined(__FreeBSD__)
 /*
  * a bit of documentation since the rdrsc function seems to often be
  * misimplemented:
@@ -282,6 +287,7 @@
   return ts;
 }
 #endif
+#ifndef __FreeBSD__
 /* these routines snagged from Wine */
 
 static inline int my_InterlockedExchangeAdd (long *dest, long incr)
@@ -306,8 +312,17 @@
     return my_InterlockedExchangeAdd (dest, 1) + 1;
 }
 
+#endif
 #endif /* defined CPU_PPC */
 
+#ifdef __FreeBSD__
+static inline long my_InterlockedIncrement (long *dest)
+{
+    atomic_add_long(dest, 1L);
+    return *dest;
+}
+#endif
+
 static inline sec_time cycle_to_sec (cycle_time c)
 {
   assert (TSC_MHZ != -1);
