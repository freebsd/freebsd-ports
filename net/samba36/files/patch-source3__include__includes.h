--- ./source3/include/includes.h.orig	2011-08-09 13:17:47.000000000 +0200
+++ ./source3/include/includes.h	2011-10-04 00:34:33.000000000 +0200
@@ -161,6 +161,10 @@
 #include <sys/uio.h>
 #endif
 
+#ifdef HAVE_SYS_SYSCTL_H
+#include <sys/sysctl.h>
+#endif
+
 #if HAVE_LANGINFO_H
 #include <langinfo.h>
 #endif
@@ -548,10 +552,6 @@
 #define SIGCLD SIGCHLD
 #endif
 
-#ifndef SIGRTMIN
-#define SIGRTMIN NSIG
-#endif
-
 #if defined(HAVE_PUTPRPWNAM) && defined(AUTH_CLEARTEXT_SEG_CHARS)
 #define OSF1_ENH_SEC 1
 #endif
