--- ./scripts/diskfree.pl.orig	2014-08-15 15:39:51.000000000 +0200
+++ ./scripts/diskfree.pl	2014-08-15 15:40:16.000000000 +0200
@@ -1,5 +1,5 @@
 #!/usr/bin/perl
-open(PROCESS,"df --block-size=1024 -P $ARGV[0] | grep -v Filesystem |");
+open(PROCESS,"df -k $ARGV[0] | grep -v Filesystem |");
 foreach (<PROCESS>) {
 	if ($_ =~ /($ARGV[0])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])%(.* )/) {
 		print "megabytes:$7 percent:$9";
