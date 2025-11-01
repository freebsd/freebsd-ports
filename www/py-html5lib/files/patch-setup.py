--- setup.py.orig	2020-06-22 23:23:02 UTC
+++ setup.py
@@ -90,8 +90,8 @@ with open(join(here, "html5lib", "__init__.py"), "rb")
         if (len(a.targets) == 1 and
                 isinstance(a.targets[0], ast.Name) and
                 a.targets[0].id == "__version__" and
-                isinstance(a.value, ast.Str)):
-            version = a.value.s
+                isinstance(a.value, ast.Constant)):
+            version = a.value
 
 setup(name='html5lib',
       version=version,
