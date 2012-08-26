--- cpuid_sparc.c.orig	2012-02-05 16:29:26.000000000 +0900
+++ cpuid_sparc.c	2012-02-05 16:29:45.000000000 +0900
@@ -49,6 +49,7 @@
 }
 
 void get_cpuconfig(void){
+  printf("#define SPARC\n");
   printf("#define V9\n");
   printf("#define DTB_DEFAULT_ENTRIES 32\n");
 }
