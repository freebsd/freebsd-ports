$FreeBSD$

We lack OpenBSD's re-entrant logging functions.

--- milter-regex.c.orig	Sat Sep 27 16:58:48 2003
+++ milter-regex.c	Fri Oct  3 23:11:00 2003
@@ -54,7 +54,6 @@
 static const char	*rule_file_name = "/etc/milter-regex.conf";
 static struct ruleset	 ruleset;
 static int		 debug = 0;
-static struct syslog_data sdata = SYSLOG_DATA_INIT;
 
 static sfsistat	 cb_connect(SMFICTX *ctx, char *name, _SOCK_ADDR *sa);
 static sfsistat	 cb_helo(SMFICTX *ctx, char *arg);
@@ -378,7 +377,7 @@
 	if (vasprintf(&msg, fmt, ap) != -1) {
 		if (debug)
 			printf("%s\n", msg);
-		syslog_r(priority, &sdata, "%s", msg);
+		syslog(priority, "%s", msg);
 		free(msg);
 	}
 	va_end(ap);
@@ -411,7 +413,7 @@
 	sfsistat r = MI_FAILURE;
 
 	tzset();
-	openlog_r("milter-regex", LOG_PID | LOG_NDELAY, LOG_DAEMON, &sdata);
+	openlog("milter-regex", LOG_PID | LOG_NDELAY, LOG_DAEMON);
 
 	while ((ch = getopt(argc, argv, "dc:p:")) != -1) {
 		switch (ch) {
