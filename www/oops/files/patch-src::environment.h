
$FreeBSD$

--- src/environment.h.orig	Wed Dec 12 16:49:39 2001
+++ src/environment.h	Thu Jul 25 20:10:35 2002
@@ -67,7 +67,7 @@
 #include	<thread.h>
 #endif
 #include	<pthread.h>
-#if	!defined(HAVE_PTHREAD_RWLOCK_INIT)
+#if	!defined(HAVE_PTHREAD_RWLOCK_INIT) && !defined(FREEBSD)
 #include	"rwlock.h"
 #endif
 
@@ -119,11 +119,11 @@
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
 
