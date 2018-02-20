--- build/linux/unbundle/replace_gn_files.py.orig	2017-12-29 23:33:23.502737000 +0100
+++ build/linux/unbundle/replace_gn_files.py	2017-12-29 23:34:06.066488000 +0100
@@ -19,7 +19,7 @@
 REPLACEMENTS = {
   'ffmpeg': 'third_party/ffmpeg/BUILD.gn',
   'flac': 'third_party/flac/BUILD.gn',
-  'freetype': 'third_party/freetype/BUILD.gn',
+  'freetype': 'build/config/freetype/freetype.gni',
   'harfbuzz-ng': 'third_party/harfbuzz-ng/BUILD.gn',
   'icu': 'third_party/icu/BUILD.gn',
   'libdrm': 'third_party/libdrm/BUILD.gn',
