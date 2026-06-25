--- src/yafstat.c.orig	2026-03-19 20:13:51 UTC
+++ src/yafstat.c
@@ -57,7 +57,7 @@
 #include "yafdag.h"
 #endif
 
-static uint32_t     yaf_do_stat = 0;
+static volatile sig_atomic_t yaf_do_stat = 0;
 static GTimer      *yaf_fft = NULL;
 static yfContext_t *statctx = NULL;
 
@@ -66,7 +66,7 @@ yfSigUsr1(
     int   s)
 {
     (void)s;
-    ++yaf_do_stat;
+    yaf_do_stat = 1;
 }
 
 
@@ -83,6 +83,11 @@ yfStatInit(
     if (sigaction(SIGUSR1, &sa, &osa)) {
         g_error("sigaction(SIGUSR1) failed: %s", strerror(errno));
     }
+#ifdef SIGINFO
+    if (sigaction(SIGINFO,&sa,&osa)) {
+        g_error("sigaction(SIGINFO) failed: %s", strerror(errno));
+    }
+#endif /* SIGINFO */
 
     /* stash statistics context */
     statctx = ctx;
@@ -152,7 +157,7 @@ yfStatDumpLoop(
     void)
 {
     if (yaf_do_stat) {
-        --yaf_do_stat;
+        yaf_do_stat = 0;
         yfStatDump();
     }
 }
