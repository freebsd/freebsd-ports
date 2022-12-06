--- src/core/include/math/hal/intnat/ubintnat.h.orig	2022-12-06 03:29:13 UTC
+++ src/core/include/math/hal/intnat/ubintnat.h
@@ -2152,17 +2152,17 @@ class NativeIntegerT : public lbcrypto::BigIntegerInte
         res.lo = x.lo * y;
         asm("umulh %0, %1, %2\n\t" : "=r"(res.hi) : "r"(x.lo), "r"(y));
         res.hi += x.hi * y;
-#elif defined(__arm__)  // 32 bit processor
+#elif defined(__powerpc64__) || defined(__riscv)
+        U128BITS wres(0), wa(a), wb(b);
+        wres   = wa * wb;  // should give us 128 bits  of 64 * 64
+        res.hi = (uint64_t)(wres >> 64);
+        res.lo = (uint64_t)wres;
+#elif defined(__arm__)  || defined(__powerpc__) // 32 bit processor
         uint64_t wres(0), wa(a), wb(b);
 
         wres   = wa * wb;  // should give us the lower 64 bits of 32*32
         res.hi = wres >> 32;
         res.lo = (uint32_t)wres & 0xFFFFFFFF;
-#elif __riscv
-        U128BITS wres(0), wa(a), wb(b);
-        wres   = wa * wb;  // should give us 128 bits  of 64 * 64
-        res.hi = (uint64_t)(wres >> 64);
-        res.lo = (uint64_t)wres;
 #elif defined(__EMSCRIPTEN__)  // web assembly
         U64BITS a1 = a >> 32;
         U64BITS a2 = (uint32_t)a;
