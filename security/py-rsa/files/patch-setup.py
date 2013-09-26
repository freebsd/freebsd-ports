--- ./setup.py.orig	2013-09-26 22:34:41.233363167 +1000
+++ ./setup.py	2013-09-26 22:34:50.192985862 +1000
@@ -42,5 +42,5 @@
         'pyrsa-encrypt-bigfile = rsa.cli:encrypt_bigfile',
         'pyrsa-decrypt-bigfile = rsa.cli:decrypt_bigfile',
     ]},
-
+    zip_safe=False,
 )
