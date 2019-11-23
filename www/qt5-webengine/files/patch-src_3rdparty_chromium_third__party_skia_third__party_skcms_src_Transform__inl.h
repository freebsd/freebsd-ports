--- src/3rdparty/chromium/third_party/skia/third_party/skcms/src/Transform_inl.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/third_party/skcms/src/Transform_inl.h
@@ -392,9 +392,11 @@ SI U32 gather_32(const uint8_t* p, I32 ix) {
 }
 
 SI U32 gather_24(const uint8_t* p, I32 ix) {
+#if !__BIG_ENDIAN__
     // First, back up a byte.  Any place we're gathering from has a safe junk byte to read
     // in front of it, either a previous table value, or some tag metadata.
     p -= 1;
+#endif
 
     // Load the i'th 24-bit value from p, and 1 extra byte.
     auto load_24_32 = [p](int i) {
@@ -435,8 +437,10 @@ SI U32 gather_24(const uint8_t* p, I32 ix) {
 
 #if !defined(__arm__)
     SI void gather_48(const uint8_t* p, I32 ix, U64* v) {
+#if !__BIG_ENDIAN__
         // As in gather_24(), with everything doubled.
         p -= 2;
+#endif
 
         // Load the i'th 48-bit value from p, and 2 extra bytes.
         auto load_48_64 = [p](int i) {
@@ -499,7 +503,9 @@ SI F F_from_U8(U8 v) {
 SI F F_from_U16_BE(U16 v) {
     // All 16-bit ICC values are big-endian, so we byte swap before converting to float.
     // MSVC catches the "loss" of data here in the portable path, so we also make sure to mask.
+#if !__BIG_ENDIAN__
     v = U16( 0 | ((v & 0x00ff) << 8) | ((v & 0xff00) >> 8) );
+#endif
     return cast<F>(v) * (1/65535.0f);
 }
 
@@ -534,9 +540,15 @@ SI F table(const skcms_Curve* curve, F v) {
 SI void sample_clut_8(const skcms_A2B* a2b, I32 ix, F* r, F* g, F* b) {
     U32 rgb = gather_24(a2b->grid_8, ix);
 
+#if __BIG_ENDIAN__
+    *r = cast<F>((rgb >> 16) & 0xff) * (1/255.0f);
+    *g = cast<F>((rgb >>  8) & 0xff) * (1/255.0f);
+    *b = cast<F>((rgb >>  0) & 0xff) * (1/255.0f);
+#else
     *r = cast<F>((rgb >>  0) & 0xff) * (1/255.0f);
     *g = cast<F>((rgb >>  8) & 0xff) * (1/255.0f);
     *b = cast<F>((rgb >> 16) & 0xff) * (1/255.0f);
+#endif
 }
 
 SI void sample_clut_16(const skcms_A2B* a2b, I32 ix, F* r, F* g, F* b) {
@@ -549,12 +561,18 @@ SI void sample_clut_16(const skcms_A2B* a2b, I32 ix, F
     // This strategy is much faster for 64-bit builds, and fine for 32-bit x86 too.
     U64 rgb;
     gather_48(a2b->grid_16, ix, &rgb);
+#if __BIG_ENDIAN__
+    *r = cast<F>((rgb >> 32) & 0xffff) * (1/65535.0f);
+    *g = cast<F>((rgb >> 16) & 0xffff) * (1/65535.0f);
+    *b = cast<F>((rgb >>  0) & 0xffff) * (1/65535.0f);
+#else
     rgb = swap_endian_16x4(rgb);
 
     *r = cast<F>((rgb >>  0) & 0xffff) * (1/65535.0f);
     *g = cast<F>((rgb >> 16) & 0xffff) * (1/65535.0f);
     *b = cast<F>((rgb >> 32) & 0xffff) * (1/65535.0f);
 #endif
+#endif
 }
 
 // GCC 7.2.0 hits an internal compiler error with -finline-functions (or -O3)
@@ -695,10 +713,17 @@ static void exec_ops(const Op* ops, const void** args,
             case Op_load_8888:{
                 U32 rgba = load<U32>(src + 4*i);
 
+#if __BIG_ENDIAN__
+                r = cast<F>((rgba >> 24) & 0xff) * (1/255.0f);
+                g = cast<F>((rgba >> 16) & 0xff) * (1/255.0f);
+                b = cast<F>((rgba >>  8) & 0xff) * (1/255.0f);
+                a = cast<F>((rgba >>  0) & 0xff) * (1/255.0f);
+#else
                 r = cast<F>((rgba >>  0) & 0xff) * (1/255.0f);
                 g = cast<F>((rgba >>  8) & 0xff) * (1/255.0f);
                 b = cast<F>((rgba >> 16) & 0xff) * (1/255.0f);
                 a = cast<F>((rgba >> 24) & 0xff) * (1/255.0f);
+#endif
             } break;
 
             case Op_load_8888_palette8:{
@@ -727,13 +752,29 @@ static void exec_ops(const Op* ops, const void** args,
                 const uint16_t* rgb = (const uint16_t*)ptr; // cast to const uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x3_t v = vld3_u16(rgb);
+#if __BIG_ENDIAN__
+                r = cast<F>(swap_endian_16((U16)v.val[0])) * (1/65535.0f);
+                g = cast<F>(swap_endian_16((U16)v.val[1])) * (1/65535.0f);
+                b = cast<F>(swap_endian_16((U16)v.val[2])) * (1/65535.0f);
+#else
                 r = cast<F>((U16)v.val[0]) * (1/65535.0f);
                 g = cast<F>((U16)v.val[1]) * (1/65535.0f);
                 b = cast<F>((U16)v.val[2]) * (1/65535.0f);
+#endif
             #else
+#if __BIG_ENDIAN__
+                U32 R = load_3<U32>(rgb+0),
+                    G = load_3<U32>(rgb+1),
+                    B = load_3<U32>(rgb+2);
+                // R,G,B are little-endian 16-bit, so byte swap them before converting to float.
+                r = cast<F>((R & 0x00ff)<<8 | (R & 0xff00)>>8) * (1/65535.0f);
+                g = cast<F>((G & 0x00ff)<<8 | (G & 0xff00)>>8) * (1/65535.0f);
+                b = cast<F>((B & 0x00ff)<<8 | (B & 0xff00)>>8) * (1/65535.0f);
+#else
                 r = cast<F>(load_3<U32>(rgb+0)) * (1/65535.0f);
                 g = cast<F>(load_3<U32>(rgb+1)) * (1/65535.0f);
                 b = cast<F>(load_3<U32>(rgb+2)) * (1/65535.0f);
+#endif
             #endif
             } break;
 
@@ -743,17 +784,33 @@ static void exec_ops(const Op* ops, const void** args,
                 const uint16_t* rgba = (const uint16_t*)ptr; // cast to const uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x4_t v = vld4_u16(rgba);
+#if __BIG_ENDIAN__
+                r = cast<F>(swap_endian_16((U16)v.val[0])) * (1/65535.0f);
+                g = cast<F>(swap_endian_16((U16)v.val[1])) * (1/65535.0f);
+                b = cast<F>(swap_endian_16((U16)v.val[2])) * (1/65535.0f);
+                a = cast<F>(swap_endian_16((U16)v.val[3])) * (1/65535.0f);
+#else
                 r = cast<F>((U16)v.val[0]) * (1/65535.0f);
                 g = cast<F>((U16)v.val[1]) * (1/65535.0f);
                 b = cast<F>((U16)v.val[2]) * (1/65535.0f);
                 a = cast<F>((U16)v.val[3]) * (1/65535.0f);
+#endif
             #else
+#if __BIG_ENDIAN__
+                U64 px = swap_endian_16x4(load<U64>(rgba));
+
+                r = cast<F>((px >> 48) & 0xffff) * (1/65535.0f);
+                g = cast<F>((px >> 32) & 0xffff) * (1/65535.0f);
+                b = cast<F>((px >> 16) & 0xffff) * (1/65535.0f);
+                a = cast<F>((px >>  0) & 0xffff) * (1/65535.0f);
+#else
                 U64 px = load<U64>(rgba);
 
                 r = cast<F>((px >>  0) & 0xffff) * (1/65535.0f);
                 g = cast<F>((px >> 16) & 0xffff) * (1/65535.0f);
                 b = cast<F>((px >> 32) & 0xffff) * (1/65535.0f);
                 a = cast<F>((px >> 48) & 0xffff) * (1/65535.0f);
+#endif
             #endif
             } break;
 
@@ -763,10 +820,21 @@ static void exec_ops(const Op* ops, const void** args,
                 const uint16_t* rgb = (const uint16_t*)ptr; // cast to const uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x3_t v = vld3_u16(rgb);
+#if __BIG_ENDIAN__
+                r = cast<F>((U16)v.val[0]) * (1/65535.0f);
+                g = cast<F>((U16)v.val[1]) * (1/65535.0f);
+                b = cast<F>((U16)v.val[2]) * (1/65535.0f);
+#else
                 r = cast<F>(swap_endian_16((U16)v.val[0])) * (1/65535.0f);
                 g = cast<F>(swap_endian_16((U16)v.val[1])) * (1/65535.0f);
                 b = cast<F>(swap_endian_16((U16)v.val[2])) * (1/65535.0f);
+#endif
             #else
+#if __BIG_ENDIAN__
+                r = cast<F>(load_3<U32>(rgb+0)) * (1/65535.0f);
+                g = cast<F>(load_3<U32>(rgb+1)) * (1/65535.0f);
+                b = cast<F>(load_3<U32>(rgb+2)) * (1/65535.0f);
+#else
                 U32 R = load_3<U32>(rgb+0),
                     G = load_3<U32>(rgb+1),
                     B = load_3<U32>(rgb+2);
@@ -774,6 +842,7 @@ static void exec_ops(const Op* ops, const void** args,
                 r = cast<F>((R & 0x00ff)<<8 | (R & 0xff00)>>8) * (1/65535.0f);
                 g = cast<F>((G & 0x00ff)<<8 | (G & 0xff00)>>8) * (1/65535.0f);
                 b = cast<F>((B & 0x00ff)<<8 | (B & 0xff00)>>8) * (1/65535.0f);
+#endif
             #endif
             } break;
 
@@ -783,17 +852,33 @@ static void exec_ops(const Op* ops, const void** args,
                 const uint16_t* rgba = (const uint16_t*)ptr; // cast to const uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x4_t v = vld4_u16(rgba);
+#if __BIG_ENDIAN__
+                r = cast<F>((U16)v.val[0]) * (1/65535.0f);
+                g = cast<F>((U16)v.val[1]) * (1/65535.0f);
+                b = cast<F>((U16)v.val[2]) * (1/65535.0f);
+                a = cast<F>((U16)v.val[3]) * (1/65535.0f);
+#else
                 r = cast<F>(swap_endian_16((U16)v.val[0])) * (1/65535.0f);
                 g = cast<F>(swap_endian_16((U16)v.val[1])) * (1/65535.0f);
                 b = cast<F>(swap_endian_16((U16)v.val[2])) * (1/65535.0f);
                 a = cast<F>(swap_endian_16((U16)v.val[3])) * (1/65535.0f);
+#endif
             #else
+#if __BIG_ENDIAN__
+                U64 px = load<U64>(rgba);
+
+                r = cast<F>((px >> 48) & 0xffff) * (1/65535.0f);
+                g = cast<F>((px >> 32) & 0xffff) * (1/65535.0f);
+                b = cast<F>((px >> 16) & 0xffff) * (1/65535.0f);
+                a = cast<F>((px >>  0) & 0xffff) * (1/65535.0f);
+#else
                 U64 px = swap_endian_16x4(load<U64>(rgba));
 
                 r = cast<F>((px >>  0) & 0xffff) * (1/65535.0f);
                 g = cast<F>((px >> 16) & 0xffff) * (1/65535.0f);
                 b = cast<F>((px >> 32) & 0xffff) * (1/65535.0f);
                 a = cast<F>((px >> 48) & 0xffff) * (1/65535.0f);
+#endif
             #endif
             } break;
 
@@ -828,10 +913,17 @@ static void exec_ops(const Op* ops, const void** args,
                     A = (U16)v.val[3];
             #else
                 U64 px = load<U64>(rgba);
+#if __BIG_ENDIAN__
+                U16 R = cast<U16>((px >> 48) & 0xffff),
+                    G = cast<U16>((px >> 32) & 0xffff),
+                    B = cast<U16>((px >> 16) & 0xffff),
+                    A = cast<U16>((px >>  0) & 0xffff);
+#else
                 U16 R = cast<U16>((px >>  0) & 0xffff),
                     G = cast<U16>((px >> 16) & 0xffff),
                     B = cast<U16>((px >> 32) & 0xffff),
                     A = cast<U16>((px >> 48) & 0xffff);
+#endif
             #endif
                 r = F_from_Half(R);
                 g = F_from_Half(G);
@@ -1024,10 +1116,17 @@ static void exec_ops(const Op* ops, const void** args,
             } return;
 
             case Op_store_8888: {
+#if __BIG_ENDIAN__
+                store(dst + 4*i, cast<U32>(to_fixed(r * 255) << 24)
+                               | cast<U32>(to_fixed(g * 255) << 16)
+                               | cast<U32>(to_fixed(b * 255) <<  8)
+                               | cast<U32>(to_fixed(a * 255) <<  0));
+#else
                 store(dst + 4*i, cast<U32>(to_fixed(r * 255) <<  0)
                                | cast<U32>(to_fixed(g * 255) <<  8)
                                | cast<U32>(to_fixed(b * 255) << 16)
                                | cast<U32>(to_fixed(a * 255) << 24));
+#endif
             } return;
 
             case Op_store_1010102: {
@@ -1043,15 +1142,30 @@ static void exec_ops(const Op* ops, const void** args,
                 uint16_t* rgb = (uint16_t*)ptr;          // for this cast to uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x3_t v = {{
+#if __BIG_ENDIAN__
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(r * 65535))),
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(g * 65535))),
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(b * 65535))),
+#else
                     (uint16x4_t)cast<U16>(to_fixed(r * 65535)),
                     (uint16x4_t)cast<U16>(to_fixed(g * 65535)),
                     (uint16x4_t)cast<U16>(to_fixed(b * 65535)),
+#endif
                 }};
                 vst3_u16(rgb, v);
             #else
+#if __BIG_ENDIAN__
+                I32 R = to_fixed(r * 65535),
+                    G = to_fixed(g * 65535),
+                    B = to_fixed(b * 65535);
+                store_3(rgb+0, cast<U16>((R & 0x00ff) << 8 | (R & 0xff00) >> 8) );
+                store_3(rgb+1, cast<U16>((G & 0x00ff) << 8 | (G & 0xff00) >> 8) );
+                store_3(rgb+2, cast<U16>((B & 0x00ff) << 8 | (B & 0xff00) >> 8) );
+#else
                 store_3(rgb+0, cast<U16>(to_fixed(r * 65535)));
                 store_3(rgb+1, cast<U16>(to_fixed(g * 65535)));
                 store_3(rgb+2, cast<U16>(to_fixed(b * 65535)));
+#endif
             #endif
 
             } return;
@@ -1062,18 +1176,33 @@ static void exec_ops(const Op* ops, const void** args,
                 uint16_t* rgba = (uint16_t*)ptr;        // for this cast to uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x4_t v = {{
+#if __BIG_ENDIAN__
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(r * 65535))),
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(g * 65535))),
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(b * 65535))),
+                    (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(a * 65535))),
+#else
                     (uint16x4_t)cast<U16>(to_fixed(r * 65535)),
                     (uint16x4_t)cast<U16>(to_fixed(g * 65535)),
                     (uint16x4_t)cast<U16>(to_fixed(b * 65535)),
                     (uint16x4_t)cast<U16>(to_fixed(a * 65535)),
