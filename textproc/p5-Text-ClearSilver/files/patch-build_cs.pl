--- tool/build_cs.pl.orig	2013-01-19 19:25:13.456439936 +0900
+++ tool/build_cs.pl	2013-01-19 19:25:22.046439456 +0900
@@ -37,7 +37,7 @@
     }
     die "$0 stopped";
 };
-xsystem('make');
+xsystem('gmake');
 
 sub xsystem {
     print "@_\n";
