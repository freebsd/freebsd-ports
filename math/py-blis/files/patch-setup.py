--- setup.py.orig	2024-07-25 17:54:37 UTC
+++ setup.py
@@ -327,10 +327,10 @@ setup(
 setup(
     setup_requires=[
         "cython>=0.25",
-        "numpy>=2.0.0,<3.0.0",
+        "numpy>=0,<3.0.0",
     ],
     install_requires=[
-        "numpy>=2.0.0,<3.0.0",
+        "numpy>=0,<3.0.0",
     ],
     ext_modules=cythonize(
         [
