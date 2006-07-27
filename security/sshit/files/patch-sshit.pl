--- /usr/ports/security/sshit/work/sshit-0.5/sshit.pl	Sat Dec 17 19:40:24 2005
+++ sshit.pl	Sat Apr 29 08:39:06 2006
@@ -232,7 +232,7 @@
        create    => 1,
        exclusive => 0,
        mode      => 0644,
-       destroy   => 0,
+       destroy   => 1,
 );
 
 $handle = tie %list, 'IPC::Shareable', 'sshi', { %options };
@@ -266,7 +266,7 @@
 						{
 							system("$IPFW_CMD delete $list{$ip}{rulenr}");
 						} elsif ($FIREWALL_TYPE =~ /^ipfw2$/i) {
-							system("$IPFW2_CMD table $IPFW_TABLE_NO delete $ip");
+							system("$IPFW2_CMD table $IPFW2_TABLE_NO delete $ip");
 					        } elsif ($FIREWALL_TYPE =~ /^pf$/i) {
 						  	system("$PFCTL_CMD -t $PF_TABLE -Tdelete $ip");
 						}
@@ -337,3 +337,18 @@
 		}
 	}
 }
+foreach $ip (keys %list) {
+	if($FIREWALL_TYPE =~ /^ipfw$/i)
+	{
+		system("$IPFW_CMD delete $list{$ip}{rulenr}");
+	} elsif ($FIREWALL_TYPE =~ /^ipfw2$/i) {
+		system("$IPFW2_CMD table $IPFW2_TABLE_NO delete $ip");
+	} elsif ($FIREWALL_TYPE =~ /^pf$/i) {
+		system("$PFCTL_CMD -t $PF_TABLE -Tdelete $ip");
+	}
+	syslog(LOG_ERR, "main removed block rule $list{$ip}{rulenr} for $ip (reset time of $RESET_IP seconds reached)\n");
+	delete($list{$ip});
+}
+
+# clear all SHM
+IPC::Shareable->clean_up;
