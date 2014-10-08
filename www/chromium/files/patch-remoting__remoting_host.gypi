--- remoting/remoting_host.gypi.orig	2014-10-02 17:39:48 UTC
+++ remoting/remoting_host.gypi
@@ -12,7 +12,7 @@
   'variables': {
     'conditions': [
       # Remoting host is supported only on Windows, OSX and Linux (with X11).
-      ['OS=="win" or OS=="mac" or (OS=="linux" and chromeos==0 and use_x11==1)', {
+      ['OS=="win" or OS=="mac" or os_bsd==1 or (OS=="linux" and chromeos==0 and use_x11==1)', {
         'enable_remoting_host': 1,
       }, {
         'enable_remoting_host': 0,
@@ -285,7 +285,7 @@
             'host/win/wts_terminal_observer.h',
           ],
           'conditions': [
-            ['OS=="linux"', {
+            ['OS=="linux" or os_bsd==1', {
               'dependencies': [
                 # Always use GTK on Linux, even for Aura builds.
                 '../build/linux/system.gyp:gtk',
