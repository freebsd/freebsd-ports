--- chrome/chrome_browser_ui.gypi.orig	2014-10-02 17:39:46 UTC
+++ chrome/chrome_browser_ui.gypi
@@ -2729,7 +2729,7 @@
             }],
           ],
         }],
-        ['use_aura==1 and chromeos==0 and use_ozone==0 and OS=="linux"', {
+        ['use_aura==1 and chromeos==0 and use_ozone==0 and (OS=="linux" or os_bsd==1)', {
           'dependencies': [
             # gtk2 is the only component that can interact with gtk2 in our new
             # world.
@@ -2737,7 +2737,7 @@
             '../build/linux/system.gyp:gio',
           ],
         }],
-        ['OS=="win" or OS=="mac" or desktop_linux==1', {
+        ['OS=="win" or OS=="mac" or desktop_linux==1 or os_bsd==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_sources)' ],
         }],
         ['use_aura==1', {
@@ -2772,7 +2772,7 @@
         ['enable_printing==1', {
           'sources': [ '<@(chrome_browser_ui_print_preview_sources)' ],
         }],
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or OS=="freebsd"', {
           'sources': [ '<@(chrome_browser_ui_android_linux_sources)' ],
         }],
         ['OS=="android"', {
@@ -2891,7 +2891,7 @@
         ['desktop_linux==1', {
           'sources': [ '<@(chrome_browser_ui_desktop_linux_sources)' ],
         }],
-        ['OS=="linux"', {  # Both desktop Linux and ChromeOS.
+        ['OS=="linux" or OS=="freebsd"', {  # Both desktop Linux and ChromeOS.
           'sources': [ '<@(chrome_browser_ui_linux_sources)' ],
           'dependencies': [
             '../build/linux/system.gyp:udev',
