--- src/downloads.c.orig	Wed Oct  3 19:12:04 2001
+++ src/downloads.c	Fri Oct 26 11:09:48 2001
@@ -7,6 +7,8 @@
 
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #include <fcntl.h>
 
 GSList *sl_downloads = NULL;
@@ -793,6 +795,7 @@
 gboolean download_send_request(struct download *d)
 {
 	gint rw;
+	struct sockaddr_in saddr;
 
 	g_return_val_if_fail(d, FALSE);
 
@@ -821,6 +824,8 @@
 			d->record_index, d->file_name,
 			GTA_VERSION, GTA_SUBVERSION);
 
+	saddr.sin_addr.s_addr=htonl(d->ip);
+	printf("\n\n----Connected to %s:%d\n", inet_ntoa(saddr.sin_addr), d->port);
 	printf("----Sending Request:\n%.*s----\n", (int) rw, dl_tmp);
 	fflush(stdout);
 
