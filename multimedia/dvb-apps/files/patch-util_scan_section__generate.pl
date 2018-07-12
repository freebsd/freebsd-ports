--- util/scan/section_generate.pl.orig	2014-03-21 19:26:36 UTC
+++ util/scan/section_generate.pl
@@ -4,7 +4,7 @@ use strict;
 
 die "no section perl file given" unless @ARGV;
 
-my $h = require($ARGV[0]);
+my $h = require("./".$ARGV[0]);
 
 our $basename;
 our $debug = $ARGV[1];
