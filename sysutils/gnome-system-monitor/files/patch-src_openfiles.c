--- src/openfiles.c.orig	Fri Jan 21 18:35:43 2005
+++ src/openfiles.c	Tue Jan 25 19:02:29 2005
@@ -8,6 +8,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include "procman.h"
 #include "openfiles.h"
@@ -143,7 +144,7 @@
 	const glibtop_open_files_entry *o2 = b;
 
 	/* Falta manejar los diferentes tipos! */
-	return (o1->fd == o2->fd) && (o1->type == o1->type); // XXX!
+	return (o1->fd == o2->fd) && (o1->type == o1->type); /* XXX! */
 }
 
 
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
