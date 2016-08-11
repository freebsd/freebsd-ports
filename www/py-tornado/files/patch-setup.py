--- setup.py.orig	2015-11-06 20:08:26 UTC
+++ setup.py
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
