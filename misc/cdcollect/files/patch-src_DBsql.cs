
$FreeBSD$

--- src/DBsql.cs.orig
+++ src/DBsql.cs
@@ -958,10 +958,10 @@
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
