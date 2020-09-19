Obtained from:	https://github.com/ecmwf/eccodes/commit/7a618fa90aaafa3a28cacae130939c3268e15876

--- src/grib_bits.c.orig	2020-06-24 09:11:27 UTC
+++ src/grib_bits.c
@@ -30,6 +30,12 @@ long GRIB_MASK = -1; /* Mask of sword bits */
     ((b) == max_nbits ? GRIB_MASK : (~(GRIB_MASK << (b)) << (max_nbits - ((q) + (b)))))
 
 
+#define VALUE_SIZE_T(p, q, b) \
+    (((b) == max_nbits_size_t ? GRIB_MASK : ~(GRIB_MASK << (b))) & ((p) >> (max_nbits_size_t - ((q) + (b)))))
+
+#define MASKVALUE_SIZE_T(q, b) \
+    ((b) == max_nbits_size_t ? GRIB_MASK : (~(GRIB_MASK << (b)) << (max_nbits_size_t - ((q) + (b)))))
+
 static const unsigned long dmasks[] = {
     0xFF,
     0xFE,
