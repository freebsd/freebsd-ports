--- src/environment.h.orig	Wed Dec 12 18:49:39 2001
+++ src/environment.h	Fri Mar 21 19:15:34 2003
@@ -52,11 +52,13 @@
 #if	defined(HAVE_CRYPT_H)
 #include	<crypt.h>
 #endif
+/*
 #if	defined(HAVE_GETOPT_H)
 #include	<getopt.h>
 #elif	!defined(HAVE_GETOPT)
 #include	"getopt.h"
 #endif
+*/
 
 #if	defined(HAVE_ZLIB)
   #include	<zlib.h>
@@ -67,7 +69,7 @@
 #include	<thread.h>
 #endif
 #include	<pthread.h>
-#if	!defined(HAVE_PTHREAD_RWLOCK_INIT)
+#if	!defined(HAVE_PTHREAD_RWLOCK_INIT) && !defined(FREEBSD)
 #include	"rwlock.h"
 #endif
 
@@ -119,11 +121,11 @@
 #include	<sys/stat.h>
 #endif
 
-#if defined(HAVE_SYS_INTTYPES_H)
+#if defined(HAVE_INTTYPES_H)
 #include    <inttypes.h>
 #endif
 
-#if !defined(HAVE_SYS_INTTYPES_H) && !defined(_STDINT_H)
+#if !defined(HAVE_INTTYPES_H) && !defined(_STDINT_H)
 typedef unsigned int    uintptr_t;
 #endif
 
