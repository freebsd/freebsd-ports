--- Makefile.PL.orig	Fri Aug  1 17:10:09 2003
+++ Makefile.PL	Sat Mar  6 12:23:30 2004
@@ -89,6 +89,7 @@
 }
 
 sub mod_perl_version {
+    eval { require Apache2 };
     eval {
         require mod_perl
     };
