--- setup.py.orig	2023-10-03 15:00:08 UTC
+++ setup.py
@@ -43,4 +43,5 @@ setup(
     py_modules=["test_pycosat"],
     description="bindings to picosat (a SAT solver)",
     long_description=open("README.rst").read(),
+    test_suite="test_pycosat",
 )
