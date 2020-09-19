Obtained from:	https://github.com/ecmwf/eccodes/commit/7a618fa90aaafa3a28cacae130939c3268e15876

--- src/grib_bits_fast_big_endian.c.orig	2020-06-24 09:11:27 UTC
+++ src/grib_bits_fast_big_endian.c
@@ -114,7 +114,6 @@ char* grib_decode_string(const unsigned char* bitStrea
     return string;
 }
 
-
 unsigned long grib_decode_unsigned_long(const unsigned char* p, long* bitp, long nbits)
 {
     long countOfLeftmostBits = 0, leftmostBits = 0;
@@ -146,6 +145,37 @@ unsigned long grib_decode_unsigned_long(const unsigned
     return val;
 }
 
+size_t grib_decode_size_t(const unsigned char* p, long* bitp, long nbits)
+{
+    long countOfLeftmostBits = 0, leftmostBits = 0;
+    long startBit      = *bitp;
+    long remainingBits = nbits;
+    long* pp           = (long*)p;
+    size_t val  = 0;
+
+    if (startBit >= max_nbits_size_t) {
+        pp += startBit / max_nbits_size_t;
+        startBit %= max_nbits_size_t;
+    }
+
+    countOfLeftmostBits = startBit + remainingBits;
+    if (countOfLeftmostBits > max_nbits_size_t) {
+        countOfLeftmostBits = max_nbits_size_t - startBit;
+        remainingBits -= countOfLeftmostBits;
+        leftmostBits = (VALUE_SIZE_T(*pp, startBit, countOfLeftmostBits)) << remainingBits;
+        startBit     = 0;
+        pp++;
+    }
+    else
+        leftmostBits = 0;
+
+    val = leftmostBits + (VALUE_SIZE_T(*pp, startBit, remainingBits));
+
+    *bitp += nbits;
+
+    return val;
+}
+
 int grib_encode_unsigned_long(unsigned char* p, unsigned long val, long* bitp, long nbits)
 {
     long* destination        = (long*)p;
@@ -184,6 +214,46 @@ int grib_encode_unsigned_longb(unsigned char* p, unsig
 {
     return grib_encode_unsigned_long(p, val, bitp, nbits);
 }
+
+int grib_encode_size_t(unsigned char* p, size_t val, long* bitp, long nbits)
+{
+    long* destination        = (long*)p;
+    long countOfLeftmostBits = 0, nextWord = 0, startBit = 0, remainingBits = 0, rightmostBits = 0;
+
+    startBit      = *bitp;
+    remainingBits = nbits;
+
+    if (startBit >= max_nbits_size_t) {
+        nextWord = startBit / max_nbits_size_t;
+        startBit %= max_nbits_size_t;
+    }
+    else
+        nextWord = 0;
+
+    countOfLeftmostBits = startBit + remainingBits;
+    if (countOfLeftmostBits > max_nbits_size_t) {
+        countOfLeftmostBits = max_nbits_size_t - startBit;
+        startBit            = max_nbits_size_t - remainingBits;
+        remainingBits -= countOfLeftmostBits;
+        destination[nextWord] =
+            ((destination[nextWord] >> countOfLeftmostBits) << countOfLeftmostBits) + (VALUE_SIZE_T(val, startBit, countOfLeftmostBits));
+        startBit = 0;
+        nextWord++;
+    }
+
+    rightmostBits = VALUE_SIZE_T(val, max_nbits_size_t - remainingBits, remainingBits);
+    destination[nextWord] =
+        (destination[nextWord] & ~MASKVALUE_SIZE_T(startBit, remainingBits)) + (rightmostBits << max_nbits_size_t - (remainingBits + startBit));
+
+    *bitp += nbits;
+    return GRIB_SUCCESS;
+}
+
+int grib_encode_size_tb(unsigned char* p, size_t val, long* bitp, long nbits)
+{
+    return grib_encode_size_t(p, val, bitp, nbits);
+}
+
 
 #if VECTOR
 #include "grib_bits_fast_big_endian_vector.c" /* Experimental */