+#endif
                 }};
                 vst4_u16(rgba, v);
             #else
+#if __BIG_ENDIAN__
+                U64 px = cast<U64>(to_fixed(r * 65535)) << 48
+                       | cast<U64>(to_fixed(g * 65535)) << 32
+                       | cast<U64>(to_fixed(b * 65535)) << 16
+                       | cast<U64>(to_fixed(a * 65535)) <<  0;
+                store(rgba, swap_endian_16x4(px));
+#else
                 U64 px = cast<U64>(to_fixed(r * 65535)) <<  0
                        | cast<U64>(to_fixed(g * 65535)) << 16
                        | cast<U64>(to_fixed(b * 65535)) << 32
                        | cast<U64>(to_fixed(a * 65535)) << 48;
                 store(rgba, px);
+#endif
             #endif
             } return;
 
@@ -1083,18 +1212,30 @@ static void exec_ops(const Op* ops, const void** args,
                 uint16_t* rgb = (uint16_t*)ptr;          // for this cast to uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x3_t v = {{
+#if __BIG_ENDIAN__
+                    (uint16x4_t)cast<U16>(to_fixed(r * 65535)),
+                    (uint16x4_t)cast<U16>(to_fixed(g * 65535)),
+                    (uint16x4_t)cast<U16>(to_fixed(b * 65535)),
+#else
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(r * 65535))),
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(g * 65535))),
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(b * 65535))),
+#endif
                 }};
                 vst3_u16(rgb, v);
             #else
