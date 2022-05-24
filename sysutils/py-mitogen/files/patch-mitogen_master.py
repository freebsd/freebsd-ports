--- mitogen/master.py.orig	2022-01-12 07:45:19 UTC
+++ mitogen/master.py
@@ -122,6 +122,13 @@ def is_stdlib_name(modname):
     """
     Return :data:`True` if `modname` appears to come from the standard library.
     """
+    # `imp.is_builtin()` isn't a documented as part of Python's stdlib API.
+    #
+    # """
+    # Main is a little special - imp.is_builtin("__main__") will return False,
+    # but BuiltinImporter is still the most appropriate initial setting for
+    # its __loader__ attribute.
+    # """ -- comment in CPython pylifecycle.c:add_main_module()
     if imp.is_builtin(modname) != 0:
         return True
 
@@ -512,42 +519,57 @@ class PkgutilMethod(FinderMethod):
         Find `fullname` using :func:`pkgutil.find_loader`.
         """
         try:
+            # If fullname refers to a submodule that's not already imported
+            # then the containing package is imported.
             # Pre-'import spec' this returned None, in Python3.6 it raises
             # ImportError.
             loader = pkgutil.find_loader(fullname)
         except ImportError:
             e = sys.exc_info()[1]
-            LOG.debug('%r._get_module_via_pkgutil(%r): %s',
-                      self, fullname, e)
+            LOG.debug('%r: find_loader(%r) failed: %s', self, fullname, e)
             return None
 
-        IOLOG.debug('%r._get_module_via_pkgutil(%r) -> %r',
-                    self, fullname, loader)
         if not loader:
+            LOG.debug('%r: find_loader(%r) returned %r, aborting',
+                      self, fullname, loader)
             return
 
         try:
-            path, is_special = _py_filename(loader.get_filename(fullname))
-            source = loader.get_source(fullname)
-            is_pkg = loader.is_package(fullname)
-
-            # workaround for special python modules that might only exist in memory
-            if is_special and is_pkg and not source:
-                source = '\n'
+            path = loader.get_filename(fullname)
         except (AttributeError, ImportError):
-            # - Per PEP-302, get_source() and is_package() are optional,
-            #   calling them may throw AttributeError.
             # - get_filename() may throw ImportError if pkgutil.find_loader()
             #   picks a "parent" package's loader for some crap that's been
             #   stuffed in sys.modules, for example in the case of urllib3:
             #       "loader for urllib3.contrib.pyopenssl cannot handle
             #        requests.packages.urllib3.contrib.pyopenssl"
             e = sys.exc_info()[1]
-            LOG.debug('%r: loading %r using %r failed: %s',
-                      self, fullname, loader, e)
+            LOG.debug('%r: %r.get_file_name(%r) failed: %r', self, loader, fullname, e)
             return
 
+        path, is_special = _py_filename(path)
+
+        try:
+            source = loader.get_source(fullname)
+        except AttributeError:
+            # Per PEP-302, get_source() is optional,
+            e = sys.exc_info()[1]
+            LOG.debug('%r: %r.get_source() failed: %r', self, loader, fullname, e)
+            return
+
+        try:
+            is_pkg = loader.is_package(fullname)
+        except AttributeError:
+            # Per PEP-302, is_package() is optional,
+            e = sys.exc_info()[1]
+            LOG.debug('%r: %r.is_package(%r) failed: %r', self, loader, fullname, e)
+            return
+
+        # workaround for special python modules that might only exist in memory
+        if is_special and is_pkg and not source:
+            source = '\n'
+
         if path is None or source is None:
+            LOG.debug('%r: path=%r, source=%r, aborting', self, path, source)
             return
 
         if isinstance(source, mitogen.core.UnicodeType):
@@ -567,23 +589,37 @@ class SysModulesMethod(FinderMethod):
         """
         Find `fullname` using its :data:`__file__` attribute.
         """
-        module = sys.modules.get(fullname)
+        try:
+            module = sys.modules[fullname]
+        except KeyError:
+            LOG.debug('%r: sys.modules[%r] absent, aborting', self, fullname)
+            return
+
         if not isinstance(module, types.ModuleType):
-            LOG.debug('%r: sys.modules[%r] absent or not a regular module',
-                      self, fullname)
+            LOG.debug('%r: sys.modules[%r] is %r, aborting',
+                      self, fullname, module)
             return
 
-        LOG.debug('_get_module_via_sys_modules(%r) -> %r', fullname, module)
-        alleged_name = getattr(module, '__name__', None)
-        if alleged_name != fullname:
-            LOG.debug('sys.modules[%r].__name__ is incorrect, assuming '
-                      'this is a hacky module alias and ignoring it. '
-                      'Got %r, module object: %r',
-                      fullname, alleged_name, module)
+        try:
+            resolved_name = module.__name__
+        except AttributeError:
+            LOG.debug('%r: %r has no __name__, aborting', self, module)
             return
 
-        path, _ = _py_filename(getattr(module, '__file__', ''))
+        if resolved_name != fullname:
+            LOG.debug('%r: %r.__name__ is %r, aborting',
+                      self, module, resolved_name)
+            return
+
+        try:
+            path = module.__file__
+        except AttributeError:
+            LOG.debug('%r: %r has no __file__, aborting', self, module)
+            return
+
+        path, _ = _py_filename(path)
         if not path:
+            LOG.debug('%r: %r.__file__ is %r, aborting', self, module, path)
             return
 
         LOG.debug('%r: sys.modules[%r]: found %s', self, fullname, path)
@@ -628,10 +664,24 @@ class ParentEnumerationMethod(FinderMethod):
     module object or any parent package's :data:`__path__`, since they have all
     been overwritten. Some men just want to watch the world burn.
     """
