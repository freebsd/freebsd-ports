--- modules/ctl/ctl_defaults.h.orig	2015-07-20 13:16:25 UTC
+++ modules/ctl/ctl_defaults.h
@@ -4,10 +4,10 @@
 /*listen by default on: */
 #ifdef SRNAME
 /* this is used when compiling sercmd tool */
-#define DEFAULT_CTL_SOCKET  "unixs:" RUN_DIR "/" SRNAME "_ctl"
+#define DEFAULT_CTL_SOCKET  "unixs:" "/var/run/" SRNAME "_ctl"
 #else
 /* this is used when compiling sip server */
-#define DEFAULT_CTL_SOCKET  "unixs:" RUN_DIR "/" NAME "_ctl"
+#define DEFAULT_CTL_SOCKET  "unixs:" "/var/run/" NAME "_ctl"
 #endif
 /* port used by default for tcp/udp if no port is explicitely specified */
 #define DEFAULT_CTL_PORT 2049
