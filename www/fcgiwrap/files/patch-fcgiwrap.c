--- fcgiwrap.c.orig	2013-02-03 13:25:17 UTC
+++ fcgiwrap.c
@@ -43,6 +43,7 @@
 #include <ctype.h>
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <netinet/in.h>
@@ -58,6 +59,8 @@
 
 extern char **environ;
 static char * const * inherited_environ;
+static const char **allowed_programs;
+static size_t allowed_programs_count;
 
 static const char * blacklisted_env_vars[] = {
 	"AUTH_TYPE",
@@ -485,6 +488,19 @@ static void inherit_environment(void)
 	}
 }
 
+static bool is_allowed_program(const char *program) {
+	size_t i;
+	if (!allowed_programs_count)
+		return true;
+
+	for (i = 0; i < allowed_programs_count; i++) {
+		if (!strcmp(allowed_programs[i], program))
+			return true;
+	}
+
+	return false;
+}
+
 static void cgi_error(const char *message, const char *reason, const char *filename)
 {
 	printf("Status: %s\r\nContent-Type: text/plain\r\n\r\n%s\r\n",
@@ -541,6 +557,9 @@ static void handle_fcgi_request(void)
 			if (!filename)
 				cgi_error("403 Forbidden", "Cannot get script name, are DOCUMENT_ROOT and SCRIPT_NAME (or SCRIPT_FILENAME) set and is the script executable?", NULL);
 
+			if (!is_allowed_program(filename))
+				cgi_error("403 Forbidden", "The given script is not allowed to execute", filename);
+
 			last_slash = strrchr(filename, '/');
 			if (!last_slash)
 				cgi_error("403 Forbidden", "Script name must be a fully qualified path", filename);
@@ -587,14 +606,29 @@ err_pipein:
 	FCGI_puts("System error");
 }
 
+static volatile sig_atomic_t sigint_received;
+static void sigint_handler(int __attribute__((__unused__))dummy)
+{
+	sigint_received = 1;
+	FCGX_ShutdownPending(); // Or we could send SIGUSR1
+}
+
 static void fcgiwrap_main(void)
 {
+	struct sigaction a;
 	signal(SIGCHLD, SIG_IGN);
 	signal(SIGPIPE, SIG_IGN);
 
+	// Use sigaction for SIGINT so we can avoid SA_RESTART and actually react
+	a.sa_handler = sigint_handler;
+	a.sa_flags = 0;
+	sigemptyset(&a.sa_mask);
+	sigaction(SIGINT, &a, NULL);
+	sigaction(SIGTERM, &a, NULL);
+
 	inherited_environ = environ;
 
-	while (FCGI_Accept() >= 0) {
+	while (FCGI_Accept() >= 0 && !sigint_received) {
 		handle_fcgi_request();
 	}
 }
@@ -671,7 +705,7 @@ static int listen_on_fd(int fd) {
 	return 0;
 }
 
-static int setup_socket(char *url) {
+static int setup_socket(char *url, int *fd_out) {
 	char *p = url;
 	char *q;
 	int fd;
@@ -685,6 +719,7 @@ static int setup_socket(char *url) {
 		struct sockaddr_in6 sa_in6;
 	} sa;
 
+    memset(&sa, 0, sizeof(sa));
 	if (!strncmp(p, "unix:", sizeof("unix:") - 1)) {
 		p += sizeof("unix:") - 1;
 
@@ -751,6 +786,7 @@ invalid_url:
 		return -1;
 	}
 
+	*fd_out = fd;
 	return listen_on_fd(fd);
 }
 
@@ -758,9 +794,10 @@ int main(int argc, char **argv)
 {
 	int nchildren = 1;
 	char *socket_url = NULL;
+	int fd = 0;
 	int c;
 
-	while ((c = getopt(argc, argv, "c:hfs:")) != -1) {
+	while ((c = getopt(argc, argv, "c:hfs:p:")) != -1) {
 		switch (c) {
 			case 'f':
 				stderr_to_fastcgi++;
@@ -773,6 +810,7 @@ int main(int argc, char **argv)
 					"  -c <number>\t\tNumber of processes to prefork\n"
 					"  -s <socket_url>\tSocket to bind to (say -s help for help)\n"
 					"  -h\t\t\tShow this help message and exit\n"
+					"  -p <path>\t\tRestrict execution to this script. (repeated options will be merged)\n"
 					"\nReport bugs to Grzegorz Nosek <"PACKAGE_BUGREPORT">.\n"
 					PACKAGE_NAME" home page: <http://nginx.localdomain.pl/wiki/FcgiWrap>\n",
 					argv[0]
@@ -784,8 +822,14 @@ int main(int argc, char **argv)
 			case 's':
 				socket_url = strdup(optarg);
 				break;
+			case 'p':
+				allowed_programs = realloc(allowed_programs, (allowed_programs_count + 1) * sizeof (char *));
+				if (!allowed_programs)
+					abort();
+				allowed_programs[allowed_programs_count++] = strdup(optarg);
+				break;
 			case '?':
-				if (optopt == 'c' || optopt == 's')
+				if (optopt == 'c' || optopt == 's' || optopt == 'p')
 					fprintf(stderr, "Option -%c requires an argument.\n", optopt);
 				else if (isprint(optopt))
 					fprintf(stderr, "Unknown option `-%c'.\n", optopt);
@@ -808,13 +852,24 @@ int main(int argc, char **argv)
 	} else
 #endif
 	if (socket_url) {
-		if (setup_socket(socket_url) < 0) {
+		if (setup_socket(socket_url, &fd) < 0) {
 			return 1;
 		}
-		free(socket_url);
 	}
 
 	prefork(nchildren);
 	fcgiwrap_main();
+	if(fd) {
+		const char *p = socket_url;
+		close(fd);
+	
+		if(socket_url) {
+			if (!strncmp(p, "unix:", sizeof("unix:") - 1)) {
+				p += sizeof("unix:") - 1;
+				unlink(p);
+			}
+			free(socket_url);
+		}
+	}
 	return 0;
 }
