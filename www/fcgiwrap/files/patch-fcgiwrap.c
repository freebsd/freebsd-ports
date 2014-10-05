--- fcgiwrap.c.orig	2014-09-22 12:36:32.000000000 +0200
+++ fcgiwrap.c	2014-09-22 12:41:59.000000000 +0200
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
@@ -485,6 +488,19 @@
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
@@ -541,6 +557,9 @@
 			if (!filename)
 				cgi_error("403 Forbidden", "Cannot get script name, are DOCUMENT_ROOT and SCRIPT_NAME (or SCRIPT_FILENAME) set and is the script executable?", NULL);
 
+			if (!is_allowed_program(filename))
+				cgi_error("403 Forbidden", "The given script is not allowed to execute", filename);
+
 			last_slash = strrchr(filename, '/');
 			if (!last_slash)
 				cgi_error("403 Forbidden", "Script name must be a fully qualified path", filename);
@@ -760,7 +779,7 @@
 	char *socket_url = NULL;
 	int c;
 
-	while ((c = getopt(argc, argv, "c:hfs:")) != -1) {
+	while ((c = getopt(argc, argv, "c:hfs:p:")) != -1) {
 		switch (c) {
 			case 'f':
 				stderr_to_fastcgi++;
@@ -773,6 +792,7 @@
 					"  -c <number>\t\tNumber of processes to prefork\n"
 					"  -s <socket_url>\tSocket to bind to (say -s help for help)\n"
 					"  -h\t\t\tShow this help message and exit\n"
+					"  -p <path>\t\tRestrict execution to this script. (repeated options will be merged)\n"
 					"\nReport bugs to Grzegorz Nosek <"PACKAGE_BUGREPORT">.\n"
 					PACKAGE_NAME" home page: <http://nginx.localdomain.pl/wiki/FcgiWrap>\n",
 					argv[0]
@@ -784,8 +804,14 @@
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
