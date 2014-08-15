--- ./scripts/query_unix_partitions.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/query_unix_partitions.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 if (($ARGV[0] ne "query") && ($ARGV[0] ne "get") && ($ARGV[0] ne "index") && ($ARGV[0] ne "num_indexes")) {
 	print "usage:\n\n";
