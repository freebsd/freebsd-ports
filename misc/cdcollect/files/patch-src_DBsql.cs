--- src/DBsql.cs.orig	2006-11-24 17:12:13 UTC
+++ src/DBsql.cs
@@ -958,10 +958,10 @@ public class CDDatabaseSql
 	private int sql_command_id (string comm)
 	{	
 		IDbCommand command = sqlite_connection.CreateCommand ();
-		command.CommandText = comm;
-		command.ExecuteScalar ();
+		command.CommandText = comm + "; SELECT last_insert_rowid() AS [ID]";
+		string s = command.ExecuteScalar ().ToString ();
 		command.Dispose ();
-		return (((SqliteConnection)sqlite_connection).LastInsertRowId);
+		return Int32.Parse (s);
 	}
 	
 	private void sql_command (string comm)
