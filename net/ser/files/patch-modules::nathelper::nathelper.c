
$FreeBSD$

--- modules/nathelper/nathelper.c.orig	Mon Jun 23 22:34:37 2003
+++ modules/nathelper/nathelper.c	Sat Aug  2 09:03:54 2003
@@ -5,6 +5,10 @@
  *			 we received this message from
  * fix_nated_sdp() - replaces IP address in the SDP with IP address
  *		     and/or adds direction=active option to the SDP
+ * force_rtp_proxy() - rewrite IP address and UDP port in the SDP
+ *		       body in such a way that RTP traffic visits
+ *		       RTP proxy running on the same machine as a
+ *		       ser itself
  *
  * Beware, those functions will only work correctly if the UA supports
  * symmetric signalling and media (not all do)!!!
@@ -48,9 +52,15 @@
 #include "../../timer.h"
 #include "../../ut.h"
 #include "../registrar/sip_msg.h"
+#include <sys/types.h>
+#include <sys/uio.h>
+#include <sys/un.h>
+#include <ctype.h>
+#include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 
 MODULE_VERSION
 
@@ -58,6 +68,14 @@
 static int fix_nated_sdp_f(struct sip_msg *, char *, char *);
 static int update_clen(struct sip_msg *, int);
 static int extract_mediaip(str *, str *);
+static int extract_mediaport(str *, str *);
+static int alter_mediaip(struct sip_msg *, str *, str *, str *, int *, int);
+static int alter_mediaport(struct sip_msg *, str *, str *, str *, int *, int);
+static int fixate_sdp_f(struct sip_msg *, char *, char *);
+static char *send_rtpp_command(str *, char, int);
+static int unforce_rtp_proxy_f(struct sip_msg *, char *, char *);
+static int force_rtp_proxy_f(struct sip_msg *, char *, char *);
+
 static void timer(unsigned int, void *);
 inline static int fixup_str2int(void**, int);
 static int mod_init(void);
