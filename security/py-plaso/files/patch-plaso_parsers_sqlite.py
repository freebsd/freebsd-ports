--- plaso/parsers/sqlite.py.orig	2024-06-08 09:38:22 UTC
+++ plaso/parsers/sqlite.py
@@ -118,8 +118,8 @@ class SQLiteDatabase(object):
   SCHEMA_QUERY = (
       'SELECT tbl_name, sql '
       'FROM sqlite_master '
-      'WHERE type = "table" AND tbl_name != "xp_proc" '
-      'AND tbl_name != "sqlite_sequence"')
+      'WHERE type = \'table\' AND tbl_name != \'xp_proc\' '
+      'AND tbl_name != \'sqlite_sequence\'')
 
   def __init__(self, filename, temporary_directory=None):
     """Initializes a SQLite database.
