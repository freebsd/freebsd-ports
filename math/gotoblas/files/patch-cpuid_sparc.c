--- cpuid_sparc.c.orig	2010-11-05 09:57:49.000000000 -0400
+++ cpuid_sparc.c	2011-09-23 13:10:18.000000000 -0400
@@ -49,6 +49,7 @@
 }
 
 void get_cpuconfig(void){
+  printf("#define SPARC\n");
   printf("#define V9\n");
   printf("#define DTB_ENTRIES 32\n");
 }
