--- src/inotifywatch.c.orig	2015-11-09 01:40:46 UTC
+++ src/inotifywatch.c
@@ -12,6 +12,9 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <getopt.h>
+#ifdef __FreeBSD__
+#include <pthread.h>
+#endif // __FreeBSD__
 #include <regex.h>
 #include <signal.h>
 #include <stdbool.h>
@@ -93,6 +96,9 @@ int main(int argc, char ** argv)
 	char * exc_iregex = NULL;
 	char * inc_regex = NULL;
 	char * inc_iregex = NULL;
+#ifdef __FreeBSD__
+	sigset_t set, oset;
+#endif // __FreeBSD__
 
 	signal( SIGINT, handle_impatient_user );
 
@@ -121,11 +127,27 @@ int main(int argc, char ** argv)
 		return EXIT_FAILURE;
 	}
 
+#ifdef __FreeBSD__
+	// Block some signals in libinotify's worker thread, so that
+	// handle_signal runs in the context of the main thread and
+	// the 'done' flag is actually honored.
+	sigemptyset(&set);
+	sigaddset(&set, SIGINT);
+	sigaddset(&set, SIGHUP);
+	sigaddset(&set, SIGTERM);
+	sigaddset(&set, SIGALRM);
+	pthread_sigmask(SIG_BLOCK, &set, &oset);
+#endif // __FreeBSD__
+
 	if ( !inotifytools_initialize() ) {
 		warn_inotify_init_error();
 		return EXIT_FAILURE;
 	}
 
+#ifdef __FreeBSD__
+	pthread_sigmask(SIG_SETMASK, &oset, NULL);
+#endif // __FreeBSD__
+
 	// Attempt to watch file
 	// If events is still 0, make it all events.
 	if ( !events )
