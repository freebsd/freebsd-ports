--- Makefile.PL.orig	Fri Jul  4 14:04:35 2003
+++ Makefile.PL	Fri Jul  4 14:07:13 2003
@@ -2,27 +2,7 @@ use ExtUtils::MakeMaker qw( WriteMakefil
 use strict;
 
 # Much logic stolen fromm libwww-perl's Makefile.PL
-my $skiplive = 0;
-
-require IO::Socket;
-my $s = IO::Socket::INET->new(PeerAddr => "www.google.com:80",
-			      Timeout  => 10,
-			     );
-if ($s) {
-    close($s);
-    $skiplive = 0;
-} else {
-    print <<EOT;
-
-It seems that you are not directly connected to the Internet.  Many of 
-the WWW::Mechanize tests interact with websites such as Google.
-
-EOT
-
-    if ( prompt("Do you want to skip these tests?", "y") =~ /^y/i ) {
-	$skiplive = 1;
-    }
-} # failed connect
+my $skiplive = 1;
 
 my $filename = "t/SKIPLIVE";
 if ( $skiplive ) {
@@ -55,8 +35,6 @@ my $parms = {
 			},
 };
 
-if ( prompt( "Do you want to install the mech-forms utility?", "y" ) =~ /^y/i ) {
     $parms->{EXE_FILES} = [ 'script/mech-forms' ];
-}
 
 WriteMakefile( %$parms );
