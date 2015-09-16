--- Makefile.PL.orig	2008-03-03 17:27:16 UTC
+++ Makefile.PL
@@ -83,6 +83,7 @@
 
 sub mod_perl_version {
     # try to figure out what version of mod_perl is installed.
+    eval { require Apache2 };
     eval {
         require mod_perl
     };
