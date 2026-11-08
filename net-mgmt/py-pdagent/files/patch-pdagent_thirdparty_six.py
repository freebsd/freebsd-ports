Description: Add find_spec()/create_module()/exec_module() to the vendored
  six, as in six 1.16 (Python 3.12 no longer uses find_module()).
Issue ID: https://github.com/PagerDuty/pdagent/issues/178;
  fix: https://github.com/PagerDuty/pdagent/pull/184
Changeset: none
TODO: Drop once a release includes it.

--- pdagent/thirdparty/six.py.orig	2026-10-12 02:33:01 UTC
+++ pdagent/thirdparty/six.py
@@ -37,6 +37,11 @@ PY34 = sys.version_info[0:2] >= (3, 4)
 PY3 = sys.version_info[0] == 3
 PY34 = sys.version_info[0:2] >= (3, 4)
 
+if PY34:
+    from importlib.util import spec_from_loader
+else:
+    spec_from_loader = None
+
 if PY3:
     string_types = str,
     integer_types = int,
@@ -186,6 +191,11 @@ class _SixMetaPathImporter(object):
             return self
         return None
 
+    def find_spec(self, fullname, path, target=None):
+        if fullname in self.known_modules:
+            return spec_from_loader(fullname, self)
+        return None
+
     def __get_module(self, fullname):
         try:
             return self.known_modules[fullname]
@@ -222,6 +232,12 @@ class _SixMetaPathImporter(object):
         self.__get_module(fullname)  # eventually raises ImportError
         return None
     get_source = get_code  # same as get_code
+
+    def create_module(self, spec):
+        return self.load_module(spec.name)
+
+    def exec_module(self, module):
+        pass
 
 _importer = _SixMetaPathImporter(__name__)
 
