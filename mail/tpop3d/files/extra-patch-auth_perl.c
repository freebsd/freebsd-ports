--- auth_perl.c.orig	Mon Aug 25 21:51:25 2003
+++ auth_perl.c	Mon Dec  4 14:23:46 2006
@@ -72,5 +72,5 @@
 
 int auth_perl_init(void) {
-    dSP;
+//    dSP;
     int argc = 2;
     char *argv[3] = {"auth_perl", "/dev/null", NULL};
@@ -106,4 +106,6 @@
     perl_parse(perl_interp, xs_init, argc, argv, 0);
     perl_run(perl_interp);
+
+    dSP;
 
     /* Try to execute the startup code. */
