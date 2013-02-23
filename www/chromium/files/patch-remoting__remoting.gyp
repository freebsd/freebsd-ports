--- remoting/remoting.gyp.orig	2013-02-13 20:16:24.000000000 +0200
+++ remoting/remoting.gyp	2013-02-13 23:31:43.000000000 +0200
@@ -44,7 +44,7 @@
 
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux.
-      ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0)', {
+      ['OS=="win" or OS=="mac" or OS=="freebsd" or (OS=="linux" and chromeos==0)', {
         'enable_remoting_host': 1,
       }, {
         'enable_remoting_host': 0,
@@ -445,7 +445,7 @@
             'host/win/window_station_and_desktop.h',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or OS=="freebsd"', {
               'link_settings': {
                 'libraries': [
                   '-lX11',
