--- ./scripts/ping.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/ping.pl	2014-08-11 17:34:23.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 # take care for tcp:hostname or TCP:ip@
 $host = $ARGV[0];
@@ -6,7 +6,7 @@
 
 # old linux version use "icmp_seq"
 # newer use "icmp_req" instead
-open(PROCESS, "ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
+open(PROCESS, "/sbin/ping -c 1 $host | grep 'icmp_[s|r]eq' | grep time |");
 $ping = <PROCESS>;
 close(PROCESS);
 $ping =~ m/(.*time=)(.*) (ms|usec)/;
