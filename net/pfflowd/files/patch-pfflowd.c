--- pfflowd.c   Wed Feb 25 16:16:35 2004
+++ pfflowd.c   Wed Feb 25 16:22:57 2004
@@ -49,7 +49,11 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include "pidfile.h"
+#else
 #include <util.h>
+#endif
 
 #define	PROGNAME		"pfflowd"
 #define	PROGVER			"0.3"
@@ -185,6 +189,9 @@
 parse_hostport(const char *s, struct sockaddr_in *addr)
 {
 	char *host, *port;
+#if defined(__FreeBSD__)
+	int val;
+#endif
 
 	if ((host = strdup(s)) == NULL) {
 		fprintf(stderr, "Out of memory\n");
@@ -197,12 +204,22 @@
 	}
 	*(port - 1) = '\0';
 	addr->sin_family = AF_INET;
+#if defined(__FreeBSD__)
+	val = atoi(port);
+	if (val <= 0 || val >= 65536) {
+		fprintf(stderr, "Invalid -n port.\n");
+		usage();
+		exit(1);
+	}
+	addr->sin_port = (in_port_t)val;
+#else
 	addr->sin_port = atoi(port);
 	if (addr->sin_port <= 0 || addr->sin_port >= 65536) {
 		fprintf(stderr, "Invalid -n port.\n");
 		usage();
 		exit(1);
 	}
+#endif
 	addr->sin_port = htons(addr->sin_port);
 	if (inet_aton(host, &addr->sin_addr) == 0) {
 		fprintf(stderr, "Invalid -n host.\n");
