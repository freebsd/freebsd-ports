diff -urP webjob-1.3.0/src/ktypes.h webjob-1.3.0.amd64/src/ktypes.h
--- src/ktypes.h.orig	Sun Jun 15 22:49:21 2003
+++ src/ktypes.h	Sun Apr  4 23:50:01 2004
@@ -11,7 +11,7 @@
  */
 
 #if defined(UNIX)
-  #if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+  #if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
     typedef char               K_INT08;
     typedef unsigned char      K_UINT08;
     typedef short              K_INT16;
