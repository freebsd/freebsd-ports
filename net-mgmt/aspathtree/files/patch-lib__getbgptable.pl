--- lib/getbgptable.pl.orig	Thu Feb  6 11:25:26 2003
+++ lib/getbgptable.pl	Thu Feb  6 11:43:58 2003
@@ -24,10 +24,55 @@
 #     ASs  (all the ASs in the router BGP table)
 # Finally this routine produces a text file containing the raw version of the router table
 # and if required log files of both the raw router table and the normalized table.
+
+
 sub get_bgp_table {
 	my ($parser, $command, $line) = ('', '', '');
 	my (@lines) = ();

+	use Socket;
+        use Net::Telnet;
+
+	if (defined($ROUTERUSERPASS)) {
+
+# TELNET module to get BGP4+ AS Path table
+
+	if ($ROUTER =~ /^JUNIPER$/i) {
+		$parser = "juniper";
+		$STATUSCODES = "*&gt; active";
+        	my $telnet_session = new Net::Telnet(
+	        prompt => '/[\w().-]*[\$#]\s*$/'
+       		);
+
+	        $telnet_session->open($ROUTERADDR);
+       		$telnet_session->login($ROUTERUSER, $ROUTERUSERPASS);
+	        $telnet_session->cmd(String => "set cli screen-length 0", Timeout => 1800);
+
+       		 @lines = $telnet_session->cmd(String => "show route table inet6.0 all terse",
+                                  Timeout => 1800);
+	        $telnet_session->close;
+	} else {
+		$ROUTER = "CISCO";
+		$parser = "cisco";
+		$STATUSCODES = "s suppressed, d damped, h history, * valid, &gt; best, r RIB-failure";
+       		my $telnet_session = new Net::Telnet(
+	        prompt => '/[\w().-]*[\$#]\s*$/'
+       		);
+
+	        $telnet_session->open($ROUTERADDR);
+       		$telnet_session->login($ROUTERUSER, $ROUTERUSERPASS);
+	        $telnet_session->cmd(String => "terminal length 0", Timeout => 1800);
+
+       		@lines = $telnet_session->cmd(String => "show bgp ipv6",
+                                  Timeout => 1800);
+	        $telnet_session->close;
+	}
+# end TELNET module
+
+        } else {
+
+# RSH module to get BGP4+ AS Path table
+
 	if ($ROUTER =~ /^JUNIPER$/i) {
 		$parser = "juniper";
 		$STATUSCODES = "*&gt; active";
@@ -58,6 +103,7 @@
 		push(@lines, $_);
 	}
 	close(OUTPUT);
+	}
 	chomp(@lines);
 # Write log and for web files (raw table)
 	open(TXTFILE,"> $BGPTABLEFILE");
