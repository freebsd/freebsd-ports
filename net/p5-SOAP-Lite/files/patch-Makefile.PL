--- Makefile.PL.orig	Mon May 28 17:12:36 2001
+++ Makefile.PL	Mon May 28 17:14:23 2001
@@ -71,7 +71,7 @@
 EOI
 
 my %prerequisites;
-my $auto = ExtUtils::MakeMaker::prompt("\nDo you want to proceed with this configuration?" => 'yes') =~ /^\s*y/i;
+my $auto = "y";
 
 foreach (split /(^[-\s]+$)/m, $prerequisites) {
   print unless $auto;
@@ -83,11 +83,7 @@
   } 
 }
 
-my $noncoretests = ExtUtils::MakeMaker::prompt('
-During "make test" phase we may run tests with several SOAP servers 
-that may take long and may fail due to server/connectivity problems. 
-
-Do you want to perform these tests in addition to core tests?', 'no') =~ /^\s*(y)/i;
+my $noncoretests = "n";
 
 my $tests = join ' ', glob ($noncoretests ? 't/*.t' : 't/0*.t');
 
