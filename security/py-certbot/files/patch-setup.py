--- setup.py.orig	2019-05-07 19:17:33 UTC
+++ setup.py
@@ -43,7 +43,6 @@ install_requires = [
     # 1.1.0+ is required to avoid the warnings described at
     # https://github.com/certbot/josepy/issues/13.
     'josepy>=1.1.0',
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'pyrfc3339',
     'pytz',
@@ -56,6 +55,7 @@ dev_extras = [
     'astroid==1.6.5',
     'coverage',
     'ipdb',
+    'mock',
     'pytest',
     'pytest-cov',
     'pytest-xdist',
