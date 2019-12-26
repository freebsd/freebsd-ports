--- setup.py.orig	2019-12-05 17:30:21 UTC
+++ setup.py
@@ -14,7 +14,6 @@ install_requires = [
     # 1.1.0+ is required to avoid the warnings described at
     # https://github.com/certbot/josepy/issues/13.
     'josepy>=1.1.0',
-    'mock',
     # Connection.set_tlsext_host_name (>=0.13)
     'PyOpenSSL>=0.13.1',
     'pyrfc3339',
@@ -26,6 +25,7 @@ install_requires = [
 ]
 
 dev_extras = [
+    'mock',
     'pytest',
     'pytest-xdist',
     'tox',
