--- Makefile.PL.orig	Sun Mar 21 19:09:20 2004
+++ Makefile.PL	Wed Apr  7 22:56:11 2004
@@ -7,7 +7,7 @@
 # don't prompt the user if we're not being called interactively (e.g., if we're
 # being called from cron or some such program instead of directly by the user):
 my $interactive = 1;
-$interactive = 1 if (-t STDIN and -t STDOUT);
+$interactive = 0 if (-t STDIN and -t STDOUT);
 
 # first, make sure the line endings in the test items are correct:
 my %files_and_newlines = (
