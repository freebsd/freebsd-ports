--- src/taucs_memory.c.orig	2003-09-01 06:16:13 UTC
+++ src/taucs_memory.c
@@ -123,7 +123,6 @@ double taucs_system_memory_size()
 }
 #endif
 
-#ifdef OSTYPE_darwin
 #define TAUCS_SYSTEM_MEMORY_SIZE_DEFINED
 
 /* This is a BSD4.4 interface, so it should work on other BSD systems */
@@ -134,7 +133,7 @@ double taucs_system_memory_size()
 double taucs_system_memory_size()
 {
   int mib[2] = { CTL_HW, HW_PHYSMEM };
-  int int_retval;
+  unsigned long int_retval;
   size_t len = sizeof(int);
   
   taucs_printf("taucs_system_memory_size: calling sysctl\n");
@@ -142,7 +141,7 @@ double taucs_system_memory_size()
   if ( sysctl(mib,2,
 	      &int_retval,&len,
 	      NULL, 0)) {
-    taucs_printf("taucs_system_memory_size: ERROR, sysctl failed (on darwin)\n");
+    taucs_printf("taucs_system_memory_size: ERROR, HW_PAGESIZE sysctl failed (on bsd)\n");
     return -1.0;
   }
   taucs_printf("  sysctl pagesize %d bytes\n",int_retval);
@@ -151,14 +150,13 @@ double taucs_system_memory_size()
   if ( sysctl(mib,2,
 	      &int_retval,&len,
 	      NULL, 0)) {
-    taucs_printf("taucs_system_memory_size: ERROR, sysctl failed (on darwin)\n");
+    taucs_printf("taucs_system_memory_size: ERROR, HW_PHYSMEM sysctl failed (on bsd)\n");
     return -1.0;
   }
   taucs_printf("  sysctl physmem %d bytes\n",int_retval);
 
   return (double) int_retval;
 }
-#endif
 
 #ifdef OSTYPE_aix
 #define TAUCS_SYSTEM_MEMORY_SIZE_DEFINED