+#if __BIG_ENDIAN__
+                store_3(rgb+0, cast<U16>(to_fixed(r * 65535)));
+                store_3(rgb+1, cast<U16>(to_fixed(g * 65535)));
+                store_3(rgb+2, cast<U16>(to_fixed(b * 65535)));
+#else
                 I32 R = to_fixed(r * 65535),
                     G = to_fixed(g * 65535),
                     B = to_fixed(b * 65535);
                 store_3(rgb+0, cast<U16>((R & 0x00ff) << 8 | (R & 0xff00) >> 8) );
                 store_3(rgb+1, cast<U16>((G & 0x00ff) << 8 | (G & 0xff00) >> 8) );
                 store_3(rgb+2, cast<U16>((B & 0x00ff) << 8 | (B & 0xff00) >> 8) );
+#endif
             #endif
 
             } return;
@@ -1105,18 +1246,33 @@ static void exec_ops(const Op* ops, const void** args,
                 uint16_t* rgba = (uint16_t*)ptr;        // for this cast to uint16_t* to be safe.
             #if defined(USING_NEON)
                 uint16x4x4_t v = {{
+#if __BIG_ENDIAN__
+                    (uint16x4_t)cast<U16>(to_fixed(r * 65535)),
+                    (uint16x4_t)cast<U16>(to_fixed(g * 65535)),
+                    (uint16x4_t)cast<U16>(to_fixed(b * 65535)),
+                    (uint16x4_t)cast<U16>(to_fixed(a * 65535)),
+#else
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(r * 65535))),
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(g * 65535))),
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(b * 65535))),
                     (uint16x4_t)swap_endian_16(cast<U16>(to_fixed(a * 65535))),
