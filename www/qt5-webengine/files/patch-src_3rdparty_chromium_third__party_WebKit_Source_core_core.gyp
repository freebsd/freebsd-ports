--- src/3rdparty/chromium/third_party/WebKit/Source/core/core.gyp.orig	2016-11-07 14:46:18 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/core/core.gyp
@@ -458,13 +458,13 @@
             'layout/LayoutThemeMac.mm',
           ],
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
@@ -785,13 +785,13 @@
                 'layout/LayoutThemeMac.mm',
               ],
             }],
-            ['OS != "linux"', {
+            ['OS != "linux" and os_bsd != 1', {
               'sources!': [
                 'layout/LayoutThemeLinux.cpp',
                 'layout/LayoutThemeLinux.h',
               ],
             }],
-            ['OS != "linux" and OS != "android"', {
+            ['OS != "linux" and OS != "android" and os_bsd == 1', {
               'sources!': [
                 'layout/LayoutThemeFontProviderLinux.cpp',
               ],
