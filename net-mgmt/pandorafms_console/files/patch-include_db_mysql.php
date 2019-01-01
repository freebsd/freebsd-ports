--- include/db/mysql.php.orig	2016-04-08 09:50:59 UTC
+++ include/db/mysql.php
@@ -29,13 +29,13 @@ function mysql_connect_db($host = null, 
 		$port = $config["dbport"];
 	
 	// Non-persistent connection: This will help to avoid mysql errors like "has gone away" or locking problems
-	// If you want persistent connections change it to mysql_pconnect(). 
-	$connect_id = @mysql_connect($host . ":" . $port, $user, $pass, true);
+	// If you want persistent connections change it to mysqli_pconnect(). 
+	$connect_id = @mysqli_connect($host . ":" . $port,  $user,  $pass);
 	if (! $connect_id) {
 		return false;
 	}
 	
-	mysql_select_db($db, $connect_id);
+	mysqli_select_db($connect_id, $db);
 	return $connect_id;
 }
 
@@ -299,14 +299,14 @@ function mysql_db_process_sql($sql, $ret
 			$dbconnection = $config['dbconnection'];
 		}
 		
-		$result = mysql_query ($sql, $dbconnection);
+		$result = mysqli_query($dbconnection, $sql);
 		
 		$time = microtime (true) - $start;
 		if ($result === false) {
 			$backtrace = debug_backtrace ();
 			$error = sprintf ('%s (\'%s\') in <strong>%s</strong> on line %d',
-				mysql_error (), $sql, $backtrace[0]['file'], $backtrace[0]['line']);
-			db_add_database_debug_trace ($sql, mysql_error ($dbconnection));
+				mysqli_error($dbconnection), $sql, $backtrace[0]['file'], $backtrace[0]['line']);
+			db_add_database_debug_trace ($sql, mysqli_error($dbconnection));
 			set_error_handler ('db_sql_error_handler');
 			trigger_error ($error);
 			restore_error_handler ();
