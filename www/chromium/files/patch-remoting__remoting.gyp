--- remoting/remoting.gyp.orig	2013-04-30 10:22:16.000000000 +0300
+++ remoting/remoting.gyp	2013-05-07 21:24:08.000000000 +0300
@@ -56,7 +56,7 @@
 
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux (with X11).
-      ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0 and use_x11==1)', {
+      ['OS=="win" or OS=="mac" or OS=="freebsd" or (OS=="linux" and chromeos==0 and use_x11==1)', {
         'enable_remoting_host': 1,
       }, {
         'enable_remoting_host': 0,
@@ -479,7 +479,7 @@
                 '*_gtk.cc',
               ],
             }],
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'link_settings': {
                 'libraries': [
                   '-lX11',
