--- wwsympa/wwsympa.fcgi	Mon Jun 21 15:04:16 2004
+++ wwsympa/wwsympa.fcgi	Sat Oct 23 16:15:08 2004
@@ -3557,10 +3557,10 @@
 
 
 	 $param->{'spool'}{$id}{'size'} = int( (-s "$Conf{'queuemod'}/$msg") / 1024 + 0.5);
-	 $param->{'spool'}{$id}{'subject'} =  &MIME::Words::decode_mimewords($mail->{'msg'}->head->get('Subject'));
+	 $param->{'spool'}{$id}{'subject'} =  &tools::decode_mimewords($mail->{'msg'}->head->get('Subject'));
 	 $param->{'spool'}{$id}{'subject'} ||= 'no_subject';
 	 $param->{'spool'}{$id}{'date'} = $mail->{'msg'}->head->get('Date');
-	 $param->{'spool'}{$id}{'from'} = &MIME::Words::decode_mimewords($mail->{'msg'}->head->get('From'));
+	 $param->{'spool'}{$id}{'from'} = &tools::decode_mimewords($mail->{'msg'}->head->get('From'));
 	 foreach my $field ('subject','date','from') {
 	     $param->{'spool'}{$id}{$field} =~ s/</&lt;/;
 	     $param->{'spool'}{$id}{$field} =~ s/>/&gt;/;
@@ -3629,7 +3629,7 @@
 	     unless  ($#sender_hdr == -1) {
 		 my $rejected_sender = $sender_hdr[0]->address;
 		 my %context;
-		 $context{'subject'} = &MIME::Words::decode_mimewords($msg->head->get('subject'));
+		 $context{'subject'} = &tools::decode_mimewords($msg->head->get('subject'));
 		 $context{'rejected_by'} = $param->{'user'}{'email'};
 		 $list->send_file('reject', $rejected_sender, $robot, \%context);
 	     }
@@ -4381,7 +4381,7 @@
 
      ## Decode subject header fields
      foreach my $m (@{$param->{'res'}}) {
-	 $m->{'subj'} = &MIME::Words::decode_mimewords($m->{'subj'});
+	 $m->{'subj'} = &tools::decode_mimewords($m->{'subj'});
      }
 
      return 1;
@@ -9135,7 +9135,7 @@
      ($param->{'local_to'},$param->{'domain_to'}) = split ('@',$param->{'to'});
 
      $param->{'mailto'}= &mailto($list,$param->{'to'});
-     $param->{'subject'}= &MIME::Words::encode_mimewords($in{'subject'});
+     $param->{'subject'}= $in{'subject'}; # &tools::encode_mimewords($in{'subject'});
      $param->{'in_reply_to'}= $in{'in_reply_to'};
      $param->{'message_id'} = &tools::get_message_id($robot);
      return 1;
