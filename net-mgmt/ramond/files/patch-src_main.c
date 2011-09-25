
$FreeBSD$

--- src/main.c.orig
+++ src/main.c
@@ -1,6 +1,5 @@
 #include "main.h"
 #include "log.h"
-
 apr_pool_t *masterPool;
 struct configuration *config;
 
@@ -14,8 +13,9 @@
 
 void usage(char *prog_name)
 {
-	fprintf(stderr, "%s [-h] [-c /etc/ramond.conf]\n", prog_name);
+	fprintf(stderr, "%s [-h] [-d] [-c %%PREFIX%%/etc/ramond.conf]\n", prog_name);
 	fprintf(stderr, "	-h : print this help.\n");
+	fprintf(stderr, "	-d : do not daemonize.\n");
 	fprintf(stderr, "	-c : path to config file.\n");
 }
 
@@ -824,11 +824,68 @@
 	pcap_close(fd);
 }
 
+/**
+ * daemonize ramond.
+ */
+void daemonize(void)
+{
+	pid_t   pid, sid;
+	int i, pidfile;
+
+	char pidstr[32];
+
+	pid = fork();
+
+	if(pid < 0)
+		exit(EXIT_FAILURE);
+	else if(pid > 0)
+		exit(EXIT_SUCCESS);
+
+	umask(027);
+	if((chdir("/")) < 0)
+		exit(EXIT_FAILURE);
+
+	sid = setsid();
+	if(sid < 0)
+		exit(EXIT_FAILURE);
+
+	pid = fork();
+
+	if(pid < 0)
+		exit(EXIT_FAILURE);
+	else if(pid > 0)
+		exit(EXIT_SUCCESS);
+
+	/* Cleanup open FDs */
+	for(i = getdtablesize(); i>=0; --i)
+		close(i);
+
+	i = open("/dev/null", O_RDWR); /* (re)open stdin */
+	dup(i); /* stdout */
+	dup(i); /* stderr */
+
+	pidfile = open("/var/run/ramond.pid", O_RDWR|O_CREAT, 0640);
+	if(pidfile < 0)
+		exit(EXIT_FAILURE);
+	if(flock(pidfile, F_TLOCK) < 0)
+		exit(EXIT_SUCCESS);
+
+	sprintf(pidstr, "%d\n", getpid());
+	write(pidfile, pidstr, strlen(pidstr));
+
+	signal(SIGTSTP,SIG_IGN); /* ignore tty signals */
+	signal(SIGTTOU,SIG_IGN);
+	signal(SIGTTIN,SIG_IGN);
+}
+
 int main(int argc, char *argv[])
 {
 	int socket;
 	struct ra_info data;
 
+	int debug = 0;
+	int i = 0;
+
 	if(argc > 6)
 	{
 		usage(argv[0]);
@@ -842,6 +899,20 @@
 
 	signal(SIGCHLD, sigchld_handler);
 
+	for(i = 0; i < argc; i++)
+	{
+		if(!strcmp(argv[i], "-d"))
+		{
+			debug = 1;
+			break;
+		}
+	}
+
+	if(!debug)
+	{
+		daemonize();
+	}
+
 	/* Find the config file */
 	if(!parseConfigFile(argc,argv))
 	{
