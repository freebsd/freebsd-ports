--- plugins-scripts/check_file_age.pl.orig	2015-09-08 21:18:08 UTC
+++ plugins-scripts/check_file_age.pl
@@ -26,7 +26,8 @@ use English;
 use Getopt::Long;
 use File::stat;
 use vars qw($PROGNAME);
-use lib ".";
+use FindBin;
+use lib "$FindBin::Bin";
 use utils qw (%ERRORS &print_revision &support);
 
 sub print_help ();
