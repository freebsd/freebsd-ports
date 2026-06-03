--- plaso/parsers/sqlite_plugins/imessage.py.orig	2026-05-12 13:50:02 UTC
+++ plaso/parsers/sqlite_plugins/imessage.py
@@ -80,7 +80,7 @@ class IMessagePlugin(interface.SQLitePlugin):
 
   _CLIENT_VERSION_QUERY = (
       'SELECT key, value FROM _SqliteDatabaseProperties '
-      'WHERE key = "_ClientVersion"')
+      'WHERE key = \'_ClientVersion\'')
 
   def _GetClientVersion(self, cache, database):
     """Retrieves the client version.
