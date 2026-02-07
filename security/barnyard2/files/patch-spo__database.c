--- src/output-plugins/spo_database.c.orig	2018-10-06 12:58:28 UTC
+++ src/output-plugins/spo_database.c
@@ -871,7 +871,7 @@ void DatabaseInitFinalize(int unused, vo
 {
     DatabaseData *data = (DatabaseData *)arg;
     
-    if ((data == NULL))
+    if (data == NULL)
     {
         FatalError("database data uninitialized\n");
     }
