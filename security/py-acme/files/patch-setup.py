--- setup.py.orig	2019-02-07 21:20:31 UTC
+++ setup.py
@@ -13,7 +13,6 @@ install_requires = [
     # formerly known as acme.jose:
     'josepy>=1.0.0',
     # Connection.set_tlsext_host_name (>=0.13)
-    'mock',
     'PyOpenSSL>=0.13.1',
     'pyrfc3339',
     'pytz',
@@ -24,6 +23,7 @@ install_requires = [
 ]
 
 dev_extras = [
+    'mock',
     'pytest',
     'pytest-xdist',
     'tox',
