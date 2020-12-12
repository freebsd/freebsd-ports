--- logmsg.c.orig	2020-12-12 20:08:57.283326000 +0000
+++ logmsg.c	2020-12-12 20:09:24.496799000 +0000
@@ -11,6 +11,8 @@
 char logmsg_msgbuf[LOGMSG_BUFLEN];
 int logmsg_inclpid;         /* true iff process ID has to be prefixed to log msgs */
 pid_t logmsg_mypid;         /* if log_prefixpid, then set to the PID of the process */
+int loglevel;               /* threshold for log messages relevance */
+char *logprefix;
 
 
 int logmsg_init(const char *prefix) {
