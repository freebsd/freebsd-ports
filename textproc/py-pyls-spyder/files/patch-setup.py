--- setup.py.orig	2021-04-29 20:01:20 UTC
+++ setup.py
@@ -33,7 +33,7 @@ def get_version(module='pyls_spyder'):
 
 def get_description():
     """Get long description."""
-    with open(os.path.join(HERE, 'README.md'), 'r') as f:
+    with open(os.path.join(HERE, 'README.md'), 'r', encoding='utf8') as f:
         data = f.read()
     return data
 
