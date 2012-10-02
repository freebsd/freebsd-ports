--- sandbox/sandbox.gyp.orig	2012-10-01 21:30:17.000000000 +0300
+++ sandbox/sandbox.gyp	2012-10-01 21:30:25.000000000 +0300
@@ -12,12 +12,12 @@
         'win/sandbox_win.gypi',
       ],
     }],
-    [ 'OS=="linux"', {
+    [ 'OS=="linux" or OS=="freebsd"', {
       'includes': [
         'linux/sandbox_linux.gypi',
       ],
     }],
-    [ 'OS!="win" and OS!="mac" and OS!="linux"', {
+    [ 'OS!="win" and OS!="mac" and OS!="linux" and OS!="freebsd"', {
       # We need a 'default' to accomodate the "sandbox" target, for instance
       # on Android.
       'targets': [
