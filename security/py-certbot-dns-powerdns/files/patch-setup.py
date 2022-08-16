--- setup.py.orig	2022-08-16 19:53:36 UTC
+++ setup.py
@@ -11,7 +11,7 @@ with open('README.md') as f:
 install_requires = [
     'acme>=0.31.0',
     'certbot>=0.31.0',
-    'dns-lexicon>=3.2.4,<=3.5.6',
+    'dns-lexicon>=3.2.4',
     'dnspython',
     'mock',
     'setuptools',
