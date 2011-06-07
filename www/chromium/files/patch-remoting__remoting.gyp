--- remoting/remoting.gyp.orig	2011-05-06 12:02:51.000000000 +0300
+++ remoting/remoting.gyp	2011-06-05 16:03:32.069163399 +0300
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
@@ -238,7 +240,7 @@
         'host/user_authenticator_win.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
           'dependencies': [
             '../build/linux/system.gyp:gtk',
           ],
@@ -555,7 +557,7 @@
         'run_all_unittests.cc',
       ],
       'conditions': [
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd" or OS=="openbsd"', {
           'dependencies': [
             '../app/app.gyp:app_base',
             # Needed for the following #include chain:
