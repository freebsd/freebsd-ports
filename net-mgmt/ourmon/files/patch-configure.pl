--- ./configure.pl.orig	2008-03-15 18:55:10.000000000 +0100
+++ ./configure.pl	2011-07-10 23:43:06.000000000 +0200
@@ -110,9 +110,9 @@
 $netmask = "127.0.0.1/32";
 
 # default absolute web paths, may be wrong
-$webpath = "/usr/local/apache/htdocs/ourmon";
+$webpath = "%%WWWDIR%%";
 if ($systype eq "FreeBSD") {
-	$webpath = "/usr/local/www/data/ourmon";
+	$webpath = "%%WWWDIR%%";
 	# guess the bsd interface whilst we are at it
 	$interface = guess_bsd_if();
 	$fbsd6 = 0;
@@ -324,10 +324,11 @@
 	# make sure everything in bin is executable
 	system("chmod +x bin/*");
 
+# XXX skip if installed from port
 	#3 create startup script for ourmon
 	$YES_CORRECT="y";
-	print "\nDo you want to install the ourmon startup script in the ourmon bin? [y] ";
-	$line = <STDIN>;
+#	print "\nDo you want to install the ourmon startup script in the ourmon bin? [y] ";
+	$line = "n";
 	unless ($line =~ /^\n/) {
 	  	chomp($YES_CORRECT = $line);  
 	}
@@ -441,21 +442,21 @@
 
 	# WEBDIR
 	print "We need a local web directory for generated web output.\n";
-	print "hint: the webpath given here is a guess: give the CORRECT base web directory with /ourmon at the end\n";
-	print "enter absolute web server web path directory: [$webpath] ";
-	$line = <STDIN>;
-	unless ($line =~ /^\n/) {
-	  	chomp($webpath = $line);  
-	}
+#	print "hint: the webpath given here is a guess: give the CORRECT base web directory with /ourmon at the end\n";
+#	print "enter absolute web server web path directory: [$webpath] ";
+#	$line = <STDIN>;
+#	unless ($line =~ /^\n/) {
+#	  	chomp($webpath = $line);  
+#	}
 	print "your output web path is: $webpath\n";
 
-	print "\nDo you want to create the web directory for ourmon?";
-	print "\nHINT: good idea if it doesn't exist. [y] ";
+#	print "\nDo you want to create the web directory for ourmon?";
+#	print "\nHINT: good idea if it doesn't exist. [y] ";
 	$YES_CORRECT = "y";
-	$line = <STDIN>;
-	unless ($line =~ /^\n/) {
-	  	chomp($YES_CORRECT = $line);  
-	}
+#	$line = <STDIN>;
+#	unless ($line =~ /^\n/) {
+#	  	chomp($YES_CORRECT = $line);  
+#	}
 	if (lc($YES_CORRECT) eq "y") {
 		system("mkdir $webpath");
 	}
@@ -781,18 +782,19 @@
 	my $dstring = $binpath . "daily.pl " . $logpath;
   	open(HANDLE, ">$file") || die "Cannot open $file";
 
-	print HANDLE "############## ourmon crontab entries ###############\n";
+    print HANDLE "# == ourmon port cron start (do not remove this anchor line) ==\n";
 	$batchip_file = $binpath . $batchip_file;
 	$batchipall_file = $binpath . $batchipall_file;
-	my $basic = "*/1	*	*	*	*	root	$omupdatepath\n";
+	my $basic = "*/1	*	*	*	*	root	env -u LC_TIME LC_TIME=en_US $omupdatepath\n";
 	print HANDLE "# run ourmon back-end omupdate.pl etc. per minute\n";
- 	print HANDLE "$basic";
+ 	print HANDLE "#$basic";
 	print HANDLE "# batchip.sh - hourly log summary\n";
-	print HANDLE "0	*	*	*	*	root	$batchip_file\n";
+	print HANDLE "#0	*	*	*	*	root	env -u LC_TIME LC_TIME=en_US $batchip_file\n";
 	print HANDLE "# batchipall.sh - roll over daily summary logs at almost midnight\n";
-	print HANDLE "50	23	*	*	*	root	$batchipall_file\n";
+	print HANDLE "#50	23	*	*	*	root	env -u LC_TIME LC_TIME=en_US $batchipall_file\n";
 	print HANDLE "# daily.pl - re init next day logs at midnight\n";
-	print HANDLE "0	0	*	*	*	root	$dstring\n";
+	print HANDLE "#0	0	*	*	*	root	env -u LC_TIME LC_TIME=en_US $dstring\n";
+    print HANDLE "# == ourmon port cron end (do not remove this anchor line) ==\n";
 	close HANDLE;
 	# concat to /etc/crontab if desired
 	if ($install eq "y") {
