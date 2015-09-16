--- third_party/WebKit/Source/core/core.gyp.orig	2015-05-13 18:48:59.000000000 -0400
+++ third_party/WebKit/Source/core/core.gyp	2015-05-20 17:42:49.101788000 -0400
@@ -505,13 +505,13 @@
           # Due to a bug in gcc 4.6 in android NDK, we get warnings about uninitialized variable.
           'cflags': ['-Wno-uninitialized'],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources!': [
             'layout/LayoutThemeLinux.cpp',
             'layout/LayoutThemeLinux.h',
           ],
         }],
-        ['OS != "linux" and OS != "android"', {
+        ['OS != "linux" and OS != "android" and os_bsd != 1', {
           'sources!': [
             'layout/LayoutThemeFontProviderLinux.cpp',
           ],
@@ -617,7 +617,7 @@
         ],
       },
       'conditions': [
-        ['OS=="linux" and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
+        ['(OS=="linux" or os_bsd==1) and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
           'link_settings': {
             'ldflags': [
               '<!@(pkg-config --libs-only-L ipp)',
@@ -812,7 +812,7 @@
               # Due to a bug in gcc 4.6 in android NDK, we get warnings about uninitialized variable.
               'cflags': ['-Wno-uninitialized'],
             }],
-            ['OS != "linux"', {
+            ['OS != "linux" and os_bsd != 1', {
               'sources!': [
                 'layout/LayoutThemeLinux.cpp',
                 'layout/LayoutThemeLinux.h',
@@ -837,7 +837,7 @@
             }],
           ],
         }],
-        ['OS=="linux" and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
+        ['(OS=="linux" or os_bsd==1) and "WTF_USE_WEBAUDIO_IPP=1" in feature_defines', {
           'link_settings': {
             'ldflags': [
               '<!@(pkg-config --libs-only-L ipp)',
