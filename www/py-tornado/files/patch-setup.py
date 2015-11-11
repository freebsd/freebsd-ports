--- setup.py.orig	2015-11-06 20:08:26 UTC
+++ setup.py
@@ -125,7 +125,7 @@ if setuptools is not None:
     if sys.version_info < (2, 7):
         # Only needed indirectly, for singledispatch.
         install_requires.append('ordereddict')
-    if sys.version_info < (3, 2):
+    if sys.version_info < (2, 7, 9):
         install_requires.append('backports.ssl_match_hostname')
     if sys.version_info < (3, 4):
         install_requires.append('singledispatch')
@@ -147,9 +147,6 @@ setup(
         # in the sdist tarball)
         "tornado.test": [
             "README",
-            "csv_translations/fr_FR.csv",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.mo",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.po",
             "options_test.cfg",
             "static/robots.txt",
             "static/sample.xml",
