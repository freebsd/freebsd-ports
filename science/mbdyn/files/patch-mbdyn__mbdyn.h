--- mbdyn/mbdyn.h.orig	Thu Feb 10 11:51:26 2005
+++ mbdyn/mbdyn.h	Thu Feb 10 11:51:34 2005
@@ -49,6 +49,7 @@
 typedef double        Real;
 
 /* signal types */
+#if !defined(__FreeBSD__)
 #ifdef HAVE_SIGNAL
 #ifndef HAVE___SIGHANDLER_T
 #ifndef HAVE_SIGHANDLER_T
@@ -58,6 +59,7 @@
 #endif /* HAVE_SIGHANDLER_T */
 #endif /* !HAVE___SIGHANDLER_T */
 #endif /* HAVE_SIGNAL */
+#endif
 
 /* sig_atomic_t */
 #ifndef HAVE_SIG_ATOMIC_T
