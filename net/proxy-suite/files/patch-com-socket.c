--- common/com-socket.c.dist	Tue Mar 30 10:31:32 2004
+++ common/com-socket.c	Tue Jun 14 09:26:44 2005
@@ -84,6 +84,9 @@
 #if defined(HAVE_STROPTS_H)
 #   include <stropts.h>
 #endif
+#if defined(HAVE_SYS_PARAM_H)
+#   include <sys/param.h>
+#endif
 #if defined(HAVE_SYS_CONF_H)
 #   include <sys/conf.h>
 #endif
@@ -2132,9 +2135,9 @@
 	/*
 	** BSD ipnat table lookup
 	*/
-	if ((nat_fd = open(IPL_NAT, O_RDONLY, 0)) < 0) {
+	if ((nat_fd = open(IPNAT_NAME, O_RDONLY, 0)) < 0) {
 		syslog_error("can't open ipnat device '%.*s'",
-		             MAX_PATH_SIZE, IPL_NAT);
+		             MAX_PATH_SIZE, IPNAT_NAME);
 		return -1;
 	}
 
