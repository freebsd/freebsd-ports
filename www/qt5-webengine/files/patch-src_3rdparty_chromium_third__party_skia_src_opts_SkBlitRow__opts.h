--- src/3rdparty/chromium/third_party/skia/src/opts/SkBlitRow_opts.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/skia/src/opts/SkBlitRow_opts.h
@@ -237,8 +237,8 @@ void blit_row_s32a_opaque(SkPMColor* dst, const SkPMCo
         // with chromium:611002 we need to keep it until we figure out where
         // the non-premultiplied src values (like 0x00FFFFFF) are coming from.
         // TODO(mtklein): sort this out and assert *src is premul here.
-        if (*src & 0xFF000000) {
-            *dst = (*src >= 0xFF000000) ? *src : SkPMSrcOver(*src, *dst);
+        if (*src & (0xFF << SK_A32_SHIFT)) {
+            *dst = ((*src << (24 - SK_A32_SHIFT)) >= 0xFF000000) ? *src : SkPMSrcOver(*src, *dst);
         }
         src++;
         dst++;
