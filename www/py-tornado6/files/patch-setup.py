--- setup.py.orig	2020-03-04 14:48:15 UTC
+++ setup.py
@@ -150,9 +150,6 @@ setup(
         "tornado": ["py.typed"],
         "tornado.test": [
             "README",
-            "csv_translations/fr_FR.csv",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.mo",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.po",
             "options_test.cfg",
             "options_test_types.cfg",
             "options_test_types_str.cfg",
