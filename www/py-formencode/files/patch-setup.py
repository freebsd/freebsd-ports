
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -1,6 +1,7 @@
-from ez_setup import use_setuptools
-use_setuptools()
-from setuptools import setup
+#from ez_setup import use_setuptools
+#use_setuptools()
+#from setuptools import setup
+from distutils.core import setup
 
 setup(name="FormEncode",
       version="0.3",
