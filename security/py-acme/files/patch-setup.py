--- setup.py.orig	2017-06-26 10:16:14 UTC
+++ setup.py
@@ -12,7 +12,6 @@ install_requires = [
     # rsa_recover_prime_factors (>=0.8)
     'cryptography>=0.8',
     # Connection.set_tlsext_host_name (>=0.13)
-    'mock',
     'PyOpenSSL>=0.13',
     'pyrfc3339',
     'pytz',
@@ -35,6 +34,7 @@ if sys.version_info < (2, 7):
     ])
 
 dev_extras = [
+    'mock',
     'nose',
     'tox',
 ]
