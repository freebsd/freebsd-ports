--- clients/upslog.c.orig	2022-08-29 22:20:14.342137000 -0700
+++ clients/upslog.c	2022-08-29 22:21:10.934419000 -0700
@@ -41,32 +45,49 @@
 #include "upslog.h"
 
 	static	int	reopen_flag = 0, exit_flag = 0;
-	static	uint16_t	port;
-	static	char	*upsname, *hostname;
-	static	UPSCONN_t	ups;
+	static	char	*upsname;
+	static	UPSCONN_t	*ups;
 
-	static	FILE	*logfile;
-	static	const	char *logfn, *monhost;
+	static	char *logfn, *monhost;
 	static	sigset_t	nut_upslog_sigmask;
 	static	char	logbuffer[LARGEBUF], *logformat;
 
 	static	flist_t	*fhead = NULL;
+	struct 	monhost_ups {
+		char	*monhost;
+		char	*logfn;
+		char	*upsname;
+		char	*hostname;
+		uint16_t	port;
+		UPSCONN_t	*ups;
+		FILE	*logfile;
+		struct	monhost_ups	*next;
+	};
+	static	struct	monhost_ups *monhost_ups_anchor = NULL;
+	static	struct	monhost_ups *monhost_ups_current = NULL;
+	static	struct	monhost_ups *monhost_ups_prev = NULL;
 
+
 #define DEFAULT_LOGFORMAT "%TIME @Y@m@d @H@M@S% %VAR battery.charge% " \
 		"%VAR input.voltage% %VAR ups.load% [%VAR ups.status%] " \
 		"%VAR ups.temperature% %VAR input.frequency%"
 
 static void reopen_log(void)
 {
-	if (logfile == stdout) {
-		upslogx(LOG_INFO, "logging to stdout");
-		return;
-	}
+	for (monhost_ups_current = monhost_ups_anchor;
+	     monhost_ups_current != NULL;
+	     monhost_ups_current = monhost_ups_current->next) {
+		if (monhost_ups_current->logfile == stdout) {
+			upslogx(LOG_INFO, "logging to stdout");
+			return;
+		}
 
-	fclose(logfile);
-	logfile = fopen(logfn, "a");
-	if (logfile == NULL)
-		fatal_with_errno(EXIT_FAILURE, "could not reopen logfile %s", logfn);
+		if ((monhost_ups_current->logfile = freopen(
+		    monhost_ups_current->logfn, "a",
+		    monhost_ups_current->logfile)) == NULL)
+			fatal_with_errno(EXIT_FAILURE,
+				"could not reopen logfile %s", logfn);
+	}
 }
 
 static void set_reopen_flag(int sig)
@@ -131,6 +152,8 @@
 	printf("  -p <pidbase>  - Base name for PID file (defaults to \"%s\")\n", prog);
 	printf("  -s <ups>	- Monitor UPS <ups> - <upsname>@<host>[:<port>]\n");
 	printf("        	- Example: -s myups@server\n");
+	printf("  -m <tuple>	- Monitor UPS <ups,logfile>\n");
+	printf("		- Example: -m myups@server,/var/log/myups.log\n");
 	printf("  -u <user>	- Switch to <user> if started as root\n");
 
 	printf("\n");
@@ -215,7 +238,7 @@
 	query[2] = var;
 	numq = 3;
 
-	ret = upscli_get(&ups, numq, query, &numa, &answer);
+	ret = upscli_get(ups, numq, query, &numa, &answer);
 
 	if ((ret < 0) || (numa < numq)) {
 		snprintfcat(logbuffer, sizeof(logbuffer), "NA");
@@ -368,7 +391,7 @@
 }
 
 /* go through the list of functions and call them in order */
-static void run_flist(void)
+static void run_flist(struct monhost_ups *monhost_ups_print)
 {
 	flist_t	*tmp;
 
@@ -382,8 +405,8 @@
 		tmp = tmp->next;
 	}
 
