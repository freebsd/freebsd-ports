--- frontpage/version5.0/apache-fp/fpexe.c.orig	Fri Apr 20 09:01:13 2001
+++ frontpage/version5.0/apache-fp/fpexe.c	Wed May  2 20:26:02 2001
@@ -134,11 +134,11 @@
 #include <time.h>
 #include <pwd.h>
 #include <grp.h>
-#if !defined(bsdi) && !defined(hpux) && !defined(sun) && !defined(linux) && !defined(SCO5) && !defined(UWARE7) && !defined(FREEBSD)
+#if !defined(bsdi) && !defined(hpux) && !defined(sun) && !defined(linux) && !defined(SCO5) && !defined(UWARE7) && !defined(__FreeBSD__)
 #include <sys/mode.h>
 #endif
 
-#if defined(sun) || defined(bsdi) || defined(sgi) || defined(SCO5) || defined(UWARE7) || defined(FREEBSD) || defined(linux)
+#if defined(sun) || defined(bsdi) || defined(sgi) || defined(SCO5) || defined(UWARE7) || defined(__FreeBSD__) || defined(linux)
 extern const char ** environ;
 #endif
 extern int errno;
@@ -162,10 +162,13 @@
 
 #define KEYLEN 128                  /* Should be a multiple of sizeof(int) */
 
+#ifndef LOCALDIR
+#define LOCALDIR "/usr/local"
+#endif
 
-#define FPKEYDIR "/usr/local/frontpage/version5.0/apache-fp"
-#define KEYFILE  "/usr/local/frontpage/version5.0/apache-fp/suidkey.%d"
-#define FPDIR    "/usr/local/frontpage/version5.0/exes"
+#define FPKEYDIR LOCALDIR "/frontpage/version5.0/apache-fp"
+#define KEYFILE  LOCALDIR "/frontpage/version5.0/apache-fp/suidkey.%d"
+#define FPDIR    LOCALDIR "/frontpage/version5.0/exes"
 
 /* Legal modules */
 #define SHTML    "/_vti_bin/shtml.exe"
