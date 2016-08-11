--- third_party/WebKit/Source/core/core.gyp.orig	2016-05-11 19:02:30 UTC
+++ third_party/WebKit/Source/core/core.gyp
@@ -367,7 +367,7 @@
             'layout/LayoutThemeMac.mm',
           ],
         }],
-        ['OS != "linux"', {
+        ['OS != "linux" and os_bsd != 1', {
           'sources!': [
             'layout/LayoutThemeLinux.cpp',
             'layout/LayoutThemeLinux.h',
@@ -644,7 +644,7 @@
                 'layout/LayoutThemeMac.mm',
               ],
             }],
-            ['OS != "linux"', {
+            ['OS != "linux" and OS != "openbsd" and OS != "freebsd"', {
               'sources!': [
                 'layout/LayoutThemeLinux.cpp',
                 'layout/LayoutThemeLinux.h',
