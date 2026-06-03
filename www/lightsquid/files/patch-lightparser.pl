--- lightparser.pl.orig	2026-04-25 10:24:38 UTC
+++ lightparser.pl
@@ -32,11 +32,11 @@ push (@INC,(fileparse($0))[1]);
 
 push (@INC,(fileparse($0))[1]);
 
-require "lightsquid.cfg";
+require "/usr/local/etc/lightsquid/lightsquid.cfg";
 require "common.pl";
 
 #include ip2name function
-require "ip2name/ip2name.$ip2name";
+require "$ip2namepath/ip2name.$ip2name";
 
 $SIG{INT} = \&LOCKREMOVER;	# traps keyboard interrupt
 my $lockfilepath	  ="$lockpath/lockfile";
@@ -66,7 +66,7 @@ my $filterdatestart=0;
 $month=sprintf("%02d",$mon+1);;
 	  
 my $filterdatestart=0;
-my $filterdatestop =timelocal(59,59,23,31,12-1,2020-1900)+1000;
+my $filterdatestop =timelocal(59,59,23,31,12-1,2100-1900)+1000;
 
 $fToday=1 if ($ARGV[0] eq "today");
 $fToday=1 if ($ARGV[0] eq "yesterday");
@@ -202,7 +202,7 @@ while (<FF>) {
 	  next;
 	};
 	
-	if ($Ltype =~ m/HIT/) {
+	if ($Ltype =~ m/(HIT|UNMODIFIED)/) {
 	  $CacheHIT+=$Lsize;
 	} else {
 	  $CacheMISS+=$Lsize;
