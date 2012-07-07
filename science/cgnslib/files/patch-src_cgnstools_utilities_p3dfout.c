--- src/cgnstools/utilities/p3dfout.c.orig	2011-02-12 23:52:26.000000000 +0100
+++ src/cgnstools/utilities/p3dfout.c	2012-03-13 22:40:39.000000000 +0100
@@ -20,7 +20,7 @@
     MACH_LOCAL == MACH_UNKNOWN
     fprintf (stderr,
         "Fortran unformatted output not supported for %s machine\n",
-        bf_machname (MACH_LOCAL);
+        bf_machname (MACH_LOCAL));
     exit (1);
 #else
     buff = (char *) malloc (length + 1);
