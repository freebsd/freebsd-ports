--- spamd-setup/spamd-setup.c.orig	Mon Sep 29 14:15:19 2003
+++ spamd-setup/spamd-setup.c	Mon Sep 29 14:16:37 2003
@@ -47,8 +47,8 @@
 #endif
 
 #define PATH_FTP		"/usr/bin/ftp"
-#define PATH_PFCTL		"/sbin/pfctl"
-#define PATH_SPAMD_CONF		"/etc/spamd.conf"
+#define PATH_PFCTL		"%%LOCALBASE%%/sbin/pfctl"
+#define PATH_SPAMD_CONF		"%%LOCALBASE%%/etc/spamd.conf"
 #define SPAMD_ARG_MAX		256 /* max # of args to an exec */
 
 struct cidr {
