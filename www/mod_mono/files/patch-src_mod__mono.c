
$FreeBSD$

--- src/mod_mono.c.orig
+++ src/mod_mono.c
@@ -1765,8 +1765,12 @@
 
 	/* Unblock signals Mono uses: see bug #472732 */
 	sigemptyset (&sigset);
+#if defined SIGPWR
 	sigaddset (&sigset, SIGPWR);
+#endif /* def SIGPWR */
+#if defined SIGXCPU
 	sigaddset (&sigset, SIGXCPU);
+#endif /* def SIGXCPU */
 	sigaddset (&sigset, 33);
 	sigaddset (&sigset, 35);
 	sigprocmask (SIG_UNBLOCK, &sigset, NULL);
