--- webview/guilib.py.orig	2024-10-27 17:42:14 UTC
+++ webview/guilib.py
@@ -114,7 +114,7 @@ def initialize(forced_gui: GUIType | None = None):
     elif hasattr(sys, 'getandroidapilevel'):
         try_import([import_android])
 
-    elif platform.system() == 'Linux' or platform.system() == 'OpenBSD':
+    elif platform.system() == 'Linux' or platform.system() == 'OpenBSD' or platform.system() == 'FreeBSD':
         if forced_gui == 'qt':
             guis = [import_qt, import_gtk]
         else:
@@ -135,7 +135,7 @@ def initialize(forced_gui: GUIType | None = None):
             raise WebViewException('You must have pythonnet installed in order to use pywebview.')
     else:
         raise WebViewException(
-            'Unsupported platform. Only Windows, Linux, OS X, OpenBSD are supported.'
+            'Unsupported platform. Only Windows, Linux, OS X, OpenBSD, FreeBSD are supported.'
         )
 
     guilib.setup_app()
