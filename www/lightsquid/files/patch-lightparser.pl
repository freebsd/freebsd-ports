--- lightparser.pl.orig	Wed Jan 10 19:06:49 2007
+++ lightparser.pl	Thu Jan 11 00:53:59 2007
@@ -36,7 +36,7 @@
 require "common.pl";
 
 #include ip2name function
-require "ip2name/ip2name.$ip2name";
+require "$ip2namepath/ip2name.$ip2name";
 
 $SIG{INT} = \&LOCKREMOVER;	# traps keyboard interrupt
 my $lockfilepath      ="$lockpath/lockfile";
