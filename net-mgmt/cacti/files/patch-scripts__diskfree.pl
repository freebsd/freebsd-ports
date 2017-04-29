--- scripts/diskfree.pl.orig	2017-04-26 00:30:09 UTC
+++ scripts/diskfree.pl
@@ -1,5 +1,5 @@
 #!/usr/bin/perl
-open(PROCESS,"df --block-size=1024 -P $ARGV[0] | grep -v Filesystem |");
+open(PROCESS,"df -k $ARGV[0] | grep -v Filesystem |");
 foreach (<PROCESS>) {
 	if ($_ =~ /($ARGV[0])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])%(.* )/) {
 		print "megabytes:$7 percent:$9";