@@ -71,12 +89,15 @@
 static cmd_export_t cmds[]={
 		{"fix_nated_contact", fix_nated_contact_f, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE },
 		{"fix_nated_sdp", fix_nated_sdp_f, 1, fixup_str2int, REQUEST_ROUTE | ONREPLY_ROUTE },
-		{0,0,0,0,0}
+		{"fixate_sdp", fixate_sdp_f, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE },
+		{"force_rtp_proxy", force_rtp_proxy_f, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE },
+		{"unforce_rtp_proxy", unforce_rtp_proxy_f, 0, 0, REQUEST_ROUTE | ONREPLY_ROUTE },
+		{0, 0, 0, 0, 0}
 	};
 
 static param_export_t params[]={
 	{"natping_interval", INT_PARAM, &natping_interval},
-	{0,0,0}
+	{0, 0, 0}
 };
 
 struct module_exports exports={
@@ -268,21 +289,28 @@
 
 #define	ADD_ADIRECTION	0x01
 #define	FIX_MEDIAIP	0x02
+#define	ADD_ANORTPPROXY	0x04
 
 #define ADIRECTION	"a=direction:active\r\n"
-#define	ADIRECTION_LEN	21
+#define	ADIRECTION_LEN	20
 
 #define AOLDMEDIAIP	"a=oldmediaip:"
 #define AOLDMEDIAIP_LEN	13
 
+#define AOLDMEDIPRT	"a=oldmediaport:"
+#define AOLDMEDIPRT_LEN	15
+
+#define	ANORTPPROXY	"a=nortpproxy:yes\r\n"
+#define	ANORTPPROXY_LEN	18
+
 #define CLEN_LEN	10
 
 static int
 fix_nated_sdp_f(struct sip_msg* msg, char* str1, char* str2)
 {
-	str body, mediaip;
-	int level, added_len, offset, len;
-	char *buf, *cp;
+	str body, body1, oldip, oldip1, newip;
+	int level, added_len;
+	char *buf;
 	struct lump* anchor;
 
 	level = (int)(long)str1;
@@ -293,82 +321,66 @@
 		return -1;
 	}
 
-	if (level & ADD_ADIRECTION) {
+	if (level & (ADD_ADIRECTION | ADD_ANORTPPROXY)) {
 		anchor = anchor_lump(&(msg->add_rm),
 		    body.s + body.len - msg->buf, 0, 0);
 		if (anchor == NULL) {
 			LOG(L_ERR, "ERROR: fix_nated_sdp: anchor_lump failed\n");
 			return -1;
 		}
-		buf = pkg_malloc(ADIRECTION_LEN * sizeof(char));
-		if (buf == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: out of memory\n");
-			return -1;
+		if (level & ADD_ADIRECTION) {
+			buf = pkg_malloc(ADIRECTION_LEN * sizeof(char));
+			if (buf == NULL) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: out of memory\n");
+				return -1;
+			}
+			memcpy(buf, ADIRECTION, ADIRECTION_LEN);
+			if (insert_new_lump_after(anchor, buf, ADIRECTION_LEN, 0) == NULL) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: insert_new_lump_after failed\n");
+				pkg_free(buf);
+				return -1;
+			}
+			added_len += ADIRECTION_LEN;
 		}
-		memcpy(buf, ADIRECTION, ADIRECTION_LEN);
-		if (insert_new_lump_after(anchor, buf, ADIRECTION_LEN - 1, 0) == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: insert_new_lump_after failed\n");
-			pkg_free(buf);
-			return -1;
+		if (level & ADD_ANORTPPROXY) {
+			buf = pkg_malloc(ANORTPPROXY_LEN * sizeof(char));
+			if (buf == NULL) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: out of memory\n");
+				return -1;
+			}
+			memcpy(buf, ANORTPPROXY, ANORTPPROXY_LEN);
+			if (insert_new_lump_after(anchor, buf, ANORTPPROXY_LEN, 0) == NULL) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: insert_new_lump_after failed\n");
+				pkg_free(buf);
+				return -1;
+			}
+			added_len += ANORTPPROXY_LEN;
 		}
-		added_len += ADIRECTION_LEN - 1;
 	}
 
 	if (level & FIX_MEDIAIP) {
-		if (extract_mediaip(&body, &mediaip) == -1) {
+		if (extract_mediaip(&body, &oldip) == -1) {
 			LOG(L_ERR, "ERROR: fix_nated_sdp: can't extract media IP from the SDP\n");
 			goto finalise;
 		}
-
-		/* check that updating mediaip is really necessary */
-		if (7 == mediaip.len && memcmp("0.0.0.0", mediaip.s, 7) == 0)
-			goto finalise;
-		cp = ip_addr2a(&msg->rcv.src_ip);
-		len = strlen(cp);
-		if (len == mediaip.len && memcmp(cp, mediaip.s, len) == 0)
-			goto finalise;
-
-		anchor = anchor_lump(&(msg->add_rm),
-		    body.s + body.len - msg->buf, 0, 0);
-		if (anchor == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: anchor_lump failed\n");
-			return -1;
-		}
-		buf = pkg_malloc(AOLDMEDIAIP_LEN + mediaip.len + CRLF_LEN);
-		if (buf == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: out of memory\n");
-			return -1;
-		}
-		memcpy(buf, AOLDMEDIAIP, AOLDMEDIAIP_LEN);
-		memcpy(buf + AOLDMEDIAIP_LEN, mediaip.s, mediaip.len);
-		memcpy(buf + AOLDMEDIAIP_LEN + mediaip.len, CRLF, CRLF_LEN);
-		if (insert_new_lump_after(anchor, buf,
-		    AOLDMEDIAIP_LEN + mediaip.len + CRLF_LEN, 0) == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: insert_new_lump_after failed\n");
-			pkg_free(buf);
-			return -1;
+		body1.s = oldip.s + oldip.len;
+		body1.len = body.s + body.len - body1.s;
+		if (extract_mediaip(&body1, &oldip1) == -1) {
+			oldip1.len = 0;
 		}
-		added_len += AOLDMEDIAIP_LEN + mediaip.len + CRLF_LEN;
 
-		buf = pkg_malloc(len);
-		if (buf == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: out of memory\n");
-			return -1;
-		}
-		offset = mediaip.s - msg->buf;
-		anchor = del_lump(&msg->add_rm, offset, mediaip.len, 0);
-		if (anchor == NULL) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: del_lump failed\n");
-			pkg_free(buf);
+		newip.s = ip_addr2a(&msg->rcv.src_ip);
+		newip.len = strlen(newip.s);
+		if (alter_mediaip(msg, &body, &oldip, &newip,
+		    &added_len, 1) == -1) {
+			LOG(L_ERR, "ERROR: fix_nated_sdp: can't alter media IP");
 			return -1;
 		}
-		memcpy(buf, cp, len);
-		if (insert_new_lump_after(anchor, buf, len, 0) == 0) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: insert_new_lump_after failed\n");
-			pkg_free(buf);
+		if (oldip1.len > 0 && alter_mediaip(msg, &body, &oldip1, &newip,
+		    &added_len, 0) == -1) {
+			LOG(L_ERR, "ERROR: fix_nated_sdp: can't alter media IP");
 			return -1;
 		}
-		added_len += len - mediaip.len;
 	}
 
 finalise:
@@ -425,7 +437,7 @@
 		cp = cp1 + 2;
 	}
 	if (cp1 == NULL) {
-		LOG(L_ERR, "ERROR: extract_mediaip: no `c=' in SDP\n");
+		LOG(L_DBG, "ERROR: extract_mediaip: no `c=' in SDP\n");
 		return -1;
 	}
 	mediaip->s = cp1 + 2;
@@ -449,6 +461,418 @@
 		LOG(L_ERR, "ERROR: extract_mediaip: no `IP4' in `c=' field\n");
 		return -1;
 	}
