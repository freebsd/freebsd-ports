$FreeBSD$
--- eqn2img.c	Tue Nov  5 18:10:13 2002
+++ eqn2img.c.port	Sat Feb  4 21:29:22 2006
@@ -675,7 +675,7 @@
     fprintf(stderr, " -> ps");
 
   cmd = NEW(char, 2*strlen(basename) + 35);
-  sprintf(cmd, "dvips -E -o %s.ps %s.dvi &> /dev/null", basename, basename);
+  sprintf(cmd, "dvips -q -E -o %s.ps %s.dvi", basename, basename);
   if(system(cmd)) {
     fprintf(stderr, "\nError running dvips\n");
     return -1;
@@ -714,7 +714,7 @@
 	  basename, dpi*supersample, xsize, ysize, basename);
   gs = popen(cmd, "w");
   fprintf(gs, "%i neg %i neg translate\n", xoffset, yoffset);
-  fclose(gs);
+  pclose(gs);
   sprintf(cmd, "%s.ps", basename);
   unlink(cmd);
   free(cmd);
