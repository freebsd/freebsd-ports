--- tools/ecflow_standalone.c.orig	2024-06-19 10:20:26 UTC
+++ tools/ecflow_standalone.c
@@ -85,7 +85,7 @@ pid_t do_setsid(void) {
 }
 
 pid_t do_setsid(void) {
-#if defined(linux) || defined(__APPLE__) || defined(__MACH__) || defined(hpux) || defined(solaris) || defined(SGI) || \
+#if defined(linux) || defined(__FreeBSD__) || defined(__APPLE__) || defined(__MACH__) || defined(hpux) || defined(solaris) || defined(SGI) || \
     defined(SVR4) || defined(AIX) || defined(SYG) || defined(alpha) || defined(__NVCOMPILER)
     return setsid();
 #else
