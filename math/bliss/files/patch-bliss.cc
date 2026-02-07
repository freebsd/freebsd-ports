--- bliss.cc.orig	2021-05-22 21:39:07 UTC
+++ bliss.cc
@@ -59,7 +59,7 @@ usage(FILE* const fp, const char* argv0)
   else program_name = argv0;  
   if(!program_name or *program_name == 0) program_name = "bliss";
 
-  fprintf(fp, "bliss version %s (compiled "__DATE__")\n", bliss::version);
+  fprintf(fp, "bliss version %s (compiled " __DATE__ ")\n", bliss::version);
   fprintf(fp, "Copyright 2003-2015 Tommi Junttila\n");
   fprintf(fp,
 "\n"
