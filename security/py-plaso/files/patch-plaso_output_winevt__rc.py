--- plaso/output/winevt_rc.py.orig	2024-06-08 09:38:22 UTC
+++ plaso/output/winevt_rc.py
@@ -16,7 +16,7 @@ class Sqlite3DatabaseFile(object):
 
   _HAS_TABLE_QUERY = (
       'SELECT name FROM sqlite_master '
-      'WHERE type = "table" AND name = "{0:s}"')
+      'WHERE type = \'table\' AND name = \'{0:s}\'')
 
   def __init__(self):
     """Initializes the database file object."""
@@ -166,7 +166,7 @@ class WinevtResourcesSqlite3DatabaseReader(object):
     """
     table_names = ['event_log_providers']
     column_names = ['event_log_provider_key']
-    condition = f'log_source == "{log_source:s}"'
+    condition = f'log_source == \'{log_source:s}\''
 
     values_list = list(self._database_file.GetValues(
         table_names, column_names, condition))
@@ -202,7 +202,7 @@ class WinevtResourcesSqlite3DatabaseReader(object):
       return None
 
     column_names = ['message_string']
-    condition = f'message_identifier == "0x{message_identifier:08x}"'
+    condition = f'message_identifier == \'0x{message_identifier:08x}\''
 
     values = list(self._database_file.GetValues(
         [table_name], column_names, condition))
@@ -290,7 +290,7 @@ class WinevtResourcesSqlite3DatabaseReader(object):
       return None
 
     column_names = ['value']
-    condition = f'name == "{attribute_name:s}"'
+    condition = f'name == \'{attribute_name:s}\''
 
     values = list(self._database_file.GetValues(
         [table_name], column_names, condition))
@@ -485,7 +485,7 @@ class WinevtResourcesHelper(object):
         'windows_wevt_template_event'):
       # TODO: add message_file_identifiers to filter_expression
       filter_expression = (
-          f'provider_identifier == "{provider_identifier:s}" and '
+          f'provider_identifier == \'{provider_identifier:s}\' and '
           f'identifier == {message_identifier:d}')
       if event_version is not None:
         filter_expression = (
