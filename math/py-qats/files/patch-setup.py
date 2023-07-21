--- setup.py.orig	2023-07-21 05:37:29 UTC
+++ setup.py
@@ -22,15 +22,15 @@ setup(
     python_requires=">=3.7, <3.11",
     setup_requires=["setuptools_scm"],
     install_requires=[
-        "numpy>=1,<2",
-        "openpyxl>=3,<4",
-        "scipy>=1,<2",
-        "matplotlib>=3,<4",
-        "npTDMS>=1,<2",
-        "h5py>=2.7,<4",
-        "QtPy>=1,<2",
-        "pandas>=1,<2",
-        "pymatreader>=0.0.20,<1",
+        "numpy>=1",
+        "openpyxl>=3",
+        "scipy>=1",
+        "matplotlib>=3",
+        "npTDMS>=1",
+        "h5py>=2.7",
+        "QtPy>=1",
+        "pandas>=1",
+        "pymatreader>=0.0.20",
         "pywin32; platform_system == 'Windows'"
     ],
     entry_points={
