--- send.php	2005/07/03 20:43:02	1.134
+++ send.php	2005/09/14 18:57:08	1.135
@@ -102,7 +102,8 @@
         $mail->smtp_server = $_SESSION['nocc_smtp_server'];
         $mail->smtp_port = $_SESSION['nocc_smtp_port'];
         $mail->charset = $charset;
-        $mail->from = cut_address(trim($mail_from), $charset);
+        $trim_mail_from = trim($mail_from);
+        $mail->from = cut_address($trim_mail_from, $charset);
         $mail->from = $mail->from[0];
         $mail->priority = $_REQUEST['priority'];
         $mail->receipt = isset($_REQUEST['receipt']);
@@ -110,13 +111,16 @@
         // $ip = (getenv('HTTP_X_FORWARDED_FOR') ? getenv('HTTP_X_FORWARDED_FOR') : getenv('REMOTE_ADDR'));
         // $mail->headers .= 'X-Originating-Ip: [' . $ip . ']' . $mail->crlf;
         $mail->headers .= 'User-Agent: ' . $conf->nocc_name . ' <' . $conf->nocc_url . '>';
-        $mail->to = cut_address(trim($mail_to), $charset);
-        $mail->cc = cut_address(trim($mail_cc), $charset);
+        $trim_mail_to = trim($mail_to);
+        $trim_mail_cc = trim($mail_cc);
+        $mail->to = cut_address($trim_mail_to, $charset);
+        $mail->cc = cut_address($trim_mail_cc, $charset);
 	$user_prefs = $_SESSION['nocc_user_prefs'];
         if(isset($user_prefs->cc_self) && $user_prefs->cc_self) {
             array_unshift($mail->cc, $mail->from);
         }
-        $mail->bcc = cut_address(trim($mail_bcc), $charset);
+        $trim_mail_bcc = trim($mail_bcc);
+        $mail->bcc = cut_address($trim_mail_bcc, $charset);
         if ($mail_subject != '')
             $mail->subject = trim($mail_subject);
 
