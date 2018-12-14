--- setup.py.orig	2018-12-05 23:47:59 UTC
+++ setup.py
@@ -39,7 +39,6 @@ install_requires = [
     'configobj',
     'cryptography>=1.2',  # load_pem_x509_certificate
     'josepy',
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'pyrfc3339',
     'pytz',
@@ -53,6 +52,7 @@ dev_extras = [
     'astroid==1.3.5',
     'coverage',
     'ipdb',
+    'mock',
     'pytest',
     'pytest-cov',
     'pytest-xdist',
