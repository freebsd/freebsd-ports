--- Makefile.PL.orig	Wed Sep 17 21:05:42 2003
+++ Makefile.PL	Wed Sep 17 21:06:03 2003
@@ -8,8 +8,8 @@
 
 use ExtUtils::MakeMaker;
 
-$cflags = `sary-config --cflags`;
-$libs = `sary-config --libs`;
+$cflags = `pkg-config --cflags sary`;
+$libs = `pkg-config --libs sary`;
 
 WriteMakefile(
 	      'NAME' => 'Search::Saryer',