@@ -314,29 +314,29 @@ function mysql_db_process_sql($sql, $ret
 		}
 		elseif ($result === true) {
 			if ($rettype == "insert_id") {
-				$result = mysql_insert_id ($dbconnection);
+				$result = ((is_null($___mysqli_res = mysqli_insert_id($dbconnection))) ? false : $___mysqli_res);
 			}
 			elseif ($rettype == "info") {
-				$result = mysql_info ($dbconnection);
+				$result = mysqli_info($dbconnection);
 			}
 			else {
-				$result = mysql_affected_rows ($dbconnection);
+				$result = mysqli_affected_rows($dbconnection);
 			}
 			
-			db_add_database_debug_trace ($sql, $result, mysql_affected_rows ($dbconnection),
+			db_add_database_debug_trace ($sql, $result, mysqli_affected_rows($dbconnection),
 				array ('time' => $time));
 			return $result;
 		}
 		else {
-			db_add_database_debug_trace ($sql, 0, mysql_affected_rows ($dbconnection), 
+			db_add_database_debug_trace ($sql, 0, mysqli_affected_rows($dbconnection), 
 				array ('time' => $time));
-			while ($row = mysql_fetch_assoc ($result)) {
+			while ($row = mysqli_fetch_assoc($result)) {
 				array_push ($retval, $row);
 			}
 			
 			if ($cache === true)
 				$sql_cache[$sql] = $retval;
-			mysql_free_result ($result);
+			((mysqli_free_result($result) || (is_object($result) && (get_class($result) == "mysqli_result"))) ? true : false);
 		}
 	}
 	
@@ -355,7 +355,8 @@ function mysql_db_process_sql($sql, $ret
  * @return string String cleaned.
  */
 function mysql_escape_string_sql($string) {
-	$str = mysql_real_escape_string($string);
+	global $config;
+	$str = mysqli_real_escape_string($config['dbconnection'], $string);
 	
 	return $str;
 }
@@ -754,10 +755,10 @@ function mysql_db_get_all_rows_filter ($
 function mysql_db_get_num_rows ($sql) {
 	global $config;
 	
-	$result = mysql_query($sql, $config['dbconnection']);
+	$result = mysqli_query($config['dbconnection'], $sql);
 	
 	if ($result) {
-		return mysql_num_rows($result);
+		return mysqli_num_rows($result);
 	}
 	else { 
 		return 0;
@@ -972,11 +973,12 @@ function mysql_db_process_sql_delete($ta
  * @return mixed The row or false in error.
  */
 function mysql_db_get_all_row_by_steps_sql($new = true, &$result, $sql = null) {
+	global $config;
 	if ($new == true)
-		$result = mysql_query($sql);
+		$result = mysqli_query($config['dbconnection'], $sql);
 	
 	if ($result) {
-		return mysql_fetch_assoc($result);
+		return mysqli_fetch_assoc($result);
 	}
 	else {
 		return array();
@@ -987,24 +989,27 @@ function mysql_db_get_all_row_by_steps_s
  * Starts a database transaction.
  */
 function mysql_db_process_sql_begin() {
-	mysql_query ('SET AUTOCOMMIT = 0');
-	mysql_query ('START TRANSACTION');
+	global $config;
+	mysqli_query($config['dbconnection'], 'SET AUTOCOMMIT = 0');
+	mysqli_query($config['dbconnection'], 'START TRANSACTION');
 }
 
 /**
  * Commits a database transaction.
  */
 function mysql_db_process_sql_commit() {
-	mysql_query ('COMMIT');
-	mysql_query ('SET AUTOCOMMIT = 1');
+	global $config;
+	mysqli_query($config['dbconnection'], 'COMMIT');
+	mysqli_query($config['dbconnection'], 'SET AUTOCOMMIT = 1');
 }
 
 /**
  * Rollbacks a database transaction.
  */
 function mysql_db_process_sql_rollback() {
-	mysql_query ('ROLLBACK ');
-	mysql_query ('SET AUTOCOMMIT = 1');
+	global $config;
+	mysqli_query($config['dbconnection'], 'ROLLBACK ');
+	mysqli_query($config['dbconnection'], 'SET AUTOCOMMIT = 1');
 }
 
 /**
@@ -1018,7 +1023,7 @@ function mysql_safe_sql_string($string) 
 	
 	global $config;
 	
-	return mysql_real_escape_string($string, $config['dbconnection']);
+	return mysqli_real_escape_string($config['dbconnection'], $string);
 }
 
 /**
@@ -1027,7 +1032,8 @@ function mysql_safe_sql_string($string) 
  * @return string Return the string error.
  */
 function mysql_db_get_last_error() {
-	return mysql_error();
+	global $config;
+	return mysqli_error($config['dbconnection']);
 }
 
 /**
@@ -1064,9 +1070,10 @@ function mysql_get_system_time() {
  * @return mixed Return the type name or False in error case.
  */
 function mysql_db_get_type_field_table($table, $field) {
-	$result = mysql_query('SELECT parameters FROM ' . $table);
+	global $config;
+	$result = mysqli_query($config['dbconnection'], 'SELECT parameters FROM ' . $table);
 	
-	return mysql_field_type($result, $field); 
+	return ((is_object($___mysqli_tmp = mysqli_fetch_field_direct($result, 0)) && !is_null($___mysqli_tmp = $___mysqli_tmp->type)) ? ((($___mysqli_tmp = (string)(substr(( (($___mysqli_tmp == MYSQLI_TYPE_STRING) || ($___mysqli_tmp == MYSQLI_TYPE_VAR_STRING) ) ? "string " : "" ) . ( (in_array($___mysqli_tmp, array(MYSQLI_TYPE_TINY, MYSQLI_TYPE_SHORT, MYSQLI_TYPE_LONG, MYSQLI_TYPE_LONGLONG, MYSQLI_TYPE_INT24))) ? "int " : "" ) . ( (in_array($___mysqli_tmp, array(MYSQLI_TYPE_FLOAT, MYSQLI_TYPE_DOUBLE, MYSQLI_TYPE_DECIMAL, ((defined("MYSQLI_TYPE_NEWDECIMAL")) ? constant("MYSQLI_TYPE_NEWDECIMAL") : -1)))) ? "real " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_TIMESTAMP) ? "timestamp " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_YEAR) ? "year " : "" ) . ( (($___mysqli_tmp == MYSQLI_TYPE_DATE) || ($___mysqli_tmp == MYSQLI_TYPE_NEWDATE) ) ? "date " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_TIME) ? "time " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_SET) ? "set " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_ENUM) ? "enum " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_GEOMETRY) ? "geometry " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_DATETIME) ? "datetime " : "" ) . ( (in_array($___mysqli_tmp, array(MYSQLI_TYPE_TINY_BLOB, MYSQLI_TYPE_BLOB, MYSQLI_TYPE_MEDIUM_BLOB, MYSQLI_TYPE_LONG_BLOB))) ? "blob " : "" ) . ( ($___mysqli_tmp == MYSQLI_TYPE_NULL) ? "null " : "" ), 0, -1))) == "") ? "unknown" : $___mysqli_tmp) : false); 
 }
 
 /**
@@ -1136,11 +1143,11 @@ function mysql_db_process_file ($path, $
 				$query .= $sql_line;
 				
 				if (preg_match("/;[\040]*\$/", $sql_line)) {
-					if (!$result = mysql_query($query)) {
+					if (!$result = mysqli_query($config['dbconnection'], $query)) {
 						// Error. Rollback the transaction
 						mysql_db_process_sql_rollback();
 						
-						$error_message = mysql_error();
+						$error_message = mysqli_error($config['dbconnection']);
 						
 						// Handle the error
 						if ($handle_error) {
