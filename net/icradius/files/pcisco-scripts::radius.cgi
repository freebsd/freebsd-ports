--- scripts/radius.cgi.orig	Wed Jul 18 16:03:17 2001
+++ scripts/radius.cgi	Wed Jul 18 15:30:03 2001
@@ -2283,7 +2283,7 @@
 				<select name="terminate_cause">
 					<option value=''>
 		~;
-		my $terminate_causes = $radius->fetch_attribute_values('Acct-Terminate-Cause');
+		my $terminate_causes = $radius->fetch_attribute_values('Cisco-Disconnect-Cause');
 		foreach my $cause (@$terminate_causes) {
 			print qq!<option value="$cause"!;
 			print q! selected! if ($terminate_cause eq $cause);
@@ -2334,7 +2334,10 @@
 			$sql .= " AND radacct.NASPortId = '$nas_port'" if $nas_port;
 			$sql .= " AND radacct.NASPortType = '$nas_port_type'" if $nas_port_type;
 			$sql .= " AND radacct.FramedIPAddress = '$framed_ipaddr'" if $framed_ipaddr;
-			$sql .= " AND radacct.AcctTerminateCause = '$terminate_cause'" if $terminate_cause;
+			if( $terminate_cause ){
+				my %list = &get_attr_list('Cisco-Disconnect-Cause');
+				$sql .= " AND radacct.CiscoDisconnectCause = \"".$list{$terminate_cause}."\"";
+			}
 
 			$sql .= " ORDER BY radacct.UserName, radacct.AcctStartTime DESC";
 
@@ -2427,7 +2430,13 @@
 
 	my $session = $radius->fetch_session_info($radacctid);
 
-	print qq~
+        my $NASPortType = &get_attr($session->{NASPortType},"NAS-Port-Type");
+        my $AcctAuthentic = &get_attr($session->{AcctAuthentic},"Acct-Authentic");
+        my $CiscoDisconnectCause = &get_attr($session->{CiscoDisconnectCause},"Cisco-Disconnect-Cause");
+        my $ServiceType = &get_attr($session->{ServiceType},"Service-Type");
+        my $FramedProtocol = &get_attr($session->{FramedProtocol},"Framed-Protocol");
+
+        print qq~
 		<center>
 		<table cellspacing="4" cellpadding="2" border="1" cols="2">
 		<tr><th bgcolor="$highlight">Attribute</th><th bgcolor="$highlight">Value</th></tr>
@@ -2436,24 +2445,23 @@
 		<tr><td align="center">Realm</td><td align="center">$session->{Realm}</td></tr>
 		<tr><td align="center">NAS-IP-Address</td><td align="center">$session->{NASIPAddress}</td></tr>
 		<tr><td align="center">NAS-Port-Id</td><td align="center">$session->{NASPortId}</td></tr>
-		<tr><td align="center">NAS-Port-Type</td><td align="center">$session->{NASPortType}</td></tr>
+       		<tr><td align="center">NAS-Port-Type</td><td align="center">$NASPortType</td></tr>
 		<tr><td align="center">Acct-Start-Time</td><td align="center">$session->{AcctStartTime}</td></tr>
 		<tr><td align="center">Acct-Stop-Time</td><td align="center">$session->{AcctStopTime}</td></tr>
 		<tr><td align="center">Acct-Session-Time</td><td align="center">$session->{AcctSessionTime}</td></tr>
-		<tr><td align="center">Acct-Authentic</td><td align="center">$session->{AcctAuthentic}</td></tr>
-		<tr><td align="center">Connect-Info</td><td align="center">$session->{ConnectInfo}</td></tr>
+		<tr><td align="center">Acct-Authentic</td><td align="center">$AcctAuthentic</td></tr>
 		<tr><td align="center">Acct-Input-Octets</td><td align="center">$session->{AcctInputOctets}</td></tr>
 		<tr><td align="center">Acct-Output-Octets</td><td align="center">$session->{AcctOutputOctets}</td></tr>
-		<tr><td align="center">Called-Station-Id</td><td align="center">$session->{CalledStationId}</td></tr>
-		<tr><td align="center">Calling-Station-Id</td><td align="center">$session->{CallingStationId}</td></tr>
-		<tr><td align="center">Acct-Terminate-Cause</td><td align="center">$session->{AcctTerminateCause}</td></tr>
-		<tr><td align="center">Service-Type</td><td align="center">$session->{ServiceType}</td></tr>
-		<tr><td align="center">Framed-Protocol</td><td align="center">$session->{FramedProtocol}</td></tr>
+		<tr><td align="center">Cisco-Disconnect-Cause</td><td align="center">$CiscoDisconnectCause</td></tr>
+		<tr><td align="center">Service-Type</td><td align="center">$ServiceType</td></tr>
+		<tr><td align="center">Framed-Protocol</td><td align="center">$FramedProtocol</td></tr>
 		<tr><td align="center">Framed-IP-Address</td><td align="center">$session->{FramedIPAddress}</td></tr>
 		<tr><td align="center">Acct-Start-Delay-Time</td><td align="center">$session->{AcctStartDelay}</td></tr>
 		<tr><td align="center">Acct-Stop-Delay-Time</td><td align="center">$session->{AcctStopDelay}</td></tr>
-		</table>
-		</center>
+                <tr><td align="center">Cisco-Data-Rate</td><td align="center">$session->{CiscoDataRate}</td></tr>
+                <tr><td align="center">Cisco-Xmit-Rate</td><td align="center">$session->{CiscoXmitRate}</td></tr>
+		<tr><td align="center">Calling-Station-Id</td><td align="center">$session->{CallingStationId}</td></tr>
+		<tr><td align="center">Called-Station-Id</td><td align="center">$session->{CalledStationId}</td></tr></table></center>
 	~;
 }
 
@@ -3160,3 +3168,33 @@
 
 	unlink $tmp_sessions_file;
 }
+
+# Get attribute description
+sub get_attr {
+    my( $attr ) = shift;
+    my( $attr_name) = shift;
+    my( $sth ) =
+        $radius->{dbh}->prepare("SELECT Value from dictionary WHERE
+                                Type='VALUE' AND Attribute='$attr_name' AND
+                                Format='$attr'");
+    $sth->execute || &terminal_error;
+    my @row = $sth->fetchrow_array;
+    $sth->finish;
+
+    return (( $#row >= 0 )? $row[0]:$attr);
+}
+
+# Make a list of values of the specified attribute
+sub get_attr_list {
+    my( $attr ) = shift;
+    my( %list, @row );
+    my( $sth ) =
+        $radius->{dbh}->prepare("SELECT Value,Format FROM dictionary WHERE
+                                Type='VALUE' AND Attribute='$attr'");
+    $sth->execute || &terminal_error;
+    while( @row = $sth->fetchrow_array ){
+        $list{$row[0]}=$row[1];
+    }
+    $sth->finish;
+    return %list;
+}
