--- src/alc/mcl_includes.h.orig	Tue Jul 22 19:37:39 2003
+++ src/alc/mcl_includes.h	Tue Oct 14 15:23:54 2003
@@ -40,11 +40,13 @@
 #include <sys/types.h>
 #include <math.h>
 
+#ifndef FREEBSD
 #if defined(DEBUG) && defined(MPATROL) && !defined(WIN32)
 #include <mpatrol.h>
 #else
 #include <malloc.h>
 #endif
+#endif
 #include <new>		// required by _set_new_handler on linux
 
 
@@ -58,14 +60,18 @@
 #else	/* UNIX Systems */
 
 #include <unistd.h>
+
+#ifndef FREEBSD
 #include <values.h>	/* for MAXINT */
+#endif
+
 #include <strings.h>
 #include <sys/time.h>
 #include <sys/wait.h>
 #include <pthread.h>
 #include <sys/uio.h>
 
-#ifdef SOLARIS
+#if defined(SOLARIS) || defined(FREEBSD)
 #include <netinet/in_systm.h>
 #endif /* SOLARIS */
 
