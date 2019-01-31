--- setup.py.orig	2018-07-09 03:59:48 UTC
+++ setup.py
@@ -22,14 +22,15 @@ description = "Python client for Consul (http://www.co
 
 py_modules = [os.path.splitext(x)[0] for x in glob.glob('consul/*.py')]
 
+# Issue #123: skip installation of consul.aio if python version < 3.4.2
+# as this version or later is required by aiohttp
+if sys.version_info < (3, 4, 2):
+    if 'consul/aio' in py_modules:
+        py_modules.remove('consul/aio')
 
+
 class Install(install):
     def run(self):
-        # Issue #123: skip installation of consul.aio if python version < 3.4.2
-        # as this version or later is required by aiohttp
-        if sys.version_info < (3, 4, 2):
-            if 'consul/aio' in self.distribution.py_modules:
-                self.distribution.py_modules.remove('consul/aio')
         install.run(self)
 
 
