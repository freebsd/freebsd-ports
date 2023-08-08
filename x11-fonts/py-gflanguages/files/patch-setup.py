--- setup.py.orig	2023-02-24 14:23:41 UTC
+++ setup.py
@@ -55,6 +55,6 @@ setup(
     install_requires=[
         # 3.7.0 fixed a bug on parsing some METADATA.pb files.
         # We cannot use v4 because our protobuf files have been compiled with v3.
-        'protobuf>=3.7.0, <4',
+        'protobuf>=3.7.0',
     ]
 )
