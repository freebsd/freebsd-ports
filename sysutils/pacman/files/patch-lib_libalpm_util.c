--- lib/libalpm/util.c.orig	2018-11-19 01:25:18 UTC
+++ lib/libalpm/util.c
@@ -33,6 +33,7 @@
 #include <sys/socket.h>
 #include <fnmatch.h>
 #include <poll.h>
+#include <signal.h>
 
 /* libarchive */
 #include <archive.h>
@@ -556,7 +557,7 @@ static void _alpm_reset_signals(void)
 	int *i, signals[] = {
 		SIGABRT, SIGALRM, SIGBUS, SIGCHLD, SIGCONT, SIGFPE, SIGHUP, SIGILL,
 		SIGINT, SIGKILL, SIGPIPE, SIGQUIT, SIGSEGV, SIGSTOP, SIGTERM, SIGTSTP,
-		SIGTTIN, SIGTTOU, SIGUSR1, SIGUSR2, SIGPOLL, SIGPROF, SIGSYS, SIGTRAP,
+		SIGTTIN, SIGTTOU, SIGUSR1, SIGUSR2, SIGIO, SIGPROF, SIGSYS, SIGTRAP,
 		SIGURG, SIGVTALRM, SIGXCPU, SIGXFSZ,
 		0
 	};
