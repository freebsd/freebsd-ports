
$FreeBSD$

--- modules/nathelper/moh.c
+++ modules/nathelper/moh.c
@@ -0,0 +1,428 @@
+/* $Id: patch-modules::nathelper::moh.c,v 1.2 2005/04/05 13:10:07 netch Exp $
+ *
+ * Copyright (C) 2005 Porta Software Ltd
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
+ *
+ */
+
+#include <sys/types.h>
+#include <sys/uio.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include "../../parser/parser_f.h"
+#include "../../ut.h"
+#include "nhelpr_funcs.h"
+#include "nathelper.h"
+
+/*
+ * The following macro is used in force_rtp_proxy2_f() and twice
+ * in start_moh() 
+ */
+
+#define PARSE_PROXY_REPLY \
+		 do { \
+			argc = 0;	\
+			memset(argv, 0, sizeof(argv));	\
+			cpend=cp+strlen(cp);	\
+			next=eat_token_end(cp, cpend);	\
+			for (ap = argv; cp<cpend; cp=next+1, next=eat_token_end(cp, cpend)){	\
+				*next=0;	\
+				if (*cp != '\0') {	\
+					*ap=cp;	\
+					argc++;	\
+					if ((char*)++ap >= ((char*)argv+sizeof(argv)))	\
+						break;	\
+				}	\
+			} \
+		} while(0)
+
+int
+is_hold_f(struct sip_msg* msg, char *str1, char *str2)
+{
+	/* Look into body and find whether we see 0.0.0.0 as IP address.
+	 * extract_mediaport() is designed to parse address from SDP.
+	 * XXX Check all addresses or only first one? What if have some
+	 * real addresses and some zero ones?
+	 */
+	str body, ip;
+	int pf;
+
+	if (extract_body(msg, &body) == -1) {
+		LOG(L_ERR,"ERROR: is_hold: cannot extract body from msg!\n");
+		return 0;
+	}
+	if (extract_mediaip(&body, &ip, &pf) == -1) {
+		LOG(L_ERR, "ERROR: is_hold: can't extract media IP from the SDP\n");
+		return 0;
+	}
+	return isnulladdr(&ip, pf) ? 1 : -1;
+}
+
+int
+start_moh_f(struct sip_msg* msg, char* str1, char* str2)
+{
+	str callid, from_tag, to_tag;
+	int asymmetric, flookup, force, real;
+	int oidx, argc, medianum, c1p_altered, pf, pf1;
+	int seen_audio, seen_video;
+	str body, body1, tmpstr1, oldip, newip, oldport, newport;
+	str medianum_str;
+	char *cpend, *next, *bodylimit, *v1p, *v2p, *c1p, *c2p, *m1p, *m2p;
+	char *cp;
+	char medianum_buf[20], opts[16];
+	char **ap, *argv[10];
+	unsigned port;
+	struct rtpp_node *node;
+	struct iovec v_create[14] = {
+		{NULL, 0},	/* command */
+		{NULL, 0},	/* options */
+		{" ", 1},	/* separator */
+		{NULL, 0},	/* callid */
+		{" ", 1},	/* separator */
+		{NULL, 7},	/* newip */
+		{" ", 1},	/* separator */
+		{NULL, 1},	/* oldport */
+		{" ", 1},	/* separator */
+		{NULL, 0},	/* from_tag */
+		{";", 1},	/* separator */
+		{NULL, 0},	/* medianum */
+		{" ", 1},	/* separator */
+		{NULL, 0}	/* to_tag */
+	};
+	struct iovec v_play[14] = {
+		{NULL, 0},	/* command */
+		{NULL, 0},	/* options */
+		{" ", 1},	/* separator */
+		{NULL, 0},	/* callid */
+		{" ", 1},	/* separator */
+		{NULL, 7},	/* pname */
+		{" ", 1},	/* separator */
+		{NULL, 1},	/* codecs */
+		{" ", 1},	/* separator */
+		{NULL, 0},	/* to_tag */
+		{";", 1},	/* separator */
+		{NULL, 0},	/* medianum */
+		{" ", 1},	/* separator */
+		{NULL, 0}	/* from_tag */
+	};
+
+	/* extract_body will also parse all the headers in the message as
+	 * a side effect => don't move get_callid/get_to_tag in front of it
+	 * -- andrei */
+	if (extract_body(msg, &body) == -1) {
+		LOG(L_ERR, "ERROR: force_rtp_proxy2: can't extract body "
+		    "from the message\n");
+		return -1;
+	}
+	if (get_callid(msg, &callid) == -1 || callid.len == 0) {
+		LOG(L_ERR, "ERROR: start_moh: can't get Call-Id field\n");
+		return -1;
+	}
+	if (get_to_tag(msg, &to_tag) == -1 || to_tag.len <= 0) {
+		LOG(L_ERR, "ERROR: start_moh: can't get To tag\n");
+		return -1;
+	}
+	if (get_from_tag(msg, &from_tag) == -1 || from_tag.len == 0) {
+		LOG(L_ERR, "ERROR: start_moh: can't get From tag\n");
+		return -1;
+	}
+	/* Setting specific options. XXX Do we really need this? */
+	v_create[1].iov_base = opts;
+	asymmetric = flookup = force = real = 0;
+	force = 1; /* XXX we must force the proxying in this case */
+	oidx = 2; /* 'UW' */
+#if 0
+	for (cp = str1; cp != NULL && *cp != '\0'; cp++) {
+		switch (*cp) {
+		case 'a':
+		case 'A':
+			opts[oidx++] = 'A';
+			asymmetric = 1;
+			real = 1;
+			break;
+
+		case 'i':
+		case 'I':
+			opts[oidx++] = 'I';
+			break;
+
+		case 'e':
+		case 'E':
+			opts[oidx++] = 'E';
+			break;
+
+		case 'l':
+		case 'L':
+			flookup = 1;
+			break;
+
+		case 'f':
+		case 'F':
+			force = 1;
+			break;
+
+		case 'r':
+		case 'R':
+			real = 1;
+			break;
+
+		default:
+			LOG(L_ERR, "ERROR: force_rtp_proxy2: unknown option `%c'\n", *cp);
+			return -1;
+		}
+	}
+#endif
+	/*
+	 * Parsing of SDP body.
+	 * It can contain a few session descriptions (each start with
+	 * "v=" line), and each session may contain a few media descriptions
+	 * (each start with "m=" line).
+	 * We have to change ports in "m=", and also change IP addresses in
+	 * "c=" which can be placed either in session header (fallback for
+	 * all medias) or media description.
+	 * Ports should be allocated for any media. IPs all should be changed
+	 * to the same value (RTP proxy IP), so we can change all "c="
+	 * unconditionally.
+	 *
+	 * Note start_moh() specifics: use only audio media or video media
+	 * and stop after first of them of both kinds. But, medianum should
+	 * reflect all of them.
+	 */
+	bodylimit = body.s + body.len;
+	v2p = v1p = find_sdp_line(body.s, bodylimit, 'v');
+	if (v1p == NULL) {
+		LOG(L_ERR, "ERROR: start_moh: no sessions in SDP\n");
+		return -1;
+	}
+	medianum = 0;
+	for(;;) {
+		/* Per-session iteration. */
+		v1p = v2p;
+		if (v1p == NULL || v1p >= bodylimit)
+			break; /* No sessions left */
+		v2p = find_next_sdp_line(v1p, bodylimit, 'v', bodylimit);
+		/* v2p is text limit for session parsing. */
+		m1p = find_sdp_line(v1p, v2p, 'm');
+		/* Have this session media description? */
+		if (m1p == NULL) {
+			LOG(L_ERR, "ERROR: start_moh: no m= in session\n");
+			return -1;
+		}
+		/*
+		 * Find c1p only between session begin and first media.
+		 * c1p will give common c= for all medias.
+		 */
+		c1p = find_sdp_line(v1p, m1p, 'c');
+		c1p_altered = 0;
+		/* Have session. Iterate media descriptions in session */
+		seen_audio = seen_video = 0;
+		m2p = m1p;
+		while (!seen_audio || !seen_video) {
+			int is_audio, is_video;
+			/* We pass address to proxy and get some port from
+			 * its resources. Then, if old address was empty
+			 * (0.0.0.0), create a play stream for this media.
+			 */
+			m1p = m2p;
+			if (m1p == NULL || m1p >= v2p)
+				break;
+			m2p = find_next_sdp_line(m1p, v2p, 'm', v2p);
+			/* c2p will point to per-media "c=" */
+			c2p = find_sdp_line(m1p, m2p, 'c');
+			++medianum;
+			/*
+			 * start_moh() specifics: work only for audio/video
+			 * media and apply to first of any in session.
+			 */
+			is_audio = (strncmp(m1p, "m=audio ", 8) == 0);
+			is_video = (strncmp(m1p, "m=video ", 8) == 0);
+			if ((is_audio && seen_audio) ||
+			    (is_video && seen_video) ||
+			    (!is_audio && !is_video))
+				continue;
+			seen_audio = seen_audio || is_audio;
+			seen_video = seen_video || is_video;
+			/* Extract address and port */
+			tmpstr1.s = c2p ? c2p : c1p;
+			if (tmpstr1.s == NULL) {
+				/* No "c=" */
+				LOG(L_ERR, "ERROR: start_moh: can't find media IP in the message\n");
+				return -1;
+			}
+			tmpstr1.len = v2p - tmpstr1.s; /* limit is session limit text */
+			if (extract_mediaip(&tmpstr1, &oldip, &pf) == -1) {
+				LOG(L_ERR, "ERROR: start_moh: can't extract media IP "
+				    "from the message\n");
+				return -1;
+			}
+			tmpstr1.s = m1p;
+			tmpstr1.len = m2p - m1p;
+			if (extract_mediaport(&tmpstr1, &oldport) == -1) {
+				LOG(L_ERR, "ERROR: start_moh: can't extract media port "
+				    "from the message\n");
+				return -1;
+			}
+			if (asymmetric != 0 || real != 0) {
+				newip = oldip;
+			} else {
+				newip.s = ip_addr2a(&msg->rcv.src_ip);
+				newip.len = strlen(newip.s);
+			}
+			/* XXX must compare address families in all addresses */
+			if (pf == AF_INET6) {
+				opts[oidx] = '6';
+				oidx++;
+			}
+
+			/*
+			 * If don't see NULL addr, this is not hold.
+			 * So, skip to next one.
+			 * XXX should also support "a=sendonly"
+			 */
+			if (!isnulladdr(&oldip, pf))
+				continue;
+
+			/* Prepare proxy command strings. */
+			snprintf(medianum_buf, sizeof medianum_buf, "%d", medianum);
+			medianum_str.s = medianum_buf;
+			medianum_str.len = strlen(medianum_buf);
+			opts[0] = 'U'; opts[1] = 'W';
+			v_create[1].iov_len = oidx;
+			STR2IOVEC(callid, v_create[3]);
+			STR2IOVEC(newip, v_create[5]);
+			STR2IOVEC(oldport, v_create[7]);
+			STR2IOVEC(from_tag, v_create[9]);
+			STR2IOVEC(medianum_str, v_create[11]);
+			STR2IOVEC(to_tag, v_create[13]);
+			STR2IOVEC(callid, v_play[3]);
+			if (is_audio) {
+				SZ2IOVEC(pname_audio, v_play[5]);
+				SZ2IOVEC(codecs_audio, v_play[7]);
+			} else {
+				SZ2IOVEC(pname_video, v_play[5]);
+				SZ2IOVEC(codecs_video, v_play[7]);
+			}
+			STR2IOVEC(to_tag, v_play[9]);
+			STR2IOVEC(medianum_str, v_play[11]);
+			STR2IOVEC(from_tag, v_play[13]);
+			SZ2IOVEC("P", v_play[1]);
+			/* Send command. */
+			do {
+				node = select_rtpp_node(callid, 1);
+				if (!node) {
+					LOG(L_ERR, "ERROR: start_moh: no available proxies\n");
+					return -1;
+				}
+				cp = send_rtpp_command(node, v_create, 14);
+				if (cp == NULL)
+					continue;
+				LOG(L_DBG, "start_moh: proxy reply to update: %s\n", cp);
+				PARSE_PROXY_REPLY;
+				if (argc < 1) {
+					LOG(L_ERR, "start_moh: no reply from rtp proxy\n");
+					return -1;
+				}
+				port = atoi(argv[0]);
+				if (port <= 0 || port > 65535) {
+					LOG(L_ERR, "start_moh: incorrect port in reply from rtp proxy\n");
+					return -1;
+				}
+	
+				pf1 = (argc >= 3 && argv[2][0] == '6') ? AF_INET6 : AF_INET;
+				newip.s = (argc < 2) ? str2 : argv[1];
+				newip.len = strlen(newip.s);
+				newport.s = int2str(port, &newport.len); /* beware static buffer */
+				/* Alter port. */
+				body1.s = m1p;
+				body1.len = bodylimit - body1.s;
+				if (alter_mediaport(msg, &body1, &oldport, &newport, 0) == -1) {
+					LOG(L_ERR, "start_mon: alter_mediaport() failed\n");
+					return -1;
+				}
+				/* Alter IP. Don't alter IP common for the session
+				 * more than once.
+				 */
+				if (c2p != NULL || !c1p_altered) {
+					body1.s = c2p ? c2p : c1p;
+					body1.len = m2p - body1.s;
+					if (alter_mediaip(msg, &body1, &oldip, pf, &newip, pf1, 2) == -1) {
+						LOG(L_ERR, "start_moh: alter_mediaip() failed\n");
+						return -1;
+					}
+					if (!c2p)
+						c1p_altered = 1;
+				}
+				cp = send_rtpp_command(node, v_play, 14);
+				LOG(L_DBG, "start_moh: proxy reply to play: %s\n", cp);
+				if (cp == NULL)
+					continue;
+				PARSE_PROXY_REPLY;
+				if (argc < 1) {
+					LOG(L_ERR, "start_moh: no reply from rtp proxy\n");
+					return -1;
+				}
+			} while(cp == NULL);
+		} /* Iterate medias in session */
+	} /* Iterate sessions */
+	return 1;
+}
+
+int
+stop_moh_f(struct sip_msg* msg, char* str1, char* str2)
+{
+	str callid, to_tag, from_tag;
+	struct rtpp_node *node;
+	struct iovec v_noplay[8] = {{NULL, 0}, {"S", 1}, {" ", 1},
+	    {NULL, 0}, {" ", 1}, {NULL, 0}, {" ", 1}, {NULL, 0}};
+	struct iovec v_del[8] = {{NULL, 0}, {"DW", 2}, {" ", 1},
+	    {NULL, 0}, {" ", 1}, {NULL, 0}, {" ", 1}, {NULL, 0}};
+
+	if (get_callid(msg, &callid) == -1 || callid.len == 0) {
+		LOG(L_ERR, "ERROR: stop_moh: can't get Call-Id field\n");
+		return -1;
+	}
+	if (get_to_tag(msg, &to_tag) == -1 || to_tag.len <= 0) {
+		LOG(L_ERR, "ERROR: stop_moh: can't get To tag\n");
+		return -1;
+	}
+	if (get_from_tag(msg, &from_tag) == -1 || from_tag.len == 0) {
+		LOG(L_ERR, "ERROR: stop_moh: can't get From tag\n");
+		return -1;
+	}
+	/* Ask RTP proxy to stop all plays for this tag. We don't iterate
+	 * separate sessions; RTP proxy has knowledge of them.
+	 */
+	STR2IOVEC(callid, v_noplay[3]);
+	STR2IOVEC(to_tag, v_noplay[5]);
+	STR2IOVEC(from_tag, v_noplay[7]);
+	node = select_rtpp_node(callid, 1);
+	send_rtpp_command(node, v_noplay, 8);
+	/* Ask weak deletion for the session. The same as previous;
+	 * RTP proxy knows all sessions.
+	 */
+	STR2IOVEC(callid, v_del[3]);
+	STR2IOVEC(to_tag, v_del[5]);
+	STR2IOVEC(from_tag, v_del[7]);
+	send_rtpp_command(node, v_del, 8);
+	return 1;
+}
