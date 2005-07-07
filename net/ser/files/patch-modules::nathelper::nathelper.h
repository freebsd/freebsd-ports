--- modules/nathelper/nathelper.h
+++ modules/nathelper/nathelper.h
@@ -0,0 +1,74 @@
+/*
+ * $Id: patch-modules::nathelper::nathelper.h,v 1.2 2005/04/05 13:10:08 netch Exp $
+ *
+ *
+ * Copyright (C) 2005 Porta Software Ltd.
+ *
+ * This file is part of ser, a free SIP server.
+ *
+ * ser is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version
+ *
+ * For a license to use the ser software under conditions
+ * other than those described here, or to purchase support for this
+ * software, please contact iptel.org by e-mail at the following addresses:
+ *    info@iptel.org
+ *
+ * ser is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License 
+ * along with this program; if not, write to the Free Software 
+ * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+ */
+
+#ifndef nathelper_H_
+#define nathelper_H_
+
+/* Handy macros */
+#define	STR2IOVEC(sx, ix)	do {(ix).iov_base = (sx).s; (ix).iov_len = (sx).len;} while(0)
+#define SZ2IOVEC(sx, ix)	do {char *_t_p = (ix).iov_base = (sx); (ix).iov_len = strlen(_t_p);} while(0)
+
+struct rtpp_node;
+
+/* Parameters from nathelper.c */
+extern struct socket_info* force_socket;
+
+/* Functions from nathelper.c */
+int isnulladdr(str *, int);
+int get_to_tag(struct sip_msg* _m, str* _tag);
+int get_from_tag(struct sip_msg* _m, str* _tag);
+int get_callid(struct sip_msg* _m, str* _cid);
+int extract_mediaip(str *, str *, int *);
+int extract_mediaport(str *, str *);
+int alter_mediaip(struct sip_msg *, str *, str *, int, str *, int, int);
+int alter_mediaport(struct sip_msg *, str *, str *, str *, int);
+struct rtpp_node * select_rtpp_node(str, int);
+char *send_rtpp_command(struct rtpp_node*, struct iovec *, int);
+char* find_sdp_line(char*, char*, char);
+char* find_next_sdp_line(char*, char*, char, char*);
+
+/* Functions from moh.c */
+int is_hold_f(struct sip_msg *msg, char *str1, char *str2);
+int start_moh_f(struct sip_msg *msg, char *str1, char *str2);
+int stop_moh_f(struct sip_msg *msg, char *str1, char *str2);
+
+/* Functions from natping.c */
+int natpinger_init(void);
+
+/* Variables from moh.c referenced from nathelper.c */
+extern char *pname_audio;
+extern char *pname_video;
+extern char *codecs_audio;
+extern char *codecs_video;
+
+/* Variables from natping.c referenced from nathelper.c */
+extern int natping_interval;
+extern int ping_nated_only;
+extern char *natping_method;
+
+#endif
