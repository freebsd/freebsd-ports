--- ./Makefile.PL.orig	2014-07-27 08:08:31.698966885 +0100
+++ ./Makefile.PL	2014-07-27 08:10:38.748963867 +0100
@@ -103,7 +103,7 @@
 # because it is accessed by some code we add to MakeMaker.
 #
 our @docs;
-@docs = qw(doc/COPYING doc/QuickStart doc/README.win32 README);
+@docs = qw();
 
 # Executables to be installed.
 my @exes
@@ -899,10 +899,7 @@
      { name => 'tv_check',
        blurb => 'Program to report exceptions and changes in a schedule',
        exes => [ 'choose/tv_check/tv_check' ],
-       docs => [ qw(choose/tv_check/README.tv_check
-                    choose/tv_check/tv_check_doc.html
-                    choose/tv_check/tv_check_doc.jpg
-                   ) ],
+       docs => [],
        prereqs => { 'Tk' => 0,
                     'Tk::TableMatrix' => 0,
                   } },
