--- ./scripts/ping.pl.orig	2014-08-15 15:39:56.000000000 +0200
+++ ./scripts/ping.pl	2014-08-15 15:40:35.000000000 +0200
@@ -6,7 +6,7 @@
 
 # old linux version use "icmp_seq"
 # newer use "icmp_req" instead
-open(PROCESS, "ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
+open(PROCESS, "/sbin/ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/;
