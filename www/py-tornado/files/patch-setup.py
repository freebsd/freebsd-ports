--- setup.py.orig	2013-04-29 08:46:17.852783104 +0200
+++ setup.py	2013-04-29 08:46:30.135662912 +0200
@@ -41,9 +41,6 @@
         # in the sdist tarball)
         "tornado.test": [
             "README",
-            "csv_translations/fr_FR.csv",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.mo",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.po",
             "options_test.cfg",
             "static/robots.txt",
             "templates/utf8.html",
