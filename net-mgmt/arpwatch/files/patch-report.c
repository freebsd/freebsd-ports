--- report.c.orig	Sat Sep 30 19:41:10 2000
+++ report.c	Tue Apr 13 17:47:16 2004
@@ -45,6 +45,8 @@
 
 #include <ctype.h>
 #include <errno.h>
+#include <fcntl.h>
+#include <paths.h>
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -70,6 +72,8 @@
 
 #define PLURAL(n) ((n) == 1 || (n) == -1 ? "" : "s")
 
+extern char *Watcher;
+
 static int cdepth;	/* number of outstanding children */
 
 static char *fmtdate(time_t);
@@ -240,7 +244,7 @@
 	register FILE *f;
 	char tempfile[64], cpu[64], os[64];
 	char *fmt = "%20s: %s\n";
-	char *watcher = WATCHER;
+	char *watcher = Watcher ? Watcher : WATCHER;
 	char *watchee = WATCHEE;
 	char *sendmail = PATH_SENDMAIL;
 	char *unknown = "<unknown>";
@@ -303,7 +307,7 @@
 	(void)fprintf(f, "From: %s\n", watchee);
 	(void)fprintf(f, "To: %s\n", watcher);
 	hn = gethname(a);
-	if (!isdigit(*hn))
+	if (hn != NULL)
 		(void)fprintf(f, "Subject: %s (%s)\n", title, hn);
 	else {
 		(void)fprintf(f, "Subject: %s\n", title);
@@ -344,6 +348,25 @@
 		exit(1);
 	}
 	/* XXX Need to freopen()? */
+
+	/*
+	 * Open /dev/null as stdout and stderr so that sendmail 8.12.1 (and
+	 * above ?) won't complain about missing file descriptors.
+	 */
+	if ((fd = open(_PATH_DEVNULL, O_RDWR)) == -1) {
+		syslog(LOG_ERR, "Cannot open %s: %m", _PATH_DEVNULL);
+		exit(1);
+	}
+	if (dup2(fd, STDOUT_FILENO) == -1) {
+		syslog(LOG_ERR, "Cannot dup2 %s to stdout: %m", _PATH_DEVNULL);
+		exit(1);
+	}
+	if (dup2(fd, STDERR_FILENO) == -1) {
+		syslog(LOG_ERR, "Cannot dup2 %s to stderr: %m", _PATH_DEVNULL);
+		exit(1);
+	}
+	close(fd);
+
 	/* Always Deliver interactively (pause when child depth gets large) */
 	execl(sendmail, "sendmail", "-odi", watcher, NULL);
 	syslog(LOG_ERR, "execl: %s: %m", sendmail);
