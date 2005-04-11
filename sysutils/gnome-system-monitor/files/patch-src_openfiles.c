--- src/openfiles.c.orig	Mon Apr 11 03:50:49 2005
+++ src/openfiles.c	Mon Apr 11 03:52:13 2005
@@ -8,6 +8,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include "procman.h"
 #include "openfiles.h"
@@ -152,10 +153,10 @@
 {
 	ProcInfo *info;
 	GtkTreeModel *model;
-	glibtop_open_files_entry *openfiles;
-	glibtop_proc_open_files procmap;
 	GHashTable *new_maps;
 	gint i;
+	glibtop_open_files_entry *openfiles;
+	glibtop_proc_open_files procmap;
 
 	info = g_object_get_data (G_OBJECT (tree), "selected_info");
 	g_return_if_fail (info);
