--- mitogen/core.py.orig	2022-01-12 07:45:19 UTC
+++ mitogen/core.py
@@ -1357,6 +1357,16 @@ class Importer(object):
             fp.close()
 
     def find_module(self, fullname, path=None):
+        """
+        Return a loader (ourself) or None, for the module with fullname.
+
+        Implements importlib.abc.MetaPathFinder.find_module().
+        Deprecrated in Python 3.4+, replaced by find_spec().
+        Raises ImportWarning in Python 3.10+.
+
+        fullname    A (fully qualified?) module name, e.g. "os.path".
+        path        __path__ of parent packge. None for a top level module.
+        """
         if hasattr(_tls, 'running'):
             return None
 
@@ -1478,6 +1488,12 @@ class Importer(object):
             callback()
 
     def load_module(self, fullname):
+        """
+        Return the loaded module specified by fullname.
+
+        Implements importlib.abc.Loader.load_module().
+        Deprecated in Python 3.4+, replaced by create_module() & exec_module().
+        """
         fullname = to_text(fullname)
         _v and self._log.debug('requesting %s', fullname)
         self._refuse_imports(fullname)
