--- src/main.c.orig	2026-09-18 05:38:16 UTC
+++ src/main.c
@@ -362,9 +362,31 @@ int main(int argc, char *argv[])
     }
 
     if (!foreground) {
-	if (fork())
+	pid_t pid;
+
+	pid = fork();
+	if (pid == -1)
+	    err(1, "Failed forking to the background");
+	if (pid)
 	    exit(0);
 
+	/*
+	 * Leave the session, the controlling terminal and the process
+	 * group of whoever started us, before the standard descriptors
+	 * go to /dev/null, so that a failure can still be reported.
+	 *
+	 * setsid() is the portable primitive for this.  The TIOCNOTTY
+	 * ioctl that used to be preferred here cannot do it: the kernel
+	 * refuses it to anyone but a session leader, which the child of
+	 * a fork() never is, and pimd threw the error away.  A daemon
+	 * started from an rc script on a console was left in the
+	 * terminal's foreground process group, where an INTR character
+	 * typed on that console killed it.  setpgrp(), taken on Linux,
+	 * left the session and the terminal attached for their part.
+	 */
+	if (setsid() == -1)
+	    perror("setsid");
+
 	close(STDIN_FILENO);
 	close(STDOUT_FILENO);
 	close(STDERR_FILENO);
@@ -376,20 +398,6 @@ int main(int argc, char *argv[])
 	    dup2(fd, STDERR_FILENO);
 	    close(fd);
 	}
-#if defined(SYSV) || defined(__linux__)
-	setpgrp();
-#else
-#ifdef TIOCNOTTY
-	fd = open("/dev/tty", 2);
-	if (fd >= 0) {
-	    (void)ioctl(fd, TIOCNOTTY, NULL);
-	    close(fd);
-	}
-#else
-	if (setsid() < 0)
-	    perror("setsid");
-#endif
-#endif
     }
 
     /*
