--- Tools/SOGoToolRemoveDoubles.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolRemoveDoubles.m
@@ -175,7 +175,7 @@
 
   now = [NSCalendarDate date];
   delSql = [NSString stringWithFormat: @"UPDATE %@"
-                     @" SET c_deleted = 1, c_lastmodified = %d,"
+                     @" SET c_deleted = 1, c_lastmodified = %lu,"
                      @" c_content = ''"
 		     @" WHERE c_name = '%@'",
 		     tableName,
