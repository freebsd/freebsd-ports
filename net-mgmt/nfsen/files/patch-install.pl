--- install.pl.orig	2012-01-23 20:36:02.000000000 +0400
+++ install.pl	2012-11-12 15:52:05.000000000 +0400
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%% -I %%PREFIX%%/libexec/nfsen
 #
 #
 #  Copyright (c) 2004, SWITCH - Teleinformatikdienste fuer Lehre und Forschung
@@ -88,33 +88,7 @@
 # Get Perl
 sub GetPerl {
 
-	my $whichperl;
-	my $ans;
-	$whichperl = FindCommand("perl");
-	if ( defined $whichperl ) {
-		print "Perl to use: [$whichperl] ";
-		chomp($ans = <STDIN>);
-		if ( length $ans ) {
-			$whichperl = $ans;
-		}
-	} else {
-		print "No Perl found in your PATH. Please specify where to find perl [] ";
-		chomp($whichperl = <STDIN>);
-	}
-
-	while (1) {
-		if ( -x $whichperl ) {
-			my $err = system("$whichperl -e 'require 5.6.0;'") >> 8;
-			last if $err == 0;
-			print "Found errors while testing Perl\n";
-		} else {
-			print "No executable: '$whichperl'\n";
-		}
-		print "Perl to use: [] ";
-		chomp($whichperl = <STDIN>);
-	}
-
-	return $whichperl;
+	return "%%PERL%%";
 
 } # End of GetPerl
 
