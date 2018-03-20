--- setup.py.orig	2018-03-20 00:33:22 UTC
+++ setup.py
@@ -14,7 +14,6 @@ install_requires = [
     # formerly known as acme.jose:
     'josepy>=1.0.0',
     # Connection.set_tlsext_host_name (>=0.13)
-    'mock',
     'PyOpenSSL>=0.13',
     'pyrfc3339',
     'pytz',
@@ -24,6 +23,7 @@ install_requires = [
 ]
 
 dev_extras = [
+    'mock',
     'pytest',
     'pytest-xdist',
     'tox',
