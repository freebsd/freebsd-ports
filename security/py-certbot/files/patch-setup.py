--- setup.py.orig	2019-04-04 22:02:09 UTC
+++ setup.py
@@ -43,7 +43,6 @@ install_requires = [
     # 1.1.0+ is required to avoid the warnings described at
     # https://github.com/certbot/josepy/issues/13.
     'josepy>=1.1.0',
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'pyrfc3339',
     'pytz',
@@ -57,6 +56,7 @@ dev_extras = [
     'astroid==1.3.5',
     'coverage',
     'ipdb',
+    'mock',
     'pytest',
     'pytest-cov',
     'pytest-xdist',
