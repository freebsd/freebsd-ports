--- couriergraph.pl.orig	Tue Jun 20 11:11:39 2006
+++ couriergraph.pl	Tue Aug  8 12:02:45 2006
@@ -314,11 +314,11 @@
 
 my $daemon_logfile = '/var/log/couriergraph.log';
 my $daemon_pidfile = '/var/run/couriergraph.pid';
-my $daemon_rrd_dir = '/var/log';
+my $daemon_rrd_dir = '%%DATADIR%%';
 
 # global variables
 my $logfile;
-my $rrd = "/etc/postfix/couriergraph.rrd";
+my $rrd = "couriergraph.rrd";
 my $year;
 my $this_minute;
 my %sum = ( imapd_ssl_login => 0, imapd_login => 0, pop3d_ssl_login => 0, pop3d_login => 0 );
@@ -350,7 +350,7 @@
 	print "      --host=HOST    use only entries for HOST (regexp) in syslog\n";
 	print "  -d, --daemon       start in the background\n";
 	print "  --daemon-pid=FILE  write PID to FILE instead of /var/run/mailgraph.pid\n";
-	print "  --daemon-rrd=DIR   write RRDs to DIR instead of /var/log\n";
+	print "  --daemon-rrd=DIR   write RRDs to DIR instead of %%DATADIR%%\n";
 	print "  --daemon-log=FILE  write verbose-log to FILE instead of /var/log/mailgraph.log\n";
 	print "  --rrd-name=NAME    use NAME.rrd for the rrd files\n";
 
@@ -473,7 +473,7 @@
 	my $prog = $sl->[2];
 	my $text = $sl->[4];
 
- 	if ($prog eq 'courierpop3login') {
+ 	if ($prog eq 'pop3d') {
  		if($text =~ /LOGIN,/) {
 		        event($time, 'pop3d_login');
   		}
