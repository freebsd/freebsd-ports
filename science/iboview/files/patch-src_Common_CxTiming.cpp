--- src/Common/CxTiming.cpp.orig	2026-09-03 10:26:42 UTC
+++ src/Common/CxTiming.cpp
@@ -67,10 +67,16 @@ unsigned long long dbgGetTimeStampCounter()
 // Use only for debugging, if at all!
 unsigned long long dbgGetTimeStampCounter()
 {
+#if defined(__powerpc64__)
+	unsigned long long tb;
+	asm volatile("mfspr %0, 268" : "=r" (tb));
+	return tb;
+#else
 	unsigned a, d;
 	asm volatile("rdtsc" : "=a" (a), "=d" (d));
 
 	return (((unsigned long long)a) | (((unsigned long long)d) << 32));
+#endif
 }
 
 } // namespace ct
