--- ./scripts/linux_memory.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/linux_memory.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 open(PROCESS, "cat /proc/meminfo | grep -w $ARGV[0] |");
 foreach (<PROCESS>) {