-	fprintf(logfile, "%s\n", logbuffer);
-	fflush(logfile);
+	fprintf(monhost_ups_print->logfile, "%s\n", logbuffer);
+	fflush(monhost_ups_print->logfile);
 }
 
 	/* -s <monhost>
@@ -396,6 +419,7 @@
 int main(int argc, char **argv)
 {
 	int	interval = 30, i, foreground = -1;
+	size_t	monhost_len = 0;
 	const char	*prog = xbasename(argv[0]);
 	time_t	now, nextpoll = 0;
 	const char	*user = NULL;
@@ -407,7 +431,7 @@
 
 	printf("Network UPS Tools %s %s\n", prog, UPS_VERSION);
 
-	while ((i = getopt(argc, argv, "+hs:l:i:f:u:Vp:FB")) != -1) {
+	while ((i = getopt(argc, argv, "+hs:l:i:f:u:Vp:FBm:")) != -1) {
 		switch(i) {
 			case 'h':
 				help(prog);
@@ -415,6 +439,33 @@
 				break;
 #endif
 
+			case 'm': { /* var scope */
+					char *m_arg, *s;
+
+					monhost_ups_prev = monhost_ups_current;
+					monhost_ups_current = xmalloc(sizeof(struct monhost_ups));
+					if (monhost_ups_anchor == NULL)
+						monhost_ups_anchor = monhost_ups_current;
+					else
+						monhost_ups_prev->next = monhost_ups_current;
+					monhost_ups_current->next = NULL;
+					monhost_len++;
+
+					/* Be sure to not mangle original optarg, nor rely on its longevity */
+					s = xstrdup(optarg);
+					m_arg = s;
+					monhost_ups_current->monhost = xstrdup(strsep(&m_arg, ","));
+					if (!m_arg)
+						fatalx(EXIT_FAILURE, "Argument '-m upsspec,logfile' requires exactly 2 components in the tuple");
+					monhost_ups_current->logfn = xstrdup(strsep(&m_arg, ","));
+					if (m_arg) /* Had a third comma - also unexpected! */
+						fatalx(EXIT_FAILURE, "Argument '-m upsspec,logfile' requires exactly 2 components in the tuple");
+					if (upscli_splitname(monhost_ups_current->monhost, &(monhost_ups_current->upsname), &(monhost_ups_current->hostname), &(monhost_ups_current->port)) != 0) {
+						fatalx(EXIT_FAILURE, "Error: invalid UPS definition.  Required format: upsname[@hostname[:port]]\n");
+					}
+					free(s);
+				} /* var scope */
+				break;
 			case 's':
 				monhost = optarg;
 				break;
@@ -479,42 +530,59 @@
 			snprintfcat(logformat, LARGEBUF, "%s ", argv[i]);
 	}
 
-	if (!monhost)
-		fatalx(EXIT_FAILURE, "No UPS defined for monitoring - use -s <system>");
+	if (monhost_ups_anchor == NULL) {
+		if (monhost) {
+			monhost_ups_current = xmalloc(sizeof(struct monhost_ups));
+			monhost_ups_anchor = monhost_ups_current;
+			monhost_ups_current->next = NULL;
+			monhost_ups_current->monhost = monhost;
+			monhost_len=1;
+		} else {
+			fatalx(EXIT_FAILURE, "No UPS defined for monitoring - use -s <system>");
+		}
 
-	if (!logfn)
-		fatalx(EXIT_FAILURE, "No filename defined for logging - use -l <file>");
+		if (logfn)
+			monhost_ups_current->logfn = logfn;
+		else
+			fatalx(EXIT_FAILURE, "No filename defined for logging - use -l <file>");
+	}
 
 	/* shouldn't happen */
 	if (!logformat)
 		fatalx(EXIT_FAILURE, "No format defined - but this should be impossible");
 
