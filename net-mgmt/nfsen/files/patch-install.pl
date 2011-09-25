--- install.pl.orig	2010-09-09 09:56:05.000000000 +0400
+++ install.pl	2011-08-13 16:39:01.000000000 +0400
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%% -I %%PREFIX%%/libexec/nfsen
 #
 #
 #  Copyright (c) 2004, SWITCH - Teleinformatikdienste fuer Lehre und Forschung
@@ -85,33 +85,7 @@
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
 
@@ -200,11 +174,8 @@
 	}
 
 	my @out = `$NfConf::PREFIX/nfdump -V`;
-	if ( scalar @out != 2 ) {
-		die "Error getting nfdump version";
-	}
 	chomp $out[0];
-	my ($major, $minor) = $out[0] =~ /Version:\s(\d)\.(\d)\s/;
+	my ($major, $minor) = $out[0] =~ /Version:\s(\d)\.(\d)[\.\s]/;
 	if ( defined $major && defined $minor) {
 		if ( $major >= 1 && $minor >= 6 ) {
 			print "Found $out[0]\n";
@@ -212,7 +183,9 @@
 			print "out[0]\n";
 			die "Nfdump version not compatible with current NfSen version.\n";
 		}
-	} 
+	} else {
+	       die "Error getting nfdump version";
+        }	       
 
 	my $www_gid = getgrnam($NfConf::WWWGROUP) || 
 		die "WWW group '$NfConf::WWWGROUP' not found on this system\n";
