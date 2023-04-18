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
