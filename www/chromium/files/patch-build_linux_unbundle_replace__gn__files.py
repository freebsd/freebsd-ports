--- build/linux/unbundle/replace_gn_files.py.orig	2022-08-31 12:19:35 UTC
+++ build/linux/unbundle/replace_gn_files.py
@@ -52,6 +52,7 @@ REPLACEMENTS = {
   'libjpeg': 'third_party/libjpeg.gni',
   'libjxl' : 'third_party/libjxl/BUILD.gn',
   'libpng': 'third_party/libpng/BUILD.gn',
+  'libusb': 'third_party/libusb/BUILD.gn',
   'libvpx': 'third_party/libvpx/BUILD.gn',
   'libwebp': 'third_party/libwebp/BUILD.gn',
   'libxml': 'third_party/libxml/BUILD.gn',
