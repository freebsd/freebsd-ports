--- third_party/ffmpeg/ffmpeg_generated.gypi.orig	2015-09-04 18:08:57.318433000 -0400
+++ third_party/ffmpeg/ffmpeg_generated.gypi	2015-09-08 12:00:45.690486000 -0400
@@ -138,7 +138,7 @@
           'libavcodec/x86/flacdsp.asm',
         ],
       }],  # (OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "ChromeOS") or (OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "ChromiumOS") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "ChromeOS") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "ChromiumOS")
-      ['(OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "Chrome") or (OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "ChromeOS") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "Chrome") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "ChromeOS") or (OS == "mac" and ffmpeg_branding == "Chrome") or (OS == "win" and ffmpeg_branding == "Chrome")', {
+      ['(OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "Chrome") or (OS == "linux" and target_arch == "ia32" and ffmpeg_branding == "ChromeOS") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "Chrome") or (OS == "linux" and target_arch == "x64" and ffmpeg_branding == "ChromeOS") or (OS == "mac" and ffmpeg_branding == "Chrome") or (OS == "win" and ffmpeg_branding == "Chrome") or (os_bsd==1 and ffmpeg_branding == "Chrome")', {
         'c_sources': [
           'libavcodec/x86/dct_init.c',
           'libavcodec/x86/h264_qpel.c',
@@ -301,7 +301,7 @@
           'libavutil/arm/autorename_libavutil_arm_float_dsp_neon.S',
         ],
       }],  # (OS == "android" and target_arch == "arm") or (OS == "linux" and target_arch == "arm" and arm_neon == 1)
-      ['(OS == "linux" and target_arch == "ia32") or (OS == "linux" and target_arch == "x64") or (OS == "mac") or (OS == "win")', {
+      ['(OS == "linux" and target_arch == "ia32") or (OS == "linux" and target_arch == "x64") or (OS == "mac") or (OS == "win") or (os_bsd==1)', {
         'c_sources': [
           'libavcodec/x86/autorename_libavcodec_x86_videodsp_init.c',
           'libavcodec/x86/autorename_libavcodec_x86_vorbisdsp_init.c',
@@ -376,7 +376,7 @@
           'libavutil/arm/float_dsp_vfp.S',
         ],
       }],  # (OS == "android" and target_arch == "arm") or (OS == "linux" and target_arch == "arm" and arm_neon == 1) or (OS == "linux" and target_arch == "arm")
-      ['(OS == "linux" and ffmpeg_branding == "Chrome") or (OS == "linux" and ffmpeg_branding == "ChromeOS") or (OS == "mac" and ffmpeg_branding == "Chrome") or (OS == "win" and ffmpeg_branding == "Chrome")', {
+      ['((OS == "linux" or os_bsd==1) and ffmpeg_branding == "Chrome") or (OS == "linux" and ffmpeg_branding == "ChromeOS") or (OS == "mac" and ffmpeg_branding == "Chrome") or (OS == "win" and ffmpeg_branding == "Chrome")', {
         'c_sources': [
           'libavcodec/cabac.c',
           'libavcodec/h264.c',
@@ -437,7 +437,7 @@
           'libavformat/rawdec.c',
         ],
       }],  # (OS == "linux" and ffmpeg_branding == "ChromeOS") or (OS == "linux" and ffmpeg_branding == "ChromiumOS") or (ffmpeg_branding == "Chrome")
-      ['(OS == "linux") or (OS == "mac") or (OS == "win")', {
+      ['(OS == "linux") or (OS == "mac") or (OS == "win") or (os_bsd==1)', {
         'c_sources': [
           'libavcodec/h264pred.c',
           'libavcodec/hpeldsp.c',
