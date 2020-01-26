--- setup.py.orig	2020-01-14 18:41:32 UTC
+++ setup.py
@@ -47,7 +47,6 @@ install_requires = [
     # 1.1.0+ is required to avoid the warnings described at
     # https://github.com/certbot/josepy/issues/13.
     'josepy>=1.1.0',
-    'mock',
     'parsedatetime>=1.3',  # Calendar.parseDT
     'pyrfc3339',
     'pytz',
@@ -76,6 +75,7 @@ elif os.name == 'nt':
 dev_extras = [
     'coverage',
     'ipdb',
+    'mock',
     'pytest',
     'pytest-cov',
     'pytest-xdist',
