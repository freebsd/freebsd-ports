--- cargo-crates/rusty_v8-0.32.0/build/linux/unbundle/replace_gn_files.py.orig	2020-06-26 16:27:54 UTC
+++ cargo-crates/rusty_v8-0.32.0/build/linux/unbundle/replace_gn_files.py
@@ -27,6 +27,7 @@ REPLACEMENTS = {
   'libevent': 'base/third_party/libevent/BUILD.gn',
   'libjpeg': 'third_party/libjpeg.gni',
   'libpng': 'third_party/libpng/BUILD.gn',
+  'libusb': 'third_party/libusb/BUILD.gn',
   'libvpx': 'third_party/libvpx/BUILD.gn',
   'libwebp': 'third_party/libwebp/BUILD.gn',
   'libxml': 'third_party/libxml/BUILD.gn',
