--- ui/views/views.gyp.orig	2016-05-11 19:02:36 UTC
+++ ui/views/views.gyp
@@ -693,12 +693,12 @@
             '../display/display.gyp:display_util',
           ],
         }],
-        ['OS=="linux" and chromeos==0 and use_ozone==0', {
+        ['(OS=="linux" or os_bsd==1) and chromeos==0 and use_ozone==0', {
           'dependencies': [
             '../../build/linux/system.gyp:atk',
            ],
         }],
-        ['OS=="linux" and chromeos==0', {
+        ['(OS=="linux" or os_bsd==1) and chromeos==0', {
           'dependencies': [
             '../shell_dialogs/shell_dialogs.gyp:shell_dialogs',
           ],
@@ -767,7 +767,7 @@
         ['use_aura and chromeos == 0', {
           'sources': [ '<@(views_desktop_aura_sources)' ],
           'conditions': [
-            ['OS == "linux"', {
+            ['OS == "linux" or os_bsd == 1', {
               'sources': [ '<@(views_desktop_aura_linux_sources)' ],
             }],
             ['use_x11 == 1', {
