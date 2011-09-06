--- cgichk.h.orig	2001-04-06 16:36:25.000000000 +0800
+++ cgichk.h	2011-09-06 11:30:51.000000000 +0800
@@ -19,13 +19,17 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 #include <stdarg.h>
 #include <getopt.h>
 #include <time.h>
 #include <unistd.h>
+#include <ctype.h>
 
 #ifdef DEBUG
 	#define MEMWATCH
@@ -125,3 +129,16 @@ extern struct in_addr      addr;
 extern struct sockaddr_in  _sin;
 extern struct hostent      *he;
 
+void waitafew(unsigned int del);
+void PRINT(char *arg, ...);
+void CPRINT(char *arg, ...);
+void close_config(result_t *r);
+void read_config(result_t *r, char *section);
+int setup_socket(char *host, int port);
+void PerformWhois(char *domain);
+result_t *open_config(char *fn);
+void read_head();
+int http_has(char *file, int result);
+void free_strings(result_t *r);
+void breakup_url(char *_url, char *_host, int hl, int *_port, int defport, char *_path, int pl);
+char *cgichk_strnstr(const char *HAYSTACK, const char *NEEDLE);
