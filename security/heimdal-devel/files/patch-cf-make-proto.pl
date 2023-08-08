--- cf/make-proto.pl.orig	2023-06-24 12:54:02.000000000 -0700
+++ cf/make-proto.pl	2023-06-26 21:14:16.008839000 -0700
@@ -4,7 +4,7 @@
 use Getopt::Std;
 use File::Compare;
 
-use JSON::PP
+# use JSON::PP
 
 my $comment = 0;
 my $doxygen = 0;
