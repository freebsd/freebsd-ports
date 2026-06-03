--- frescobaldi/portmidi/__init__.py.orig	2020-12-26 10:15:52 UTC
+++ frescobaldi/portmidi/__init__.py
@@ -264,16 +264,7 @@ def _setup():
 
     """
     global pypm
-    if pypm is None:
-        for name in try_order:
-            try:
-                pypm = globals()['_do_import_' + name]()
-                break
-            except ImportError:
-                continue
-        else:
-            pypm = False
-    return bool(pypm)
+    return False
 
 def _load_module(name):
     """Loads and returns a single module.
