--- setup.py.orig	2015-05-27 01:44:57 UTC
+++ setup.py
@@ -122,7 +122,7 @@ if (platform.python_implementation() == 
 if setuptools is not None:
     # If setuptools is not available, you're on your own for dependencies.
     install_requires = []
-    if sys.version_info < (3, 2):
+    if sys.version_info < (2, 7, 9):
         install_requires.append('backports.ssl_match_hostname')
     if sys.version_info < (3, 4):
         # Certifi is also optional on 2.7.9+, although making our dependencies
@@ -141,9 +141,6 @@ setup(
         # in the sdist tarball)
         "tornado.test": [
             "README",
-            "csv_translations/fr_FR.csv",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.mo",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.po",
             "options_test.cfg",
             "static/robots.txt",
             "static/dir/index.html",
