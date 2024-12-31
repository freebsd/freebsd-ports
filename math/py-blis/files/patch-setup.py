--- setup.py.orig	2024-12-13 12:03:50 UTC
+++ setup.py
@@ -328,7 +328,7 @@ setup(
     python_requires=">=3.9,<3.14",
     setup_requires=[
         "cython>=0.25",
-        "numpy>=2.0.0,<3.0.0",
+        "numpy>=1.19.3,<3.0.0",
     ],
     install_requires=[
         "numpy>=1.19.3,<3.0.0",
