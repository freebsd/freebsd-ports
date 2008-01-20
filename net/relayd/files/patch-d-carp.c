--- relayd/carp.c.orig	2007-12-08 02:17:00.000000000 +0900
+++ relayd/carp.c	2008-01-14 08:43:07.745281030 +0900
@@ -19,6 +19,7 @@
 #include <sys/param.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
+#include <sys/queue.h>
 
 #include <net/if.h>
 
@@ -105,6 +106,7 @@
 int
 carp_demote_get(char *group)
 {
+#if 0
 	int			s;
 	struct ifgroupreq	ifgr;
 
@@ -131,6 +133,9 @@
 
 	close(s);
 	return ((int)ifgr.ifgr_attrib.ifg_carp_demoted);
+#else
+	return (-1);
+#endif
 }
 
 int
@@ -188,6 +193,7 @@
 int
 carp_demote_ioctl(char *group, int demote)
 {
+#if 0
 	int			s, res;
 	struct ifgroupreq	ifgr;
 
@@ -214,4 +220,7 @@
 
 	close(s);
 	return (res);
+#else
+	return (-1);
+#endif
 }
