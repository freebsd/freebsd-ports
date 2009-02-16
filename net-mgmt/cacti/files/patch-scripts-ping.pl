--- cacti-0.8.7d/scripts/ping.pl.orig	2009-02-12 05:55:50.000000000 +0300
+++ cacti-0.8.7d/scripts/ping.pl	2009-02-16 17:01:59.000000000 +0300
@@ -4,7 +4,7 @@
 $host = $ARGV[0];
 $host =~ s/tcp:/$1/gis;
 
-open(PROCESS, "ping -c 1 $host | grep icmp_seq | grep time |");
+open(PROCESS, "/sbin/ping -c 1 $host | grep icmp_seq | grep time |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/;
