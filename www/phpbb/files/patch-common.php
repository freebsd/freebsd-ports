--- common.php:1.74.2.10	Wed Jun  4 10:41:39 2003
+++ common.php	Wed Apr 21 05:18:02 2004
@@ -6,8 +6,7 @@
  *   copyright            : (C) 2001 The phpBB Group
  *   email                : support@phpbb.com
  *
- *   $Id: common.php,v 1.74.2.10 2003/06/04 17:41:39 acydburn Exp $
- *
+ *   $Id: common.php,v 1.74.2.11 2004/04/21 12:18:02 psotfx Exp $
  *
  ***************************************************************************/
 
@@ -25,9 +24,44 @@
 	die("Hacking attempt");
 }
 
+//
+function unset_vars(&$var)
+{
+	while (list($var_name, $null) = @each($var))
+	{
+		unset($GLOBALS[$var_name]);
+	}
+	return;
+}
+
+//
 error_reporting  (E_ERROR | E_WARNING | E_PARSE); // This will NOT report uninitialized variables
 set_magic_quotes_runtime(0); // Disable magic_quotes_runtime
 
+$ini_val = (@phpversion() >= '4.0.0') ? 'ini_get' : 'get_cfg_var';
+
+// Unset globally registered vars - PHP5 ... hhmmm
+if (@$ini_val('register_globals') == '1' || strtolower(@$ini_val('register_globals')) == 'on')
+{
+	$var_prefix = (phpversion() >= '4.3.0') ? '' : 'HTTP';
+	$var_suffix = (phpversion() >= '4.3.0') ? '' : '_VARS';
+
+	if(is_array(${$var_prefix . '_GET' . $var_suffix}))
+	{
+		unset_vars(${$var_prefix . '_GET' . $var_suffix});
+	}
+
+	if(is_array(${$var_prefix . '_POST' . $var_suffix}))
+	{
+		unset_vars(${$var_prefix . '_POST' . $var_suffix});
+	}
+
+	if(is_array(${$var_prefix . '_COOKIE' . $var_suffix}))
+	{
+		unset_vars(${$var_prefix . '_COOKIE' . $var_suffix});
+	}
+}
+
 //
 // addslashes to vars if magic_quotes_gpc is off
 // this is a security precaution to prevent someone
@@ -106,6 +140,7 @@
 $theme = array();
 $images = array();
 $lang = array();
+$nav_links = array();
 $gen_simple_header = FALSE;
 
 include($phpbb_root_path . 'config.'.$phpEx);
@@ -126,32 +161,12 @@
 //
 // Obtain and encode users IP
 //
-if( getenv('HTTP_X_FORWARDED_FOR') != '' )
-{
-	$client_ip = ( !empty($HTTP_SERVER_VARS['REMOTE_ADDR']) ) ? $HTTP_SERVER_VARS['REMOTE_ADDR'] : ( ( !empty($HTTP_ENV_VARS['REMOTE_ADDR']) ) ? $HTTP_ENV_VARS['REMOTE_ADDR'] : $REMOTE_ADDR );
-
-	$entries = explode(',', getenv('HTTP_X_FORWARDED_FOR'));
-	reset($entries);
-	while (list(, $entry) = each($entries)) 
-	{
-		$entry = trim($entry);
-		if ( preg_match("/^([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+)/", $entry, $ip_list) )
-		{
-			$private_ip = array('/^0\./', '/^127\.0\.0\.1/', '/^192\.168\..*/', '/^172\.((1[6-9])|(2[0-9])|(3[0-1]))\..*/', '/^10\..*/', '/^224\..*/', '/^240\..*/');
-			$found_ip = preg_replace($private_ip, $client_ip, $ip_list[1]);
-
-			if ($client_ip != $found_ip)
-			{
-				$client_ip = $found_ip;
-				break;
-			}
-		}
-	}
-}
-else
-{
-	$client_ip = ( !empty($HTTP_SERVER_VARS['REMOTE_ADDR']) ) ? $HTTP_SERVER_VARS['REMOTE_ADDR'] : ( ( !empty($HTTP_ENV_VARS['REMOTE_ADDR']) ) ? $HTTP_ENV_VARS['REMOTE_ADDR'] : $REMOTE_ADDR );
-}
+// I'm removing HTTP_X_FORWARDED_FOR ... this may well cause other problems such as
+// private range IP's appearing instead of the guilty routable IP, tough, don't
+// even bother complaining ... go scream and shout at the idiots out there who feel
+// "clever" is doing harm rather than good ... karma is a great thing ... :)
+//
+$client_ip = ( !empty($HTTP_SERVER_VARS['REMOTE_ADDR']) ) ? $HTTP_SERVER_VARS['REMOTE_ADDR'] : ( ( !empty($HTTP_ENV_VARS['REMOTE_ADDR']) ) ? $HTTP_ENV_VARS['REMOTE_ADDR'] : $REMOTE_ADDR );
 $user_ip = encode_ip($client_ip);
 
 //
