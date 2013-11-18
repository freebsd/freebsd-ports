--- ./plaso/parsers/firefox.py.orig	2013-10-31 18:02:07.000000000 +0000
+++ ./plaso/parsers/firefox.py	2013-11-15 23:23:14.000000000 +0000
@@ -26,18 +26,9 @@
 
 # Check SQlite version, bail out early if too old.
 import sqlite3
-release, major, minor = sqlite3.sqlite_version_info
-if (release < 3):
+if sqlite3.sqlite_version_info < (3, 7, 8):
   raise ImportWarning(
       'FirefoxHistoryParser requires at least SQLite version 3.7.8.')
-elif release == 3:
-  if major < 7:
-    raise ImportWarning(
-        'FirefoxHistoryParser requires at least SQLite version 3.7.8.')
-  elif major == 7:
-    if minor < 8:
-      raise ImportWarning(
-          'FirefoxHistoryParser requires at least SQLite version 3.7.8.')
 
 
 class FirefoxPlacesBookmarkAnnotation(event.EventContainer):
