--- src/core/include/math/bigintnat/ubintnat.h.orig	2022-12-02 20:31:23 UTC
+++ src/core/include/math/bigintnat/ubintnat.h
@@ -2218,7 +2218,12 @@ class NativeIntegerT
     res.lo = x.lo * y;
     asm("umulh %0, %1, %2\n\t" : "=r"(res.hi) : "r"(x.lo), "r"(y));
     res.hi += x.hi * y;
-#elif defined(__arm__) // 32 bit processor
+#elif defined(__powerpc64__) || defined(__riscv)
+    U128BITS wres(0), wa(a), wb(b);
+    wres = wa * wb;  // should give us 128 bits  of 64 * 64 
+    res.hi = (uint64_t)(wres >> 64);
+    res.lo = (uint64_t)wres;
+#elif defined(__arm__) || defined(__powerpc__) // 32 bit processor
     uint64_t wres(0), wa(a), wb(b);
 
     wres = wa * wb;  // should give us the lower 64 bits of 32*32
