--- src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h.orig	2019-10-27 17:19:53 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkRasterPipeline_opts.h
@@ -729,7 +729,10 @@ SI F approx_powf(F x, F y) {
 }
 
 SI F from_half(U16 h) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) && defined(__aarch64__)  // Required to build on FreeBSD aarch64
+    return vcvt_f32_f16(h);
+
+#elif defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) // Temporary workaround for some Google3 builds.
     __fp16 fp16;
     memcpy(&fp16, &h, sizeof(U16));
     return float(fp16);
@@ -751,7 +754,10 @@ SI F from_half(U16 h) {
 }
 
 SI U16 to_half(F f) {
-#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
+#if defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3) && defined(__aarch64__) // Required to build on FreeBSD aarch64
+    return vcvt_f16_f32(f);
+
+#elif defined(SK_CPU_ARM64) && !defined(SK_BUILD_FOR_GOOGLE3)  // Temporary workaround for some Google3 builds.
     __fp16 fp16 = __fp16(f);
     U16 u16;
     memcpy(&u16, &fp16, sizeof(U16));
@@ -954,10 +954,17 @@ SI void from_4444(U16 _4444, F* r, F* g, F* b, F* a) {
     *a = cast(wide & (15<< 0)) * (1.0f / (15<< 0));
 }
 SI void from_8888(U32 _8888, F* r, F* g, F* b, F* a) {
+#ifdef SK_CPU_BENDIAN
+    *r = cast((_8888 >> 24)       ) * (1/255.0f);
+    *g = cast((_8888 >> 16) & 0xff) * (1/255.0f);
+    *b = cast((_8888 >>  8) & 0xff) * (1/255.0f);
+    *a = cast((_8888      ) & 0xff) * (1/255.0f);
+#else
     *r = cast((_8888      ) & 0xff) * (1/255.0f);
     *g = cast((_8888 >>  8) & 0xff) * (1/255.0f);
     *b = cast((_8888 >> 16) & 0xff) * (1/255.0f);
     *a = cast((_8888 >> 24)       ) * (1/255.0f);
+#endif
 }
 SI void from_1010102(U32 rgba, F* r, F* g, F* b, F* a) {
     *r = cast((rgba      ) & 0x3ff) * (1/1023.0f);
@@ -1284,10 +1291,17 @@ STAGE(srcover_rgba_8888, const SkRasterPipeline_Memory
     auto ptr = ptr_at_xy<uint32_t>(ctx, dx,dy);
 
     U32 dst = load<U32>(ptr, tail);
+#ifdef SK_CPU_BENDIAN
+    dr = cast((dst >> 24)       );
+    dg = cast((dst >> 16) & 0xff);
+    db = cast((dst >>  8) & 0xff);
+    da = cast((dst      ) & 0xff);
+#else
     dr = cast((dst      ) & 0xff);
     dg = cast((dst >>  8) & 0xff);
     db = cast((dst >> 16) & 0xff);
     da = cast((dst >> 24)       );
+#endif
     // {dr,dg,db,da} are in [0,255]
     // { r, g, b, a} are in [0,  1] (but may be out of gamut)
 
@@ -1298,10 +1312,17 @@ STAGE(srcover_rgba_8888, const SkRasterPipeline_Memory
     // { r, g, b, a} are now in [0,255]  (but may be out of gamut)
 
     // to_unorm() clamps back to gamut.  Scaling by 1 since we're already 255-biased.
+#ifdef SK_CPU_BENDIAN
+    dst = to_unorm(r, 1, 255) << 24
+        | to_unorm(g, 1, 255) << 16
+        | to_unorm(b, 1, 255) <<  8
+        | to_unorm(a, 1, 255);
+#else
     dst = to_unorm(r, 1, 255)
         | to_unorm(g, 1, 255) <<  8
         | to_unorm(b, 1, 255) << 16
         | to_unorm(a, 1, 255) << 24;
+#endif
     store(ptr, dst, tail);
 }
 
@@ -1700,10 +1721,17 @@ STAGE(gather_8888, const SkRasterPipeline_GatherCtx* c
 STAGE(store_8888, const SkRasterPipeline_MemoryCtx* ctx) {
     auto ptr = ptr_at_xy<uint32_t>(ctx, dx,dy);
 
+#ifdef SK_CPU_BENDIAN
+    U32 px = to_unorm(r, 255) << 24
+           | to_unorm(g, 255) << 16
+           | to_unorm(b, 255) <<  8
+           | to_unorm(a, 255);
+#else
     U32 px = to_unorm(r, 255)
            | to_unorm(g, 255) <<  8
            | to_unorm(b, 255) << 16
            | to_unorm(a, 255) << 24;
+#endif
     store(ptr, px, tail);
 }
 
@@ -2858,10 +2886,17 @@ SI void from_8888(U32 rgba, U16* r, U16* g, U16* b, U1
         return cast<U16>(v);
     };
 #endif
+#ifdef SK_CPU_BENDIAN
+    *r = cast_U16(rgba >>   16) >>  8;
+    *g = cast_U16(rgba >>   16) & 255;
+    *b = cast_U16(rgba & 65535) >>  8;
+    *a = cast_U16(rgba & 65535) & 255;
+#else
     *r = cast_U16(rgba & 65535) & 255;
     *g = cast_U16(rgba & 65535) >>  8;
     *b = cast_U16(rgba >>   16) & 255;
     *a = cast_U16(rgba >>   16) >>  8;
+#endif
 }
 
 SI void load_8888_(const uint32_t* ptr, size_t tail, U16* r, U16* g, U16* b, U16* a) {
@@ -2904,8 +2939,13 @@ SI void store_8888_(uint32_t* ptr, size_t tail, U16 r,
         case 1: vst4_lane_u8((uint8_t*)(ptr+0), rgba, 0);
     }
 #else
+#ifdef SK_CPU_BENDIAN
+    store(ptr, tail, cast<U32>((r<<8) | g) << 16
+                   | cast<U32>((b<<8) | a) << 0);
+#else
     store(ptr, tail, cast<U32>(r | (g<<8)) <<  0
                    | cast<U32>(b | (a<<8)) << 16);
+#endif
 #endif
 }
 
