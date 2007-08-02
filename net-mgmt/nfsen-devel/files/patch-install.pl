
$FreeBSD$

--- install.pl.orig
+++ install.pl
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!%%PERL%% -I %%PREFIX%%/libexec/nfsen
 #
 #
 #  Copyright (c) 2004, SWITCH - Teleinformatikdienste fuer Lehre und Forschung
@@ -83,33 +83,7 @@
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
 
@@ -620,7 +594,7 @@
 	exit 1;
 }
 
-my $hints = NfSen::LoadHints();
+my $hints = NfSen::LoadHints_startup();
 if ( $$$hints{'version'} == -1 ) {
 	# initial NfSen install or upgrade from old version without hints
 	$$$hints{'version'} 		= $nfsen_version;
@@ -725,7 +699,7 @@
 
 
 Nfsources::Reconfig();
-NfSen::StoreHints();
+NfSen::StoreHints_startup();
 chown $nfsen_uid, $www_gid, "$NfConf::PROFILESTATDIR/hints" || die "Can't chown hints db: $!\n";
 print "Setup done.\n\n";
 
