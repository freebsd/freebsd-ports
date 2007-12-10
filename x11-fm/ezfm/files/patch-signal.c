--- signal.c.orig	1999-10-07 22:08:11.000000000 +0200
+++ signal.c	2007-12-07 00:17:33.000000000 +0100
@@ -88,7 +88,7 @@
 {
   int i;
   char command[256];
-  fprintf(stderr, "existing, please wait ... ");
+  fprintf(stderr, "exiting, please wait ... ");
   sleep(3);
   for(i = 0; i < 8; i++)
     {
@@ -100,6 +100,7 @@
         }
     }
   fprintf(stderr, "Done\n");
+  _exit(EXIT_SUCCESS);
 }
 /**************************************************************/
 
