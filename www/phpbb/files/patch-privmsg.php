--- privmsg.php	2004-03-18 19:51:32.000000000 +0000
+++ privmsg.1.php	2004-03-26 19:51:07.000000000 +0000
@@ -212,7 +212,17 @@
 			break;
 		case 'savebox':
 			$l_box_name = $lang['Savebox'];
-			$pm_sql_user .= "AND ( ( pm.privmsgs_to_userid = " . $userdata['user_id'] . "
+			
+			//
+			// For some obscure reason, the assignment 
+			// concatenation operator was coded below, which 
+			// allowed an attacker to append arbitrary SQL code
+			// to the end of the $pm_sql_user variable.
+			// This is fixed below.
+			//
+			// -shaun2k2
+			//
+			$pm_sql_user = "AND ( ( pm.privmsgs_to_userid = " . $userdata['user_id'] . "
 					AND pm.privmsgs_type = " . PRIVMSGS_SAVED_IN_MAIL . " ) 
 				OR ( pm.privmsgs_from_userid = " . $userdata['user_id'] . "
 					AND pm.privmsgs_type = " . PRIVMSGS_SAVED_OUT_MAIL . " ) 
