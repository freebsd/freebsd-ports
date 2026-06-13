--- setup.py.orig	2020-10-15 12:31:26 UTC
+++ setup.py
@@ -14,7 +14,7 @@ def get_version():
     with open(filename) as input_file:
         for line in input_file:
             if line.startswith('__version__'):
-                return ast.parse(line).body[0].value.s
+                return ast.parse(line).body[0].value.value
 
 
 def get_long_description():
