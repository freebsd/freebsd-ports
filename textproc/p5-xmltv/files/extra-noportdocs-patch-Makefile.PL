--- Makefile.PL.orig	Tue Jul 20 22:34:47 2004
+++ Makefile.PL	Tue Jul 20 22:34:58 2004
@@ -88,7 +88,7 @@
 # because it is accessed by some code we add to MakeMaker.
 #
 our @docs;
-@docs = qw(doc/COPYING doc/QuickStart doc/README.win32 README);
+@docs = qw();
 
 # Executables to be installed.
 my @exes
@@ -375,10 +375,7 @@
      { name => 'tv_check',
        blurb => 'Program to report exceptions and changes in a schedule',
        exes => [ 'choose/tv_check/tv_check' ],
-       docs => [ qw(choose/tv_check/README.tv_check
-		    choose/tv_check/tv_check_doc.html
-		    choose/tv_check/tv_check_doc.jpg
-		   ) ],
+       docs => [],
        prereqs => { 'Tk' => 0,
 		    'Tk::TableMatrix' => 0,
 		  } },
