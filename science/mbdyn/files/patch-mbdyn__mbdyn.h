--- mbdyn/mbdyn.h.orig	2015-10-30 05:05:37 UTC
+++ mbdyn/mbdyn.h
@@ -50,6 +50,7 @@ typedef long int      Lint;
 typedef double        Real;
 
 /* signal types */
+#if !defined(__FreeBSD__)
 #ifdef HAVE_SIGNAL
 #ifndef HAVE___SIGHANDLER_T
 #ifndef HAVE_SIGHANDLER_T
@@ -59,6 +60,7 @@ typedef sighandler_t __sighandler_t;
 #endif /* HAVE_SIGHANDLER_T */
 #endif /* !HAVE___SIGHANDLER_T */
 #endif /* HAVE_SIGNAL */
+#endif
 
 /* sig_atomic_t */
 #ifndef HAVE_SIG_ATOMIC_T
