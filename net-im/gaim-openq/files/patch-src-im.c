--- src/im.c.orig	Sat Oct  2 17:48:11 2004
+++ src/im.c	Sat Oct 16 18:06:57 2004
@@ -435,6 +435,8 @@
 	gchar *font_size = NULL, *font_color = NULL, *font_name = NULL, *tmp;
 	gboolean is_bold = FALSE, is_italic = FALSE, is_underline = FALSE;
 	const gchar *start, *end, *last;
+	guint font_name_len, tail_len;
+	guint8 *send_im_tail;
 
 	g_return_if_fail(gc != NULL && gc->proto_data != NULL);
 
@@ -488,7 +490,6 @@
 	now = time(NULL);
 	md5 = _gen_session_md5(qd->uid, qd->session_key);
 
-	guint font_name_len, tail_len;
 	font_name_len = (font_name) ? strlen(font_name) : DEFAULT_FONT_NAME_LEN;
 	tail_len = font_name_len + QQ_SEND_IM_AFTER_MSG_HEADER_LEN + 1;
 
@@ -530,7 +531,7 @@
 	bytes += create_packet_b(raw_data, &cursor, type);
 	//053-   : msg ends with 0x00
 	bytes += create_packet_data(raw_data, &cursor, msg_filtered, msg_len);
-	guint8 *send_im_tail = qq_get_send_im_tail(font_color, font_size, font_name, is_bold,
+	send_im_tail = qq_get_send_im_tail(font_color, font_size, font_name, is_bold,
 						   is_italic, is_underline, tail_len);
 	_qq_show_packet("QQ_MESG debug", send_im_tail, tail_len);
 	bytes += create_packet_data(raw_data, &cursor, (gchar *) send_im_tail, tail_len);
