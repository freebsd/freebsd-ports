--- chrome/chrome_browser.gypi.orig	2011-04-16 11:02:00.000000000 +0300
+++ chrome/chrome_browser.gypi	2011-04-21 21:49:54.625558694 +0300
@@ -3455,7 +3455,7 @@
             ['exclude', '^browser/views/tab_contents/tab_contents_view_gtk.h'],
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           'dependencies': [
             '../build/linux/system.gyp:dbus-glib',
             '../build/linux/system.gyp:gconf',
@@ -3465,12 +3465,6 @@
             '../build/linux/system.gyp:x11',
             '../third_party/undoview/undoview.gyp:undoview',
           ],
-          'link_settings': {
-            'libraries': [
-              # For dlsym() in 'browser/zygote_main_linux.cc'
-              '-ldl',
-            ],
-          },
           'sources!': [
             'browser/ui/views/extensions/extension_view.cc',
             'browser/ui/views/extensions/extension_view.h',
@@ -4118,7 +4112,7 @@
               ],
             }],
             # GTK build only
-            ['OS=="linux" and toolkit_views==0', {
+            ['(OS=="linux" or OS=="freebsd") and toolkit_views==0', {
               'sources/': [
                 ['include', '^browser/printing/print_dialog_gtk.cc'],
                 ['include', '^browser/printing/print_dialog_gtk.h'],
@@ -4196,7 +4190,7 @@
                 },
               ],
             }],
-            ['OS=="linux" and gcc_version==45', {
+            ['(OS=="linux" or OS=="freebsd") and gcc_version==45', {
               # Avoid gcc 4.5 miscompilation of template_url.cc
               # as per http://crbug.com/41887
               'cflags': [
