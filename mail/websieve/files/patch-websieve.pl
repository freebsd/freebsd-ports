--- websieve.pl.orig	Mon Sep 17 01:23:49 2001
+++ websieve.pl	Fri Apr 25 19:49:30 2003
@@ -98,7 +98,7 @@
 	$encode_params=&encode_base64($encode_params) if $userc4;
 	$auth_cookie=cookie(-name => 'websieve',
 			-value=>$encode_params,
-			-path=>"$program_url",
+			-path=>"/",
 			-expires => 'now');
 	print header(-cookie=> $auth_cookie);
 	param('op','');
@@ -193,7 +193,7 @@
 	$encode_params=&encode_base64($encode_params) if $userc4;	
 	$auth_cookie=cookie(-name => 'websieve',
 			-value=>$encode_params,
-			-path=>"$program_url",
+			-path=>"/",
 			-expires => $expires);
 	if ($uid ne "" && $pass ne "")
 	{
@@ -301,7 +301,7 @@
 	}
 
 	print "</TABLE></TD></TABLE>";
-	print "<b>NOTE:&nbspYou will lose ALL changes made to a script in advanced mode if you switch back to basic mode.</b>" if ($mode eq 'advanced' && $op eq 'advanced');
+	print "<b>NOTE:&nbsp;You will lose ALL changes made to a script in advanced mode if you switch back to basic mode.</b>" if ($mode eq 'advanced' && $op eq 'advanced');
 }
 
 
@@ -405,7 +405,7 @@
 		else {
 		    $change=1 ;
 		    param('mbx',$mbx);
-		    print hidden('mbx');
+		    #print hidden('mbx');
 		}
 	}
 	if (!$mbx || !(( $acl && $useracl) || $maxquota)) {
@@ -547,7 +547,7 @@
 	}
 	@tmpbox=@mailboxes;
         print "<TR><TD >",popup_menu('selectedmbx',[@aclview],' ') if ($shortacl);
-	print "&nbsp&nbsp".submit('Select Folder')."&nbsp".submit('Up One Level')."</TD></TR>" if ($shortacl && $ismanager);
+	print "&nbsp;&nbsp;".submit('Select Folder')."&nbsp;".submit('Up One Level')."</TD></TR>" if ($shortacl && $ismanager);
 
 	print "</TABLE>";
 	print "</TD></TABLE>";
@@ -567,10 +567,10 @@
 	if (!$ismanager) {
                 print popup_menu('mbx',[@tmpbox],' ')."</TD></TR>";
 	} else {
-		print textfield("mbx","",48)."&nbsp&nbsp&nbsp".submit("Select","Select $subtext")."&nbsp&nbsp(Wildcards allowed [*])</TD></TR>";
+		print textfield("mbx","",48)."&nbsp;&nbsp;&nbsp;".submit("Select","Select $subtext")."&nbsp;&nbsp;(Wildcards allowed [*])</TD></TR>";
 	}
 	print "<TR><TD $cb ><b>Foreign User ID:</b></TD>";
-        print "<TD $cb>".textfield("acluser")."&nbsp(User ID to assign access rights) &nbsp".submit("Set Acl")."</TD></TR>";
+        print "<TD $cb>".textfield("acluser")."&nbsp;(User ID to assign access rights) &nbsp;".submit("Set Acl")."</TD></TR>";
 
 	print "<TD><b> General Rights:</b></TD><TD $cb>".radio_group('rights',[@rights],"-",'',\%rightshash)."</TD></TR>";	
 	print "<TR><TD $cb><b>Specific Rights:</b></TD><TD $cb>".checkbox_group('acl',[@acls],'','',\%aclhash)."</TD></TR>";
@@ -580,7 +580,7 @@
 		param('aclmaxquota',$imapquota[2]);	
 		print "<TR><TD><$cb><B>Disk Quota Limit (KB):</b></TD><TD $cb>";
 		print textfield('aclmaxquota',$imapquota[2],20,40);
-	   print "&nbsp&nbsp<b>Disk Quota Used (KB):</b>&nbsp&nbsp".$imapquota[1]."&nbsp&nbsp".submit("Set Quota")."</TD></TR>";
+	   print "&nbsp;&nbsp;<b>Disk Quota Used (KB):</b>&nbsp;&nbsp;".$imapquota[1]."&nbsp;&nbsp;".submit("Set Quota")."</TD></TR>";
 	}
 	print "</TABLE>";
 	print "</TD></TABLE>",br;
@@ -592,10 +592,10 @@
 	param('delmailbox','');
 	param('newmbx','');
 	param('partition','');
-	print "<TR><TD $cb ><b>$subtext to Create:</b></TD><TD $cb>".textfield("newmbx")."&nbsp&nbsp";
+	print "<TR><TD $cb ><b>$subtext to Create:</b></TD><TD $cb>".textfield("newmbx")."&nbsp;&nbsp;";
 	print "<b>Partition: </b>",textfield("partition") if $ismanager;
