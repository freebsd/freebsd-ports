diff -urP webjob-1.3.0/src/webjob.c webjob-1.3.0.amd64/src/webjob.c
--- src/webjob.c.orig	Thu Jul 24 23:05:17 2003
+++ src/webjob.c	Sun Apr  4 23:50:08 2004
@@ -1478,7 +1478,7 @@
     return ER;
   }
 
-#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64)
+#if defined(K_CPU_ALPHA) || defined(K_CPU_IA64) || defined(K_CPU_AMD64)
   sprintf(acQuery, "VERSION=%s&SYSTEM=%s&CLIENTID=%s&FILENAME=%s&RUNTYPE=%s&STDOUT_LENGTH=%u&STDERR_LENGTH=%u&STDENV_LENGTH=%u",
 #else
   sprintf(acQuery, "VERSION=%s&SYSTEM=%s&CLIENTID=%s&FILENAME=%s&RUNTYPE=%s&STDOUT_LENGTH=%lu&STDERR_LENGTH=%lu&STDENV_LENGTH=%lu",
