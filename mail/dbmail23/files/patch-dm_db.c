--- src/dm_db.c.orig	Tue Jan  6 14:51:55 2009
+++ src/dm_db.c	Sun Jan 25 19:25:06 2009
@@ -312,8 +312,9 @@
 	TRACE(TRACE_DATABASE,"[%p] [%s]", c, query);
 	TRY
 		gettimeofday(&before, NULL);
-		result = Connection_execute(c, query);
+		Connection_execute(c, query);
 		gettimeofday(&after, NULL);
+		result = TRUE;
 	CATCH(SQLException)
 		LOG_SQLERROR;
 		TRACE(TRACE_ERR,"failed query [%s]", query);
@@ -395,26 +396,51 @@
 int db_stmt_set_str(S s, int index, const char *x)
 {
 	TRACE(TRACE_DATABASE,"[%p] %d:[%s]", s, index, x);
-	return PreparedStatement_setString(s, index, x);
+	TRY
+		PreparedStatement_setString(s, index, x);
+		return TRUE;
+	CATCH(SQLException)
+		return FALSE;
+	END_TRY;
 }
 int db_stmt_set_int(S s, int index, int x)
 {
 	TRACE(TRACE_DATABASE,"[%p] %d:[%d]", s, index, x);
-	return PreparedStatement_setInt(s, index, x);
+	TRY
+		PreparedStatement_setInt(s, index, x);
+		return TRUE;
+	CATCH(SQLException)
+		return FALSE;
+	END_TRY;
 }
 int db_stmt_set_u64(S s, int index, u64_t x)
 {	
 	TRACE(TRACE_DATABASE,"[%p] %d:[%llu]", s, index, x);
-	return PreparedStatement_setLLong(s, index, (long long)x);
+	TRY
+		PreparedStatement_setLLong(s, index, (long long)x);
+		return TRUE;
+	CATCH(SQLException)
+		return FALSE;
+	END_TRY;
 }
 int db_stmt_set_blob(S s, int index, const void *x, int size)
 {
 //	TRACE(TRACE_DATABASE,"[%p] %d:[%s]", s, index, (const char *)x);
-	return PreparedStatement_setBlob(s, index, x, size);
+	TRY
+		PreparedStatement_setBlob(s, index, x, size);
+		return TRUE;
+	CATCH(SQLException)
+		return FALSE;
+	END_TRY;
 }
 gboolean db_stmt_exec(S s)
 {
-	return PreparedStatement_execute(s);
+	TRY
+		PreparedStatement_execute(s);
+		return TRUE;
+	CATCH(SQLException)
+		return FALSE;
+	END_TRY;
 }
 R db_stmt_query(S s)
 {
@@ -474,28 +500,36 @@
 int db_begin_transaction(C c)
 {
 	TRACE(TRACE_DATABASE,"BEGIN");
-	if (! Connection_beginTransaction(c))
+	TRY
+		Connection_beginTransaction(c);
+		return DM_SUCCESS;
+	CATCH(SQLException)
 		return DM_EQUERY;
-	return DM_SUCCESS;
+	END_TRY;
 }
 
 int db_commit_transaction(C c)
 {
 	TRACE(TRACE_DATABASE,"COMMIT");
-	if (! Connection_commit(c)) {
+	TRY
+		Connection_commit(c);
+		return DM_SUCCESS;
+	CATCH(SQLException)
 		db_rollback_transaction(c);
 		return DM_EQUERY;
-	}
-	return DM_SUCCESS;
+	END_TRY;
 }
 
 
 int db_rollback_transaction(C c)
 {
 	TRACE(TRACE_DATABASE,"ROLLBACK");
-	if (! Connection_rollback(c))
+	TRY
+		Connection_rollback(c);
+		return DM_SUCCESS;
+	CATCH(SQLException)
 		return DM_EQUERY;
-	return DM_SUCCESS;
+	END_TRY;
 }
 
 int db_savepoint(C UNUSED c, const char UNUSED *id)
