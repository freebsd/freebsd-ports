--- src/group_im.c.orig	Sat Oct  2 17:48:11 2004
+++ src/group_im.c	Sat Oct 16 17:59:51 2004
@@ -59,6 +59,7 @@
 	guint8 *raw_data, *cursor;
 	guint16 msg_len;
 	gchar *msg_filtered;
+	guint8 *send_im_tail;
 
 	g_return_if_fail(gc != NULL && group != NULL && msg != NULL);
 
@@ -73,7 +74,7 @@
 	bytes += create_packet_dw(raw_data, &cursor, group->internal_group_id);
 	bytes += create_packet_w(raw_data, &cursor, msg_len + QQ_SEND_IM_AFTER_MSG_LEN);
 	bytes += create_packet_data(raw_data, &cursor, (gchar *) msg_filtered, msg_len);
-	guint8 *send_im_tail = qq_get_send_im_tail(NULL, NULL, NULL,
+	send_im_tail = qq_get_send_im_tail(NULL, NULL, NULL,
 						   FALSE, FALSE, FALSE,
 						   QQ_SEND_IM_AFTER_MSG_LEN);
 	bytes += create_packet_data(raw_data, &cursor, (gchar *) send_im_tail, QQ_SEND_IM_AFTER_MSG_LEN);
