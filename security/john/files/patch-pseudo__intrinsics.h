--- pseudo_intrinsics.h.orig	2019-04-09 16:13:11 UTC
+++ pseudo_intrinsics.h
@@ -66,10 +66,10 @@ typedef union {
 #define VLOADU_EMULATED         1
 #define vor(x, y)               (vtype)vorrq_u32((x).v32, (y).v32)
 #define vorn(x, y)              (vtype)vornq_u32((x).v32, (y).v32)
-#define vroti_epi32(x, i)       (i > 0 ? (vtype)vsliq_n_u32(vshrq_n_u32((x).v32, 32 - (i)), (x).v32, i) : \
-                                         (vtype)vsriq_n_u32(vshlq_n_u32((x).v32, 32 + (i)), (x).v32, -(i)))
-#define vroti_epi64(x, i)       (i > 0 ? (vtype)vsliq_n_u64(vshrq_n_u64((x).v64, 64 - (i)), (x).v64, i) : \
-                                         (vtype)vsriq_n_u64(vshlq_n_u64((x).v64, 64 + (i)), (x).v64, -(i)))
+#define vroti_epi32(x, i)       (i > 0 ? (vtype)vsliq_n_u32(vshrq_n_u32((x).v32, 32 - ((i) & 31)), (x).v32, (i) & 31) : \
+                                 (vtype)vsriq_n_u32(vshlq_n_u32((x).v32, (32 + (i)) & 31), (x).v32, (-(i)) & 31))
+#define vroti_epi64(x, i)       (i > 0 ? (vtype)vsliq_n_u64(vshrq_n_u64((x).v64, 64 - ((i) & 63)), (x).v64, (i) & 63) : \
+                                 (vtype)vsriq_n_u64(vshlq_n_u64((x).v64, (64 + (i)) & 63), (x).v64, (-(i)) & 63))
 #define vroti16_epi32           vroti_epi32
 #define vset1_epi32(i)          (vtype)vdupq_n_u32(i)
 #define vset1_epi64(i)          (vtype)vdupq_n_u64(i)
