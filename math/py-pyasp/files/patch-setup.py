--- setup.py.orig	2019-03-02 23:56:14 UTC
+++ setup.py
@@ -46,7 +46,8 @@ BINARIES_NAME = {
     # binary remote name: binary local name
     'clasp-3.1.1': 'clasp',
     'gringo-3.0.5': 'gringo3',
-    'gringo-5.3.0': 'gringo4',
+    'gringo-4.5.3': 'gringo',
+    'gringo-5.3.0': 'gringo',
 }
 
 BASE_URL_PLATFORM_SPECIFIC_SUBPATHS = {
@@ -138,7 +139,7 @@ class install(_install):
     def run(self):
         """Call superclass run method, then downloads the binaries"""
         _install.run(self)
-        self.execute(post_install, args=[], msg=post_install.__doc__)
+        #self.execute(post_install, args=[], msg=post_install.__doc__)
 
 
 setup(