+#endif
                 }};
                 vst4_u16(rgba, v);
             #else
+#if __BIG_ENDIAN__
+                U64 px = cast<U64>(to_fixed(r * 65535)) << 48
+                       | cast<U64>(to_fixed(g * 65535)) << 32
+                       | cast<U64>(to_fixed(b * 65535)) << 16
+                       | cast<U64>(to_fixed(a * 65535)) <<  0;
+                store(rgba, px);
+#else
                 U64 px = cast<U64>(to_fixed(r * 65535)) <<  0
                        | cast<U64>(to_fixed(g * 65535)) << 16
                        | cast<U64>(to_fixed(b * 65535)) << 32
                        | cast<U64>(to_fixed(a * 65535)) << 48;
                 store(rgba, swap_endian_16x4(px));
+#endif
             #endif
             } return;
 
@@ -1160,10 +1316,17 @@ static void exec_ops(const Op* ops, const void** args,
                 }};
                 vst4_u16(rgba, v);
             #else
+#if __BIG_ENDIAN__
+                store(rgba, cast<U64>(R) << 48
+                          | cast<U64>(G) << 32
+                          | cast<U64>(B) << 16
+                          | cast<U64>(A) <<  0);
+#else
                 store(rgba, cast<U64>(R) <<  0
                           | cast<U64>(G) << 16
                           | cast<U64>(B) << 32
                           | cast<U64>(A) << 48);
+#endif
             #endif
 
             } return;
