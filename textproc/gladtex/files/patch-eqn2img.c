$FreeBSD$
--- eqn2img.c	2007-10-05 17:51:48.000000000 +0200
+++ eqn2img.c.port	2007-12-19 14:08:52.000000000 +0100
@@ -691,7 +691,7 @@
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 35);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi > /dev/null 2>&1", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
