--- functions.php	2005/09/13 19:19:36	1.207
+++ functions.php	2005/09/14 18:57:08	1.208
@@ -45,9 +45,10 @@
     {
         $subject = $from = $to = '';
         $msgnum = $sorted[$i];
-        $ref_contenu_message = $pop->headerinfo($pop->msgno($msgnum), $ev);
+        $pop_msgno_msgnum = $pop->msgno($msgnum);
+        $ref_contenu_message = $pop->headerinfo($pop_msgno_msgnum, $ev);
         if(NoccException::isException($ev)) return;
-        $struct_msg = $pop->fetchstructure($pop->msgno($msgnum), $ev);
+        $struct_msg = $pop->fetchstructure($pop_msgno_msgnum, $ev);
         if(NoccException::isException($ev)) return;
         $subject_array = nocc_imap::mime_header_decode($ref_contenu_message->subject);
         for ($j = 0; $j < count($subject_array); $j++)
@@ -182,7 +183,9 @@
     if ($struct_msg->type == 3 || (isset($struct_msg->parts) && (sizeof($struct_msg->parts) > 0)))
         GetPart($attach_tab, $struct_msg, NULL, $conf->display_rfc822);
     else {
-        GetSinglePart($attach_tab, $struct_msg, $pop->fetchheader($mail, $ev), $pop->body($mail, $ev));
+        $pop_fetchheader_mail_ev = $pop->fetchheader($mail, $ev);
+        $pop_body_mail_ev = $pop->body($mail, $ev);
+        GetSinglePart($attach_tab, $struct_msg, $pop_fetchheader_mail_ev, $pop_body_mail_ev);
         if(NoccException::isException($ev)) return;
     }
 
