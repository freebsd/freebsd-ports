--- plugins-scripts/check_ntp.pl.orig	Sun Jun 23 14:28:03 2002
+++ plugins-scripts/check_ntp.pl	Sun Jun 23 14:28:27 2002
@@ -44,6 +44,10 @@
 #     o Server has correct time but isn't suitable synchronization
 #           source. This happens while starting up and if contact
 #           with master has been lost.
+#
+# (c) 2001 David Douthitt <n9ubh@callsign.net>
+#
+# Script modified to handle NTP v2 with new -n parameter
 
 BEGIN {
 	if ($0 =~ m/^(.*?)[\/\\]([^\/\\]+)$/) {
@@ -56,7 +60,7 @@
 use POSIX;
 use strict;
 use Getopt::Long;
-use vars qw($opt_H $opt_w $opt_c $verbose $PROGNAME);
+use vars qw($opt_n $opt_H $opt_w $opt_c $verbose $PROGNAME);
 use lib $main::runtimedir;
 use utils qw($TIMEOUT %ERRORS &print_revision &usage &support &is_error);
 
@@ -69,6 +73,7 @@
 sub version ();
 
 delete @ENV{'PATH', 'IFS', 'CDPATH', 'ENV', 'BASH_ENV'};
+$ENV{'PATH'} = "/bin:/usr/bin:/sbin:/usr/sbin:/usr/local/bin";
 
 Getopt::Long::Configure('bundling', 'no_ignore_case');
 GetOptions
@@ -77,6 +82,7 @@
 	 "v|verbose"    => \$verbose,
 	 "w|warning=s"  => \$opt_w,
 	 "c|critical=s" => \$opt_c,
+	 "n|ntpversion"	=> \$opt_n,
 	 "H|hostname=s" => \$opt_H);
 
 ($opt_H) || ($opt_H = shift) || usage("Host name/address not specified\n");
@@ -93,6 +99,9 @@
 ($opt_c) || ($opt_c = shift) || ($opt_c = 120);
 my $critical = $1 if ($opt_c =~ /([0-9]+)/);
 
+($opt_n) || ($opt_n = shift) || ($opt_n = 3);
+my $ntp_version = $1 if ($opt_n =~ /([0-9])/);
+
 my $answer = undef;
 my $offset = undef;
 my $msg; # first line of output to print if format is invalid
@@ -117,7 +126,7 @@
 ###
 ###
 
-if (!open (NTPDATE, "/usr/local/sbin/ntpdate -q $host 2>&1 |")) {
+if (!open (NTPDATE, "ntpdate -o$ntp_version -q $host 2>&1 |")) {
 	print "Could not open ntpdate\n";
 	exit $ERRORS{"UNKNOWN"};
 }
@@ -154,8 +163,7 @@
 ###
 ###
 
-if (open(NTPDC,"/usr/sbin/xntpdc -c peers $host 2>&1 |") ||
-    open(NTPDC,"/usr/sbin/ntpdc -c peers $host 2>&1 |")) {
+if (open(NTPDC,"/usr/sbin/ntpdc -c peers $host 2>&1 |")) {
 	while (<NTPDC>) {
 		print if ($verbose);
 		if (/([^\s]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)\s+([-0-9.]+)/) {
@@ -224,7 +232,7 @@
 exit $state;
 
 sub print_usage () {
-	print "Usage: $PROGNAME -H <host> [-w <warn>] [-c <crit>]\n";
+	print "Usage: $PROGNAME -H <host> [ -n <ntp_version> ] [-w <warn>] [-c <crit>]\n";
 }
 
 sub print_help () {
