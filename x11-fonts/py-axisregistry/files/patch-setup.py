--- setup.py.orig	2022-03-04 09:40:48 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(
         'Programming Language :: Python :: 3'
     ],
     python_requires=">=3.7",
-    setup_requires=['setuptools_scm>=4,<6.1'],
+    setup_requires=['setuptools_scm>=4'],
     install_requires=[
         'protobuf'
     ]
