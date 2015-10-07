--- plugins-scripts/check_mailq.pl.orig	2015-07-30 21:40:06 UTC
+++ plugins-scripts/check_mailq.pl
@@ -35,7 +35,7 @@ use FindBin;
 use lib "$FindBin::Bin";
 use utils qw(%ERRORS &print_revision &support &usage );
 
-my ($sudo)
+my ($sudo);
 
 sub print_help ();
 sub print_usage ();
