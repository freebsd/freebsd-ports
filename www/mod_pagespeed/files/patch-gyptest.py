--- tools/gyp/gyptest.py.orig	2012-07-11 21:42:55.394188934 -0400
+++ tools/gyp/gyptest.py	2012-07-11 21:43:15.729199931 -0400
@@ -208,6 +208,8 @@
     format_list = {
       'freebsd7': ['make'],
       'freebsd8': ['make'],
+      'freebsd9': ['make'],
+      'freebsd10': ['make'],
       'cygwin':   ['msvs'],
       'win32':    ['msvs'],
       'linux2':   ['make', 'ninja'],
