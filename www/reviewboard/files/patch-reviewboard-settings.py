--- reviewboard/settings.py.orig	2012-04-30 12:28:31.000000000 +0800
+++ reviewboard/settings.py	2012-04-30 12:30:01.000000000 +0800
@@ -16,8 +16,8 @@
 MANAGERS = ADMINS
 
 # Local time zone for this installation. All choices can be found here:
-# http://www.postgresql.org/docs/current/static/datetime-keywords.html#DATETIME-TIMEZONE-SET-TABLE
-TIME_ZONE = 'US/Pacific'
+# http://www.postgresql.org/docs/8.1/static/datetime-keywords.html#DATETIME-TIMEZONE-SET-TABLE
+TIME_ZONE = 'Etc/UTC'
 
 # Language code for this installation. All choices can be found here:
 # http://www.w3.org/TR/REC-html40/struct/dirlang.html#langcodes
