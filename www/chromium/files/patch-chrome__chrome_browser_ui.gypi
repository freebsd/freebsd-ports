--- ./chrome/chrome_browser_ui.gypi.orig	2014-08-20 21:02:14.000000000 +0200
+++ ./chrome/chrome_browser_ui.gypi	2014-08-22 15:06:25.000000000 +0200
@@ -2673,7 +2673,7 @@
             'browser/ui/views/message_center/web_notification_tray.cc',
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -2681,7 +2681,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['use_aura==0 or chromeos==1 or OS!="linux"', {
+        ['use_aura==0 or chromeos==1 or (OS!="linux" and os_bsd!=1)', {
           'sources!': [
             'browser/ui/views/first_run_dialog.cc',
             'browser/ui/views/first_run_dialog.h',
@@ -3047,7 +3047,7 @@
             }],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_aura==1', {
               'dependencies': [
@@ -3140,7 +3140,7 @@
             'browser/ui/webui/local_discovery/local_discovery_ui_handler.h',
           ],
         }],
-        ['OS!="linux" and OS!="win"', {
+        ['OS!="linux" and OS!="win" and os_bsd!=1', {
           'sources': [
             'browser/ui/startup/session_crashed_bubble.cc'
           ],
