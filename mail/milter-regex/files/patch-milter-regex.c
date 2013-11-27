--- milter-regex.c.orig	2013-11-25 09:41:55.000000000 +0100
+++ milter-regex.c	2013-11-27 05:25:43.000000000 +0100
@@ -60,6 +60,7 @@
 
 static const char	*rule_file_name = "/etc/milter-regex.conf";
 static int		 debug = 0;
+static int		 quiet = 0;
 static unsigned		 maxlines = 0;
 static pthread_mutex_t	 mutex;
 
@@ -97,6 +98,7 @@
 
 #define USER		"_milter-regex"
 #define OCONN		"unix:/var/spool/milter-regex/sock"
+#define OPID		"/var/spool/milter-regex/milter-regex.pid"
 #define RCODE_REJECT	"554"
 #define RCODE_TEMPFAIL	"451"
 #define XCODE_REJECT	"5.7.1"
@@ -645,6 +647,9 @@
 	va_list ap;
 	char msg[8192];
 
+	if (LOG_PRI(priority) > LOG_INFO && quiet)
+		return;
+
 	va_start(ap, fmt);
 	if (context != NULL)
 		snprintf(msg, sizeof(msg), "%s [%s]: ", context->host_name,
@@ -682,15 +687,19 @@
 {
 	int ch;
 	const char *oconn = OCONN;
+	const char *pid_file_name = OPID;
 	const char *user = USER;
 	const char *jail = NULL;
 	sfsistat r = MI_FAILURE;
 	const char *ofile = NULL;
 
+	pid_t pid;
+	FILE *pid_fd = NULL;
+
 	tzset();
 	openlog("milter-regex", LOG_PID | LOG_NDELAY, LOG_DAEMON);
 
-	while ((ch = getopt(argc, argv, "c:dj:l:m:p:u:")) != -1) {
+	while ((ch = getopt(argc, argv, "c:dj:l:m:p:qr:u:")) != -1) {
 		switch (ch) {
 		case 'c':
 			rule_file_name = optarg;
@@ -710,6 +719,12 @@
 		case 'p':
 			oconn = optarg;
 			break;
+		case 'q':
+			quiet = 1;
+			break;
+		case 'r':
+			pid_file_name = optarg;
+			break;
 		case 'u':
 			user = optarg;
 			break;
@@ -782,9 +797,22 @@
 		perror("daemon");
 		goto done;
 	}
-	umask(0177);
 
 	msg(LOG_INFO, NULL, "started: %s", rcsid);
+
+	umask(0006);
+
+	if((pid_fd = fopen(pid_file_name, "w")) == NULL) {
+		msg(LOG_ERR, NULL, "can't open file: %s", pid_file_name);
+		goto done;
+	} else {
+		pid = getpid();
+		fprintf(pid_fd, "%d", (int) pid);
+		fclose(pid_fd);
+	}
+
+	umask(0177);
+
 	r = smfi_main();
 	if (r != MI_SUCCESS)
 		msg(LOG_ERR, NULL, "smfi_main: terminating due to error");
