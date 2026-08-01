Fix compile error with newer clang

src/transcoding/codec/codecs/libs/vaapi.c:819:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
  819 |                 .def.dyn_i= tvh_codec_profile_vaapi_h264_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:829:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
  829 |                 .def.dyn_i= tvh_codec_profile_vaapi_h264lp_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1132:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1132 |                 .def.dyn_i= tvh_codec_profile_vaapi_hevc_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1142:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1142 |                 .def.dyn_i= tvh_codec_profile_vaapi_hevclp_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1439:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1439 |                 .def.dyn_i= tvh_codec_profile_vaapi_vp8_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1449:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1449 |                 .def.dyn_i= tvh_codec_profile_vaapi_vp8lp_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1766:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1766 |                 .def.dyn_i= tvh_codec_profile_vaapi_vp9_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
src/transcoding/codec/codecs/libs/vaapi.c:1776:29: error: incompatible function pointer types initializing 'int (*)(void)' with an expression of type 'const int (void)' [-Wincompatible-function-pointer-types]
 1776 |                 .def.dyn_i= tvh_codec_profile_vaapi_vp9lp_ui,
      |                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
8 errors generated.

--- src/transcoding/codec/codecs/libs/vaapi.c.orig	2026-05-19 20:37:17 UTC
+++ src/transcoding/codec/codecs/libs/vaapi.c
@@ -275,7 +275,7 @@ tvh_codec_profile_vaapi_device_list(void *obj, const c
 }
 
 #define TVH_CODEC_PROFILE_VAAPI_CODEC_UI(codec_ui, codec_name) \
-    static const int tvh_codec_profile_vaapi_##codec_ui##_ui(void) \
+    static int tvh_codec_profile_vaapi_##codec_ui##_ui(void) \
     { \
         return TVH_CODEC_PROFILE_VAAPI_UI(codec_name); \
     }
