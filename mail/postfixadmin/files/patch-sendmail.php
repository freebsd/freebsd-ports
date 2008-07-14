--- sendmail.php	2007/12/02 13:59:33	250
+++ sendmail.php	2008/06/29 16:11:37	396
@@ -49,15 +49,20 @@
    $fHeaders .= "MIME-Version: 1.0\n";
    $fHeaders .= "Content-Type: text/plain; charset=utf-8\n";
    $fHeaders .= "Content-Transfer-Encoding: 8bit\n";
+   $fHeaders .= "\n";
 
-   $fHeaders .= escape_string ($_POST['fBody']);
+   $tBody = $_POST['fBody'];
+   if (get_magic_quotes_gpc ())
+   {
+      $tBody = stripslashes($tBody);
+   }
+   $fHeaders .= $tBody;
 
    if (empty ($fTo) or !check_email ($fTo))
    {
       $error = 1;
       $tTo = escape_string ($_POST['fTo']);
       $tSubject = escape_string ($_POST['fSubject']);
-      $tBody = escape_string ($_POST['fBody']);
       $tMessage = $PALANG['pSendmail_to_text_error'];
    }
