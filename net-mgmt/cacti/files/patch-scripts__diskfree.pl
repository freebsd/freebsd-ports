--- ./scripts/diskfree.pl.orig	2013-08-06 19:31:19.000000000 -0700
+++ ./scripts/diskfree.pl	2014-08-11 17:34:23.000000000 -0700
@@ -1,5 +1,5 @@
-#!/usr/bin/perl
-open(PROCESS,"df --block-size=1024 -P $ARGV[0] | grep -v Filesystem |");
+#!/usr/local/bin/perl
+open(PROCESS,"df -k $ARGV[0] | grep -v Filesystem |");
 foreach (<PROCESS>) {
 	if ($_ =~ /($ARGV[0])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])%(.* )/) {
 		print "megabytes:$7 percent:$9";
