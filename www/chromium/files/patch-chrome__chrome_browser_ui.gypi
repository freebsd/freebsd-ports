--- chrome/chrome_browser_ui.gypi.orig	2014-10-10 09:15:30 UTC
+++ chrome/chrome_browser_ui.gypi
@@ -2875,7 +2875,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -2883,7 +2883,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['OS=="win" or OS=="mac" or desktop_linux==1', {
+        ['OS=="win" or OS=="mac" or desktop_linux==1 or os_bsd==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_sources)' ],
         }],
         ['use_aura==1', {
@@ -2918,7 +2918,7 @@
         ['enable_print_preview==1', {
           'sources': [ '<@(chrome_browser_ui_print_preview_sources)' ],
         }],
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or OS=="freebsd"', {
           'sources': [ '<@(chrome_browser_ui_android_linux_sources)' ],
         }],
         ['OS=="android"', {
@@ -3030,10 +3030,10 @@
             }],
           ],
         }],
-        ['desktop_linux==1', {
+        ['desktop_linux==1 or os_bsd==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_linux_sources)' ],
         }],
-        ['OS=="linux"', {  # Both desktop Linux and ChromeOS.
+        ['OS=="linux" or OS=="freebsd"', {  # Both desktop Linux and ChromeOS.
           'sources': [ '<@(chrome_browser_ui_linux_sources)' ],
           'conditions': [
             ['use_aura==1', {