-	print"&nbsp&nbsp". submit('Create Mailbox',"Create $subtext")."&nbsp&nbsp</TR>";
-	print "<TR><TD $cb ><b>$subtext to Delete:</b></TD><TD $cb>".textfield("delmailbox")."&nbsp&nbsp&nbsp".submit("Delete This Mailbox","Delete $subtext")."</tr>" if $ismanager;
+	print"&nbsp;&nbsp;". submit('Create Mailbox',"Create $subtext")."&nbsp;&nbsp;</TR>";
+	print "<TR><TD $cb ><b>$subtext to Delete:</b></TD><TD $cb>".textfield("delmailbox")."&nbsp;&nbsp;&nbsp;".submit("Delete This Mailbox","Delete $subtext")."</tr>" if $ismanager;
 
 	print "</TABLE>";
 	print "</TD></TABLE>";
@@ -1046,7 +1046,7 @@
 	if (!$rulecount) {
 		print " [No Rules avalailable]<br>";
 	}
-	print "<hr><center>",submit('Save Changes'),"&nbsp&nbsp",submit("Refresh"),"&nbsp&nbsp",reset("Reset Values"),"</center>";
+	print "<hr><center>",submit('Save Changes'),"&nbsp;&nbsp;",submit("Refresh"),"&nbsp;&nbsp;",reset("Reset Values"),"</center>";
 
 	} # if viewrules
      if (($op eq 'addrule'  || $modrule) && ($op ne 'forward')) {
@@ -1057,8 +1057,8 @@
 	print "<center><b>New Rule Entry for user: </b>$uid</center></TD></TR><TR $cb><TD>";
 	print "<TABLE >";
 	print "<TR $cb><TD><b>Rule#: </b>[$rulecount]";
-		print "&nbsp&nbsp<b>Priority: </b>",textfield("rules.priority.$rulecount",$spriority,2);
-		print "&nbsp&nbsp<b>Status: </b>",popup_menu("rules.ruletype.$rulecount",[@ruletype],'ENABLED'),"</TD><TD></TR>";
+		print "&nbsp;&nbsp;<b>Priority: </b>",textfield("rules.priority.$rulecount",$spriority,2);
+		print "&nbsp;&nbsp;<b>Status: </b>",popup_menu("rules.ruletype.$rulecount",[@ruletype],'ENABLED'),"</TD><TD></TR>";
 	my @checked;
 	my @checkvalues=("copy","keep");
 	push @checkvalues,"regex" if $useregex;
@@ -1096,23 +1096,23 @@
 			param("rules.searchflg.$rulecount","$ssearchflg");
 			print popup_menu("rules.searchflg.$rulecount",[@flgsts],$ssearchflg,\%searchflghash);	
 		}	
-		print " field(s):</b></TD><TD $cb>&nbsp 'from' contains ",
+		print " field(s):</b></TD><TD $cb>&nbsp; 'from' contains ",
 		"</TD><TD $cb >";
 		param("rules.from.$rulecount","$sfrom");
 		print textfield("rules.from.$rulecount","$sfrom",50),"</TD></TR>";
 		
 ############# TO field
 		print "<TR>";		
-		print "<TD $cb align=right>&nbsp</TD><TD $cb >";
-		print "&nbsp 'to' contains ",
+		print "<TD $cb align=right>&nbsp;</TD><TD $cb >";
+		print "&nbsp; 'to' contains ",
 		"</TD><TD $cb >";
 		param("rules.to.$rulecount","$sto");
 		print textfield("rules.to.$rulecount","$sto",50),"</TD></TR>";
 
 ########### SUBJECT field
 		print "<TR></TD>";
-		print "<TD $cb align=right>&nbsp</TD><TD $cb>";
-		print "&nbsp 'subject' contains ",
+		print "<TD $cb align=right>&nbsp;</TD><TD $cb>";
+		print "&nbsp; 'subject' contains ",
 		"</TD><TD $cb>";
 		param("rules.subject.$rulecount","$ssubject");
 		print textfield("rules.subject.$rulecount","$ssubject",50),"</TD></TR>";
@@ -1154,26 +1154,26 @@
 
 ############## Action REDIRECT 
 		param("rules.forward.$rulecount","$sdest1");
