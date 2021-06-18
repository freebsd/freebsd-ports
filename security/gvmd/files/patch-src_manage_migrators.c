--- src/manage_migrators.c	2021-06-15 13:01:15.511923000 -0500
+++ src/manage_migrators.c	2021-06-15 13:04:16.836317000 -0500
@@ -2627,10 +2627,20 @@
 
   sql ("ALTER TABLE results_trash DROP COLUMN IF EXISTS score;");
 
-  /* Change the vt_severities table to a CVSS score */
-  sql ("ALTER TABLE vt_severities ALTER COLUMN score"
-       " SET DATA TYPE double precision;");
-  sql ("UPDATE vt_severities SET score = round((score / 10.0)::numeric, 1);");
+ /* Change the vt_severities table to use a CVSS score
+   * if it already exists (migrating from a 21.04 development version) */
+  if (sql_int ("SELECT EXISTS (SELECT * FROM information_schema.tables"
+               "               WHERE table_catalog = '%s'"
+               "               AND table_schema = 'public'"
+               "               AND table_name = 'vt_severities')"
+               " ::integer;",
+               sql_database ()))
+    {
+      sql ("ALTER TABLE vt_severities ALTER COLUMN score"
+           " SET DATA TYPE double precision;");
+      sql ("UPDATE vt_severities"
+           " SET score = round((score / 10.0)::numeric, 1);");
+    }
 
   /* Set the database version to 242. */
 
