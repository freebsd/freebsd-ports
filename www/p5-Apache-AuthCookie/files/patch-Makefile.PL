--- Makefile.PL.orig	2008-03-03 18:27:16.000000000 +0100
+++ Makefile.PL	2008-04-17 14:22:53.000000000 +0200
@@ -83,6 +83,7 @@
 
 sub mod_perl_version {
     # try to figure out what version of mod_perl is installed.
+    eval { require Apache2 };
     eval {
         require mod_perl
     };
