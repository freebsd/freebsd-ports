--- ./remoting/remoting.gyp.orig	2010-12-13 12:03:06.000000000 +0100
+++ ./remoting/remoting.gyp	2011-01-07 14:17:11.000000000 +0100
@@ -16,7 +16,7 @@
   },
 
   'conditions': [
-    ['OS=="linux" or OS=="mac"', {
+    ['OS=="linux" or OS=="freebsd" or OS=="mac"', {
       'targets': [
         # Simple webserver for testing chromoting client plugin.
         {
@@ -40,6 +40,8 @@
             'chromoting_base',
             'chromoting_client',
             'chromoting_jingle_glue',
+	    '../build/linux/system.gyp:x11',
+	    '../build/linux/system.gyp:xext',
           ],
           'link_settings': {
             'libraries': [
@@ -221,7 +223,11 @@
             'host/event_executor_win.h',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
+          'dependencies': [
+	    '../build/linux/system.gyp:x11',
+	    '../build/linux/system.gyp:xext',
+          ],
           'sources': [
             'host/capturer_linux.cc',
             'host/capturer_linux.h',
@@ -497,7 +503,7 @@
             'host/capturer_gdi_unittest.cc',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             # Needed for the following #include chain:
             #   base/run_all_unittests.cc
