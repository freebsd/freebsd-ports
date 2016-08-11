--- remoting/remoting_host.gypi.orig	2016-05-11 19:02:25 UTC
+++ remoting/remoting_host.gypi
@@ -18,7 +18,7 @@
         'remoting_host_win.gypi',
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'includes': [
         'remoting_host_linux.gypi',
       ],
@@ -57,7 +57,7 @@
             '<@(remoting_host_sources)',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'conditions': [
                 ['use_x11==1', {
                   'dependencies': [
@@ -652,7 +652,7 @@
                 'host/it2me/it2me_native_messaging_host_main.h',
               ],
               'conditions': [
-                ['OS=="linux" and chromeos==0 and use_ozone==0', {
+                ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_ozone==0', {
                   'dependencies': [
                     # Always use GTK on Linux, even for Aura builds.
                     '../build/linux/system.gyp:gtk2',
