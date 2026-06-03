--- setup.py.orig	2024-12-20 11:52:02 UTC
+++ setup.py
@@ -59,12 +59,12 @@ setup(
         "Programming Language :: Python :: 3",
     ],
     python_requires=">=3.8",
-    setup_requires=["setuptools_scm>=8.1.0,<8.2"],
+    setup_requires=["setuptools_scm>=8.1.0"],
     install_requires=[
         "requests",
         "setuptools",
         "FontTools[ufo]",
-        "glyphsLib>=6.9.5",
+        "glyphsLib",
         "defcon",
         "unicodedata2",
         "gflanguages>=0.7.1",
