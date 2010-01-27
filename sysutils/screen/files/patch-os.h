--- os.h.orig	2002-01-08 07:42:33.000000000 -0800
+++ os.h	2010-01-26 21:20:44.000000000 -0800
@@ -161,7 +161,7 @@
 # define setregid(rgid, egid) setresgid(rgid, egid, -1)
 #endif
 
-#if defined(HAVE_SETEUID) || defined(HAVE_SETREUID)
+#if (defined(HAVE_SETEUID) || defined(HAVE_SETREUID)) && __FreeBSD_version < 500000
 # define USE_SETEUID
 #endif
 
@@ -262,7 +262,9 @@
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
 # if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
 #  include <utmpx.h>
+#ifndef __FreeBSD_version
 #  define UTMPFILE	UTMPX_FILE
+#endif
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
