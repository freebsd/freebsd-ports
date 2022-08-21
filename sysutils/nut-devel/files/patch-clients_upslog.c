--- clients/upslog.c.orig	2022-08-26 15:25:26.539215000 -0700
+++ clients/upslog.c	2022-08-26 15:26:10.909994000 -0700
@@ -32,6 +32,10 @@
  */
 
 #include "common.h"
+#include <signal.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 #include "nut_platform.h"
 #include "upsclient.h"
 
@@ -41,17 +45,32 @@
 #include "upslog.h"
 
 	static	int	reopen_flag = 0, exit_flag = 0;
+	static	int	wait_status;
 	static	uint16_t	port;
 	static	char	*upsname, *hostname;
 	static	UPSCONN_t	ups;
 
 	static	FILE	*logfile;
-	static	const	char *logfn, *monhost;
+	static	char *logfn, *monhost;
 	static	sigset_t	nut_upslog_sigmask;
 	static	char	logbuffer[LARGEBUF], *logformat;
 
 	static	flist_t	*fhead = NULL;
+	struct 	monhost_child {
+		char	*monhost;
+		char	*logfn;
+		char	*pidfilebase;
+		pid_t	pid;
+		struct	monhost_child	*next;
+	};
+	static	struct	monhost_child *monhost_child_anchor = NULL;
+	static	struct	monhost_child *monhost_child_current = NULL;
+	static	struct	monhost_child *monhost_child_prev = NULL;
+	static	struct	sigaction upslog_sigaction;
+	static	int	trapped_signals[] = { SIGHUP, SIGINT, SIGTERM, SIGCHLD };
+	static	pid_t	daemon_pid;
 
+
 #define DEFAULT_LOGFORMAT "%TIME @Y@m@d @H@M@S% %VAR battery.charge% " \
 		"%VAR input.voltage% %VAR ups.load% [%VAR ups.status%] " \
 		"%VAR ups.temperature% %VAR input.frequency%"
@@ -131,6 +150,8 @@
 	printf("  -p <pidbase>  - Base name for PID file (defaults to \"%s\")\n", prog);
 	printf("  -s <ups>	- Monitor UPS <ups> - <upsname>@<host>[:<port>]\n");
 	printf("        	- Example: -s myups@server\n");
+	printf("  -m <tuple>	- Monitor UPS <ups,logfile,pidfile>,\n");
+	printf("		- Example: -m myups@server,/var/log/myups.log,/var/run/myups.pid\n");
 	printf("  -u <user>	- Switch to <user> if started as root\n");
 
 	printf("\n");
@@ -393,9 +414,25 @@
 	 * -u <username>
 	 */
 
+static void term_handler(int signo)
+{
+	if (signo != SIGCHLD && monhost_child_anchor != NULL) {
+		for (monhost_child_current = monhost_child_anchor;
+		     monhost_child_current != NULL;
+		     monhost_child_current = monhost_child_current->next
+		) {
+			kill(monhost_child_current->pid, signo);
+		}
+
+		if (signo != SIGHUP)
+			fatalx(EXIT_FAILURE, "Killed by user");
+	}
+}
+
 int main(int argc, char **argv)
 {
 	int	interval = 30, i, foreground = -1;
+	size_t	monhost_len = 0, mh;
 	const char	*prog = xbasename(argv[0]);
 	time_t	now, nextpoll = 0;
 	const char	*user = NULL;
@@ -407,7 +444,7 @@
 
 	printf("Network UPS Tools %s %s\n", prog, UPS_VERSION);
 
-	while ((i = getopt(argc, argv, "+hs:l:i:f:u:Vp:FB")) != -1) {
+	while ((i = getopt(argc, argv, "+hs:l:i:f:u:Vp:FBm:")) != -1) {
 		switch(i) {
 			case 'h':
 				help(prog);
@@ -415,6 +452,33 @@
 				break;
 #endif
 
+			case 'm': { /* var scope */
+				char *m_arg, *s;
+
+				monhost_child_prev = monhost_child_current;
+				monhost_child_current = xmalloc(sizeof(struct monhost_child));
+				if (monhost_child_anchor == NULL)
+					monhost_child_anchor = monhost_child_current;
+				else
+					monhost_child_prev->next = monhost_child_current;
+				monhost_child_current->next = NULL;
+				monhost_len++;
+
+				/* Be sure to not mangle original optarg, nor rely on its longevity */
+				s = xstrdup(optarg);
+				m_arg = s;
+				monhost_child_current->monhost = xstrdup(strsep(&m_arg, ","));
+				if (!m_arg)
+					fatalx(EXIT_FAILURE, "Argument '-m upsspec,logfile,pidfile' requires exactly 3 components in the tuple");
+				monhost_child_current->logfn = xstrdup(strsep(&m_arg, ","));
+				if (!m_arg)
+					fatalx(EXIT_FAILURE, "Argument '-m upsspec,logfile,pidfile' requires exactly 3 components in the tuple");
+				monhost_child_current->pidfilebase = xstrdup(strsep(&m_arg, ","));
+				if (m_arg) /* Had a third comma - also unexpected! */
+					fatalx(EXIT_FAILURE, "Argument '-m upsspec,logfile,pidfile' requires exactly 3 components in the tuple");
+				free(s);
+				} /* var scope */
+				break;
 			case 's':
 				monhost = optarg;
 				break;
@@ -477,6 +541,41 @@
 
 		for (i = 3; i < argc; i++)
 			snprintfcat(logformat, LARGEBUF, "%s ", argv[i]);
+	}
+
+	if (monhost_child_anchor != NULL) {
+		if (foreground > 0)
+			daemon_pid = 0;
+		else
+			daemon_pid = fork();
+		if (!daemon_pid) {
+			upsdebugx(1,"Forking to log %" PRIuSIZE " devices", monhost_len);
+			for (monhost_child_current = monhost_child_anchor;
+			     monhost_child_current != NULL;
+			     monhost_child_current = monhost_child_current->next) {
+				if ((monhost_child_current->pid = fork()) == 0) {
+					monhost = monhost_child_current->monhost;
+					logfn = monhost_child_current->logfn;
+					pidfilebase = monhost_child_current->pidfilebase;
+					foreground = 1;
+					break;
+				}
+			}
+			if (monhost_child_anchor->pid) {	/* parent */
+				for (mh = 0; mh < sizeof(trapped_signals)/sizeof(trapped_signals[0]); mh++) {
+					upslog_sigaction.sa_handler = &term_handler;
+					sigfillset(&upslog_sigaction.sa_mask);
+					upslog_sigaction.sa_flags = SA_NOCLDSTOP | SA_NOCLDWAIT;
+					sigaction(trapped_signals[mh], &upslog_sigaction, NULL);
+				}
+				become_user(get_user_pwent(user));
+				writepid(pidfilebase);
+				while(wait(&wait_status) > 0);
+				exit(EXIT_SUCCESS);
+			}
+		} else {
+			exit(EXIT_SUCCESS);
+		}
 	}
 
 	if (!monhost)
