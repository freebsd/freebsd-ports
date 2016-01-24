--- ui/views/controls/webview/webview.gyp.orig	2016-01-21 20:39:27.633964842 +0100
+++ ui/views/controls/webview/webview.gyp	2016-01-21 20:39:46.305964070 +0100
@@ -42,7 +42,7 @@
         'webview_export.h',
       ],
       'conditions': [
-        ['OS=="linux" or OS=="android"', {
+        ['OS=="linux" or OS=="android" or os_bsd==1', {
           'sources': [ 'unhandled_keyboard_event_handler_default.cc', ],
         }],
       ],
