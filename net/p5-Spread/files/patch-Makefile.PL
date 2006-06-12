--- Makefile.PL.orig	Thu Sep 26 07:54:46 2002
+++ Makefile.PL	Mon Jun 12 12:13:33 2006
@@ -2,8 +2,8 @@
 use ExtUtils::MakeMaker 5.16 ;
 use Config ;
 
-$SPLIB_LIB = '-L../.. -L../spread-src-3.17.0/' ;
-$SPLIB_INCLUDE = '-I ../.. -I ../spread-src-3.17.0/' ;
+$SPLIB_LIB = '-L../.. -L../spread-src-3.17.0/ -L/usr/local/lib' ;
+$SPLIB_INCLUDE = '-I ../.. -I ../spread-src-3.17.0/ -I/usr/local/include';
 
 WriteMakefile(
 	NAME		=> 'Spread',
