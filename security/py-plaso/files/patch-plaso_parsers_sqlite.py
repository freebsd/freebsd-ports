--- plaso/parsers/sqlite.py.orig	2026-05-12 13:50:02 UTC
+++ plaso/parsers/sqlite.py
@@ -117,8 +117,8 @@ class SQLiteDatabase:
   SCHEMA_QUERY = (
       'SELECT tbl_name, sql '
       'FROM sqlite_master '
-      'WHERE type = "table" AND tbl_name != "xp_proc" '
-      'AND tbl_name != "sqlite_sequence"')
+      'WHERE type = \'table\' AND tbl_name != \'xp_proc\' '
+      'AND tbl_name != \'sqlite_sequence\'')
 
   def __init__(self, filename, temporary_directory=None):
     """Initializes a SQLite database.
