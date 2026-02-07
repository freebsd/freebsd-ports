--- gosthash.c.orig	2022-12-13 13:51:25 UTC
+++ gosthash.c
@@ -26,9 +26,8 @@ echo -n "8JaanTcVv6ndF8Xp/N011Lp46e68LjaUT9FhnEyQGs8="
 #if defined(__sun__) || defined(__linux__) || defined(__FreeBSD__)
 #define _aligned_malloc(size, align) memalign(align, size)
 #define _aligned_free(ptr) free(ptr)
-#else
-#include <malloc.h>
 #endif // __sun__ __linux__ __FreeBSD__
+#include <malloc.h>
 
 typedef char v16qi __attribute__((__vector_size__(16)));
 //typedef uint8_t v4qi __attribute__((__vector_size__(4)));
@@ -141,7 +140,53 @@ static inline void XOR(v256 *x, const v256 *a)
     x->q[1] ^= a->q[1];
 }
 #if defined(__arm__)
-extern void UADD(v256 *a, v256 *b);
+static inline
+void UADD(v256 *a, v256 *b)
+{
+    __asm volatile (
+    "   ldmia %0, {r0, r1, r2, r3}\n"
+    "   ldmia %1!, {r4, r5, r6, r7}\n"
+    "   adds  r0, r0, r4\n"
+    "   adcs  r1, r1, r5\n"
+    "   adcs  r2, r2, r6\n"
+    "   adcs  r3, r3, r7\n"
+    "   stmia %0!, {r0, r1, r2, r3}\n"
+
+    "   ldmia %0, {r0, r1, r2, r3}\n"
+    "   ldmia %1!, {r4, r5, r6, r7}\n"
+    "   adcs  r0, r0, r4\n"
+    "   adcs  r1, r1, r5\n"
+    "   adcs  r2, r2, r6\n"
+    "   adcs  r3, r3, r7\n"
+    "   stmia %0!, {r0, r1, r2, r3}\n"
+
+    "   sub   %0, %0, #64\n"
+    "   sub   %1, %1, #64\n"
+
+    :: "r"(a), "r"(b) : "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "memory");
+}
+#elif defined(__aarch64__)
+static inline
+void UADD(v256 *a, v256 *b)
+{
+    uint64_t a0, a1, b0, b1;
+
+    __asm volatile (
+    "   ldp   %0, %1, [%4, #0]\n"
+    "   ldp   %2, %3, [%5, #0]\n"
+    "   adds  %0, %0, %2\n"
+    "   adcs  %1, %1, %3\n"
+    "   stp   %0, %1, [%4, #0]\n"
+
+    "   ldp   %0, %1, [%4, #16]\n"
+    "   ldp   %2, %3, [%5, #16]\n"
+    "   adcs  %0, %0, %2\n"
+    "   adcs  %1, %1, %3\n"
+    "   stp   %0, %1, [%4, #16]\n"
+
+    : "=r"(a0), "=r"(a1), "=r"(b0), "=r"(b1)
+    : "r"(a), "r"(b) : "memory");
+}
 
 #elif defined(__x86_64__)//0
 static inline
