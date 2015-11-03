--- Tools/SOGoToolManageEAS.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolManageEAS.m
@@ -227,7 +227,7 @@ typedef enum
 
               NSMutableString *sql;
 
-              sql = [NSMutableString stringWithFormat: @"DELETE FROM %@" @" WHERE c_path like '/%@%'", [oc tableName], deviceId];
+              sql = [NSMutableString stringWithFormat: @"DELETE FROM %@ WHERE c_path like '/%@'", [oc tableName], deviceId];
 
               [oc performBatchSQLQueries: [NSArray arrayWithObject: sql]];
               rc = YES;
