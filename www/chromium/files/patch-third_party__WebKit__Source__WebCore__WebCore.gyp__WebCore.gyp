--- third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp.orig	2011-07-19 20:25:57.839631432 +0300
+++ third_party/WebKit/Source/WebCore/WebCore.gyp/WebCore.gyp	2011-07-19 20:26:53.497910347 +0300
@@ -986,7 +986,7 @@
             'include_dirs+++': ['../dom'],
           },
         }],
-        ['(OS=="linux" or OS=="win") and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
+        ['(OS=="linux" or OS=="freebsd" or OS=="win") and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
           'include_dirs': [
             '<(chromium_src_dir)/third_party/fftw/api',
           ],
@@ -1194,7 +1194,7 @@
             'include_dirs++': ['../dom'],
           },
         }],
-        ['(OS=="linux" or OS=="win") and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
+        ['(OS=="linux" or OS=="freebsd" or OS=="win") and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
           # This directory needs to be on the include path for multiple sub-targets of webcore.
           'direct_dependent_settings': {
             'include_dirs': [
@@ -1202,7 +1202,7 @@
             ],
           },
         }],
-        ['(OS=="mac" or OS=="linux" or OS=="win") and "WTF_USE_WEBAUDIO_FFMPEG=1" in feature_defines', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd" or OS=="win") and "WTF_USE_WEBAUDIO_FFMPEG=1" in feature_defines', {
           # This directory needs to be on the include path for multiple sub-targets of webcore.
           'direct_dependent_settings': {
             'include_dirs': [
@@ -1708,7 +1708,7 @@
             'include_dirs+++': ['../dom'],
           },
         }],
-        ['OS=="linux" and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
+        ['OS=="linux" or OS=="freebsd" and "WTF_USE_WEBAUDIO_FFTW=1" in feature_defines', {
           # FIXME: (kbr) figure out how to make these dependencies
           # work in a cross-platform way. Attempts to use
           # "link_settings" and "libraries" in conjunction with the
