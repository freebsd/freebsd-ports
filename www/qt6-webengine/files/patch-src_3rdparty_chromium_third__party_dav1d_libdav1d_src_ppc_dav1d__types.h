--- src/3rdparty/chromium/third_party/dav1d/libdav1d/src/ppc/dav1d_types.h.orig	2026-05-08 07:54:08 UTC
+++ src/3rdparty/chromium/third_party/dav1d/libdav1d/src/ppc/dav1d_types.h
@@ -55,4 +55,19 @@
 #define u16l_to_i32(v) ((i32x4) vec_mergel((u16x8) v, vec_splat_u16(0)))
 #define i16l_to_i32(v) ((i32x4) vec_unpackl((i16x8)v))
 
+#if defined(__clang__)
+#undef vec_splats
+#define vec_splats(N)                     \
+    _Generic((N),                         \
+        unsigned char:      ((u8x16)(N)), \
+        signed char:        ((i8x16)(N)), \
+        unsigned short:     ((u16x8)(N)), \
+        signed short:       ((i16x8)(N)), \
+        unsigned int:       ((u32x4)(N)), \
+        signed int:         ((i32x4)(N)), \
+        unsigned long long: ((u64x2)(N)), \
+        signed long long:   ((i64x2)(N))  \
+    )
+#endif
+
 #endif /* DAV1D_SRC_PPC_TYPES_H */
