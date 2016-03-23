--- lightparser.pl.orig	2009-07-02 22:15:32 UTC
+++ lightparser.pl
@@ -36,7 +36,7 @@ require "lightsquid.cfg";
 require "common.pl";
 
 #include ip2name function
-require "ip2name/ip2name.$ip2name";
+require "$ip2namepath/ip2name.$ip2name";
 
 $SIG{INT} = \&LOCKREMOVER;	# traps keyboard interrupt
 my $lockfilepath	  ="$lockpath/lockfile";
@@ -202,7 +202,7 @@ while (<FF>) {
 	  next;
 	};
 	
-	if ($Ltype =~ m/HIT/) {
+	if ($Ltype =~ m/(HIT|UNMODIFIED)/) {
 	  $CacheHIT+=$Lsize;
 	} else {
 	  $CacheMISS+=$Lsize;
