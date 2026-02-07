--- Makefile.PL.orig	2010-10-13 16:31:29.000000000 +0800
+++ Makefile.PL	2010-10-13 16:33:05.000000000 +0800
@@ -10,6 +10,9 @@
 my @INCLUDES;
 my @LIBPATHS;
 
+push @INCLUDES , '%%LOCALBASE%%/include';
+push @LIBPATHS, '%%LOCALBASE%%/lib';
+
 if ($^O eq 'darwin') {
     if (! exists $ENV{USE_MACPORTS}) {
         print 
@@ -60,4 +63,4 @@
 
 test_requires 'Test::More';
 test_requires 'Test::Requires';
-WriteAll;
\ No newline at end of file
+WriteAll;
