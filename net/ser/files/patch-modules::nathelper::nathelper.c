
$FreeBSD$

--- modules/nathelper/nathelper.c.orig
+++ modules/nathelper/nathelper.c
@@ -110,14 +110,42 @@
  *
  * 2004-03-22	Fix get_body position (should be called before get_callid)
  * 				(andrei)
+ *
  * 2004-03-24	Fix newport for null ip address case (e.g onhold re-INVITE)
  * 				(andrei)
- * 2004-09-30	added received port != via port test (andrei) 
+ *
+ * 2004-09-30	added received port != via port test (andrei)
+ *
  * 2004-10-10   force_socket option introduced (jiri)
+ * 2004-12-21	support for multiple medias added (netch)
+ * 2005-01-18	proxying on protocol type (RTP/AVP, udp, udptl), not
+ *		media type. (sobomax,netch)
+ *
+ * 2005-02-24	Added support for using more than one rtp proxy, in which
+ *		case traffic will be distributed evenly among them. In addition,
+ *		each such proxy can be assigned a weight, which will specify
+ *		which share of the traffic should be placed to this particular
+ *		proxy.
+ *
+ *		Introduce failover mechanism, so that if SER detects that one
+ *		of many proxies is no longer available it temporarily decreases
+ *		its weight to 0, so that no traffic will be assigned to it.
+ *		Such "disabled" proxies are periodically checked to see if they
+ *		are back to normal in which case respective weight is restored
+ *		resulting in traffic being sent to that proxy again.
+ *
+ *		Those features can be enabled by specifying more than one "URI"
+ *		in the rtpproxy_sock parameter, optionally followed by the weight,
+ *		which if absent is assumed to be 1, for example:
  *
+ *		rtpproxy_sock="unix:/foo/bar=4 udp:1.2.3.4:3456=3 udp:5.6.7.8:5432=1"
+ *
+ * 2005-03-24	music-on-hold implemented (netch)
  */
 
 #include "nhelpr_funcs.h"
+#include "nathelper.h"
+#include "../../action.h"
 #include "../../flags.h"
 #include "../../sr_module.h"
 #include "../../dprint.h"
@@ -127,6 +155,7 @@
 #include "../../forward.h"
 #include "../../mem/mem.h"
 #include "../../parser/parse_from.h"
+#include "../../parser/parse_hostport.h"
 #include "../../parser/parse_to.h"
 #include "../../parser/parse_uri.h"
 #include "../../parser/parser_f.h"
@@ -171,39 +200,30 @@
 #define	NAT_UAC_TEST_S_1918	0x08
 #define	NAT_UAC_TEST_RPORT	0x10
 
-/* Handy macros */
-#define	STR2IOVEC(sx, ix)	{(ix).iov_base = (sx).s; (ix).iov_len = (sx).len;}
-
 /* Supported version of the RTP proxy command protocol */
 #define	SUP_CPROTOVER	20040107
+/* Required additional version of the RTP proxy command protocol */
+#define	REQ_CPROTOVER	"20050322"
 #define	CPORT		"22222"
 
 static int nat_uac_test_f(struct sip_msg* msg, char* str1, char* str2);
 static int fix_nated_contact_f(struct sip_msg *, char *, char *);
 static int fix_nated_sdp_f(struct sip_msg *, char *, char *);
-static int extract_mediaip(str *, str *, int *);
-static int extract_mediaport(str *, str *);
-static int alter_mediaip(struct sip_msg *, str *, str *, int, str *, int, int);
-static int alter_mediaport(struct sip_msg *, str *, str *, str *, int);
+static int fixate_sdp_f(struct sip_msg *, char *, char *);
 static char *gencookie();
-static int rtpp_test(int, int);
-static char *send_rtpp_command(struct iovec *, int);
+static int rtpp_test(struct rtpp_node*, int, int);
 static int unforce_rtp_proxy_f(struct sip_msg *, char *, char *);
 static int force_rtp_proxy0_f(struct sip_msg *, char *, char *);
 static int force_rtp_proxy1_f(struct sip_msg *, char *, char *);
 static int force_rtp_proxy2_f(struct sip_msg *, char *, char *);
 static int fix_nated_register_f(struct sip_msg *, char *, char *);
 static int add_rcv_param_f(struct sip_msg *, char *, char *);
+static int rewrite_from_from_f(struct sip_msg *, char *, char *);
 
-static void timer(unsigned int, void *);
 inline static int fixup_str2int(void**, int);
 static int mod_init(void);
 static int child_init(int);
 
-static usrloc_api_t ul;
-
-static int cblen = 0;
-static int natping_interval = 0;
 struct socket_info* force_socket = 0;
 
 
@@ -218,27 +238,51 @@
 	{NULL, 0, 0}
 };
 
-/*
- * If this parameter is set then the natpinger will ping only contacts
- * that have the NAT flag set in user location database
- */
-static int ping_nated_only = 0;
-static const char sbuf[4] = {0, 0, 0, 0};
-static char *rtpproxy_sock = "unix:/var/run/rtpproxy.sock";
+static str sup_ptypes[] = {
+	{.s = "udp", .len = 3},
+	{.s = "udptl", .len = 5},
+	{.s = "rtp/avp", .len = 7},
+	{.s = NULL, .len = 0}
+};
+
+static char *rtpproxy_sock = "unix:/var/run/rtpproxy.sock"; /* list */
 static char *force_socket_str = 0;
 static int rtpproxy_disable = 0;
 static int rtpproxy_disable_tout = 60;
 static int rtpproxy_retr = 5;
 static int rtpproxy_tout = 1;
-static int umode = 0;
-static int controlfd;
 static pid_t mypid;
 static unsigned int myseqn = 0;
-static int rcv_avp_no=42;
+static int rcv_avp_no = 42;
+char *pname_audio = "-";
+char *pname_video = "-";
+char *codecs_audio = "-";
+char *codecs_video = "-";
+
+struct rtpp_head {
+	struct rtpp_node	*rn_first;
+	struct rtpp_node	*rn_last;
+};
+
+struct rtpp_node {
+	char			*rn_url;	/* unparsed, deletable */
+	int			rn_umode;
+	char			*rn_address;	/* substring of rn_url */
+	int			rn_fd;		/* control fd */
+	int			rn_disabled;	/* found unaccessible? */
+	unsigned		rn_weight;	/* for load balancing */
+	int			rn_recheck_ticks;
+	struct rtpp_node	*rn_next;
+};
+
+/* RTP proxy balancing list */
+static struct rtpp_head rtpp_list;
+static int rtpp_node_count = 0;
 
 static cmd_export_t cmds[] = {
 	{"fix_nated_contact",  fix_nated_contact_f,    0, 0,             REQUEST_ROUTE | ONREPLY_ROUTE },
 	{"fix_nated_sdp",      fix_nated_sdp_f,        1, fixup_str2int, REQUEST_ROUTE | ONREPLY_ROUTE | FAILURE_ROUTE },
+	{"fixate_sdp",         fixate_sdp_f,           0, 0,             REQUEST_ROUTE | ONREPLY_ROUTE },
 	{"unforce_rtp_proxy",  unforce_rtp_proxy_f,    0, 0,             REQUEST_ROUTE | ONREPLY_ROUTE | FAILURE_ROUTE },
 	{"force_rtp_proxy",    force_rtp_proxy0_f,     0, 0,             REQUEST_ROUTE | ONREPLY_ROUTE },
 	{"force_rtp_proxy",    force_rtp_proxy1_f,     1, 0,             REQUEST_ROUTE | ONREPLY_ROUTE },
@@ -246,11 +290,16 @@
 	{"nat_uac_test",       nat_uac_test_f,         1, fixup_str2int, REQUEST_ROUTE | ONREPLY_ROUTE | FAILURE_ROUTE },
 	{"fix_nated_register", fix_nated_register_f,   0, 0,             REQUEST_ROUTE },
 	{"add_rcv_param",      add_rcv_param_f,        0, 0,             REQUEST_ROUTE },
+	{"rewrite_from_from",  rewrite_from_from_f,    0, 0,             REQUEST_ROUTE | ONREPLY_ROUTE },
+	{"is_hold",		is_hold_f,	       0, 0,		 REQUEST_ROUTE | ONREPLY_ROUTE },
+	{"start_moh",		start_moh_f,	       0, 0,		 REQUEST_ROUTE | ONREPLY_ROUTE },
+	{"stop_moh",		stop_moh_f,	       0, 0,		 REQUEST_ROUTE | ONREPLY_ROUTE },
 	{0, 0, 0, 0, 0}
 };
 
 static param_export_t params[] = {
 	{"natping_interval",      INT_PARAM, &natping_interval      },
+	{"natping_method",	  STR_PARAM, &natping_method	    },
 	{"ping_nated_only",       INT_PARAM, &ping_nated_only       },
 	{"rtpproxy_sock",         STR_PARAM, &rtpproxy_sock         },
 	{"rtpproxy_disable",      INT_PARAM, &rtpproxy_disable      },
@@ -259,6 +308,10 @@
 	{"rtpproxy_tout",         INT_PARAM, &rtpproxy_tout         },
 	{"received_avp",          INT_PARAM, &rcv_avp_no            },
 	{"force_socket",          STR_PARAM, &force_socket_str		},
+	{"pname_audio",		  STR_PARAM, &pname_audio		},
+	{"pname_video",		  STR_PARAM, &pname_video		},
+	{"codecs_audio",	  STR_PARAM, &codecs_audio		},
+	{"codecs_video",	  STR_PARAM, &codecs_video		},
 	{0, 0, 0}
 };
 
