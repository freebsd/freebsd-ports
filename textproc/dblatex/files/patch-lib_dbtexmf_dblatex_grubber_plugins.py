--- lib/dbtexmf/dblatex/grubber/plugins.py.orig	2025-12-19 19:39:46 UTC
+++ lib/dbtexmf/dblatex/grubber/plugins.py
@@ -4,7 +4,8 @@ All the modules must be derived from the TexModule cla
 Mechanisms to dynamically load extra modules to help the LaTeX compilation.
 All the modules must be derived from the TexModule class.
 """
-import imp
+import importlib.machinery
+import importlib.util
 
 from os.path import *
 from dbtexmf.dblatex.grubber.msg import _, msg
@@ -108,17 +109,16 @@ class Plugins (object):
         """
         if name in self.modules:
             return 2
-        try:
-            file, path, descr = imp.find_module(name, [""])
-        except ImportError:
+        spec = importlib.machinery.PathFinder.find_spec(name, [""])
+        if not spec:
             if not self.path:
                 return 0
-            try:
-                file, path, descr = imp.find_module(name, self.path)
-            except ImportError:
-                return 0
-        module = imp.load_module(name, file, path, descr)
-        file.close()
+            spec = importlib.machinery.PathFinder.find_spec(name, self.path)
+        if not spec:
+            return 0
+        module = importlib.util.module_from_spec(spec)
+        spec.loader.exec_module(module)
+        sys.modules[name] = module
         self.modules[name] = module
         return 1
 
