--- platform/python/mozbuild/mozbuild/configure/__init__.py.orig	2021-02-05 18:43:01 UTC
+++ platform/python/mozbuild/mozbuild/configure/__init__.py
@@ -192,8 +192,9 @@ class ConfigureSandbox(dict):
         b: __builtins__[b]
         for b in ('None', 'False', 'True', 'int', 'bool', 'any', 'all', 'len',
                   'list', 'tuple', 'set', 'dict', 'isinstance', 'getattr',
-                  'hasattr', 'enumerate', 'range', 'zip')
-    }, __import__=forbidden_import, str=unicode)
+                  'hasattr', 'enumerate', 'range', 'zip', '__build_class__')
+        if b in __builtins__},
+    __import__=forbidden_import, str=unicode)
 
     # Expose a limited set of functions from os.path
     OS = ReadOnlyNamespace(path=ReadOnlyNamespace(**{
