--- src/3rdparty/chromium/build/linux/unbundle/replace_gn_files.py.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/build/linux/unbundle/replace_gn_files.py
@@ -25,6 +25,7 @@ REPLACEMENTS = {
   'libevent': 'base/third_party/libevent/BUILD.gn',
   'libjpeg': 'third_party/libjpeg.gni',
   'libpng': 'third_party/libpng/BUILD.gn',
+  'libusb': 'third_party/libusb/BUILD.gn',
   'libvpx': 'third_party/libvpx/BUILD.gn',
   'libwebp': 'third_party/libwebp/BUILD.gn',
   'libxml': 'third_party/libxml/BUILD.gn',
