--- src/inotifywatch.c.orig	2021-09-28 08:39:16 UTC
+++ src/inotifywatch.c
@@ -11,6 +11,9 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <getopt.h>
+#ifdef __FreeBSD__
+#include <pthread.h>
+#endif // __FreeBSD__
 #include <limits.h>
 #include <regex.h>
 #include <signal.h>
@@ -96,8 +99,24 @@ int main(int argc, char **argv) {
     char *inc_iregex = NULL;
     int rc;
 
+#ifdef __FreeBSD__
+    sigset_t set, oset;
+#endif // __FreeBSD__
+
     signal(SIGINT, handle_impatient_user);
 
+#ifdef __FreeBSD__
+    // Block some signals in libinotify's worker thread, so that
+    // handle_signal runs in the context of the main thread and
+    // the 'done' flag is actually honored.
+    sigemptyset(&set);
+    sigaddset(&set, SIGINT);
+    sigaddset(&set, SIGHUP);
+    sigaddset(&set, SIGTERM);
+    sigaddset(&set, SIGALRM);
+    pthread_sigmask(SIG_BLOCK, &set, &oset);
+#endif // __FreeBSD__
+
     // Parse commandline options, aborting if something goes wrong
     if (!parse_opts(&argc, &argv, &events, &timeout, &verbose, &zero, &sort,
 		    &recursive, &no_dereference, &fromfile, &exc_regex,
@@ -130,6 +149,10 @@ int main(int argc, char **argv) {
 	    warn_inotify_init_error(fanotify);
 	    return EXIT_FAILURE;
     }
+
+#ifdef __FreeBSD__
+    pthread_sigmask(SIG_SETMASK, &oset, NULL);
+#endif // __FreeBSD__
 
     // Attempt to watch file
     // If events is still 0, make it all events.
