--- cvsview.py.orig	Wed Jun 11 23:35:31 2003
+++ cvsview.py	Wed Jun 11 23:36:04 2003
@@ -90,7 +90,7 @@
                 if plus >= 0:
                     cotime = 0
                 try:
-                    cotime = time.mktime( time.strptime(date) )
+                    cotime = time.mktime( time.strptime(date) ) - time.timezone
                 except ValueError, e:
                     if not date.startswith("Result of merge"):
                         print "Unable to parse date '%s' in '%s/CVS/Entries'" % (date, directory)
