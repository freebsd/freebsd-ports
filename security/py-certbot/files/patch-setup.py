--- setup.py.orig	2017-06-26 10:13:14 UTC
+++ setup.py
@@ -42,7 +42,6 @@ install_requires = [
     'ConfigArgParse>=0.9.3',
     'configobj',
     'cryptography>=1.2',  # load_pem_x509_certificate
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'PyOpenSSL',
     'pyrfc3339',
@@ -67,6 +66,7 @@ dev_extras = [
     'astroid==1.3.5',
     'coverage',
     'ipdb',
+    'mock',
     'nose',
     'pylint==1.4.2',  # upstream #248
     'tox',
