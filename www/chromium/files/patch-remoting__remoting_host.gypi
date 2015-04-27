--- remoting/remoting_host.gypi.orig	2015-04-19 16:56:09.000000000 +0200
+++ remoting/remoting_host.gypi	2015-04-19 16:55:50.000000000 +0200
@@ -18,7 +18,7 @@
         'remoting_host_win.gypi',
       ],
     }],
-    ['OS=="linux"', {
+    ['OS=="linux" or os_bsd==1', {
       'includes': [
         'remoting_host_linux.gypi',
       ],
@@ -56,7 +56,7 @@
             '<@(remoting_host_sources)',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'conditions': [
                 ['use_x11==1', {
                   'dependencies': [
@@ -535,7 +535,7 @@
                 }],  # mac_breakpad==1
               ],  # conditions
             }],  # OS=mac
-            ['OS=="linux" and use_allocator!="none"', {
+            ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
               'dependencies': [
                 '../base/allocator/allocator.gyp:allocator',
               ],
@@ -657,13 +657,13 @@
                 'host/it2me/it2me_native_messaging_host_main.h',
               ],
               'conditions': [
-                ['OS=="linux" and chromeos==0 and use_ozone==0', {
+                ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_ozone==0', {
                   'dependencies': [
                     # Always use GTK on Linux, even for Aura builds.
                     '../build/linux/system.gyp:gtk',
                   ],
                 }],
-                ['OS=="linux" and use_allocator!="none"', {
+                ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
                   'dependencies': [
                     '../base/allocator/allocator.gyp:allocator',
                   ],
