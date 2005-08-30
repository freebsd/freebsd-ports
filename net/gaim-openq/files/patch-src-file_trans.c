--- src/file_trans.c.orig	Thu Aug 18 19:21:53 2005
+++ src/file_trans.c	Thu Aug 18 19:33:01 2005
@@ -26,6 +26,9 @@
 #define random rand
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 #include "debug.h"		// gaim_debug
 #include "ft.h"			// gaim_xfer
 #include "md5.h"
@@ -213,8 +216,8 @@
 int _qq_xfer_open_file(const gchar *filename, const gchar *method, GaimXfer *xfer)
 {
 	ft_info *info = xfer->data;
-	info->dest_fp = fopen(gaim_xfer_get_local_filename(xfer), method);
-	if (info->dest_fp == NULL) {
+	info->un.dest_fp = fopen(gaim_xfer_get_local_filename(xfer), method);
+	if (info->un.dest_fp == NULL) {
 		return -1;
 	}
 	return 0;
@@ -225,26 +228,28 @@
 {
 	ft_info *info = xfer->data;
 
-	fseek(info->dest_fp, index * len, SEEK_SET);
-	return fread(buffer, 1, len, info->dest_fp);
+	fseek(info->un.dest_fp, index * len, SEEK_SET);
+	return fread(buffer, 1, len, info->un.dest_fp);
 }
 
 gint
 _qq_xfer_write_file(guint8 *buffer, guint index, guint len, GaimXfer *xfer)
 {
 	ft_info *info = xfer->data;
-	fseek(info->dest_fp, index * len, SEEK_SET);
-	return fwrite(buffer, 1, len, info->dest_fp);
+	fseek(info->un.dest_fp, index * len, SEEK_SET);
+	return fwrite(buffer, 1, len, info->un.dest_fp);
 }
 
 void qq_xfer_close_file(GaimXfer *xfer)
 {
 	ft_info *info = xfer->data;
 
-	if (info->dest_fp) fclose(info->dest_fp);
+	if (info->un.dest_fp) fclose(info->un.dest_fp);
 }
 #endif
 
+ssize_t _qq_xfer_write(const char *buf, size_t len, GaimXfer *xfer);
+
 gint _qq_send_file(GaimConnection *gc, guint8 *data, gint len, guint16 packet_type, guint32 to_uid)
 {
 	gint bytes;
@@ -270,7 +275,6 @@
 	bytes += create_packet_dw(buf, &cursor, _encrypt_qq_uid(to_uid, file_key));
 	bytes += create_packet_data(buf, &cursor, data, len);
 
-	ssize_t _qq_xfer_write(const char *buf, size_t len, GaimXfer *xfer);
 	if (bytes == len + 12) {
 		//gaim_xfer_write(qd->xfer, buf, bytes);
 		_qq_xfer_write(buf, bytes, qd->xfer);
@@ -397,10 +401,11 @@
 	gchar file_md5[16], filename_md5[16], *filename;
 	gint filename_len, filesize;
 	qq_data *qd;
+	ft_info *info;
 
 	g_return_if_fail(gc != NULL && gc->proto_data != NULL);
 	qd = (qq_data *) gc->proto_data;
-	ft_info *info = (ft_info *) qd->xfer->data;
+	info = (ft_info *) qd->xfer->data;
 
 	filename = (gchar *) gaim_xfer_get_filename(qd->xfer);
 	filesize = gaim_xfer_get_size(qd->xfer);
@@ -669,6 +674,8 @@
 	GaimXfer *xfer = qd->xfer;
 	ft_info *info = (ft_info *) xfer->data;
 	guint32 mask;
+	guint8 *buffer;
+	gint readbytes;
 
 	gaim_debug(GAIM_DEBUG_INFO, "QQ", "receiving %dth fragment ack, slide window status %o, max_fragment_index %d\n", 
 			fragment_index, info->window, info->max_fragment_index);
@@ -698,8 +705,6 @@
 		{
 			//move the slide window
 			info->window &= ~mask;
-			guint8 *buffer;
-			gint readbytes;
 
 			buffer = g_newa(guint8, info->fragment_len);
 			readbytes = _qq_xfer_read_file(buffer, info->max_fragment_index + sizeof(info->window), 