-	printf("logging status of %s to %s (%is intervals)\n",
-		monhost, logfn, interval);
+	for (monhost_ups_current = monhost_ups_anchor;
+	     monhost_ups_current != NULL;
+	     monhost_ups_current = monhost_ups_current->next) {
+		printf("logging status of %s to %s (%is intervals)\n",
+			monhost_ups_current->monhost, monhost_ups_current->logfn, interval);
+		if (upscli_splitname(monhost_ups_current->monhost, &(monhost_ups_current->upsname), &(monhost_ups_current->hostname), &(monhost_ups_current->port)) != 0) {
+			fatalx(EXIT_FAILURE, "Error: invalid UPS definition.  Required format: upsname[@hostname[:port]]\n");
+		}
 
-	if (upscli_splitname(monhost, &upsname, &hostname, &port) != 0) {
-		fatalx(EXIT_FAILURE, "Error: invalid UPS definition.  Required format: upsname[@hostname[:port]]\n");
-	}
+		monhost_ups_current->ups = xmalloc(sizeof(UPSCONN_t));
+		if (upscli_connect(monhost_ups_current->ups, monhost_ups_current->hostname, monhost_ups_current->port, UPSCLI_CONN_TRYSSL) < 0)
+			fprintf(stderr, "Warning: initial connect failed: %s\n",
+				upscli_strerror(monhost_ups_current->ups));
 
-	if (upscli_connect(&ups, hostname, port, UPSCLI_CONN_TRYSSL) < 0)
-		fprintf(stderr, "Warning: initial connect failed: %s\n",
-			upscli_strerror(&ups));
+		if (strcmp(monhost_ups_current->logfn, "-") == 0)
+			monhost_ups_current->logfile = stdout;
+		else
+			monhost_ups_current->logfile = fopen(monhost_ups_current->logfn, "a");
 
-	if (strcmp(logfn, "-") == 0)
-		logfile = stdout;
-	else
-		logfile = fopen(logfn, "a");
+		if (monhost_ups_current->logfile == NULL)
+			fatal_with_errno(EXIT_FAILURE, "could not open logfile %s", logfn);
 
-	if (logfile == NULL)
-		fatal_with_errno(EXIT_FAILURE, "could not open logfile %s", logfn);
+	}
 
+
 	/* now drop root if we have it */
 	new_uid = get_user_pwent(user);
 
 	open_syslog(prog);
 
 	if (foreground < 0) {
-		if (logfile == stdout) {
+		if (monhost_ups_anchor->logfile == stdout) {
 			foreground = 1;
 		} else {
 			foreground = 0;
@@ -552,25 +620,35 @@
 			reopen_flag = 0;
 		}
 
-		/* reconnect if necessary */
-		if (upscli_fd(&ups) < 0) {
-			upscli_connect(&ups, hostname, port, 0);
-		}
+		for (monhost_ups_current = monhost_ups_anchor;
+		     monhost_ups_current != NULL;
+		     monhost_ups_current = monhost_ups_current->next) {
+			ups = monhost_ups_current->ups;	/* XXX Not ideal */
+			upsname = monhost_ups_current->upsname;	/* XXX Not ideal */
+			/* reconnect if necessary */
+			if (upscli_fd(ups) < 0) {
+				upscli_connect(ups, monhost_ups_current->hostname, monhost_ups_current->port, 0);
+			}
 
-		run_flist();
+			run_flist(monhost_ups_current);
 
-		/* don't keep connection open if we don't intend to use it shortly */
-		if (interval > 30) {
-			upscli_disconnect(&ups);
+			/* don't keep connection open if we don't intend to use it shortly */
+			if (interval > 30) {
+				upscli_disconnect(ups);
+			}
 		}
 	}
 
 	upslogx(LOG_INFO, "Signal %d: exiting", exit_flag);
+	for (monhost_ups_current = monhost_ups_anchor;
+	     monhost_ups_current != NULL;
+	     monhost_ups_current = monhost_ups_current->next) {
 
-	if (logfile != stdout)
-		fclose(logfile);
+		if (monhost_ups_current->logfile != stdout)
+			fclose(monhost_ups_current->logfile);
 
-	upscli_disconnect(&ups);
+		upscli_disconnect(monhost_ups_current->ups);
+	}
 
 	exit(EXIT_SUCCESS);
 }
