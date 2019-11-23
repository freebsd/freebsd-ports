--- src/3rdparty/chromium/third_party/skia/third_party/skcms/skcms.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/third_party/skcms/skcms.cc
@@ -66,10 +66,15 @@ static float eval_curve(const skcms_Curve* curve, floa
         uint16_t be_l, be_h;
         memcpy(&be_l, curve->table_16 + 2*lo, 2);
         memcpy(&be_h, curve->table_16 + 2*hi, 2);
+#if __BIG_ENDIAN__
+        l = be_l * (1/65535.0f);
+        h = be_h * (1/65535.0f);
+#else
         uint16_t le_l = ((be_l << 8) | (be_l >> 8)) & 0xffff;
         uint16_t le_h = ((be_h << 8) | (be_h >> 8)) & 0xffff;
         l = le_l * (1/65535.0f);
         h = le_h * (1/65535.0f);
+#endif
     }
     return l + (h-l)*t;
 }
@@ -124,20 +129,28 @@ enum {
 static uint16_t read_big_u16(const uint8_t* ptr) {
     uint16_t be;
     memcpy(&be, ptr, sizeof(be));
+#if __BIG_ENDIAN__
+    return be;
+#else
 #if defined(_MSC_VER)
     return _byteswap_ushort(be);
 #else
     return __builtin_bswap16(be);
 #endif
+#endif
 }
 
 static uint32_t read_big_u32(const uint8_t* ptr) {
     uint32_t be;
     memcpy(&be, ptr, sizeof(be));
+#if __BIG_ENDIAN__
+    return be;
+#else
 #if defined(_MSC_VER)
     return _byteswap_ulong(be);
 #else
     return __builtin_bswap32(be);
+#endif
 #endif
 }
 
