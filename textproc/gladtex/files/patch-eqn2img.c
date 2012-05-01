--- ./eqn2img.c.orig	2012-05-01 18:17:08.000000000 +0200
+++ ./eqn2img.c	2012-05-01 18:18:00.000000000 +0200
@@ -715,7 +715,7 @@
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 38);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
