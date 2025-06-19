--- catatonit.c.orig	2024-12-14 09:08:49 UTC
+++ catatonit.c
@@ -28,8 +28,9 @@
 #include <stdbool.h>
 #include <unistd.h>
 #include <getopt.h>
-#include <sys/prctl.h>
-#include <sys/signalfd.h>
+#include <sys/param.h>
+#include <sys/event.h>
+#include <sys/procctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -359,7 +360,7 @@ static int spawn_pid1(char *file, char **argv, sigset_
 	if (sigprocmask(SIG_SETMASK, sigmask, NULL) < 0)
 		bail("failed to reset sigmask: %m");
 
-	execvpe(file, argv, environ);
+	execvp(file, argv);
 	bail("failed to exec pid1: %m");
 }
 
@@ -412,6 +413,19 @@ static int reap_zombies(pid_t pid1, int *pid1_exitcode
 	}
 }
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 1400093
+
+char *secure_getenv(const char *name)
+{
+	if (getuid() != geteuid()) {
+		return NULL;
+	} else {
+		return getenv(name);
+	}
+}
+
+#endif
+
 int main(int argc, char **argv)
 {
 	/* If CATATONIT_DEBUG is defined we change the global log level. */
@@ -439,9 +453,18 @@ int main(int argc, char **argv)
 	if (sigprocmask(SIG_SETMASK, &init_sigmask, &pid1_sigmask) < 0)
 		bail("failed to block all signals: %m");
 
-	int sfd = signalfd(-1, &init_sigmask, SFD_CLOEXEC);
+	int sfd = kqueue();
 	if (sfd < 0)
-		bail("failed to create signalfd: %m");
+		bail("failed to create kqueue: %m");
+	for (i = 0; i < SIGRTMIN; i++) {
+		if (sigismember(&init_sigmask, i)) {
+			struct kevent kev;
+			EV_SET(&kev, i, EVFILT_SIGNAL, EV_ADD, 0, 0, NULL);
+			if (kevent(sfd, &kev, 1, NULL, 0, NULL)) {
+				bail("failed to add kevent signal %d: %m", i);
+			}
+		}
+	}
 
 	/*
 	 * We need to support "--" as well as provide license information and so
@@ -490,12 +513,9 @@ int main(int argc, char **argv)
 	 * container init is effectively zero in that instance).
 	 */
 	if (getpid() != 1) {
-#if defined(PR_SET_CHILD_SUBREAPER)
-		if (prctl(PR_SET_CHILD_SUBREAPER, 1, 0, 0, 0) < 0)
+		if (procctl(P_PID, getpid(), PROC_REAP_ACQUIRE, NULL) < 0) {
 			bail("failed to set child-reaper as non-pid1: %m");
-#else
-		bail("cannot run as non-pid1 without child-reaper support in kernel");
-#endif
+		}
 	}
 
 	/* Spawn the faux-pid1. */
@@ -541,18 +561,15 @@ int main(int argc, char **argv)
 		 * anything else, so no need for select(2) or epoll(2) or anything
 		 * equivalently clever.
 		 */
-		struct signalfd_siginfo ssi = {0};
+		struct kevent kev;
 
-		int n = read(sfd, &ssi, sizeof(ssi));
-		if (n != sizeof(ssi)) {
-			if (n < 0)
-				warn("signalfd read failed: %m");
-			else
-				warn("signalfd had %d-byte partial-read: %m", n);
+		int n = kevent(sfd, NULL, 0, &kev, 1, NULL);
+		if (n < 0) {
+			warn("signalfd read failed: %m");
 			continue;
 		}
 
-		switch (ssi.ssi_signo) {
+		switch (kev.ident) {
 		/*
 		 * Signals that we get sent if we are a background job in the current
 		 * terminal (if it has TOSTOP set), which is possible since we make
@@ -578,10 +595,10 @@ int main(int argc, char **argv)
 		default:
 			/* We just forward the signal to pid1. */
 			if (run_as_pause) {
-				if (ssi.ssi_signo == SIGTERM || ssi.ssi_signo == SIGINT)
+				if (kev.ident == SIGTERM || kev.ident == SIGINT)
 					return 0;
-			} else if (kill(pid1_target, ssi.ssi_signo) < 0) {
-				warn("forwarding of signal %d to pid1 (%d) failed: %m", ssi.ssi_signo, pid1_target);
+			} else if (kill(pid1_target, kev.ident) < 0) {
+				warn("forwarding of signal %d to pid1 (%d) failed: %m", kev.ident, pid1_target);
 			}
 			break;
 		}
