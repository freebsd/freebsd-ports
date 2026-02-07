--- src/sqlite3_drv.c.orig	2024-06-01 03:59:05 UTC
+++ src/sqlite3_drv.c
@@ -918,7 +918,7 @@ _ds_get_signature (DSPAM_CTX * CTX, struct _ds_spam_si
   }
 
   snprintf (query, sizeof (query),
-            "SELECT data FROM dspam_signature_data WHERE signature=\"%s\"",
+            "SELECT data FROM dspam_signature_data WHERE signature='%s'",
             signature);
 
   if ((sqlite3_prepare(s->dbh, query, -1, &stmt, &query_tail))
@@ -967,7 +967,7 @@ _ds_set_signature (DSPAM_CTX * CTX, struct _ds_spam_si
 
   snprintf (scratch, sizeof (scratch),
             "INSERT INTO dspam_signature_data (signature,created_on,data)"
-            " VALUES (\"%s\",date('now'),?)", signature);
+            " VALUES ('%s',date('now'),?)", signature);
 
   if ((sqlite3_prepare(s->dbh, scratch, -1, &stmt, &query_tail))!=SQLITE_OK)
   {
@@ -1001,7 +1001,7 @@ _ds_delete_signature (DSPAM_CTX * CTX, const char *sig
   }
 
   snprintf (query, sizeof (query),
-            "DELETE FROM dspam_signature_data WHERE signature=\"%s\"",
+            "DELETE FROM dspam_signature_data WHERE signature='%s'",
              signature);
 
   if ((sqlite3_exec(s->dbh, query, NULL, NULL, &err))!=SQLITE_OK)
@@ -1028,7 +1028,7 @@ _ds_verify_signature (DSPAM_CTX * CTX, const char *sig
   }
 
   snprintf (query, sizeof (query),
-        "SELECT signature FROM dspam_signature_data WHERE signature=\"%s\"",
+        "SELECT signature FROM dspam_signature_data WHERE signature='%s'",
         signature);
 
   if ((sqlite3_get_table(s->dbh, query, &row, &nrow, &ncolumn, &err))!=SQLITE_OK)  {
