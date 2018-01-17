--- setup.py.orig	2017-03-28 11:25:30 UTC
+++ setup.py
@@ -46,7 +46,7 @@ BINARIES_NAME = {
     # binary remote name: binary local name
     'clasp-3.1.3': 'clasp',
     'gringo-3.0.5': 'gringo3',
-    'gringo-4.5.3': 'gringo4',
+    'gringo-4.5.3': 'gringo',
 }
 
 BASE_URL_PLATFORM_SPECIFIC_SUBPATHS = {
@@ -142,7 +142,7 @@ class install(_install):
     def run(self):
         """Call superclass run method, then downloads the binaries"""
         _install.run(self)
-        self.execute(post_install, args=[], msg=post_install.__doc__)
+        #self.execute(post_install, args=[], msg=post_install.__doc__)
 
 
 setup(
