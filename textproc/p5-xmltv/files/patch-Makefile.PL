--- Makefile.PL.orig	Thu Sep 18 11:53:31 2003
+++ Makefile.PL	Thu Sep 18 11:53:46 2003
@@ -365,7 +365,7 @@
 		  "\n");
 }
 print STDERR "\n";
-if (not ask('Do you want to proceed with this configuration?', 1)) {
+if (0) {
     # Need to set {install} for each component by prompting.
     foreach my $info (@opt_components) {
 	my $missing = $info->{missing};
