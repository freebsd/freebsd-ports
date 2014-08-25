--- ./setup.py.orig	2014-08-08 18:54:35.336077625 +1000
+++ ./setup.py	2014-08-08 18:54:46.442391757 +1000
@@ -43,4 +43,5 @@
     py_modules = ['test_pycosat'],
     description = "bindings to picosat (a SAT solver)",
     long_description = open('README.rst').read(),
+    test_suite="test_pycosat",
 )
