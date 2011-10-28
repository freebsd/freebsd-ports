--- ./scripts/ping.pl.orig	2011-10-26 09:31:56.000000000 -0400
+++ ./scripts/ping.pl	2011-10-26 09:32:02.000000000 -0400
@@ -6,7 +6,7 @@
 
 # old linux version use "icmp_seq"
 # newer use "icmp_req" instead
-open(PROCESS, "ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
+open(PROCESS, "/sbin/ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/;
