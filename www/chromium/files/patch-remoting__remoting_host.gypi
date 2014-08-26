--- ./remoting/remoting_host.gypi.orig	2014-08-20 21:02:52.000000000 +0200
+++ ./remoting/remoting_host.gypi	2014-08-22 15:06:26.000000000 +0200
@@ -12,7 +12,7 @@
   'variables': {
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux (with X11).
-      ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0 and use_x11==1)', {
+      ['OS=="win" or OS=="mac" or os_bsd==1 or (OS=="linux" and chromeos==0 and use_x11==1)', {
         'enable_remoting_host': 1,
       }, {
         'enable_remoting_host': 0,
@@ -270,7 +270,7 @@
             'host/win/wts_terminal_observer.h',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'dependencies': [
                 # Always use GTK on Linux, even for Aura builds.
                 '../build/linux/system.gyp:gtk',
