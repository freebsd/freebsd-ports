--- ./scripts/loadavg.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/loadavg.pl	2014-08-11 18:37:08.000000000 -0700
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 #get load avg for 5;15;30 min
 open(PROCESS,"uptime |");
