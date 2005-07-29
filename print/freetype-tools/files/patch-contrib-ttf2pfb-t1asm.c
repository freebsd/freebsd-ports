--- contrib/ttf2pfb/t1asm.c.orig	Thu Jul 28 01:54:45 2005
+++ contrib/ttf2pfb/t1asm.c	Thu Jul 28 01:56:55 2005
@@ -49,8 +49,8 @@
 
 typedef unsigned char byte;
 
-static FILE *ifp = stdin;
-static FILE *ofp = stdout;
+static FILE *ifp;
+static FILE *ofp;
 
 /* flags */
 static int pfb = 0;
@@ -437,6 +437,8 @@
   extern int optind;
   extern int getopt(int argc, char **argv, char *optstring);
 
+  ifp = stdin;
+  ofp = stdout;
   fprintf(stderr, "%s", BANNER);
 
   /* interpret command line arguments using getopt */
