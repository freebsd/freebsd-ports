--- appl/telnet/telnetd/state.c.orig	Thu Jun 15 15:42:53 2006
+++ appl/telnet/telnetd/state.c	Wed Apr  4 14:02:18 2007
@@ -1665,7 +1665,8 @@
 	    strcmp(varp, "RESOLV_HOST_CONF") && /* linux */
 	    strcmp(varp, "NLSPATH") && /* locale stuff */
 	    strncmp(varp, "LC_", strlen("LC_")) && /* locale stuff */
-	    strcmp(varp, "IFS")) {
+	    strcmp(varp, "IFS") &&
+	    !strchr(varp, '-')) {
 		return 1;
 	} else {
 		syslog(LOG_INFO, "Rejected the attempt to modify the environment variable \"%s\"", varp);