+
+    @staticmethod
+    def _iter_parents(fullname):
+        """
+        >>> list(ParentEnumerationMethod._iter_parents('a'))
+        [('', 'a')]
+        >>> list(ParentEnumerationMethod._iter_parents('a.b.c'))
+        [('a.b', 'c'), ('a', 'b'), ('', 'a')]
+        """
+        while fullname:
+            fullname, _, modname = str_rpartition(fullname, u'.')
+            yield fullname, modname
+
     def _find_sane_parent(self, fullname):
         """
         Iteratively search :data:`sys.modules` for the least indirect parent of
-        `fullname` that is loaded and contains a :data:`__path__` attribute.
+        `fullname` that's from the same package and has a :data:`__path__`
+        attribute.
 
         :return:
             `(parent_name, path, modpath)` tuple, where:
@@ -644,21 +694,40 @@ class ParentEnumerationMethod(FinderMethod):
                 * `modpath`: list of module name components leading from `path`
                    to the target module.
         """
-        path = None
         modpath = []
-        while True:
-            pkgname, _, modname = str_rpartition(to_text(fullname), u'.')
+        for pkgname, modname in self._iter_parents(fullname):
             modpath.insert(0, modname)
             if not pkgname:
                 return [], None, modpath
 
-            pkg = sys.modules.get(pkgname)
-            path = getattr(pkg, '__path__', None)
-            if pkg and path:
-                return pkgname.split('.'), path, modpath
+            try:
+                pkg = sys.modules[pkgname]
+            except KeyError:
+                LOG.debug('%r: sys.modules[%r] absent, skipping', self, pkgname)
+                continue
 
-            LOG.debug('%r: %r lacks __path__ attribute', self, pkgname)
-            fullname = pkgname
+            try:
+                resolved_pkgname = pkg.__name__
+            except AttributeError:
+                LOG.debug('%r: %r has no __name__, skipping', self, pkg)
+                continue
+
+            if resolved_pkgname != pkgname:
+                LOG.debug('%r: %r.__name__ is %r, skipping',
+                          self, pkg, resolved_pkgname)
+                continue
+
+            try:
+                path = pkg.__path__
+            except AttributeError:
+                LOG.debug('%r: %r has no __path__, skipping', self, pkg)
+                continue
+
+            if not path:
+                LOG.debug('%r: %r.__path__ is %r, skipping', self, pkg, path)
+                continue
+
+            return pkgname.split('.'), path, modpath
 
     def _found_package(self, fullname, path):
         path = os.path.join(path, '__init__.py')
