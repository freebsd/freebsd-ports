--- Makefile.PL.orig	Sun Apr 28 17:19:28 2002
+++ Makefile.PL	Sun Apr 28 17:19:36 2002
@@ -1,6 +1,6 @@
 use ExtUtils::MakeMaker;
 
-@scripts = grep {-f } glob("scripts/*.*");
+@scripts = grep {-f } glob("scripts/*.pl");
 
 # incantation to enable MY::pm_to_blib later on
 push(@ExtUtils::MakeMaker::Overridable, qw(pm_to_blib)) if ($^O eq 'MSWin32');
