--- src/send_file.c.orig	Thu Dec 23 18:22:22 2004
+++ src/send_file.c	Thu Aug 18 18:18:11 2005
@@ -22,6 +22,8 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <network.h>
 
 #include "send_file.h"
@@ -203,8 +205,8 @@
 	info = (ft_info *) xfer->data;
 
 	qq_xfer_close_file(xfer);
-	if (info->dest_fp != NULL) {
-		fclose(info->dest_fp);
+	if (info->un.dest_fp != NULL) {
+		fclose(info->un.dest_fp);
 		gaim_debug(GAIM_DEBUG_INFO, "QQ", "file closed\n");
 	}
 	if (info->major_fd != 0) {
@@ -499,6 +501,8 @@
 	guint8 *cursor, *raw_data;
 	gint packet_len, bytes;
 	ft_info *info;
+	guint16 minor_port;
+	guint32 real_ip;
 
 	g_return_if_fail (gc != NULL && gc->proto_data != NULL);
 	qd = (qq_data *) gc->proto_data;
@@ -506,8 +510,6 @@
 
 	gaim_debug(GAIM_DEBUG_INFO, "QQ", "I've accepted the file transfer request from %d\n", to_uid);
 	_qq_xfer_init_socket(qd->xfer);
-	guint16 minor_port;
-	guint32 real_ip;
 
 	packet_len = 79;
 	raw_data = g_newa (guint8, packet_len);
@@ -809,6 +811,7 @@
 	GaimXfer *xfer;
 	gchar *sender_name;
 	ft_info *info;
+	gchar **fileinfo;
 
 	g_return_if_fail (gc != NULL && data != NULL && data_len != 0);
 	qd = (qq_data *) gc->proto_data;
@@ -834,7 +837,6 @@
 			GAIM_XFER_RECEIVE,
 			sender_name);
 
-	gchar **fileinfo;
 	fileinfo = g_strsplit(data + 81 + 12, "\x1f", 2);
 	g_return_if_fail (fileinfo != NULL && fileinfo[0] != NULL && fileinfo[1] != NULL);
 	gaim_xfer_set_filename(xfer, fileinfo[0]);
