--- milter-regex.c.orig	2018-09-25 20:31:25 UTC
+++ milter-regex.c
@@ -61,6 +61,7 @@ extern int	 parse_ruleset(const char *, 
 
 static const char	*rule_file_name = "/etc/milter-regex.conf";
 static int		 debug = 0;
+static int		 quiet = 0;
 static unsigned		 maxlines = 0;
 static pthread_mutex_t	 mutex;
 
@@ -98,6 +99,7 @@ static void		 msg(int, struct context *,
 
 #define USER		"_milter-regex"
 #define OCONN		"unix:/var/spool/milter-regex/sock"
+#define OPID		"/var/spool/milter-regex/milter-regex.pid"
 #define RCODE_REJECT	"554"
 #define RCODE_TEMPFAIL	"451"
 #define XCODE_REJECT	"5.7.1"
@@ -646,6 +648,9 @@ msg(int priority, struct context *contex
 	va_list ap;
 	char msg[8192];
 
+	if (LOG_PRI(priority) > LOG_INFO && quiet)
+		return;
+
 	va_start(ap, fmt);
 	if (context != NULL)
 		snprintf(msg, sizeof(msg), "%s [%s]: ", context->host_name,
@@ -684,6 +689,7 @@ main(int argc, char **argv)
 {
 	int ch, maskpri = LOG_INFO;
 	const char *oconn = OCONN;
+	const char *pid_file_name = OPID;
 	const char *user = USER;
 	const char *jail = NULL;
 	sfsistat r = MI_FAILURE;
@@ -691,8 +697,10 @@ main(int argc, char **argv)
 	const char *pgroup = NULL;
 	const char *puser = NULL;
 	mode_t pperm = 0600;
+	pid_t pid;
+	FILE *pid_fd = NULL;
 
-	while ((ch = getopt(argc, argv, "c:dj:l:m:p:u:G:P:U:")) != -1) {
+	while ((ch = getopt(argc, argv, "c:dj:l:m:p:qr:u:G:P:U:")) != -1) {
 		switch (ch) {
 		case 'c':
 			rule_file_name = optarg;
@@ -712,6 +720,12 @@ main(int argc, char **argv)
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
@@ -833,6 +847,20 @@ main(int argc, char **argv)
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
