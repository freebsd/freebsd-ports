--- third_party/ffmpeg/chromium/scripts/generate_gn.py.orig	2017-09-06 23:01:27.764648000 +0200
+++ third_party/ffmpeg/chromium/scripts/generate_gn.py	2017-09-06 23:06:22.774520000 +0200
@@ -54,7 +54,7 @@
 ffmpeg_gas_sources = []
 ffmpeg_yasm_sources = []
 
-use_linux_config = is_linux || is_fuchsia
+use_linux_config = is_linux || is_fuchsia || is_bsd
 
 """
 GN_CONDITION_BEGIN = """if (%s) {
