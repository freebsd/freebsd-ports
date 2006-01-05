--- scripts/diskfree.pl.orig	Wed Jan  4 06:08:30 2006
+++ scripts/diskfree.pl	Fri Jan  6 00:16:58 2006
@@ -1,5 +1,5 @@
 #!/usr/bin/perl
-open(PROCESS,"df --block-size=1024 -P $ARGV[0] | grep -v Filesystem |");
+open(PROCESS,"df -k $ARGV[0] | grep -v Filesystem |");
 foreach (<PROCESS>) {
 	if ($_ =~ /($ARGV[0])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])(.* )(.*[0-9])%(.* )/) {
 		print "megabytes:$7 percent:$9";
