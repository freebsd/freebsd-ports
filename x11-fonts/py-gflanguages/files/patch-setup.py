--- setup.py.orig	2022-11-14 13:16:17 UTC
+++ setup.py
@@ -51,10 +51,10 @@ setup(
         'Programming Language :: Python :: 3'
     ],
     python_requires=">=3.7",
-    setup_requires=['setuptools_scm>=4,<6.1'],
+    setup_requires=['setuptools_scm>=4'],
     install_requires=[
         # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
-        'protobuf>=3.7.0, <4',
+        'protobuf>=3.7.0',
     ]
 )
