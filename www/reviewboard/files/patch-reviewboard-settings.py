--- reviewboard/settings.py.orig	2012-12-19 00:50:53.000000000 +0800
+++ reviewboard/settings.py	2012-12-19 00:52:55.000000000 +0800
@@ -28,7 +28,7 @@
 # http://www.postgresql.org/docs/8.1/static/datetime-keywords.html#DATETIME-TIMEZONE-SET-TABLE
 # When USE_TZ is enabled, this is used as the default time zone for datetime
 # objects
-TIME_ZONE = 'UTC'
+TIME_ZONE = 'Etc/UTC'
 
 # Language code for this installation. All choices can be found here:
 # http://www.w3.org/TR/REC-html40/struct/dirlang.html#langcodes
