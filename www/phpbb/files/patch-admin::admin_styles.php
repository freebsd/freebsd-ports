--- admin/admin_styles.php.orig	Sun Dec 22 04:09:58 2002
+++ admin/admin_styles.php	Mon Jul  7 12:59:05 2003
@@ -39,16 +39,14 @@
 // Check if the user has cancled a confirmation message.
 //
 $phpbb_root_path = "./../";
+require($phpbb_root_path . 'extension.inc');
 
 $confirm = ( isset($HTTP_POST_VARS['confirm']) ) ? TRUE : FALSE;
 $cancel = ( isset($HTTP_POST_VARS['cancel']) ) ? TRUE : FALSE;
 
-if (empty($HTTP_POST_VARS['send_file']))
-{
-	$no_page_header = ( $cancel ) ? TRUE : FALSE;
-	require($phpbb_root_path . 'extension.inc');
-	require('./pagestart.' . $phpEx);
-}
+$no_page_header = (!empty($HTTP_POST_VARS['send_file']) || $cancel) ? TRUE : FALSE;
+
+require('./pagestart.' . $phpEx);
 
 if ($cancel)
 {

