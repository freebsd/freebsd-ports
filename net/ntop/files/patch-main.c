--- main.c.orig	Mon Jul 14 19:34:51 2003
+++ main.c	Mon Jul 14 19:43:31 2003
@@ -757,7 +757,7 @@
   
   if((argc == 2) && (argv[1][0] != '-')) {
     /* Options specified on a configuration file */
-    FILE *fd = fopen(argv[optind], "r");
+    FILE *fd = fopen(argv[optind] + 1, "r");
 
     if(fd != NULL) {
 