-		print "<TD $cb>&nbsp</TD><TD $cb><input type=radio $check1 name=rules.desttype.$rulecount value=\"address\"> Forward To </TD><TD $cb>";
+		print "<TD $cb>&nbsp;</TD><TD $cb><input type=radio $check1 name=rules.desttype.$rulecount value=\"address\"> Forward To </TD><TD $cb>";
 		print textfield("rules.forward.$rulecount",$sdest1,50)," (Email Address) </TD></TR><TR>";
 
 ############### Action REPLY WITH	
 		if ($usereply) {
 
 			param("rules.reply.$rulecount","$sdest2") if (defined $sdest2);
-			print "<TD $cb>&nbsp</TD><TD $cb valign=top><input type=radio $check2 name=rules.desttype.$rulecount value=\"reply\"> Reply With  </TD><TD $cb>";
+			print "<TD $cb>&nbsp;</TD><TD $cb valign=top><input type=radio $check2 name=rules.desttype.$rulecount value=\"reply\"> Reply With  </TD><TD $cb>";
 			print textarea("rules.reply.$rulecount",$sdest2,2,43)," (Text Message) </TD></TR>";
 
 		}
 ############## Action Reject  
 	     if ($usereject) { 
 	        	param("rules.reject.$rulecount","$sdest3");
-		        print "<TD $cb>&nbsp</TD><TD $cb valign=top><input type=radio $check3 name=rules.desttype.$rulecount value=\"reject\"> Reject </TD><TD $cb>";
+		        print "<TD $cb>&nbsp;</TD><TD $cb valign=top><input type=radio $check3 name=rules.desttype.$rulecount value=\"reject\"> Reject </TD><TD $cb>";
 		        print textarea("rules.reject.$rulecount",$sdest3,2,43)," (Text Message) </TD></TR>";
 	     }
 ############## Action Discard  
 	     if ($usediscard) { 
-		        print "<TD $cb>&nbsp</TD><TD $cb valign=top><input type=radio $check4 name=rules.desttype.$rulecount value=\"discard\"> Discard </TD><TD $cb>&nbsp</TD></TR>";
+		        print "<TD $cb>&nbsp;</TD><TD $cb valign=top><input type=radio $check4 name=rules.desttype.$rulecount value=\"discard\"> Discard </TD><TD $cb>&nbsp;</TD></TR>";
 	     }
 
 ############### Action CustomCode	
@@ -1196,7 +1196,7 @@
 	print hr,"<TABLE ><TR><TD >$wild</TD></TABLE>";
 
 	$rulecount--;
-	print hr,"<center>",submit("Save Rule "),"&nbsp&nbsp",reset('Clear'),"</center>";
+	print hr,"<center>",submit("Save Rule "),"&nbsp;&nbsp;",reset('Clear'),"</center>";
 
       } # if addrule
 
@@ -1248,7 +1248,7 @@
 	print "<TD $cb><b>Server: </b>$imapserver</TD><TD $cb><b>Userid: </b>$uid</TD>"; 
 	print "<TD $cb><b>Used Quota: </b>";
 	if ($percent ne "") {
-		print "[<b>$quota[1]</b> kbytes used /<b> $quota[2]</b> kbytes available.($percent\% usage)]</TD>";
+		print "[<b>$quota[1]</b> kbytes used /<b> $quota[2]</b> kbytes available. ($percent\% usage)]</TD>";
 	} else {
 		print "<TD $cb><b>$quota[1]</b> No limits</TD>";
 	};
@@ -1387,7 +1387,7 @@
 	print start_form(-action=>$program_url);
 	$gomodifyit = 'yes';
 	 print hidden('s',$sencode_params) if $useservercookie;
-	 print "<center>",submit('Save Changes'),"&nbsp&nbsp",submit("Refresh"),"&nbsp&nbsp",reset('Reset Values'),"</center>" if $op;
+	 print "<center>",submit('Save Changes'),"&nbsp;&nbsp;",submit("Refresh"),"&nbsp;&nbsp;",reset('Reset Values'),"</center>" if $op;
 	param('op',$op);
 	if (param('action') && param('action') eq 'deletembx') {
 		&deleteimapmailbox;
@@ -1407,7 +1407,7 @@
 	&initscripts(%scripts);
 	if ($op eq 'setacl') {
 	 	&viewacl if $useacl;
-		print "<hr><center>",submit('Save Changes'),"&nbsp&nbsp",submit("Refresh"),"&nbsp&nbsp",reset('Reset Values'),"</center>";
+		print "<hr><center>",submit('Save Changes'),"&nbsp;&nbsp;",submit("Refresh"),"&nbsp;&nbsp;",reset('Reset Values'),"</center>";
 
 	}
 	if ($mode =~ /basic/i && $op ne 'setacl') {
@@ -1420,7 +1420,7 @@
 #		print "printing $op<br>";
 
 		&printscript($scripts{'script'}) ;
-	print "<hr><center>",submit('Save Changes'),"&nbsp&nbsp",submit("Refresh"),"&nbsp&nbsp",reset('Reset Values'),"</center>";
+	print "<hr><center>",submit('Save Changes'),"&nbsp;&nbsp;",submit("Refresh"),"&nbsp;&nbsp;",reset('Reset Values'),"</center>";
 
 
 	}
