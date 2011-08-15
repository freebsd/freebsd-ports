--- skia/skia.gyp.orig	2011-08-06 10:01:12.000000000 +0200
+++ skia/skia.gyp	2011-08-14 23:28:45.000000000 +0200
@@ -752,7 +752,7 @@
             '../third_party/skia/src/opts/opts_check_SSE2.cpp'
           ],
         }],
-        ['clang==1', {
+        ['OS=="freebsd"', {
           'defines': [
             # Remove all use of __restrict__ -- skia uses it incorrectly,
             # and clang is more strict about it.