+	return 1;
+}
+
+static int
+extract_mediaport(str *body, str *mediaport)
+{
+	char *cp, *cp1;
+	int len;
+
+	cp1 = NULL;
+	for (cp = body->s; (len = body->s + body->len - cp) > 0;) {
+		cp1 = ser_memmem(cp, "m=", len, 2);
+		if (cp1 == NULL || cp1[-1] == '\n' || cp1[-1] == '\r')
+			break;
+		cp = cp1 + 2;
+	}
+	if (cp1 == NULL) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no `m=' in SDP\n");
+		return -1;
+	}
+	mediaport->s = cp1 + 2;
+	mediaport->len = eat_line(mediaport->s, body->s + body->len -
+	  mediaport->s) - mediaport->s;
+	trim_len(mediaport->len, mediaport->s, *mediaport);
+
+	if (mediaport->len < 7 || memcmp(mediaport->s, "audio", 5) != 0 ||
+	  !isspace(mediaport->s[5])) {
+		LOG(L_ERR, "ERROR: extract_mediaport: can't parse `m=' in SDP\n");
+		return -1;
+	}
+	cp = eat_space_end(mediaport->s + 5, mediaport->s + mediaport->len);
+	mediaport->len = eat_token_end(cp, mediaport->s + mediaport->len) - cp;
+	mediaport->s = cp;
+	return 1;
+}
+
+static int
+alter_mediaip(struct sip_msg *msg, str *body, str *oldip, str *newip,
+  int *clendelta, int preserve)
+{
+	char *buf;
+	int offset;
+	struct lump* anchor;
+
+	/* check that updating mediaip is really necessary */
+	if (7 == oldip->len && memcmp("0.0.0.0", oldip->s, 7) == 0)
+		return 0;
+	if (newip->len == oldip->len &&
+	    memcmp(newip->s, oldip->s, newip->len) == 0)
+		return 0;
+
+	if (preserve != 0) {
+		anchor = anchor_lump(&(msg->add_rm),
+		    body->s + body->len - msg->buf, 0, 0);
+		if (anchor == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaip: anchor_lump failed\n");
+			return -1;
+		}
+		buf = pkg_malloc(AOLDMEDIAIP_LEN + oldip->len + CRLF_LEN);
+		if (buf == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaip: out of memory\n");
+			return -1;
+		}
+		memcpy(buf, AOLDMEDIAIP, AOLDMEDIAIP_LEN);
+		memcpy(buf + AOLDMEDIAIP_LEN, oldip->s, oldip->len);
+		memcpy(buf + AOLDMEDIAIP_LEN + oldip->len, CRLF, CRLF_LEN);
+		if (insert_new_lump_after(anchor, buf,
+		    AOLDMEDIAIP_LEN + oldip->len + CRLF_LEN, 0) == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaip: insert_new_lump_after failed\n");
+			pkg_free(buf);
+			return -1;
+		}
+		*clendelta += AOLDMEDIAIP_LEN + oldip->len + CRLF_LEN;
+	}
+
+	buf = pkg_malloc(newip->len);
+	if (buf == NULL) {
+		LOG(L_ERR, "ERROR: alter_mediaip: out of memory\n");
+		return -1;
+	}
+	offset = oldip->s - msg->buf;
+	anchor = del_lump(&msg->add_rm, offset, oldip->len, 0);
+	if (anchor == NULL) {
+		LOG(L_ERR, "ERROR: alter_mediaip: del_lump failed\n");
+		pkg_free(buf);
+		return -1;
+	}
+	memcpy(buf, newip->s, newip->len);
+	if (insert_new_lump_after(anchor, buf, newip->len, 0) == 0) {
+		LOG(L_ERR, "ERROR: alter_mediaip: insert_new_lump_after failed\n");
+		pkg_free(buf);
+		return -1;
+	}
+	*clendelta += newip->len - oldip->len;
+	return 0;
+}
+
+static int
+alter_mediaport(struct sip_msg *msg, str *body, str *oldport, str *newport,
+  int *clendelta, int preserve)
+{
+	char *buf;
+	int offset;
+	struct lump* anchor;
+
+	/* check that updating mediaport is really necessary */
+	if (newport->len == oldport->len &&
+	    memcmp(newport->s, oldport->s, newport->len) == 0)
+		return 0;
+
+	if (preserve != 0) {
+		anchor = anchor_lump(&(msg->add_rm),
+		    body->s + body->len - msg->buf, 0, 0);
+		if (anchor == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaport: anchor_lump failed\n");
+			return -1;
+		}
+		buf = pkg_malloc(AOLDMEDIPRT_LEN + oldport->len + CRLF_LEN);
+		if (buf == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaport: out of memory\n");
+			return -1;
+		}
+		memcpy(buf, AOLDMEDIPRT, AOLDMEDIPRT_LEN);
+		memcpy(buf + AOLDMEDIPRT_LEN, oldport->s, oldport->len);
+		memcpy(buf + AOLDMEDIPRT_LEN + oldport->len, CRLF, CRLF_LEN);
+		if (insert_new_lump_after(anchor, buf,
+		    AOLDMEDIPRT_LEN + oldport->len + CRLF_LEN, 0) == NULL) {
+			LOG(L_ERR, "ERROR: alter_mediaport: insert_new_lump_after failed\n");
+			pkg_free(buf);
+			return -1;
+		}
+		*clendelta += AOLDMEDIPRT_LEN + oldport->len + CRLF_LEN;
+	}
+
+	buf = pkg_malloc(newport->len);
+	if (buf == NULL) {
+		LOG(L_ERR, "ERROR: alter_mediaport: out of memory\n");
+		return -1;
+	}
+	offset = oldport->s - msg->buf;
+	anchor = del_lump(&msg->add_rm, offset, oldport->len, 0);
+	if (anchor == NULL) {
+		LOG(L_ERR, "ERROR: alter_mediaport: del_lump failed\n");
+		pkg_free(buf);
+		return -1;
+	}
+	memcpy(buf, newport->s, newport->len);
+	if (insert_new_lump_after(anchor, buf, newport->len, 0) == 0) {
+		LOG(L_ERR, "ERROR: alter_mediaport: insert_new_lump_after failed\n");
+		pkg_free(buf);
+		return -1;
+	}
+	*clendelta += newport->len - oldport->len;
+	return 0;
+}
+
+static int
+fixate_sdp_f(struct sip_msg* msg, char* str1, char* str2)
+{
+	char *cp, *cp1;
+	int len, cldelta;
+	str body, body1, newip, newip1, newport, dest, oldip, oldport;
+	struct sip_uri ruri;
+	struct hdr_field *hdr;
+	struct via_body *rvia;
+
+	if (msg->first_line.type == SIP_REQUEST &&
+	    msg->first_line.u.request.method_value == METHOD_INVITE) {
+		LOG(L_ERR, "DEBUG: fixate_sdp: request\n");
+		if (msg->parsed_uri_ok) {
+			dest = msg->parsed_uri.host;
+		} else {
+			if (parse_uri(msg->new_uri.s, msg->new_uri.len, &ruri) < 0) {
+				LOG(L_ERR, "ERROR: fixate_sdp: can't parse request uri\n");
+				return -1;
+			}
+			dest = ruri.host;
+		}
+	} else if (msg->first_line.type == SIP_REPLY) {
+		LOG(L_ERR, "DEBUG: fixate_sdp: reply\n");
+		rvia = NULL;
+		for (hdr=msg->headers; hdr; hdr=hdr->next) {
+			if (hdr->type == HDR_VIA)
+				rvia = hdr->parsed;
+		}
+		if (rvia == NULL) {
+			LOG(L_ERR, "ERROR: fixate_sdp: no or incorrect Via in reply\n");
+			return -1;
+		}
+		if (rvia->received != NULL) {
+			dest = rvia->received->value;
+		} else {
+			dest = rvia->host;
+		}
+	} else {
+		return -1;
+	}
+
+	if (extract_body(msg, &body) == -1 || body.len == 0)
+		return -1;
+	if (extract_mediaip(&body, &newip) == -1) {
+		LOG(L_ERR, "ERROR: fixate_sdp: can't extract media IP from the SDP\n");
+		return -1;
+	}
+	body1.s = newip.s + newip.len;
+	body1.len = body.s + body.len - body1.s;
+	if (extract_mediaip(&body1, &newip1) == -1) {
+		newip1.len = 0;
+	}
+	if (newip.len != dest.len || memcmp(newip.s, dest.s, dest.len) != 0)
+		return -1;
+	if (extract_mediaport(&body, &newport) == -1) {
+		LOG(L_ERR, "ERROR: fixate_sdp: can't extract media port from the SDP\n");
+		return -1;
+	}
+
+	for (cp = body.s; (len = body.s + body.len - cp) >= AOLDMEDIAIP_LEN;) {
+		cp1 = ser_memmem(cp, AOLDMEDIAIP, len, AOLDMEDIAIP_LEN);
+		if (cp1 == NULL || cp1[-1] == '\n' || cp1[-1] == '\r')
+			break;
+		cp = cp1 + AOLDMEDIAIP_LEN;
+	}
+	if (cp1 == NULL) {
+		oldip.len = 0;
+	} else {
+		oldip.s = cp1 + AOLDMEDIAIP_LEN;
+		oldip.len = eat_line(oldip.s, body.s + body.len -
+		    oldip.s) - oldip.s;
+		trim_len(oldip.len, oldip.s, oldip);
+	}
+	if (newip.len == oldip.len &&
+	    memcmp(newip.s, oldip.s, newip.len) == 0)
+		oldip.len = 0;
+
+	for (cp = body.s; (len = body.s + body.len - cp) >= AOLDMEDIPRT_LEN;) {
+		cp1 = ser_memmem(cp, AOLDMEDIPRT, len, AOLDMEDIPRT_LEN);
+		if (cp1 == NULL || cp1[-1] == '\n' || cp1[-1] == '\r')
+			break;
+		cp = cp1 + AOLDMEDIPRT_LEN;
+	}
+	if (cp1 == NULL) {
+		oldport.len = 0;
+	} else {
+		oldport.s = cp1 + AOLDMEDIPRT_LEN;
+		oldport.len = eat_line(oldport.s, body.s + body.len -
+		    oldport.s) - oldport.s;
+		trim_len(oldport.len, oldport.s, oldport);
+	}
+	if (newport.len == oldport.len &&
+	    memcmp(newport.s, oldport.s, newport.len) == 0)
+		oldport.len = 0;
+
+	cldelta = 0;
+
+	if (oldip.len != 0) {
+		if (alter_mediaip(msg, &body, &newip, &oldip,
+		    &cldelta, 0) == -1)
+			return -1;
+		if (newip1.len > 0 && alter_mediaip(msg, &body1, &newip1,
+		    &oldip, &cldelta, 0) == -1)
+			return -1;
+	}
+	if (oldport.len != 0 &&
+	    alter_mediaport(msg, &body, &newport, &oldport, &cldelta, 0) == -1)
+		return -1;
+
+	if (cldelta == 0)
+		return 1;
+
+	return (update_clen(msg, body.len + cldelta));
+}
+
+static char *
+send_rtpp_command(str *callid, char command, int getreply)
+{
+	struct sockaddr_un addr;
+	int fd, len;
+	struct iovec v[3];
+	static char buf[16];
+	char cmd[2] = {' ', ' '};
+
+	memset(&addr, 0, sizeof(addr));
+	addr.sun_family = AF_LOCAL;
+	strncpy(addr.sun_path, "/var/run/rtpproxy.sock",
+	    sizeof(addr.sun_path) - 1);
+#if !defined(__linux__)
+	addr.sun_len = strlen(addr.sun_path);
+#endif
+
+	fd = socket(AF_LOCAL, SOCK_STREAM, 0);
+	if (fd < 0) {
+		LOG(L_ERR, "ERROR: send_rtpp_command: can't create socket\n");
+		return NULL;
+	}
+	if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
+		close(fd);
+		LOG(L_ERR, "ERROR: send_rtpp_command: can't connect to RTP proxy\n");
+		return NULL;
+	}
+
+	cmd[0] = command;
+	v[0].iov_base = cmd;
+	v[0].iov_len = 2;
+	v[1].iov_base = callid->s;
+	v[1].iov_len = callid->len;
+	v[2].iov_base = "\n";
+	v[2].iov_len = 1;
+	do {
+		len = writev(fd, v, 3);
+	} while (len == -1 && errno == EINTR);
+	if (len <= 0) {
+		close(fd);
+		LOG(L_ERR, "ERROR: send_rtpp_command: can't send command to a RTP proxy\n");
+		return NULL;
+	}
+
+	if (getreply != 0) {
+		do {
+			len = read(fd, buf, sizeof(buf) - 1);
+		} while (len == -1 && errno == EINTR);
+		close(fd);
+		if (len <= 0) {
+			LOG(L_ERR, "ERROR: send_rtpp_command: can't read reply from a RTP proxy\n");
+			return NULL;
+		}
+		buf[len] = '\0';
+	}
+
+	return buf;
+}
+
+static int
+unforce_rtp_proxy_f(struct sip_msg* msg, char* str1, char* str2)
+{
+
+	if (msg->callid == NULL || msg->callid->body.len <= 0) {
+		LOG(L_ERR, "ERROR: unforce_rtp_proxy: no Call-Id field\n");
+		return -1;
+	}
+	send_rtpp_command(&(msg->callid->body), 'D', 0);
+
+	return 1;
+}
+
+static int
+force_rtp_proxy_f(struct sip_msg* msg, char* str1, char* str2)
+{
+	str body, body1, oldport, oldip, oldip1, newport, newip;
+	int create, port, cldelta, len;
+	char buf[16];
+	char *cp, *cp1;
+
+	if (msg->first_line.type == SIP_REQUEST &&
+	    msg->first_line.u.request.method_value == METHOD_INVITE) {
+		create = 1;
+	} else if (msg->first_line.type == SIP_REPLY) {
+		create = 0;
+	} else {
+		return -1;
+	}
+	if (msg->callid == NULL || msg->callid->body.len <= 0) {
+		LOG(L_ERR, "ERROR: force_rtp_proxy: no Call-Id field\n");
+		return -1;
+	}
+	if (extract_body(msg, &body) == -1 || body.len == 0)
+		return -1;
+	for (cp = body.s; (len = body.s + body.len - cp) >= ANORTPPROXY_LEN;) {
+		cp1 = ser_memmem(cp, ANORTPPROXY, len, ANORTPPROXY_LEN);
+		if (cp1 == NULL)
+			break;
+		if (cp1[-1] == '\n' || cp1[-1] == '\r')
+			return 1;
+		cp = cp1 + ANORTPPROXY_LEN;
+	}
+	if (extract_mediaip(&body, &oldip) == -1) {
+		LOG(L_ERR, "ERROR: force_rtp_proxy: can't extract media IP from the message\n");
+		return -1;
+	}
+	body1.s = oldip.s + oldip.len;
+	body1.len = body.s + body.len - body1.s;
+	if (extract_mediaip(&body1, &oldip1) == -1) {
+		oldip1.len = 0;
+	}
+	if (extract_mediaport(&body, &oldport) == -1) {
+		LOG(L_ERR, "ERROR: force_rtp_proxy: can't extract media port from the message\n");
+		return -1;
+	}
+	cp = send_rtpp_command(&(msg->callid->body), create ? 'U' : 'L', 1);
+	if (cp == NULL)
+		return -1;
+	port = atoi(cp);
+	if (port <= 0 || port > 65535)
+		return -1;
+
+	newport.s = buf;
+	newport.len = sprintf(buf, "%d", port);
+	newip.s = ip_addr2a(&msg->rcv.dst_ip);
+	newip.len = strlen(newip.s);
+
+	cldelta = 0;
+	if (alter_mediaip(msg, &body, &oldip, &newip, &cldelta, 0) == -1)
+		return -1;
+	if (oldip1.len > 0 &&
+	    alter_mediaip(msg, &body1, &oldip1, &newip, &cldelta, 0) == -1)
+		return -1;
+	if (alter_mediaport(msg, &body, &oldport, &newport, &cldelta, 0) == -1)
+		return -1;
+
+	if (cldelta == 0)
+		return 1;
+
+	return (update_clen(msg, body.len + cldelta));
 	return 1;
 }
 
