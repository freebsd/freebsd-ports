--- wwsympa/wwsympa.fcgi	2003/11/28 18:16:39
+++ wwsympa/wwsympa.fcgi	2003/12/28 18:16:39
@@ -3523,10 +3523,10 @@
 	 close MSG;
 
 	 $param->{'spool'}{$id}{'size'} = int( (-s "$Conf{'queuemod'}/$msg") / 1024 + 0.5);
-	 $param->{'spool'}{$id}{'subject'} =  &MIME::Words::decode_mimewords($mail->head->get('Subject'));
+	 $param->{'spool'}{$id}{'subject'} =  &tools::decode_mimewords($mail->head->get('Subject'));
 	 $param->{'spool'}{$id}{'subject'} ||= 'no_subject';
 	 $param->{'spool'}{$id}{'date'} = $mail->head->get('Date');
-	 $param->{'spool'}{$id}{'from'} = &MIME::Words::decode_mimewords($mail->head->get('From'));
+	 $param->{'spool'}{$id}{'from'} = &tools::decode_mimewords($mail->head->get('From'));
 	 foreach my $field ('subject','date','from') {
 	     $param->{'spool'}{$id}{$field} =~ s/</&lt;/;
 	     $param->{'spool'}{$id}{$field} =~ s/>/&gt;/;
@@ -3595,7 +3595,7 @@
 	     unless  ($#sender_hdr == -1) {
 		 my $rejected_sender = $sender_hdr[0]->address;
 		 my %context;
-		 $context{'subject'} = &MIME::Words::decode_mimewords($msg->head->get('subject'));
+		 $context{'subject'} = &tools::decode_mimewords($msg->head->get('subject'));
 		 $context{'rejected_by'} = $param->{'user'}{'email'};
 		 $list->send_file('reject', $rejected_sender, $robot, \%context);
 	     }
@@ -4352,7 +4352,7 @@
 
      ## Decode subject header fields
      foreach my $m (@{$param->{'res'}}) {
-	 $m->{'subj'} = &MIME::Words::decode_mimewords($m->{'subj'});
+	 $m->{'subj'} = &tools::decode_mimewords($m->{'subj'});
      }
 
      return 1;
@@ -9020,7 +9020,7 @@
      ($param->{'local_to'},$param->{'domain_to'}) = split ('@',$param->{'to'});
 
      $param->{'mailto'}= &mailto($list,$param->{'to'});
-     $param->{'subject'}= &MIME::Words::encode_mimewords($in{'subject'});
+     $param->{'subject'}= $in{'subject'}; # &tools::encode_mimewords($in{'subject'});
      $param->{'in_reply_to'}= $in{'in_reply_to'};
      $param->{'message_id'} = &tools::get_message_id($robot);
      return 1;
