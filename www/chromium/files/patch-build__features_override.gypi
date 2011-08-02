--- build/features_override.gypi.orig	2011-06-24 11:30:52.000000000 +0300
+++ build/features_override.gypi	2011-06-26 17:35:55.815781753 +0300
@@ -110,7 +110,7 @@
       # TODO(crogers): For the moment Windows is only enabled for
       # Google-branded build, since the FFmpeg DLLs need to be re-built
       # for chromium.
-      ['OS=="mac" or OS=="linux" or (OS=="win" and branding=="Chrome")', {
+      ['OS=="mac" or OS=="linux" or OS=="freebsd" or (OS=="win" and branding=="Chrome")', {
         'feature_defines': [
           'ENABLE_WEB_AUDIO=1',
         ],
