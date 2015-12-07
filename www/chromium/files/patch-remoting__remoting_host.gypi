--- remoting/remoting_host.gypi.orig	2015-10-14 03:01:21.000000000 -0400
+++ remoting/remoting_host.gypi	2015-10-23 13:56:18.229194000 -0400
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
@@ -331,7 +331,7 @@
             'host/setup/start_host.cc',
           ],
           'conditions': [
-            ['OS=="linux" and use_allocator!="none"', {
+            ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
               'dependencies': [
                 '../base/allocator/allocator.gyp:allocator',
               ],
@@ -549,7 +549,7 @@
                 }],  # mac_breakpad==1
               ],  # conditions
             }],  # OS=mac
-            ['OS=="linux" and use_allocator!="none"', {
+            ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
               'dependencies': [
                 '../base/allocator/allocator.gyp:allocator',
               ],
@@ -671,13 +671,13 @@
                 'host/it2me/it2me_native_messaging_host_main.h',
               ],
               'conditions': [
-                ['OS=="linux" and chromeos==0 and use_ozone==0', {
+                ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_ozone==0', {
                   'dependencies': [
                     # Always use GTK on Linux, even for Aura builds.
                     '../build/linux/system.gyp:gtk2',
                   ],
                 }],
-                ['OS=="linux" and use_allocator!="none"', {
+                ['(OS=="linux" or os_bsd==1) and use_allocator!="none"', {
                   'dependencies': [
                     '../base/allocator/allocator.gyp:allocator',
                   ],
