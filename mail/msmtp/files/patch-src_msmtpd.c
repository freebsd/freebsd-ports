--- src/msmtpd.c.orig	2021-01-01 05:37:02 UTC
+++ src/msmtpd.c
@@ -33,6 +33,7 @@
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
+#include <sys/wait.h>
 #include <getopt.h>
 extern char *optarg;
 extern int optind;
