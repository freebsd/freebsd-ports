--- src/www/htdocs/favorites.rpy.orig	2009-02-19 12:59:44.000000000 -0500
+++ src/www/htdocs/favorites.rpy	2010-02-19 11:03:40.000000000 -0500
@@ -115,9 +115,9 @@
         fv.tableRowClose()
 
         def sortByPriority(a,b):
-            if (a.priority < b.priority):
+            if (int(a.priority) < int(b.priority)):
                 return -1
-            elif (a.priority > b.priority):
+            elif (int(a.priority) > int(b.priority)):
                 return 1
             else:
                 return 0
