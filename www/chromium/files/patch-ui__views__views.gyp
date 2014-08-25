--- ./ui/views/views.gyp.orig	2014-08-20 21:02:18.000000000 +0200
+++ ./ui/views/views.gyp	2014-08-22 15:06:27.000000000 +0200
@@ -490,7 +490,7 @@
             '../display/display.gyp:display_util',
           ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd==1) and chromeos==0', {
           'dependencies': [
             '../shell_dialogs/shell_dialogs.gyp:shell_dialogs',
           ],
