--- Graphics/PLplot/Makefile.PL.orig	Fri Mar 12 08:38:52 2004
+++ Graphics/PLplot/Makefile.PL	Fri Mar 12 08:39:43 2004
@@ -164,7 +164,7 @@
 				   'PLplot.pm PLplot.xs PLplot.o PLplot.c PLplot.bs *.xfig temp* OPTIONS! Makefile.old'},
 	      );
 
-sub MY::postamble { pdlpp_postamble($package); }	
+sub MY::postamble { pdlpp_postamble_int($package); }	
 
 sub compileAndRun {
   my $flags = shift;
