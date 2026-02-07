Taken from ../py-cryptography source code as of
FreeBSD ports tree 3216ed57448ee28aa6061e08839198c3e5cff5d7
with py-cryptography-42.0.7,1, with type annotations stripped out:
-- mandree@ 2024-05-30

--- src/cryptography/utils.py.orig	2021-08-24 17:17:17 UTC
+++ src/cryptography/utils.py
@@ -132,13 +132,15 @@ class _ModuleWithDeprecations(object):
         return ["_module"] + dir(self._module)
 
 
-def deprecated(value, module_name, message, warning_class):
+def deprecated(value, module_name, message, warning_class, name=None):
     module = sys.modules[module_name]
     if not isinstance(module, _ModuleWithDeprecations):
-        sys.modules[module_name] = _ModuleWithDeprecations(
-            module
-        )  # type: ignore[assignment]
-    return _DeprecatedValue(value, message, warning_class)
+        sys.modules[module_name] = module = _ModuleWithDeprecations(module)
+    dv = _DeprecatedValue(value, message, warning_class)
+    # Maintain backwards compatibility with `name is None` for pyOpenSSL.
+    if name is not None:
+        setattr(module, name, dv)
+    return dv
 
 
 def cached_property(func):
