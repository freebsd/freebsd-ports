--- plaso/parsers/sqlite_plugins/imessage.py.orig	2024-06-08 09:38:22 UTC
+++ plaso/parsers/sqlite_plugins/imessage.py
@@ -81,7 +81,7 @@ class IMessagePlugin(interface.SQLitePlugin):
 
   _CLIENT_VERSION_QUERY = (
       'SELECT key, value FROM _SqliteDatabaseProperties '
-      'WHERE key = "_ClientVersion"')
+      'WHERE key = \'_ClientVersion\'')
 
   def _GetClientVersion(self, cache, database):
     """Retrieves the client version.
