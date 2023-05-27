--- setup.py.orig	2023-03-09 22:50:58 UTC
+++ setup.py
@@ -70,7 +70,6 @@ setup(
         'cryptography>=3.3.1'
     ],
     setup_requires=[
-        'wheel', 'pytest-runner'
     ],
     extras_require={
         'extra_pubkey_algs': ['oscrypto>=1.2.1'],
@@ -79,7 +78,7 @@ setup(
             'fonttools>=4.33.3',
             # uharfbuzz sometimes includes breaking changes, so
             # we set an explicit range
-            'uharfbuzz>=0.25.0,<0.31.0'
+            'uharfbuzz>=0.25.0'
         ],
         'image-support': [
             # Only tested systematically on 8.x,
