--- remoting/remoting_host.gypi.orig	2015-01-21 20:28:17 UTC
+++ remoting/remoting_host.gypi
@@ -12,7 +12,7 @@
   'variables': {
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux (with X11).
-      ['OS=="win" or OS=="mac" or (OS=="linux" and use_x11==1)', {
+      ['OS=="win" or OS=="mac" or ((OS=="linux" or os_bsd==1) and use_x11==1)', {
         'enable_me2me_host': 1,
         'enable_it2me_host': 1,
         'enable_remoting_host': 1,
@@ -317,7 +317,7 @@
                 ],
               },
             }],
-            ['OS=="linux" and chromeos==0 and use_ozone==0', {
+            ['((OS=="linux" and chromeos==0) or os_bsd==1) and use_ozone==0', {
               'dependencies' : [
                 # Always use GTK on Linux, even for Aura builds.
                 '../build/linux/system.gyp:gtk',
@@ -910,7 +910,7 @@
             'host/it2me/it2me_native_messaging_host_main.h',
           ],
           'conditions': [
-            ['OS=="linux" and chromeos==0 and use_ozone==0', {
+            ['((OS=="linux" and chromeos==0) or os_bsd==1) and use_ozone==0', {
               'dependencies': [
                 # Always use GTK on Linux, even for Aura builds.
                 '../build/linux/system.gyp:gtk',
