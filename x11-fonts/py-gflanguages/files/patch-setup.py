--- setup.py.orig	2022-03-04 21:26:42 UTC
+++ setup.py
@@ -51,7 +51,7 @@ setup(
         'Programming Language :: Python :: 3'
     ],
     python_requires=">=3.7",
-    setup_requires=['setuptools_scm>=4,<6.1'],
+    setup_requires=['setuptools_scm>=4'],
     install_requires=[
         'protobuf'
     ]
