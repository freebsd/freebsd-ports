--- ./setup.py.orig	2012-09-04 15:09:29.000000000 +1000
+++ ./setup.py	2012-11-19 19:24:33.000000000 +1100
@@ -25,6 +25,8 @@
 
 kwargs = {}
 
+kwargs["zip_safe"] = False
+
 # Build the epoll extension for Linux systems with Python < 2.6
 extensions = []
 major, minor = sys.version_info[:2]
@@ -54,9 +56,6 @@
             "test.key",
             "static/robots.txt",
             "templates/utf8.html",
-            "csv_translations/fr_FR.csv",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.mo",
-            "gettext_translations/fr_FR/LC_MESSAGES/tornado_test.po",
             ],
         },
     ext_modules = extensions,
