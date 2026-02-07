--- lib/identify.c.orig	1970-01-01 00:00:00.000000000 +0000
+++ lib/identify.c	2012-10-14 13:12:57.000000000 +0000
@@ -0,0 +1,24 @@
+#include <string.h>
+#include <afpfs-ng/afp.h>
+
+
+/* 
+ * afp_server_identify()
+ *
+ * Identifies a server
+ *
+ * Right now, this only does identification using the machine_type
+ * given in getsrvrinfo, but this could later use mDNS to get 
+ * more details.
+ */
+void afp_server_identify(struct afp_server * s)
+{
+	if (strcmp(s->machine_type,"Netatalk")==0)
+		s->server_type=AFPFS_SERVER_TYPE_NETATALK;
+	else if (strcmp(s->machine_type,"AirPort")==0)
+		s->server_type=AFPFS_SERVER_TYPE_AIRPORT;
+	else if (strcmp(s->machine_type,"Macintosh")==0)
+		s->server_type=AFPFS_SERVER_TYPE_MACINTOSH;
+	else
+		s->server_type=AFPFS_SERVER_TYPE_UNKNOWN;
+}
diff -Naur afpfs-ng-0.8.1.orig/lib/log.c afpfs-ng-0.8.1/lib/log.c
