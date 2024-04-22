--- src/core/include/math/hal/intnat/ubintnat.h.orig	2024-03-05 00:18:51 UTC
+++ src/core/include/math/hal/intnat/ubintnat.h
@@ -1919,6 +1919,11 @@ class NativeIntegerT final : public lbcrypto::BigInteg
             uint128_t c{static_cast<uint128_t>(a) * b};
             res.hi = static_cast<uint64_t>(c >> 64);
             res.lo = static_cast<uint64_t>(c);
+#elif __riscv
+            U128BITS wres(0), wa(a), wb(b);
+            wres   = wa * wb;
+            res.hi = (uint64_t)(wres >> 64);
+            res.lo = (uint64_t)wres;
 #elif defined(__EMSCRIPTEN__)  // web assembly
             uint64_t a1 = a >> 32;
             uint64_t a2 = (uint32_t)a;
@@ -1957,6 +1962,11 @@ class NativeIntegerT final : public lbcrypto::BigInteg
             res.lo = x.lo * y;
             asm("umulh %0, %1, %2\n\t" : "=r"(res.hi) : "r"(x.lo), "r"(y));
             res.hi += x.hi * y;
+#elif defined(__powerpc64__) || defined(__riscv)
+            U128BITS wres(0), wa(a), wb(b);
+            wres   = wa * wb;  // should give us 128 bits  of 64 * 64
+            res.hi = (uint64_t)(wres >> 64);
+            res.lo = (uint64_t)wres;
 #elif defined(__arm__) || defined(__powerpc__)  // 32 bit processor
             uint64_t wres(0), wa(a), wb(b);
             wres   = wa * wb;
