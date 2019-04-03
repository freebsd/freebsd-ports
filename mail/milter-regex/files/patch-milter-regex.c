--- milter-regex.c.orig	2019-04-02 15:47:26 UTC
+++ milter-regex.c
@@ -62,6 +62,7 @@ extern int	 parse_ruleset(const char *, 
 
 static const char	*rule_file_name = "/etc/milter-regex.conf";
 static int		 debug = 0;
+static int		 quiet = 0;
 static unsigned		 maxlines = 0;
 static pthread_mutex_t	 mutex;
 
@@ -99,6 +100,7 @@ static void		 msg(int, struct context *,
 
 #define USER		"_milter-regex"
 #define OCONN		"unix:/var/spool/milter-regex/sock"
+#define OPID		"/var/spool/milter-regex/milter-regex.pid"
 #define RCODE_REJECT	"554"
 #define RCODE_TEMPFAIL	"451"
 #define XCODE_REJECT	"5.7.1"
@@ -647,6 +649,9 @@ msg(int priority, struct context *contex
 	va_list ap;
 	char msg[8192];
 
+	if (LOG_PRI(priority) > LOG_INFO && quiet)
+		return;
+
 	va_start(ap, fmt);
 	if (context != NULL)
 		snprintf(msg, sizeof(msg), "%s [%s]: ", context->host_name,
@@ -685,6 +690,7 @@ main(int argc, char **argv)
 {
 	int ch, maskpri = LOG_INFO;
 	const char *oconn = OCONN;
+	const char *pid_file_name = OPID;
 	const char *user = USER;
 	const char *jail = NULL;
 	sfsistat r = MI_FAILURE;
@@ -693,8 +699,10 @@ main(int argc, char **argv)
 	const char *puser = NULL;
 	mode_t pperm = 0600;
 	int facility = LOG_DAEMON;
+	pid_t pid;
+	FILE *pid_fd = NULL;
 
-	while ((ch = getopt(argc, argv, "c:df:j:l:m:p:u:G:P:U:")) != -1) {
+	while ((ch = getopt(argc, argv, "c:df:j:l:m:p:qr:u:G:P:U:")) != -1) {
 		switch (ch) {
 		case 'c':
 			rule_file_name = optarg;
@@ -724,6 +732,12 @@ main(int argc, char **argv)
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
@@ -845,6 +859,20 @@ main(int argc, char **argv)
 	}
 
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
+	umask(0117); /* make socket group writeable */
+
 	r = smfi_main();
 	if (r != MI_SUCCESS)
 		msg(LOG_ERR, NULL, "smfi_main: terminating due to error");
