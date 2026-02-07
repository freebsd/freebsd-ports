--- setup.py.orig	2023-12-23 09:28:27 UTC
+++ setup.py
@@ -68,7 +68,7 @@ setup(
     license='MIT',
     scripts=[],
     data_files=[],
-    setup_requires=["oldest-supported-numpy", "cython>=0.23"],
+    setup_requires=["numpy", "cython>=0.23"],
     install_requires=["numpy>=1.16", "scipy>=1.6"],
     python_requires=">=3.6",
     classifiers=[
