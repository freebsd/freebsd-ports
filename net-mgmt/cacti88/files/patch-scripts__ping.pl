--- scripts/ping.pl.orig	2017-06-01 00:09:48 UTC
+++ scripts/ping.pl
@@ -7,7 +7,7 @@ $host =~ s/:[0-9]{1,5}/$1/gis;
 
 # old linux version use "icmp_seq"
 # newer use "icmp_req" instead
-open(PROCESS, "ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
+open(PROCESS, "/sbin/ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/;