@@ -277,8 +330,6 @@
 mod_init(void)
 {
 	int i;
-	char *cp;
-	bind_usrloc_t bind_usrloc;
 	struct in_addr addr;
 	str socket_str;
 
@@ -288,18 +339,9 @@
 		force_socket=grep_sock_info(&socket_str,0,0);
 	}
 
-	if (natping_interval > 0) {
-		bind_usrloc = (bind_usrloc_t)find_export("ul_bind_usrloc", 1, 0);
-		if (!bind_usrloc) {
-			LOG(L_ERR, "nathelper: Can't find usrloc module\n");
- 			return -1;
- 		}
-
-		if (bind_usrloc(&ul) < 0) {
-			return -1;
-		}
-
-		register_timer(timer, NULL, natping_interval);
+	if (natpinger_init() < 0) {
+		LOG(L_ERR, "nathelper: natpinger_init() failed\n");
+		return -1;
 	}
 
 	/* Prepare 1918 networks list */
@@ -309,25 +351,72 @@
 		nets_1918[i].netaddr = ntohl(addr.s_addr) & nets_1918[i].mask;
 	}
 
+	memset(&rtpp_list, 0, sizeof(rtpp_list));
+	rtpp_node_count = 0;
 	if (rtpproxy_disable == 0) {
-		/* Make rtpproxy_sock writable */
-		cp = pkg_malloc(strlen(rtpproxy_sock) + 1);
-		if (cp == NULL) {
-			LOG(L_ERR, "nathelper: Can't allocate memory\n");
-			return -1;
-		}
-		strcpy(cp, rtpproxy_sock);
-		rtpproxy_sock = cp;
+		/* Make rtp proxies list. */
+		char *p, *p1, *p2, *plim;
 
-		if (strncmp(rtpproxy_sock, "udp:", 4) == 0) {
-			umode = 1;
-			rtpproxy_sock += 4;
-		} else if (strncmp(rtpproxy_sock, "udp6:", 5) == 0) {
-			umode = 6;
-			rtpproxy_sock += 5;
-		} else if (strncmp(rtpproxy_sock, "unix:", 5) == 0) {
-			umode = 0;
-			rtpproxy_sock += 5;
+		p = rtpproxy_sock;
+		plim = p + strlen(p);
+		for(;;) {
+			struct rtpp_node *pnode;
+			int weight;
+
+			weight = 1;
+			while (*p && isspace(*p))
+				++p;
+			if (p >= plim)
+				break;
+			p1 = p;
+			while (*p && !isspace(*p))
+				++p;
+			if (p <= p1)
+				break; /* may happen??? */
+			/* Have weight specified? If yes, scan it */
+			p2 = memchr(p1, '=', p - p1);
+			if (p2 != NULL) {
+				weight = strtoul(p2 + 1, NULL, 10);
+			} else {
+				p2 = p;
+			}
+			pnode = pkg_malloc(sizeof(struct rtpp_node));
+			if (pnode == NULL) {
+				LOG(L_ERR, "nathelper: Can't allocate memory\n");
+				return -1;
+			}
+			memset(pnode, 0, sizeof(*pnode));
+			pnode->rn_recheck_ticks = 0;
+			pnode->rn_weight = weight;
+			pnode->rn_umode = 0;
+			pnode->rn_fd = -1;
+			pnode->rn_disabled = 0;
+			pnode->rn_url = pkg_malloc(p2 - p1 + 1);
+			if (pnode->rn_url == NULL) {
+				LOG(L_ERR, "nathelper: Can't allocate memory\n");
+				return -1;
+			}
+			memmove(pnode->rn_url, p1, p2 - p1);
+			pnode->rn_url[p2 - p1] = 0;
+			if (rtpp_list.rn_first == NULL) {
+				rtpp_list.rn_first = pnode;
+			} else {
+				rtpp_list.rn_last->rn_next = pnode;
+			}
+			rtpp_list.rn_last = pnode;
+			++rtpp_node_count;
+			/* Leave only address in rn_address */
+			pnode->rn_address = pnode->rn_url;
+			if (strncmp(pnode->rn_address, "udp:", 4) == 0) {
+				pnode->rn_umode = 1;
+				pnode->rn_address += 4;
+			} else if (strncmp(pnode->rn_address, "udp6:", 5) == 0) {
+				pnode->rn_umode = 6;
+				pnode->rn_address += 5;
+			} else if (strncmp(pnode->rn_address, "unix:", 5) == 0) {
+				pnode->rn_umode = 0;
+				pnode->rn_address += 5;
+			}
 		}
 	}
 
@@ -340,52 +429,66 @@
 	int n;
 	char *cp;
 	struct addrinfo hints, *res;
+	struct rtpp_node *pnode;
 
-	if (rtpproxy_disable == 0) {
-		mypid = getpid();
-		if (umode != 0) {
-			cp = strrchr(rtpproxy_sock, ':');
-			if (cp != NULL) {
-				*cp = '\0';
-				cp++;
-			}
-			if (cp == NULL || *cp == '\0')
-				cp = CPORT;
+	/* Iterate known RTP proxies - create sockets */
+	mypid = getpid();
+	for (pnode = rtpp_list.rn_first; pnode != NULL; pnode = pnode->rn_next) {
+		char *old_colon;
 
-			memset(&hints, 0, sizeof(hints));
-			hints.ai_flags = 0;
-			hints.ai_family = (umode == 6) ? AF_INET6 : AF_INET;
-			hints.ai_socktype = SOCK_DGRAM;
-			if ((n = getaddrinfo(rtpproxy_sock, cp, &hints, &res)) != 0) {
-				LOG(L_ERR, "nathelper: getaddrinfo: %s\n", gai_strerror(n));
-				return -1;
-			}
+		if (pnode->rn_umode == 0)
+			goto rptest;
+		/*
+		 * This is UDP or UDP6. Detect host and port; lookup host;
+		 * do connect() in order to specify peer address
+		 */
+		old_colon = cp = strrchr(pnode->rn_address, ':');
+		if (cp != NULL) {
+			old_colon = cp;
+			*cp = '\0';
+			cp++;
+		}
+		if (cp == NULL || *cp == '\0')
+			cp = CPORT;
 
-			controlfd = socket((umode == 6) ? AF_INET6 : AF_INET, SOCK_DGRAM, 0);
-			if (controlfd == -1) {
-				LOG(L_ERR, "nathelper: can't create socket\n");
-				freeaddrinfo(res);
-				return -1;
-			}
+		memset(&hints, 0, sizeof(hints));
+		hints.ai_flags = 0;
+		hints.ai_family = (pnode->rn_umode == 6) ? AF_INET6 : AF_INET;
+		hints.ai_socktype = SOCK_DGRAM;
+		if ((n = getaddrinfo(pnode->rn_address, cp, &hints, &res)) != 0) {
+			LOG(L_ERR, "nathelper: getaddrinfo: %s\n", gai_strerror(n));
+			return -1;
+		}
+		if (old_colon)
+			*old_colon = ':'; /* restore rn_address */
 
-			if (connect(controlfd, res->ai_addr, res->ai_addrlen) == -1) {
-				LOG(L_ERR, "nathelper: can't connect to a RTP proxy\n");
-				close(controlfd);
-				freeaddrinfo(res);
-				return -1;
-			}
+		pnode->rn_fd = socket((pnode->rn_umode == 6)
+		    ? AF_INET6 : AF_INET, SOCK_DGRAM, 0);
+		if (pnode->rn_fd == -1) {
+			LOG(L_ERR, "nathelper: can't create socket\n");
 			freeaddrinfo(res);
+			return -1;
 		}
 
-		rtpproxy_disable = rtpp_test(0, 1);
-	} else {
-		rtpproxy_disable_tout = -1;
+		if (connect(pnode->rn_fd, res->ai_addr, res->ai_addrlen) == -1) {
+			LOG(L_ERR, "nathelper: can't connect to a RTP proxy\n");
+			close(pnode->rn_fd);
+			pnode->rn_fd = -1;
+			freeaddrinfo(res);
+			return -1;
+		}
+		freeaddrinfo(res);
+rptest:
+		pnode->rn_disabled = rtpp_test(pnode, 0, 1);
 	}
 
+	if (rtpproxy_disable)
+		rtpproxy_disable_tout = -1;
+
 	return 0;
 }
 
-static int
+int
 isnulladdr(str *sx, int pf)
 {
 	char *cp;
@@ -440,7 +543,7 @@
  * assumes the to header is already parsed, so
  * make sure it really is before calling this function
  */
-static inline int
+int
 get_to_tag(struct sip_msg* _m, str* _tag)
 {
 
@@ -463,7 +566,7 @@
 /*
  * Extract tag from From header field of a request
  */
-static inline int
+int
 get_from_tag(struct sip_msg* _m, str* _tag)
 {
 
@@ -488,7 +591,7 @@
  * (so make sure it is, before calling this function or
  *  it might fail even if the message _has_ a callid)
  */
-static inline int
+int
 get_callid(struct sip_msg* _m, str* _cid)
 {
 
@@ -562,9 +665,13 @@
 	if (anchor == 0)
 		return -1;
 
-	hostport = uri.host;
-	if (uri.port.len > 0)
-		hostport.len = uri.port.s + uri.port.len - uri.host.s;
+	if (uri.maddr_val.len == 0) {
+		hostport = uri.host;
+		if (uri.port.len > 0)
+			hostport.len = uri.port.s + uri.port.len - uri.host.s;
+	} else {
+		hostport = uri.maddr_val;
+	}
 
 	cp = ip_addr2a(&msg->rcv.src_ip);
 	len = c->uri.len + strlen(cp) + 6 /* :port */ - hostport.len + 1;
@@ -651,11 +758,22 @@
 {
 	struct sip_uri uri;
 	contact_t* c;
+	char t;
+	str host;
+	short int port;
 
 	if (get_contact_uri(msg, &uri, &c) == -1)
 		return -1;
 
-	return (is1918addr(&(uri.host)) == 1) ? 1 : 0;
+	if (uri.maddr_val.len == 0)
+		return (is1918addr(&(uri.host)) == 1) ? 1 : 0;
+	t = uri.maddr_val.s[uri.maddr_val.len];
+	uri.maddr_val.s[uri.maddr_val.len] = '\0';
+	parse_hostport(uri.maddr_val.s, &host, &port);
+	uri.maddr_val.s[uri.maddr_val.len] = t;
+	if (host.len <= 0)
+		return 0;
+	return (is1918addr(&host) == 1) ? 1 : 0;
 }
 
 /*
@@ -755,8 +873,8 @@
 static int
 fix_nated_sdp_f(struct sip_msg* msg, char* str1, char* str2)
 {
-	str body, body1, oldip, oldip1, newip;
-	int level, pf, pf1;
+	str body, body1, oldip, newip;
+	int level, pf;
 	char *buf;
 	struct lump* anchor;
 
@@ -803,37 +921,43 @@
 	}
 
 	if (level & FIX_MEDIP) {
-		if (extract_mediaip(&body, &oldip, &pf) == -1) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: can't extract media IP from the SDP\n");
-			goto finalize;
-		}
-		if (pf != AF_INET) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: "
-			    "not an IPv4 address in SDP\n");
-			goto finalize;
-		}
-		body1.s = oldip.s + oldip.len;
-		body1.len = body.s + body.len - body1.s;
-		if (extract_mediaip(&body1, &oldip1, &pf1) == -1) {
-			oldip1.len = 0;
-		}
-		if (oldip1.len > 0 && pf != pf1) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: mismatching "
-			    "address families in SDP\n");
-			return -1;
-		}
-
+		/* Iterate all c= and replace ips in them. */
+		unsigned hasreplaced = 0;
+		int pf1 = 0;
+		str body2;
+		char* bodylimit = body.s + body.len;
 		newip.s = ip_addr2a(&msg->rcv.src_ip);
 		newip.len = strlen(newip.s);
-		if (alter_mediaip(msg, &body, &oldip, pf, &newip, pf,
-		    1) == -1) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: can't alter media IP");
-			return -1;
+		body1 = body;
+		for(;;) {
+			if (extract_mediaip(&body1, &oldip, &pf) == -1)
+				break;
+			if (pf != AF_INET) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: "
+				    "not an IPv4 address in SDP\n");
+				goto finalize;
+			}
+			if (!pf1)
+				pf1 = pf;
+			else if (pf != pf1) {
+				LOG(L_ERR, "ERROR: fix_nated_sdp: mismatching "
+				    "address families in SDP\n");
+				return -1;
+			}
+			body2.s = oldip.s + oldip.len;
+			body2.len = bodylimit - body2.s;
+			if (alter_mediaip(msg, &body1, &oldip, pf, &newip, pf,
+			    1) == -1)
+			{
+				LOG(L_ERR, "ERROR: fix_nated_sdp: can't alter media IP");
+				return -1;
+			}
+			hasreplaced = 1;
+			body1 = body2;
 		}
-		if (oldip1.len > 0 && alter_mediaip(msg, &body, &oldip1, pf1,
-		    &newip, pf, 0) == -1) {
-			LOG(L_ERR, "ERROR: fix_nated_sdp: can't alter media IP");
-			return -1;
+		if (!hasreplaced) {
+			LOG(L_ERR, "ERROR: fix_nated_sdp: can't extract media IP from the SDP\n");
+			goto finalize;
 		}
 	}
 
@@ -841,7 +965,7 @@
 	return 1;
 }
 
-static int
+int
 extract_mediaip(str *body, str *mediaip, int *pf)
 {
 	char *cp, *cp1;
@@ -855,7 +979,7 @@
 		cp = cp1 + 2;
 	}
 	if (cp1 == NULL) {
-		LOG(L_DBG, "ERROR: extract_mediaip: no `c=' in SDP\n");
+		LOG(L_ERR, "ERROR: extract_mediaip: no `c=' in SDP\n");
 		return -1;
 	}
 	mediaip->s = cp1 + 2;
@@ -897,11 +1021,12 @@
 	return 1;
 }
 
-static int
+int
 extract_mediaport(str *body, str *mediaport)
 {
 	char *cp, *cp1;
-	int len;
+	int len, i;
+	str ptype;
 
 	cp1 = NULL;
 	for (cp = body->s; (len = body->s + body->len - cp) > 0;) {
@@ -914,32 +1039,62 @@
 		LOG(L_ERR, "ERROR: extract_mediaport: no `m=' in SDP\n");
 		return -1;
 	}
-	mediaport->s = cp1 + 2;
+	mediaport->s = cp1 + 2; /* skip `m=' */
 	mediaport->len = eat_line(mediaport->s, body->s + body->len -
 	  mediaport->s) - mediaport->s;
 	trim_len(mediaport->len, mediaport->s, *mediaport);
 
-	if (mediaport->len > 6 && memcmp(mediaport->s, "audio", 5) == 0 &&
-	    isspace((int)mediaport->s[5])) {
-		mediaport->s += 5;
-		mediaport->len -= 5;
-	} else if (mediaport->len > 12 && memcmp(mediaport->s, "application", 11) == 0 &&
-	    isspace((int)mediaport->s[11])) {
-		mediaport->s += 11;
-		mediaport->len -= 11;
-	} else {
-		LOG(L_ERR, "ERROR: extract_mediaport: can't parse `m=' in SDP\n");
+	/* Skip media supertype and spaces after it */
+	cp = eat_token_end(mediaport->s, mediaport->s + mediaport->len);
+	mediaport->len -= cp - mediaport->s;
+	if (mediaport->len <= 0 || cp == mediaport->s) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no port in `m='\n");
 		return -1;
 	}
+	mediaport->s = cp;
 	cp = eat_space_end(mediaport->s, mediaport->s + mediaport->len);
-	mediaport->len = eat_token_end(cp, mediaport->s + mediaport->len) - cp;
+	mediaport->len -= cp - mediaport->s;
+	if (mediaport->len <= 0 || cp == mediaport->s) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no port in `m='\n");
+		return -1;
+	}
+	/* Extract port */
 	mediaport->s = cp;
-	return 1;
+	cp = eat_token_end(mediaport->s, mediaport->s + mediaport->len);
+	ptype.len = mediaport->len - (cp - mediaport->s);
+	if (ptype.len <= 0 || cp == mediaport->s) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no port in `m='\n");
+		return -1;
+	}
+	ptype.s = cp;
+	mediaport->len = cp - mediaport->s;
+	/* Skip spaces after port */
+	cp = eat_space_end(ptype.s, ptype.s + ptype.len);
+	ptype.len -= cp - ptype.s;
+	if (ptype.len <= 0 || cp == ptype.s) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no protocol type in `m='\n");
+		return -1;
+	}
+	/* Extract protocol type */
+	ptype.s = cp;
+	cp = eat_token_end(ptype.s, ptype.s + ptype.len);
+	if (cp == ptype.s) {
+		LOG(L_ERR, "ERROR: extract_mediaport: no protocol type in `m='\n");
+		return -1;
+	}
+	ptype.len = cp - ptype.s;
+
+	for (i = 0; sup_ptypes[i].s != NULL; i++)
+		if (ptype.len == sup_ptypes[i].len &&
+		    strncasecmp(ptype.s, sup_ptypes[i].s, ptype.len) == 0)
+			return 0;
+	/* Unproxyable protocol type. Generally it isn't error. */
+	return -1;
 }
 
-static int
+int
 alter_mediaip(struct sip_msg *msg, str *body, str *oldip, int oldpf,
-  str *newip, int newpf, int preserve)
+  str *newip, int newpf, int flags)
 {
 	char *buf;
 	int offset;
@@ -947,7 +1102,7 @@
 	str omip, nip, oip;
 
 	/* check that updating mediaip is really necessary */
-	if (oldpf == newpf && isnulladdr(oldip, oldpf))
+	if (oldpf == newpf && isnulladdr(oldip, oldpf) && !(flags & 2))
 		return 0;
 	if (newip->len == oldip->len &&
 	    memcmp(newip->s, oldip->s, newip->len) == 0)
@@ -960,7 +1115,7 @@
 	 * another request comes.
 	 */
 #if 0
-	/* disabled: 
+	/* disabled:
 	 *  - alter_mediaip is called twice if 2 c= lines are present
 	 *    in the sdp (and we want to allow it)
 	 *  - the message flags are propagated in the on_reply_route
@@ -975,7 +1130,7 @@
 	}
 #endif
 
-	if (preserve != 0) {
+	if ((flags & 1) != 0) {
 		anchor = anchor_lump(msg, body->s + body->len - msg->buf, 0, 0);
 		if (anchor == NULL) {
 			LOG(L_ERR, "ERROR: alter_mediaip: anchor_lump failed\n");
@@ -1051,7 +1206,7 @@
 	return 0;
 }
 
-static int
+int
 alter_mediaport(struct sip_msg *msg, str *body, str *oldport, str *newport,
   int preserve)
 {
@@ -1127,6 +1282,161 @@
 	return 0;
 }
 
+/*
+ * Finds specified text in area [*pp...bodylimit) at line beginning.
+ * Returns pointer to text, updates *pp to position after it.
+ */
+
+static char*
+find_sdp_text_bol(char **pp, char *plimit, char *text, size_t textlen)
+{
+	/* Find text at beginning of line */
+	if (*pp == NULL)
+		return NULL;
+	for(;;) {
+		char* p;
+		if (*pp >= plimit)
+			return NULL;
+		if (!(p = ser_memmem(*pp, text, plimit - *pp, textlen))) {
+			*pp = plimit;
+			return NULL;
+		}
+		*pp = p + 1;
+		if (p[-1] != '\n' && p[-1] != '\r')
+			continue;
+		return p;
+	}
+	/*UNREACHED*/
+	return NULL;
+}
+
+static int
+fixate_sdp_f(struct sip_msg* msg, char* str1, char* str2)
+{
+	char *cp;
+	int newpf;
+	str body, newip, newport, dest, oldip, oldport;
+	struct sip_uri ruri;
+	struct hdr_field *hdr;
+	struct via_body *rvia;
+	char *bodylimit, *v1p, *v2p, *m1p, *m2p, *c1p, *c2p;
+	char *om_ip_pos, *om_port_pos;
+	int c1_altered;
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
+	if (extract_body(msg, &body) == -1 || body.len == 0) {
+		LOG(L_ERR, "ERROR: fixate_sdp: can't extract body "
+		    "from the message\n");
+		return -1;
+	}
+	bodylimit = body.s + body.len;
+	v2p = v1p = find_sdp_line(body.s, bodylimit, 'v');
+	if (!v1p) {
+		LOG(L_ERR, "fixate_sdp: no sessions found\n");
+		return -1;
+	}
+	om_ip_pos = body.s;
+	om_port_pos = body.s;
+	for(;;) {
+		v1p = v2p;
+		if (v1p == NULL || v1p >= bodylimit)
+			break;
+		v2p = find_next_sdp_line(v1p, bodylimit, 'v', bodylimit);
+		m2p = m1p = find_sdp_line(v1p, v2p, 'm');
+		c1p = find_sdp_line(v1p, v2p, 'c');
+		c1_altered = 0;
+		if (!m1p) {
+			LOG(L_ERR, "fixate_sdp: session without media\n");
+			return -1;
+		}
+		for(;;) {
+			str tmpstr1;
+			m1p = m2p;
+			if (m1p == NULL || m1p >= v2p)
+				break;
+			m2p = find_next_sdp_line(m1p, v2p, 'm', v2p);
+			c2p = find_sdp_line(m1p, m2p, 'c');
+			/* Set old port and IP. Order doesn't matter. */
+			tmpstr1.s = m1p;
+			tmpstr1.len = bodylimit - m1p;
+			if (extract_mediaport(&tmpstr1, &newport) == -1) {
+				LOG(L_ERR, "ERROR: fixate_sdp: can't extract media port from the SDP\n");
+				return -1;
+			}
+			cp = find_sdp_text_bol(&om_port_pos, bodylimit, AOLDMEDPRT, AOLDMEDPRT_LEN);
+			if (cp) {
+				oldport.s = cp + AOLDMEDPRT_LEN;
+				oldport.len = eat_line(oldport.s, bodylimit - oldport.s) - oldport.s;
+				trim_len(oldport.len, oldport.s, oldport);
+				if (oldport.len != 0 &&
+				    alter_mediaport(msg, &body, &newport, &oldport, 0) == -1)
+					return -1;
+			}
+			if (c2p || !c1_altered) {
+				tmpstr1.s = c2p ? c2p : c1p;
+				tmpstr1.len = bodylimit - tmpstr1.s;
+				if (extract_mediaip(&tmpstr1, &newip, &newpf) == -1) {
+					LOG(L_ERR, "ERROR: fixate_sdp: can't extract media IP from the SDP\n");
+					return -1;
+				}
+				if (newip.len != dest.len || memcmp(newip.s, dest.s, dest.len) != 0 ||
+				    isnulladdr(&newip, newpf))
+					return -1;
+				cp = find_sdp_text_bol(&om_ip_pos, bodylimit, AOLDMEDIP, AOLDMEDIP_LEN);
+				if (cp) {
+					oldip.s = cp + AOLDMEDIP_LEN;
+					oldip.len = eat_line(oldip.s, bodylimit - oldip.s) - oldip.s;
+					trim_len(oldip.len, oldip.s, oldip);
+				}
+				if (newip.len == oldip.len &&
+				    memcmp(newip.s, oldip.s, newip.len) == 0)
+					oldip.len = 0;
+						
+				if (oldip.len != 0) {
+					if (alter_mediaip(msg, &body, &newip, newpf, &oldip, AF_INET,
+					    0) == -1)
+						return -1;
+				}
+				if (!c2p)
+					c1_altered = 1;
+			} /* if rewrite IP */
+		} /* medias */
+	} /* sessions */
+
+	return 1;
+}
+
 static char *
 gencookie()
 {
@@ -1138,45 +1448,58 @@
 }
 
 static int
-rtpp_test(int isdisabled, int force)
+rtpp_test(struct rtpp_node *node, int isdisabled, int force)
 {
 	int rtpp_ver;
-	static int recheck_ticks = 0;
 	char *cp;
 	struct iovec v[2] = {{NULL, 0}, {"V", 1}};
+	struct iovec vf[4] = {{NULL, 0}, {"VF", 2}, {" ", 1},
+	    {REQ_CPROTOVER, 8}};
 
 	if (force == 0) {
 		if (isdisabled == 0)
 			return 0;
-		if (recheck_ticks > get_ticks())
+		if (node->rn_recheck_ticks > get_ticks())
 			return 1;
 	}
-	cp = send_rtpp_command(v, 2);
-	if (cp == NULL) {
-		LOG(L_WARN,"WARNING: rtpp_test: can't get version of "
-		    "the RTP proxy\n");
-	} else {
+	do {
+		cp = send_rtpp_command(node, v, 2);
+		if (cp == NULL) {
+			LOG(L_WARN,"WARNING: rtpp_test: can't get version of "
+			    "the RTP proxy\n");
+			break;
+		}
 		rtpp_ver = atoi(cp);
-		if (rtpp_ver == SUP_CPROTOVER) {
-			LOG(L_INFO, "rtpp_test: RTP proxy found, support for "
-			    "it %senabled\n", force == 0 ? "re-" : "");
-			return 0;
+		if (rtpp_ver != SUP_CPROTOVER) {
+			LOG(L_WARN, "WARNING: rtpp_test: unsupported "
+			    "version of RTP proxy <%s> found: %d supported, "
+			    "%d present\n", node->rn_url,
+			    SUP_CPROTOVER, rtpp_ver);
+			break;
 		}
-		LOG(L_WARN, "WARNING: rtpp_test: unsupported "
-		    "version of RTP proxy found: %d supported, "
-		    "%d present\n", SUP_CPROTOVER, rtpp_ver);
-	}
-	LOG(L_WARN, "WARNING: rtpp_test: support for RTP proxy "
-	    "has been disabled%s\n",
+		cp = send_rtpp_command(node, vf, 4);
+		if (cp[0] == 'E' || atoi(cp) != 1) {
+			LOG(L_WARN, "WARNING: rtpp_test: of RTP proxy <%s>"
+			    "doesn't support required protocol version %s\n",
+			    node->rn_url, REQ_CPROTOVER);
+			break;
+		}
+		LOG(L_INFO, "rtpp_test: RTP proxy <%s> found, support for "
+		    "it %senabled\n",
+		    node->rn_url, force == 0 ? "re-" : "");
+		return 0;
+	} while(0);
+	LOG(L_WARN, "WARNING: rtpp_test: support for RTP proxy <%s>"
+	    "has been disabled%s\n", node->rn_url,
 	    rtpproxy_disable_tout < 0 ? "" : " temporarily");
 	if (rtpproxy_disable_tout >= 0)
-		recheck_ticks = get_ticks() + rtpproxy_disable_tout;
+		node->rn_recheck_ticks = get_ticks() + rtpproxy_disable_tout;
 
 	return 1;
 }
 
-static char *
-send_rtpp_command(struct iovec *v, int vcnt)
+char *
+send_rtpp_command(struct rtpp_node *node, struct iovec *v, int vcnt)
 {
 	struct sockaddr_un addr;
 	int fd, len, i;
@@ -1186,10 +1509,10 @@
 
 	len = 0;
 	cp = buf;
-	if (umode == 0) {
+	if (node->rn_umode == 0) {
 		memset(&addr, 0, sizeof(addr));
 		addr.sun_family = AF_LOCAL;
-		strncpy(addr.sun_path, rtpproxy_sock,
+		strncpy(addr.sun_path, node->rn_address,
 		    sizeof(addr.sun_path) - 1);
 #ifdef HAVE_SOCKADDR_SA_LEN
 		addr.sun_len = strlen(addr.sun_path);
@@ -1198,12 +1521,12 @@
 		fd = socket(AF_LOCAL, SOCK_STREAM, 0);
 		if (fd < 0) {
 			LOG(L_ERR, "ERROR: send_rtpp_command: can't create socket\n");
-			return NULL;
+			goto badproxy;
 		}
 		if (connect(fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
 			close(fd);
 			LOG(L_ERR, "ERROR: send_rtpp_command: can't connect to RTP proxy\n");
-			return NULL;
+			goto badproxy;
 		}
 
 		do {
@@ -1212,7 +1535,7 @@
 		if (len <= 0) {
 			close(fd);
 			LOG(L_ERR, "ERROR: send_rtpp_command: can't send command to a RTP proxy\n");
-			return NULL;
+			goto badproxy;
 		}
 		do {
 			len = read(fd, buf, sizeof(buf) - 1);
@@ -1220,38 +1543,38 @@
 		close(fd);
 		if (len <= 0) {
 			LOG(L_ERR, "ERROR: send_rtpp_command: can't read reply from a RTP proxy\n");
-			return NULL;
+			goto badproxy;
 		}
 	} else {
-		fds[0].fd = controlfd;
+		fds[0].fd = node->rn_fd;
 		fds[0].events = POLLIN;
 		fds[0].revents = 0;
 		/* Drain input buffer */
 		while ((poll(fds, 1, 0) == 1) &&
 		    ((fds[0].revents & POLLIN) != 0)) {
-			recv(controlfd, buf, sizeof(buf) - 1, 0);
+			recv(node->rn_fd, buf, sizeof(buf) - 1, 0);
 			fds[0].revents = 0;
 		}
 		v[0].iov_base = gencookie();
 		v[0].iov_len = strlen(v[0].iov_base);
 		for (i = 0; i < rtpproxy_retr; i++) {
 			do {
-				len = writev(controlfd, v, vcnt);
+				len = writev(node->rn_fd, v, vcnt);
 			} while (len == -1 && (errno == EINTR || errno == ENOBUFS));
 			if (len <= 0) {
 				LOG(L_ERR, "ERROR: send_rtpp_command: "
 				    "can't send command to a RTP proxy\n");
-				return NULL;
+				goto badproxy;
 			}
 			while ((poll(fds, 1, rtpproxy_tout * 1000) == 1) &&
 			    (fds[0].revents & POLLIN) != 0) {
 				do {
-					len = recv(controlfd, buf, sizeof(buf) - 1, 0);
+					len = recv(node->rn_fd, buf, sizeof(buf) - 1, 0);
 				} while (len == -1 && errno == EINTR);
 				if (len <= 0) {
 					LOG(L_ERR, "ERROR: send_rtpp_command: "
 					    "can't read reply from a RTP proxy\n");
-					return NULL;
+					goto badproxy;
 				}
 				if (len >= (v[0].iov_len - 1) &&
 				    memcmp(buf, v[0].iov_base, (v[0].iov_len - 1)) == 0) {
@@ -1269,28 +1592,97 @@
 		if (i == rtpproxy_retr) {
 			LOG(L_ERR, "ERROR: send_rtpp_command: "
 			    "timeout waiting reply from a RTP proxy\n");
-			return NULL;
+			goto badproxy;
 		}
 	}
 
 out:
 	cp[len] = '\0';
 	return cp;
+badproxy:
+	LOG(L_ERR, "send_rtpp_command(): proxy <%s> does not responding, disable it\n", node->rn_url);
+	node->rn_disabled = 1;
+	node->rn_recheck_ticks = get_ticks() + rtpproxy_disable_tout;
+	return NULL;
+}
+
+/*
+ * Main balancing routine. This does not try to keep the same proxy for
+ * the call if some proxies were disabled or enabled; proxy death considered
+ * too rare. Otherwise we should implement "mature" HA clustering, which is
+ * too expensive here.
+ */
+struct rtpp_node *
+select_rtpp_node(str callid, int do_test)
+{
+	unsigned sum, sumcut, weight_sum;
+	struct rtpp_node* node;
+	int was_forced;
+
+	/* Most popular case: 1 proxy, nothing to calculate */
+	if (rtpp_node_count == 1) {
+		node = rtpp_list.rn_first;
+		return node->rn_disabled ? NULL : node;
+	}
+
+	/* XXX Use quick-and-dirty hashing algo */
+	for(sum = 0; callid.len > 0; callid.len--)
+		sum += callid.s[callid.len - 1];
+	sum &= 0xff;
+
+	was_forced = 0;
+retry:
+	weight_sum = 0;
+	for (node = rtpp_list.rn_first; node != NULL; node = node->rn_next) {
+		if (node->rn_disabled) {
+			/* Try to enable if it's time to try. */
+			if (node->rn_recheck_ticks <= get_ticks())
+				node->rn_disabled = rtpp_test(node, 1, 0);
+		}
+		if (!node->rn_disabled)
+			weight_sum += node->rn_weight;
+	}
+	if (weight_sum == 0) {
+		/* No proxies? Force all to be redetected, if not yet */
+		if (was_forced)
+			return NULL;
+		was_forced = 1;
+		for (node = rtpp_list.rn_first; node != NULL; node = node->rn_next) {
+			node->rn_disabled = rtpp_test(node, 1, 1);
+		}
+		goto retry;
+	}
+	sumcut = sum % weight_sum;
+	/*
+	 * sumcut here lays from 0 to weight_sum-1.
+	 * Scan proxy list and decrease until appropriate proxy is found.
+	 */
+	for (node = rtpp_list.rn_first; node != NULL; node = node->rn_next) {
+		if (node->rn_disabled)
+			continue;
+		if (sumcut < node->rn_weight)
+			goto found;
+		sumcut -= node->rn_weight;
+	}
+	/* No node list */
+	return NULL;
+found:
+	if (do_test) {
+		node->rn_disabled = rtpp_test(node, node->rn_disabled, 0);
+		if (node->rn_disabled)
+			goto retry;
+	}
+	return node;
 }
 
 static int
 unforce_rtp_proxy_f(struct sip_msg* msg, char* str1, char* str2)
 {
 	str callid, from_tag, to_tag;
+	struct rtpp_node *node;
 	struct iovec v[1 + 4 + 3] = {{NULL, 0}, {"D", 1}, {" ", 1}, {NULL, 0}, {" ", 1}, {NULL, 0}, {" ", 1}, {NULL, 0}};
 						/* 1 */   /* 2 */   /* 3 */    /* 4 */   /* 5 */    /* 6 */   /* 1 */
 
-	rtpproxy_disable = rtpp_test(rtpproxy_disable, 0);
-	if (rtpproxy_disable != 0) {
-		LOG(L_ERR, "ERROR: unforce_rtp_proxy: support for RTP proxy "
-		    "is disabled\n");
-		return -1;
-	}
 	if (get_callid(msg, &callid) == -1 || callid.len == 0) {
 		LOG(L_ERR, "ERROR: unforce_rtp_proxy: can't get Call-Id field\n");
 		return -1;
@@ -1306,29 +1698,139 @@
 	STR2IOVEC(callid, v[3]);
 	STR2IOVEC(from_tag, v[5]);
 	STR2IOVEC(to_tag, v[7]);
-	send_rtpp_command(v, (to_tag.len > 0) ? 8 : 6);
+	node = select_rtpp_node(callid, 1);
+	if (!node) {
+		LOG(L_ERR, "ERROR: unforce_rtp_proxy: no available proxies\n");
+		return -1;
+	}
+	send_rtpp_command(node, v, (to_tag.len > 0) ? 8 : 6);
+
+	return 1;
+}
+
+/*
+ * Auxiliary for some functions.
+ * Returns pointer to first character of found line, or NULL if no such line.
+ */
+
+char*
+find_sdp_line(char *p, char *plimit, char linechar)
+{
+	static char linehead[3] = "x=";
+	char *cp, *cp1;
+	linehead[0] = linechar;
+	/* Iterate thru body */
+	cp = p;
+	for (;;) {
+		if (cp >= plimit)
+			return NULL;
+		cp1 = ser_memmem(cp, linehead, plimit-cp, 2);
+		if (cp1 == NULL)
+			return NULL;
+		/*
+		 * As it is body, we assume it has previous line and we can
+		 * lookup previous character.
+		 */
+		if (cp1[-1] == '\n' || cp1[-1] == '\r')
+			return cp1;
+		/*
+		 * Having such data, but not at line beginning.
+		 * Skip them and reiterate. ser_memmem() will find next
+		 * occurence.
+		 */
+		if (plimit - cp1 < 2)
+			return NULL;
+		cp = cp1 + 2;
+	}
+	/*UNREACHED*/
+	return NULL;
+}
+
+/* This function assumes p points to a line of requested type. */
+
+char*
+find_next_sdp_line(char *p, char *plimit, char linechar, char *defptr)
+{
+	char* t;
+	if (p >= plimit || plimit - p < 3)
+		return defptr;
+	t = find_sdp_line(p + 2, plimit, linechar);
+	return t ? t : defptr;
+}
 
+static int
+alter_line(struct sip_msg *msg, str *where, str *what)
+{
+	struct lump *anchor;
+	anchor = del_lump(msg, where->s - msg->buf, where->len, 0);
+	if (!anchor) {
+		LOG(L_ERR, "del_lump() failed\n");
+		return 0;
+	}
+	if (insert_new_lump_after(anchor, what->s, what->len, 0) == 0) {
+		LOG(L_ERR, "insert_new_lump_after() failed\n");
+		return 0;
+	}
 	return 1;
 }
 
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
 static int
 force_rtp_proxy2_f(struct sip_msg* msg, char* str1, char* str2)
 {
-	str body, body1, oldport, oldip, oldip1, newport, newip;
-	str callid, from_tag, to_tag, tmp;
+	str body, body1, oldport, oldip, newport, newip;
+	str callid, from_tag, to_tag;
 	int create, port, len, asymmetric, flookup, argc, proxied, real;
+	int create1;
 	int oidx, pf, pf1, force;
 	char opts[16];
 	char *cp, *cp1;
 	char  *cpend, *next;
 	char **ap, *argv[10];
 	struct lump* anchor;
-	struct iovec v[1 + 6 + 5] = {{NULL, 0}, {NULL, 0}, {" ", 1}, {NULL, 0},
-		{" ", 1}, {NULL, 7}, {" ", 1}, {NULL, 1}, {" ", 1}, {NULL, 0},
-		{" ", 1}, {NULL, 0}};
-						/* 1 */    /* 2 */   /* 3 */    /* 4 */
-		/* 5 */    /* 6 */   /* 7 */    /* 8 */   /* 9 */    /* 10 */
-		/* 11 */
+	struct rtpp_node *node;
+	struct iovec v[14] = {
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
+	char *v1p, *v2p, *c1p, *c2p, *m1p, *m2p, *bodylimit;
+	char medianum_buf[20];
+	int medianum, media_multi;
+	str medianum_str, tmpstr1;
+	int c1_altered;
 
 	v[1].iov_base=opts;
 	asymmetric = flookup = force = real = 0;
@@ -1373,13 +1875,6 @@
 		}
 	}
 
-	rtpproxy_disable = rtpp_test(rtpproxy_disable, 0);
-	if (rtpproxy_disable != 0) {
-		LOG(L_ERR, "ERROR: force_rtp_proxy2: support for RTP proxy "
-		    "is disabled\n");
-		return -1;
-	}
-
 	if (msg->first_line.type == SIP_REQUEST &&
 	    msg->first_line.u.request.method_value == METHOD_INVITE) {
 		create = 1;
@@ -1408,14 +1903,7 @@
 		LOG(L_ERR, "ERROR: force_rtp_proxy2: can't get From tag\n");
 		return -1;
 	}
-	if (flookup != 0) {
-		if (create == 0 || to_tag.len == 0)
-			return -1;
-		create = 0;
-		tmp = from_tag;
-		from_tag = to_tag;
-		to_tag = tmp;
-	}
+
 	proxied = 0;
 	for (cp = body.s; (len = body.s + body.len - cp) >= ANORTPPROXY_LEN;) {
 		cp1 = ser_memmem(cp, ANORTPPROXY, len, ANORTPPROXY_LEN);
@@ -1429,88 +1917,198 @@
 	}
 	if (proxied != 0 && force == 0)
 		return -1;
-	if (extract_mediaip(&body, &oldip, &pf) == -1) {
-		LOG(L_ERR, "ERROR: force_rtp_proxy2: can't extract media IP "
-		    "from the message\n");
-		return -1;
-	}
-	if (asymmetric != 0 || real != 0) {
-		newip = oldip;
-	} else {
-		newip.s = ip_addr2a(&msg->rcv.src_ip);
-		newip.len = strlen(newip.s);
-	}
-	body1.s = oldip.s + oldip.len;
-	body1.len = body.s + body.len - body1.s;
-	if (extract_mediaip(&body1, &oldip1, &pf1) == -1) {
-		oldip1.len = 0;
-	}
-	if (oldip1.len > 0 && pf != pf1) {
-		LOG(L_ERR, "ERROR: force_rtp_proxy2: mismatching address "
-		    "families in SDP\n");
-		return -1;
-	}
-	if (extract_mediaport(&body, &oldport) == -1) {
-		LOG(L_ERR, "ERROR: force_rtp_proxy2: can't extract media port "
-		    "from the message\n");
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
+	 */
+	bodylimit = body.s + body.len;
+	v1p = find_sdp_line(body.s, bodylimit, 'v');
+	if (v1p == NULL) {
+		LOG(L_ERR, "ERROR: force_rtp_proxy2: no sessions in SDP\n");
 		return -1;
 	}
-	if (pf == AF_INET6) {
-		opts[oidx] = '6';
-		oidx++;
-	}
-	opts[0] = (create == 0) ? 'L' : 'U';
-	v[1].iov_len = oidx;
-	STR2IOVEC(callid, v[3]);
-	STR2IOVEC(newip, v[5]);
-	STR2IOVEC(oldport, v[7]);
-	STR2IOVEC(from_tag, v[9]);
-	STR2IOVEC(to_tag, v[11]);
-	cp = send_rtpp_command(v, (to_tag.len > 0) ? 12 : 10);
-	if (cp == NULL)
-		return -1;
-	argc = 0;
-	memset(argv, 0, sizeof(argv));
-	cpend=cp+strlen(cp);
-	next=eat_token_end(cp, cpend);
-	for (ap = argv; cp<cpend; cp=next+1, next=eat_token_end(cp, cpend)){
-		*next=0;
-		if (*cp != '\0') {
-			*ap=cp;
-			argc++;
-			if ((char*)++ap >= ((char*)argv+sizeof(argv)))
-				break;
+	v2p = find_next_sdp_line(v1p, bodylimit, 'v', bodylimit);
+	media_multi = (v2p != bodylimit);
+	v2p = v1p;
+	medianum = 0;
+	for (;;) {
+		unsigned nmseen, nmchanged;
+		/* Per-session iteration. */
+		v1p = v2p;
+		if (v1p == NULL || v1p >= bodylimit)
+			break; /* No sessions left */
+		v2p = find_next_sdp_line(v1p, bodylimit, 'v', bodylimit);
+		/* v2p is text limit for session parsing. */
+		m1p = find_sdp_line(v1p, v2p, 'm');
+		/* Have this session media description? */
+		if (m1p == NULL) {
+			LOG(L_ERR, "ERROR: force_rtp_proxy2: no m= in session\n");
+			return -1;
 		}
-	}
-	if (argc < 1)
-		return -1;
-	port = atoi(argv[0]);
-	if (port <= 0 || port > 65535)
-		return -1;
+		/*
+		 * Find c1p only between session begin and first media.
+		 * c1p will give common c= for all medias.
+		 */
+		c1p = find_sdp_line(v1p, m1p, 'c');
+		c1_altered = 0;
+		/* Have session. Iterate media descriptions in session */
+		m2p = m1p;
+		nmseen = nmchanged = 0;
+		for (;;) {
+			create1 = create;
+			if (flookup != 0) {
+				if (!create || to_tag.len <= 0) {
+					LOG(L_ERR, "force_rtp_proxy(): inappropriate 'l'\n");
+					return -1;
+				}
+				create1 = 0;
+			}
+			m1p = m2p;
+			if (m1p == NULL || m1p >= v2p)
+				break;
+			m2p = find_next_sdp_line(m1p, v2p, 'm', v2p);
+			/* c2p will point to per-media "c=" */
+			c2p = find_sdp_line(m1p, m2p, 'c');
+			/* Extract address and port */
+			tmpstr1.s = c2p ? c2p : c1p;
+			++nmseen;
+			if (tmpstr1.s == NULL) {
+				/* No "c=" */
+				LOG(L_ERR, "ERROR: force_rtp_proxy2: can't find media IP "
+				    "in the message\n");
+				return -1;
+			}
+			tmpstr1.len = v2p - tmpstr1.s; /* limit is session limit text */
+			if (extract_mediaip(&tmpstr1, &oldip, &pf) == -1) {
+				LOG(L_ERR, "ERROR: force_rtp_proxy2: can't extract media IP "
+				    "from the message\n");
+				return -1;
+			}
+			tmpstr1.s = m1p;
+			tmpstr1.len = m2p - m1p;
+			if (extract_mediaport(&tmpstr1, &oldport) == -1) {
+				LOG(L_ERR, "ERROR: force_rtp_proxy2: can't extract media port "
+				    "from the message\n");
+				return -1;
+			}
+			++medianum;
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
+			snprintf(medianum_buf, sizeof medianum_buf, "%d", medianum);
+			medianum_str.s = medianum_buf;
+			medianum_str.len = strlen(medianum_buf);
+			opts[0] = (create1 == 0) ? 'L' : 'U';
+			v[1].iov_len = oidx;
+			STR2IOVEC(callid, v[3]);
+			STR2IOVEC(newip, v[5]);
+			STR2IOVEC(oldport, v[7]);
+			/*assert(!flookup || to_tag.len > 0);*/
+			STR2IOVEC(flookup ? to_tag : from_tag, v[9]);
+			if (1 || media_multi) /* XXX */ {
+				STR2IOVEC(medianum_str, v[11]);
+			} else {
+				v[10].iov_len = v[11].iov_len = 0;
+			}
+			STR2IOVEC(flookup ? from_tag : to_tag, v[13]);
+			do {
+				node = select_rtpp_node(callid, 1);
+				if (!node) {
+					LOG(L_ERR, "ERROR: force_rtp_proxy2: no available proxies\n");
+					return -1;
+				}
+				cp = send_rtpp_command(node, v,
+				    (to_tag.len > 0) ? 14 : 12);
+			} while (cp == NULL);
+			LOG(L_DBG, "force_rtp_proxy2: proxy reply: %s\n", cp);
+			PARSE_PROXY_REPLY;
+			if (argc < 1) {
+				LOG(L_ERR, "force_rtp_proxy2: no reply from rtp proxy\n");
+				return -1;
+			}
+			port = atoi(argv[0]);
+			if (port <= 0 || port > 65535) {
+				LOG(L_ERR, "force_rtp_proxy2: incorrect port in reply from rtp proxy\n");
+				return -1;
+			}
 
-	pf1 = (argc >= 3 && argv[2][0] == '6') ? AF_INET6 : AF_INET;
+			pf1 = (argc >= 3 && argv[2][0] == '6') ? AF_INET6 : AF_INET;
 
-	if (isnulladdr(&oldip, pf)) {
-		if (pf1 == AF_INET6) {
-			newip.s = "::";
-			newip.len = 2;
-		} else {
-			newip.s = "0.0.0.0";
-			newip.len = 7;
+			if (isnulladdr(&oldip, pf)) {
+				if (pf1 == AF_INET6) {
+					newip.s = "::";
+					newip.len = 2;
+				} else {
+					newip.s = "0.0.0.0";
+					newip.len = 7;
+				}
+			} else {
+				newip.s = (argc < 2) ? str2 : argv[1];
+				newip.len = strlen(newip.s);
+			}
+			newport.s = int2str(port, &newport.len); /* beware static buffer */
+			/* Alter port. */
+			body1.s = m1p;
+			body1.len = bodylimit - body1.s;
+			if (alter_mediaport(msg, &body1, &oldport, &newport, 0) == -1)
+				return -1;
+			/*
+			 * Alter IP. Don't alter IP common for the session
+			 * more than once.
+			 */
+			if (c2p != NULL || !c1_altered) {
+				body1.s = c2p ? c2p : c1p;
+				body1.len = bodylimit - body1.s;
+				if (alter_mediaip(msg, &body1, &oldip, pf, &newip, pf1, 0) == -1)
+					return -1;
+				if (!c2p)
+					c1_altered = 1;
+			}
+			++nmchanged;
+			/*
+			 * Gross hack: turn off flookup here, after first
+			 * media stream. This is used to allow changing number
+			 * of media streams during re-INVITE.
+			 */
+			flookup = 0;
+		} /* Iterate medias in session */
+		if (c1p && nmseen == nmchanged && !c1_altered) {
+			/* Alter default c-line of this session. */
+			str c1s, janus;
+			size_t newlen;
+			c1s.s = c1p;
+			c1s.len = eat_line(c1p, bodylimit - c1p) - c1p;
+			newlen = c1s.len + 6 + 1;
+			janus.s = pkg_malloc(c1s.len);
+			if (janus.s == NULL) {
+				LOG(L_ERR, "pkg_malloc failed\n");
+				return 0;
+			}
+			sprintf(janus.s, "a=oldc:%*.*s",
+			    (int) c1s.len, (int) c1s.len, c1s.s);
+			janus.len = strlen(janus.s);
+			if (alter_line(msg, &c1s, &janus) <= 0) {
+				LOG(L_ERR, "alter_line() failed\n");
+				return 0;
+			}
 		}
-	} else {
-		newip.s = (argc < 2) ? str2 : argv[1];
-		newip.len = strlen(newip.s);
-	}
-	newport.s = int2str(port, &newport.len); /* beware static buffer */
-
-	if (alter_mediaip(msg, &body, &oldip, pf, &newip, pf1, 0) == -1)
-		return -1;
-	if (oldip1.len > 0 &&
-	    alter_mediaip(msg, &body1, &oldip1, pf, &newip, pf1, 0) == -1)
-		return -1;
-	if (alter_mediaport(msg, &body, &oldport, &newport, 0) == -1)
-		return -1;
+	} /* Iterate sessions */
 
 	if (proxied == 0) {
 		cp = pkg_malloc(ANORTPPROXY_LEN * sizeof(char));
@@ -1554,75 +2152,41 @@
 	return force_rtp_proxy1_f(msg, arg, NULL);
 }
 
-static void
-timer(unsigned int ticks, void *param)
+static int
+rewrite_from_from_f(struct sip_msg* msg, char* str1, char* str2)
 {
-	int rval;
-	void *buf, *cp;
-	str c;
-	struct sip_uri curi;
-	union sockaddr_union to;
-	struct hostent* he;
-	struct socket_info* send_sock;
+	struct action act;
+	struct sip_uri uri;
+	str ruri;
 
-	buf = NULL;
-	if (cblen > 0) {
-		buf = pkg_malloc(cblen);
-		if (buf == NULL) {
-			LOG(L_ERR, "ERROR: nathelper::timer: out of memory\n");
-			return;
-		}
+	/* parsing from header */
+	if (parse_from_header(msg) == -1) {
+		LOG(L_ERR, "rewrite_from_from(): cannot get FROM header\n");
+		return -1;
 	}
-	rval = ul.get_all_ucontacts(buf, cblen, (ping_nated_only ? FL_NAT : 0));
-	if (rval > 0) {
-		if (buf != NULL)
-			pkg_free(buf);
-		cblen = rval * 2;
-		buf = pkg_malloc(cblen);
-		if (buf == NULL) {
-			LOG(L_ERR, "ERROR: nathelper::timer: out of memory\n");
-			return;
-		}
-		rval = ul.get_all_ucontacts(buf, cblen, (ping_nated_only ? FL_NAT : 0));
-		if (rval != 0) {
-			pkg_free(buf);
-			return;
-		}
+	ruri.len = get_from(msg)->uri.len;
+	ruri.s = pkg_malloc(ruri.len + 1);
+	memcpy(ruri.s, get_from(msg)->uri.s, ruri.len + 1);
+	if (parse_uri(ruri.s, ruri.len, &uri) < 0) {
+		LOG(L_ERR, "rewrite_from_from(): can't parse FROM URI\n");
+		pkg_free(ruri.s);
+		return -1;
+	}
+	if (uri.user.len <= 0) {
+		uri.user.s = "Unknown";
+		uri.user.len = 7;
+	} else {
+		uri.user.s[uri.user.len] = '\0';
 	}
 
-	if (buf == NULL)
-		return;
+	bzero(&act, sizeof(act));
+	act.type = SET_USER_T;
+	act.p1_type = STRING_ST;
+	act.p1.string = uri.user.s;
+	do_action(&act, msg);
 
-	cp = buf;
-	while (1) {
-		memcpy(&(c.len), cp, sizeof(c.len));
-		if (c.len == 0)
-			break;
-		c.s = (char*)cp + sizeof(c.len);
-		cp =  (char*)cp + sizeof(c.len) + c.len;
-		if (parse_uri(c.s, c.len, &curi) < 0) {
-			LOG(L_ERR, "ERROR: nathelper::timer: can't parse contact uri\n");
-			continue;
-		}
-		if (curi.proto != PROTO_UDP && curi.proto != PROTO_NONE)
-			continue;
-		if (curi.port_no == 0)
-			curi.port_no = SIP_PORT;
-		he = sip_resolvehost(&curi.host, &curi.port_no, PROTO_UDP);
-		if (he == NULL){
-			LOG(L_ERR, "ERROR: nathelper::timer: can't resolve_hos\n");
-			continue;
-		}
-		hostent2su(&to, he, 0, curi.port_no);
-		send_sock=force_socket ? force_socket : 
-					get_send_socket(0, &to, PROTO_UDP);
-		if (send_sock == NULL) {
-			LOG(L_ERR, "ERROR: nathelper::timer: can't get sending socket\n");
-			continue;
-		}
-		udp_send(send_sock, (char *)sbuf, sizeof(sbuf), &to);
-	}
-	pkg_free(buf);
+	pkg_free(ruri.s);
+	return 1;
 }
 
 
