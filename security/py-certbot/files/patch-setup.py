--- setup.py.orig	2018-03-08 22:20:34 UTC
+++ setup.py
@@ -44,7 +44,6 @@ install_requires = [
     'configobj',
     'cryptography>=1.2',  # load_pem_x509_certificate
     'josepy',
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'pyrfc3339',
     'pytz',
@@ -58,6 +57,7 @@ dev_extras = [
     'astroid==1.3.5',
     'coverage',
     'ipdb',
+    'mock',
     'pytest',
     'pytest-cov',
     'pytest-xdist',
