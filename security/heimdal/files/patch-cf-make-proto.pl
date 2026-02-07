--- cf/make-proto.pl.orig	2019-06-07 06:21:35 UTC
+++ cf/make-proto.pl
@@ -4,7 +4,7 @@
 use Getopt::Std;
 use File::Compare;
 
-use JSON;
+# use JSON;
 
 my $comment = 0;
 my $doxygen = 0;
