--- pop3vscan.c.orig	Wed Jun 12 08:19:05 2002
+++ pop3vscan.c	Tue Jun  3 03:23:38 2003
@@ -27,11 +27,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <arpa/inet.h>
+#include <sys/types.h>
 #include <netinet/in.h>
+#include <netinet/in_systm.h>
+#include <arpa/inet.h>
 #include <netinet/ip.h>
 #include <sys/socket.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
@@ -44,8 +45,8 @@
 #include <syslog.h>
 #include <sys/param.h>
 #include <ctype.h>
-#include <linux/netfilter_ipv4.h>
-#include <malloc.h>
+//#include <linux/netfilter_ipv4.h>
+#include <stdlib.h>
 #include <getopt.h>
 #include <netdb.h>
 #include <libgen.h>
@@ -66,14 +67,14 @@
 /* default configuration, anything can be changed at runtime {{{1 */
 #define PORT_NUMBER		8110
 #define MAX_CHILDS		10
-#define RUNAS_USER		"mail"
+#define RUNAS_USER		"pop3vscan"
 #define VIRUS_DIR		"/var/spool/pop3vscan"
 #define VIRUS_SCANNER		NULL
 #define VIRUS_SCANNER_VIRUSCODE	1
 #define PID_FILE		"/var/run/pop3vscan.pid"
 #define SYSLOG_NAME		"pop3vscan"
-#define CONFIGFILE		"/etc/pop3vscan.conf"
-#define VIRUS_TEMPLATE		"/etc/pop3vscan.mail"
+#define CONFIGFILE		PREFIX"/etc/pop3vscan.conf"
+#define VIRUS_TEMPLATE		PREFIX"/etc/pop3vscan.mail"
 #define DEBUG			0
 /* TOS:  do not set, or use IPTOS_[LOWDELAY|THROUGHPUT|RELIABILITY|LOWCOST] */
 #define SET_TOS			IPTOS_THROUGHPUT
@@ -519,8 +520,8 @@
 		inet_ntoa(p->client_addr.sin_addr), ntohs(p->client_addr.sin_port));
 
     p->server_addr.sin_family = AF_INET;
-    if (getsockopt(p->client_fd, SOL_IP, SO_ORIGINAL_DST, &p->server_addr, &p->socksize)){
-	do_log(LOG_CRIT, "No IP-Conntrack-data (getsockopt failed)");
+    if (getsockname(p->client_fd, (struct sockaddr*)&p->server_addr, &p->socksize)){
+	do_log(LOG_CRIT, "No IP-Conntrack-data (getsockname failed)");
 	return 1;
     }
     do_log(LOG_NOTICE, "Real-server adress is %s:%i",
