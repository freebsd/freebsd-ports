--- src/main.c.orig	2022-08-11 06:59:04 UTC
+++ src/main.c
@@ -373,20 +373,24 @@ int main(int argc, char *argv[])
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
+
+	/*
+	 * Become a session leader with no controlling terminal.
+	 *
+	 * When pimd is started at boot from an rc script whose session is
+	 * attached to the (serial) console, the forked child otherwise stays
+	 * in the console's foreground process group.  An INTR character (^C)
+	 * on the console then reaches pimd through the tty line discipline
+	 * (tty_signal_pgrp -> SIGINT) and pimd shuts down.  setsid() detaches
+	 * us from that session and controlling tty entirely.
+	 *
+	 * setsid() is the portable primitive; it supersedes the older
+	 * setpgrp()/TIOCNOTTY variants below, which on FreeBSD left the child
+	 * in the console process group because TIOCNOTTY was preferred over
+	 * setsid().
+	 */
 	if (setsid() < 0)
 	    perror("setsid");
-#endif
-#endif
     }
 
     /*
