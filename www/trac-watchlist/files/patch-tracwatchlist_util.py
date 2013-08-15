--- tracwatchlist/util.py.orig	2013-08-15 04:15:56.000000000 +0800
+++ tracwatchlist/util.py	2013-08-15 04:16:05.000000000 +0800
@@ -198,8 +198,8 @@
 try:
     from  babel.dates        import  get_datetime_format, get_date_format, get_time_format
     def datetime_format(format='medium', locale=LC_TIME):
-        time_format = unicode(get_time_format(format, locale))
-        date_format = unicode(get_date_format(format, locale))
+        time_format = unicode(get_time_format(format, locale=locale))
+        date_format = unicode(get_date_format(format, locale=locale))
         return convert_LDML_to_MySQL( get_datetime_format(format, locale)\
                 .replace('{0}', time_format)\
                 .replace('{1}', date_format) )
