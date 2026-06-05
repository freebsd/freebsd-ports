--- lib/dbtexmf/xslt/xslt.py.orig	2025-12-19 19:39:14 UTC
+++ lib/dbtexmf/xslt/xslt.py
@@ -2,20 +2,22 @@ import os
 # Very simple plugin loader for Xslt classes
 #
 import os
-import imp
+import importlib.machinery
+import importlib.util
 import glob
+import sys
 
 def load(modname):
-    try:
-        file, path, descr = imp.find_module(modname, [""])
-    except ImportError:
-        try:
-            file, path, descr = imp.find_module(modname,
-                                                [os.path.dirname(__file__)])
-        except ImportError:
-            raise ValueError("Xslt '%s' not found" % modname)
-    mod = imp.load_module(modname, file, path, descr)
-    file.close()
+    spec = importlib.machinery.PathFinder.find_spec(modname, [""])
+    if not spec:
+        spec = importlib.machinery.PathFinder.find_spec(modname,
+                                                        [os.path.dirname(__file__)])
+    if not spec:
+        raise ValueError("Xslt '%s' not found" % modname)
+
+    mod = importlib.util.module_from_spec(spec)
+    spec.loader.exec_module(mod)
+    sys.modules[modname] = mod
     o = mod.Xslt()
     return o
 
