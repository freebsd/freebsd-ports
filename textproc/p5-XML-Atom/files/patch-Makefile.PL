--- Makefile.PL.orig	Mon Sep  8 15:33:37 2003
+++ Makefile.PL	Sat Dec 27 19:39:19 2003
@@ -3,7 +3,7 @@
 use ExtUtils::MakeMaker;
 use strict;
 
-use ExtUtils::AutoInstall (
+q{use ExtUtils::AutoInstall (
     -core => [
         'XML::LibXML' => 1.54,
         'MIME::Base64' => 0,
@@ -24,7 +24,7 @@
         -default => 0,
         'XML::LibXSLT' => 0,
     ],
-);
+)};
 
 WriteMakefile(
     NAME => 'XML::Atom',
