--- ./setup.py.orig	2012-06-19 00:14:17.000000000 +1000
+++ ./setup.py	2012-06-29 17:34:36.000000000 +1000
@@ -1,9 +1,5 @@
 #!/usr/bin/env python
 
-# Ensure that a reasonably recent version of 'distribute' is installed.
-from distribute_setup import use_setuptools
-use_setuptools('0.6.10')
-
 from setuptools import setup
 
 import rsa
@@ -41,5 +37,5 @@
         'pyrsa-encrypt-bigfile = rsa.cli:encrypt_bigfile',
         'pyrsa-decrypt-bigfile = rsa.cli:decrypt_bigfile',
     ]},
-
+    zip_safe=False,
 )
