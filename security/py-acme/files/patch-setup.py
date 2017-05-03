--- setup.py.orig	2017-04-30 10:29:55 UTC
+++ setup.py
@@ -8,7 +8,6 @@ version = '0.13.0'
 
 # Please update tox.ini when modifying dependency version requirements
 install_requires = [
-    'argparse',
     # load_pem_private/public_key (>=0.6)
     # rsa_recover_prime_factors (>=0.8)
     'cryptography>=0.8',
@@ -28,6 +27,10 @@ install_requires = [
     'six',
 ]
 
+# env markers cause problems with older pip and setuptools
+if sys.version_info < (2, 7):
+    install_requires.append('argparse')
+
 dev_extras = [
     'nose',
     'tox',
