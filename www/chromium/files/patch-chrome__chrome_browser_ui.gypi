--- chrome/chrome_browser_ui.gypi.orig	2015-10-14 16:42:08.849931000 +0200
+++ chrome/chrome_browser_ui.gypi	2015-10-14 16:45:35.205417000 +0200
@@ -2921,7 +2921,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -2929,7 +2929,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['OS=="win" or OS=="mac" or desktop_linux==1', {
+        ['OS=="win" or OS=="mac" or desktop_linux==1 or os_bsd==1', {
           # A temporary define to make it easier to remove CrOS dependencies on
           # avatar button code. TODO(estade): remove.
           'defines': [ 'FRAME_AVATAR_BUTTON=1', ],
@@ -3095,10 +3095,10 @@
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
