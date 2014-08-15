--- ./ui/views/views.gyp.orig	2014-08-12 21:02:26.000000000 +0200
+++ ./ui/views/views.gyp	2014-08-13 09:57:00.000000000 +0200
@@ -461,7 +461,7 @@
             '../display/display.gyp:display_util',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd==1) and chromeos==0', {
           'dependencies': [
             '../shell_dialogs/shell_dialogs.gyp:shell_dialogs',
           ],
