--- bench/benchmarks.c.orig	2008-09-04 03:03:34.000000000 +0400
+++ bench/benchmarks.c	2008-09-04 03:04:55.000000000 +0400
@@ -21,8 +21,13 @@
 #endif
 	TIME(asm volatile("cpuid": : :"ax", "dx", "cx", "bx"), "cpuid");
 
+#ifdef __i386__
 	TIME(asm volatile("addl $1,0(%esp)"), "addl");
 	TIME(asm volatile("lock ; addl $1,0(%esp)"), "locked add");
+#elif defined(__amd64__)
+	TIME(asm volatile("addl $1,0(%rsp)"), "addl");
+	TIME(asm volatile("lock ; addl $1,0(%rsp)"), "locked add");
+#endif
 
 	TIME(asm volatile("bswap %0" : "=r" (tmp) : "0" (tmp)), "bswap");
 }
