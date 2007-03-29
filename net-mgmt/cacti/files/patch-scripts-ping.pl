--- cacti-0.8.6j/scripts/ping.pl.orig	Sat Apr 15 22:26:44 2006
+++ cacti-0.8.6j/scripts/ping.pl	Sat Apr 15 22:27:16 2006
@@ -1,6 +1,6 @@
 #!/usr/bin/perl 
 
-open(PROCESS, "ping -c 1 $ARGV[0] | grep icmp_seq |");
+open(PROCESS, "/sbin/ping -c 1 $ARGV[0] | grep icmp_seq |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/; 
