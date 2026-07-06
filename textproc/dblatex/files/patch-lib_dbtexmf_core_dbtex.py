--- lib/dbtexmf/core/dbtex.py.orig	2025-12-19 19:39:32 UTC
+++ lib/dbtexmf/core/dbtex.py
@@ -15,7 +15,8 @@ import glob
 except ImportError:
     from urllib.request import pathname2url
 import glob
-import imp
+import importlib.machinery
+import importlib.util
 from optparse import OptionParser
 from io import open
 
@@ -540,15 +541,14 @@ class DbTexCommand:
 
     def load_plugin(self, pathname):
         moddir, modname = os.path.split(pathname)
-        try:
-            filemod, path, descr = imp.find_module(modname, [moddir])
-        except ImportError:
-            try:
-                filemod, path, descr = imp.find_module(modname)
-            except ImportError:
-                failed_exit("Error: '%s' module not found" % modname)
-        mod = imp.load_module(modname, filemod, path, descr)
-        filemod.close()
+        spec = importlib.machinery.PathFinder.find_spec(modname, [moddir])
+        if not spec:
+            spec = importlib.machinery.PathFinder.find_spec(modname)
+        if not spec:
+            failed_exit("Error: '%s' module not found" % modname)
+        mod = importlib.util.module_from_spec(spec)
+        spec.loader.exec_module(mod)
+        sys.modules[modname] = mod
         return mod
 
     def run_setup(self, options):
