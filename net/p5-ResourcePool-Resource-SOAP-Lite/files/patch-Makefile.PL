--- Makefile.PL.orig	Sat Feb 22 21:33:53 2003
+++ Makefile.PL	Fri Feb 28 12:43:54 2003
@@ -21,11 +21,4 @@
     $opts{AUTHOR} = 'Markus Winand <mws@fatalmind.com>';
 }
 
-my $onlinetests = ExtUtils::MakeMaker::prompt('
-During "make test" phase we may run tests against a SOAP server located
-at the authors website.
-
-Do you want to perform these tests in addition to core tests?', 'yes') =~ /^\s*(y)/i;
-
-$opts{test} = {TESTS => join(' ', glob($onlinetests ? 't/*.t' : 't/[0-3]*.t'))};
 WriteMakefile(%opts);
