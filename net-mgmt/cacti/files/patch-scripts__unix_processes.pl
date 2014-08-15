--- ./scripts/unix_processes.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/unix_processes.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 open(PROCESS, "ps ax | grep -c : |");
 $output = <PROCESS>;
