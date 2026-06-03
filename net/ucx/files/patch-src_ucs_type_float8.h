--- src/ucs/type/float8.h.orig	2026-02-04 09:52:46 UTC
+++ src/ucs/type/float8.h
@@ -3,12 +3,63 @@
 *
 * See file LICENSE for terms.
 */
-
 #ifndef UCS_TYPE_FLOAT_H
 #define UCS_TYPE_FLOAT_H
 
-#include <ieee754.h>
+#include <stdint.h>
+#include <string.h>
 
+/* IEEE754 double layout helpers without bitfields.
+ */
+static inline void
+ucs_double_to_words(double d, uint32_t *hi, uint32_t *lo)
+{
+    uint32_t w[2];
+    memcpy(w, &d, sizeof(w));
+#if defined(FLOAT_WORDS_BIGENDIAN)
+    *hi = w[0];
+    *lo = w[1];
+#else
+    *hi = w[1];
+    *lo = w[0];
+#endif
+}
+
+static inline double
+ucs_words_to_double(uint32_t hi, uint32_t lo)
+{
+    uint32_t w[2];
+    double d;
+#if defined(FLOAT_WORDS_BIGENDIAN)
+    w[0] = hi;
+    w[1] = lo;
+#else
+    w[0] = lo;
+    w[1] = hi;
+#endif
+    memcpy(&d, w, sizeof(d));
+    return d;
+}
+
+static inline uint32_t ucs_ieee_double_sign(uint32_t hi)
+{
+    return hi >> 31;
+}
+
+static inline uint32_t ucs_ieee_double_exp(uint32_t hi)
+{
+    return (hi >> 20) & 0x7ffu;
+}
+
+static inline uint32_t ucs_ieee_double_mant_hi20(uint32_t hi)
+{
+    return hi & 0x000fffffu;
+}
+
+#ifndef IEEE754_DOUBLE_BIAS
+#  define IEEE754_DOUBLE_BIAS 1023
+#endif
+
 #include <ucs/sys/preprocessor.h>
 #include <ucs/debug/assert.h>
 #include <ucs/arch/bitops.h>
@@ -18,7 +69,6 @@ typedef uint8_t ucs_fp8_t;
 
 typedef uint8_t ucs_fp8_t;
 
-
 /**
  * Bits number in the exponent part of a packed floating-point number
  */
@@ -103,24 +153,31 @@ static UCS_F_ALWAYS_INLINE ucs_fp8_t ucs_fp8_pack(doub
 static UCS_F_ALWAYS_INLINE ucs_fp8_t ucs_fp8_pack(double value, uint64_t min,
                                                   uint64_t max)
 {
-    union ieee754_double ieee_value = {0};
+    uint32_t hi, lo;
+    uint32_t exp;
+    uint32_t mant0;
     uint8_t exponent;
     int8_t min_exponent, max_exponent;
 
-    ieee_value.d = value;
     min_exponent = ucs_ilog2(min);
     max_exponent = ucs_ilog2(max);
 
-    if (ucs_unlikely(ieee_value.ieee.exponent == _UCS_FP8_IEEE_NAN_EXPONENT)) {
+    ucs_double_to_words(value, &hi, &lo);
+    exp   = ucs_ieee_double_exp(hi);
+    mant0 = ucs_ieee_double_mant_hi20(hi);
+
+    if (ucs_unlikely(exp == _UCS_FP8_IEEE_NAN_EXPONENT)) {
         /* NaN maps to a special value for NaN */
         exponent = _UCS_FP8_NAN;
-    } else if (ucs_unlikely(ieee_value.ieee.exponent >
+    } else if (ucs_unlikely(exp >
                             (max_exponent + _UCS_FP8_EXPONENT_OFFSET))) {
         /* A number beyond the max supported is capped */
         exponent                  = max_exponent - min_exponent;
-        ieee_value.ieee.mantissa0 = 0;
-        ieee_value.ieee.mantissa1 = 0;
-    } else if (ucs_unlikely(ieee_value.ieee.exponent <=
+        /* zero mantissa in-place */
+        mant0 = 0;
+        lo    = 0;
+        hi    = (hi & 0xfff00000u); /* keep sign+exp, clear mantissa hi20 */
+    } else if (ucs_unlikely(exp <=
                             min_exponent + _UCS_FP8_EXPONENT_OFFSET)) {
         if (ucs_unlikely(value == 0)) {
             /* 0 maps to a special value for 0 */
@@ -128,15 +185,16 @@ static UCS_F_ALWAYS_INLINE ucs_fp8_t ucs_fp8_pack(doub
         } else {
             /* A number below the min supported is rounded up */
             exponent                  = 1;
-            ieee_value.ieee.mantissa0 = 0;
-            ieee_value.ieee.mantissa1 = 0;
+            mant0 = 0;
+            lo    = 0;
+            hi    = (hi & 0xfff00000u);
         }
     } else {
-        exponent = ieee_value.ieee.exponent - _UCS_FP8_EXPONENT_OFFSET -
+        exponent = exp - _UCS_FP8_EXPONENT_OFFSET -
                    min_exponent;
     }
 
-    return exponent | ((ieee_value.ieee.mantissa0 >> _UCS_FP_MANTISSA_OFFSET)
+    return exponent | ((mant0 >> _UCS_FP_MANTISSA_OFFSET)
                        << _UCS_FP8_EXPONENT_BITS);
 }
 
@@ -154,23 +212,28 @@ ucs_fp8_unpack(ucs_fp8_t value, uint64_t min, uint64_t
 static UCS_F_ALWAYS_INLINE double
 ucs_fp8_unpack(ucs_fp8_t value, uint64_t min, uint64_t max)
 {
-    union ieee754_double ieee_value = {0};
+    uint32_t hi = 0, lo = 0;
+    uint32_t exp;
+    uint32_t mant0;
     uint8_t exponent                = value & _UCS_FP8_EXPONENT_MASK;
 
-    ieee_value.ieee.negative = 0;
+    (void)max;
+
     if (ucs_unlikely(exponent == 0)) {
-        ieee_value.ieee.exponent = 0;
+        exp = 0;
     } else if (ucs_unlikely(exponent == _UCS_FP8_NAN)) {
-        ieee_value.ieee.exponent = _UCS_FP8_IEEE_NAN_EXPONENT;
+        exp = _UCS_FP8_IEEE_NAN_EXPONENT;
     } else {
-        ieee_value.ieee.exponent = exponent + _UCS_FP8_EXPONENT_OFFSET +
+        exp = exponent + _UCS_FP8_EXPONENT_OFFSET +
                                    ucs_ilog2(min);
     }
-    ieee_value.ieee.mantissa0 = value >> _UCS_FP8_EXPONENT_BITS;
-    ieee_value.ieee.mantissa0 = ieee_value.ieee.mantissa0
-                                << _UCS_FP_MANTISSA_OFFSET;
+    mant0 = (uint32_t)(value >> _UCS_FP8_EXPONENT_BITS);
+    mant0 = (mant0 << _UCS_FP_MANTISSA_OFFSET) & 0x000fffffu;
 
-    return ieee_value.d;
+    hi = ((exp & 0x7ffu) << 20) | (mant0 & 0x000fffffu);
+    lo = 0;
+
+    return ucs_words_to_double(hi, lo);
 }
 
 
