--- Makefile.PL.orig	Mon Mar 12 14:50:35 2001
+++ Makefile.PL	Mon Mar 12 14:50:39 2001
@@ -1,9 +1,5 @@
 use ExtUtils::MakeMaker;
 use File::Basename;
-use blib '..';
-use blib '../Gnome';
-use blib '../GdkImlib';
-use blib '../GdkPixbuf';
 use Cwd;
 require '../Depends.pm';
 require '../tools/gendefs.pl';
