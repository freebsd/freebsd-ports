
$FreeBSD$

--- install.pl.orig
+++ install.pl
@@ -56,33 +56,7 @@
 # Get Perl
 sub GetPerl {
 
-	my $whichperl;
-	my $ans;
-	chomp($whichperl = `which perl`);
-	if ( length $whichperl ) {
-		print "Perl to use: [$whichperl] ";
-		chomp($ans = <STDIN>);
-		if ( length $ans ) {
-			$whichperl = $ans;
-		}
-	} else {
-		print "No Perl found in PATH. Please specify where to find perl [] ";
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
 
