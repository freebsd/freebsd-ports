--- includes/sessions.php.orig	Sun Jul 20 17:42:23 2003
+++ includes/sessions.php	Thu May  6 12:02:56 2004
@@ -147,7 +147,7 @@
 		$sql = "INSERT INTO " . SESSIONS_TABLE . "
 			(session_id, session_user_id, session_start, session_time, session_ip, session_page, session_logged_in)
 			VALUES ('$session_id', $user_id, $current_time, $current_time, '$user_ip', $page_id, $login)";
-		if ( !$db->sql_query($sql) )
+		if ( $user_id != ANONYMOUS && !$db->sql_query($sql) )
 		{
 			message_die(CRITICAL_ERROR, 'Error creating new session', '', __LINE__, __FILE__, $sql);
 		}
@@ -380,4 +380,4 @@
 	return $url;
 }
 
-?>
\ No newline at end of file
+?>
