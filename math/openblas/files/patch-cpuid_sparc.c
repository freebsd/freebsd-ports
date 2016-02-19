--- cpuid_sparc.c.orig	2015-10-27 20:44:50 UTC
+++ cpuid_sparc.c
@@ -49,6 +49,7 @@ void get_subdirname(void){
 }
 
 void get_cpuconfig(void){
+  printf("#define SPARC\n");
   printf("#define V9\n");
   printf("#define DTB_DEFAULT_ENTRIES 32\n");
 }
