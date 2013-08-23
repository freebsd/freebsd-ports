--- remoting/remoting.gyp.orig	2013-08-09 19:06:51.000000000 +0000
+++ remoting/remoting.gyp	2013-08-12 21:21:56.000000000 +0000
@@ -53,7 +53,7 @@
 
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux (with X11).
-      ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0 and use_x11==1)', {
+      ['OS=="win" or OS=="mac" or OS=="freebsd" or (OS=="linux" and chromeos==0 and use_x11==1)', {
         'enable_remoting_host': 1,
       }, {
         'enable_remoting_host': 0,
@@ -484,7 +484,7 @@
             'host/win/wts_terminal_observer.h',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'dependencies': [
                 # Always use GTK on Linux, even for Aura builds.
                 #
