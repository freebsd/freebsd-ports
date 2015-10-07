--- chrome/chrome_browser_ui.gypi.orig	2015-07-15 16:29:59.000000000 -0400
+++ chrome/chrome_browser_ui.gypi	2015-07-21 22:40:24.997217000 -0400
@@ -2922,7 +2922,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -2930,7 +2930,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['OS=="win" or OS=="mac" or desktop_linux==1', {
+        ['OS=="win" or OS=="mac" or desktop_linux==1 or os_bsd==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_sources)' ],
         }],
         ['use_aura==1', {
@@ -3083,10 +3083,10 @@
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
