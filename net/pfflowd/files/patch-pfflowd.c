--- pfflowd.c	Thu May  6 16:06:45 2004
+++ pfflowd.c	Tue Jun 15 09:40:46 2004
@@ -43,7 +43,11 @@
 #include <syslog.h>
 #include <time.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include "pidfile.h"
+#else
 #include <util.h>
+#endif
 
 #define	PROGNAME		"pfflowd"
 #define	PROGVER			"0.5"
@@ -189,6 +193,9 @@
 parse_hostport(const char *s, struct sockaddr_in *addr)
 {
 	char *host, *port;
+#if defined(__FreeBSD__)
+	int val;
+#endif
 
 	if ((host = strdup(s)) == NULL) {
 		fprintf(stderr, "Out of memory\n");
@@ -201,12 +208,22 @@
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
@@ -425,7 +442,9 @@
 				strlcat(dst_s, pbuf, sizeof(dst_s));
 			}
 
+#ifndef OLD_PFSYNC
 			syslog(LOG_DEBUG, "IFACE %s\n", st->ifname); 
+#endif
 			syslog(LOG_DEBUG, "GWY %s\n", rt_s); 
 			syslog(LOG_DEBUG, "FLOW proto %d direction %d", 
 			    st->proto, st->direction);
