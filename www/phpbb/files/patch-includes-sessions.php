--- includes/sessions.php.orig	Sat May 14 05:04:00 2005
+++ includes/sessions.php	Sun May 15 18:53:48 2005
@@ -167,7 +167,7 @@
 		$sql = "INSERT INTO " . SESSIONS_TABLE . "
 			(session_id, session_user_id, session_start, session_time, session_ip, session_page, session_logged_in, session_admin)
 			VALUES ('$session_id', $user_id, $current_time, $current_time, '$user_ip', $page_id, $login, $admin)";
-		if ( !$db->sql_query($sql) )
+		if ( $user_id != ANONYMOUS && !$db->sql_query($sql) )
 		{
 			message_die(CRITICAL_ERROR, 'Error creating new session', '', __LINE__, __FILE__, $sql);
 		}
