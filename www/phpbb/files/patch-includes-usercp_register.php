--- includes/usercp_register.php.orig	Sun Mar 13 19:44:02 2005
+++ includes/usercp_register.php	Sun Mar 13 19:48:34 2005
@@ -145,10 +145,9 @@
 	if ( $mode == 'register' )
 	{
 		$attachsig = ( isset($HTTP_POST_VARS['attachsig']) ) ? ( ($HTTP_POST_VARS['attachsig']) ? TRUE : 0 ) : $board_config['allow_sig'];
-
-		$allowhtml = ( isset($HTTP_POST_VARS['allowhtml']) ) ? ( ($HTTP_POST_VARS['allowhtml']) ? TRUE : 0 ) : $board_config['allow_html'];
-		$allowbbcode = ( isset($HTTP_POST_VARS['allowbbcode']) ) ? ( ($HTTP_POST_VARS['allowbbcode']) ? TRUE : 0 ) : $board_config['allow_bbcode'];
-		$allowsmilies = ( isset($HTTP_POST_VARS['allowsmilies']) ) ? ( ($HTTP_POST_VARS['allowsmilies']) ? TRUE : 0 ) : $board_config['allow_smilies'];
+		$allowhtml = ( ($board_config['allowhtml']) ) ? TRUE : 0;
+		$allowbbcode = ( ($board_config['allowbbcode']) ) ? TRUE : 0;
+		$allowsmilies = ( ($board_config['allowsmilies']) ) ? TRUE : 0;	
 	}
 	else
 	{
