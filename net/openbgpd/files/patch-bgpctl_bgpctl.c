Index: bgpctl/bgpctl.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/bgpctl.c,v
retrieving revision 1.1.1.7
retrieving revision 1.7
diff -u -p -r1.1.1.7 -r1.7
--- bgpctl/bgpctl.c	14 Feb 2010 20:20:14 -0000	1.1.1.7
+++ bgpctl/bgpctl.c	10 Apr 2010 12:17:18 -0000	1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpctl.c,v 1.142 2009/06/06 06:33:15 eric Exp $ */
+/*	$OpenBSD: bgpctl.c,v 1.157 2010/03/08 17:02:19 claudio Exp $ */
 
 /*
  * Copyright (c) 2003 Henning Brauer <henning@openbsd.org>
@@ -16,11 +16,19 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <net/if.h>
+#if defined(__FreeBSD__)	/* net/if_media.h */
+#include "if_media.h"
+#else
 #include <net/if_media.h>
+#endif /* defined(__FreeBSD__) */
 #include <net/if_types.h>
 
 #include <err.h>
@@ -29,7 +37,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)	/* util.h */
+#include "util.h"
+#else
 #include <util.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "session.h"
@@ -38,6 +50,10 @@
 #include "parser.h"
 #include "irrfilter.h"
 
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
+
 enum neighbor_views {
 	NV_DEFAULT,
 	NV_TIMERS
@@ -50,7 +66,7 @@ int		 show_summary_msg(struct imsg *, in
 int		 show_summary_terse_msg(struct imsg *, int);
 int		 show_neighbor_terse(struct imsg *);
 int		 show_neighbor_msg(struct imsg *, enum neighbor_views);
-void		 print_neighbor_capa_mp_safi(u_int8_t);
+void		 print_neighbor_capa_mp(struct peer *);
 void		 print_neighbor_msgstats(struct peer *);
 void		 print_timer(const char *, time_t);
 static char	*fmt_timeframe(time_t t);
@@ -65,7 +81,7 @@ void		 show_interface_head(void);
 int		 ift2ifm(int);
 const char *	 get_media_descr(int);
 const char *	 get_linkstate(int, int);
-void		 print_baudrate(u_int64_t);
+const char *	 get_baudrate(u_int64_t, char *);
 int		 show_interface_msg(struct imsg *);
 void		 show_rib_summary_head(void);
 void		 print_prefix(struct bgpd_addr *, u_int8_t, u_int8_t);
@@ -74,7 +90,6 @@ void		 print_flags(u_int8_t, int);
 int		 show_rib_summary_msg(struct imsg *);
 int		 show_rib_detail_msg(struct imsg *, int);
 void		 show_community(u_char *, u_int16_t);
-const char	*get_ext_subtype(u_int8_t);
 void		 show_ext_community(u_char *, u_int16_t);
 char		*fmt_mem(int64_t);
 int		 show_rib_memory_msg(struct imsg *);
@@ -98,7 +113,7 @@ int
 main(int argc, char *argv[])
 {
 	struct sockaddr_un	 sun;
-	int			 fd, n, done, ch, nodescr = 0;
+	int			 fd, n, done, ch, nodescr = 0, verbose = 0;
 	struct imsg		 imsg;
 	struct network_config	 net;
 	struct parse_result	*res;
@@ -128,8 +143,11 @@ main(int argc, char *argv[])
 	if ((res = parse(argc, argv)) == NULL)
 		exit(1);
 
-	if (res->action == IRRFILTER)
+	if (res->action == IRRFILTER) {
+		if (!(res->flags & (F_IPV4|F_IPV6)))
+			res->flags |= (F_IPV4|F_IPV6);
 		irr_main(res->as.as, res->flags, res->irr_outdir);
+	}
 
 	memcpy(&neighbor.addr, &res->peeraddr, sizeof(neighbor.addr));
 	strlcpy(neighbor.descr, res->peerdesc, sizeof(neighbor.descr));
@@ -164,15 +182,17 @@ main(int argc, char *argv[])
 		imsg_compose(ibuf, IMSG_CTL_SHOW_TERSE, 0, 0, -1, NULL, 0);
 		break;
 	case SHOW_FIB:
-		if (!res->addr.af) {
+		if (!res->addr.aid) {
 			struct buf	*msg;
+			sa_family_t	 af;
 
+			af = aid2af(res->aid);
 			if ((msg = imsg_create(ibuf, IMSG_CTL_KROUTE, 0, 0,
-			    sizeof(res->flags) + sizeof(res->af))) == NULL)
+			    sizeof(res->flags) + sizeof(af))) == NULL)
 				errx(1, "imsg_create failure");
 			if (imsg_add(msg, &res->flags, sizeof(res->flags)) ==
 			    -1 ||
-			    imsg_add(msg, &res->af, sizeof(res->af)) == -1)
+			    imsg_add(msg, &af, sizeof(af)) == -1)
 				errx(1, "imsg_add failure");
 			imsg_close(ibuf, msg);
 		} else
@@ -192,7 +212,7 @@ main(int argc, char *argv[])
 	case SHOW_NEIGHBOR_TIMERS:
 	case SHOW_NEIGHBOR_TERSE:
 		neighbor.show_timers = (res->action == SHOW_NEIGHBOR_TIMERS);
-		if (res->peeraddr.af || res->peerdesc[0])
+		if (res->peeraddr.aid || res->peerdesc[0])
 			imsg_compose(ibuf, IMSG_CTL_SHOW_NEIGHBOR, 0, 0, -1,
 			    &neighbor, sizeof(neighbor));
 		else
@@ -206,7 +226,7 @@ main(int argc, char *argv[])
 			memcpy(&ribreq.as, &res->as, sizeof(res->as));
 			type = IMSG_CTL_SHOW_RIB_AS;
 		}
-		if (res->addr.af) {
+		if (res->addr.aid) {
 			memcpy(&ribreq.prefix, &res->addr, sizeof(res->addr));
 			ribreq.prefixlen = res->prefixlen;
 			type = IMSG_CTL_SHOW_RIB_PREFIX;
@@ -220,7 +240,7 @@ main(int argc, char *argv[])
 		memcpy(&ribreq.neighbor, &neighbor,
 		    sizeof(ribreq.neighbor));
 		strlcpy(ribreq.rib, res->rib, sizeof(ribreq.rib));
-		ribreq.af = res->af;
+		ribreq.aid = res->aid;
 		ribreq.flags = res->flags;
 		imsg_compose(ibuf, type, 0, 0, -1, &ribreq, sizeof(ribreq));
 		if (!(res->flags & F_CTL_DETAIL))
@@ -290,12 +310,21 @@ main(int argc, char *argv[])
 		break;
 	case NETWORK_SHOW:
 		bzero(&ribreq, sizeof(ribreq));
-		ribreq.af = res->af;
+		ribreq.aid = res->aid;
 		strlcpy(ribreq.rib, res->rib, sizeof(ribreq.rib));
 		imsg_compose(ibuf, IMSG_CTL_SHOW_NETWORK, 0, 0, -1,
 		    &ribreq, sizeof(ribreq));
 		show_network_head();
 		break;
+	case LOG_VERBOSE:
+		verbose = 1;
+		/* FALLTHROUGH */
+	case LOG_BRIEF:
+		imsg_compose(ibuf, IMSG_CTL_LOG_VERBOSE, 0, 0, -1,
+		    &verbose, sizeof(verbose));
+		printf("logging request sent.\n");
+		done = 1;
+		break;
 	}
 
 	while (ibuf->w.queued)
@@ -304,13 +333,13 @@ main(int argc, char *argv[])
 
 	while (!done) {
 		if ((n = imsg_read(ibuf)) == -1)
-			errx(1, "imsg_read error");
+			err(1, "imsg_read error");
 		if (n == 0)
 			errx(1, "pipe closed");
 
 		while (!done) {
 			if ((n = imsg_get(ibuf, &imsg)) == -1)
-				errx(1, "imsg_get error");
+				err(1, "imsg_get error");
 			if (n == 0)
 				break;
 
@@ -373,6 +402,8 @@ main(int argc, char *argv[])
 			case NETWORK_REMOVE:
 			case NETWORK_FLUSH:
 			case IRRFILTER:
+			case LOG_VERBOSE:
+			case LOG_BRIEF:
 				break;
 			}
 			imsg_free(&imsg);
@@ -398,8 +429,8 @@ fmt_peer(const char *descr, const struct
 	}
 
 	ip = log_addr(remote_addr);
-	if (masklen != -1 && ((remote_addr->af == AF_INET && masklen != 32) ||
-	    (remote_addr->af == AF_INET6 && masklen != 128))) {
+	if (masklen != -1 && ((remote_addr->aid == AID_INET && masklen != 32) ||
+	    (remote_addr->aid == AID_INET6 && masklen != 128))) {
 		if (asprintf(&p, "%s/%u", ip, masklen) == -1)
 			err(1, NULL);
 	} else {
@@ -521,13 +552,15 @@ show_neighbor_msg(struct imsg *imsg, enu
 	struct ctl_timer	*t;
 	struct in_addr		 ina;
 	char			 buf[NI_MAXHOST], pbuf[NI_MAXSERV], *s;
+	int			 hascapamp = 0;
+	u_int8_t		 i;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_NEIGHBOR:
 		p = imsg->data;
-		if ((p->conf.remote_addr.af == AF_INET &&
+		if ((p->conf.remote_addr.aid == AID_INET &&
 		    p->conf.remote_masklen != 32) ||
-		    (p->conf.remote_addr.af == AF_INET6 &&
+		    (p->conf.remote_addr.aid == AID_INET6 &&
 		    p->conf.remote_masklen != 128)) {
 			if (asprintf(&s, "%s/%u",
 			    log_addr(&p->conf.remote_addr),
@@ -549,6 +582,10 @@ show_neighbor_msg(struct imsg *imsg, enu
 			printf(", Template");
 		if (p->conf.cloned)
 			printf(", Cloned");
+		if (p->conf.passive)
+			printf(", Passive");
+		if (p->conf.ebgp && p->conf.distance > 1)
+			printf(", Multihop (%u)", (int)p->conf.distance);
 		printf("\n");
 		if (p->conf.descr[0])
 			printf(" Description: %s\n", p->conf.descr);
@@ -563,17 +600,16 @@ show_neighbor_msg(struct imsg *imsg, enu
 		printf("  Last read %s, holdtime %us, keepalive interval %us\n",
 		    fmt_timeframe(p->stats.last_read),
 		    p->holdtime, p->holdtime/3);
-		if (p->capa.peer.mp_v4 || p->capa.peer.mp_v6 ||
-		    p->capa.peer.refresh || p->capa.peer.restart ||
-		    p->capa.peer.as4byte) {
+		for (i = 0; i < AID_MAX; i++)
+			if (p->capa.peer.mp[i])
+				hascapamp = 1;
+		if (hascapamp || p->capa.peer.refresh ||
+		    p->capa.peer.restart || p->capa.peer.as4byte) {
 			printf("  Neighbor capabilities:\n");
-			if (p->capa.peer.mp_v4) {
-				printf("    Multiprotocol extensions: IPv4");
-				print_neighbor_capa_mp_safi(p->capa.peer.mp_v4);
-			}
-			if (p->capa.peer.mp_v6) {
-				printf("    Multiprotocol extensions: IPv6");
-				print_neighbor_capa_mp_safi(p->capa.peer.mp_v6);
+			if (hascapamp) {
+				printf("    Multiprotocol extensions: ");
+				print_neighbor_capa_mp(p);
+				printf("\n");
 			}
 			if (p->capa.peer.refresh)
 				printf("    Route Refresh\n");
@@ -633,20 +669,16 @@ show_neighbor_msg(struct imsg *imsg, enu
 }
 
 void
-print_neighbor_capa_mp_safi(u_int8_t safi)
+print_neighbor_capa_mp(struct peer *p)
 {
-	switch (safi) {
-	case SAFI_UNICAST:
-		printf(" Unicast");
-		break;
-	case SAFI_MULTICAST:
-		printf(" Multicast");
-		break;
-	default:
-		printf(" unknown (%u)", safi);
-		break;
-	}
-	printf("\n");
+	int		comma;
+	u_int8_t	i;
+
+	for (i = 0, comma = 0; i < AID_MAX; i++)
+		if (p->capa.peer.mp[i]) {
+			printf("%s%s", comma ? ", " : "", aid2str(i));
+			comma = 1;
+		}
 }
 
 void
@@ -680,7 +712,7 @@ print_neighbor_msgstats(struct peer *p)
 }
 
 void
-print_timer(const char *name, timer_t d)
+print_timer(const char *name, time_t d)
 {
 	printf("  %-20s ", name);
 
@@ -848,35 +880,70 @@ show_fib_msg(struct imsg *imsg)
 void
 show_nexthop_head(void)
 {
-	printf("%-20s %-10s\n", "Nexthop", "State");
+	printf("Flags: * = nexthop valid\n");
+	printf("\n  %-15s %-19s%-4s %-15s %-20s\n", "Nexthop", "Route",
+	     "Prio", "Gateway", "Iface");
 }
 
 int
 show_nexthop_msg(struct imsg *imsg)
 {
 	struct ctl_show_nexthop	*p;
-	int			 ifms_type;
+	struct kroute		*k;
+	struct kroute6		*k6;
+	char			*s;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_NEXTHOP:
 		p = imsg->data;
-		printf("%-20s %-10s", log_addr(&p->addr),
-		    p->valid ? "valid" : "invalid");
+		printf("%s %-15s ", p->valid ? "*" : " ", log_addr(&p->addr));
+		if (!p->krvalid) {
+			printf("\n");
+			return (0);
+		}
+		switch (p->addr.aid) {
+		case AID_INET:
+			k = &p->kr.kr4;
+			if (asprintf(&s, "%s/%u", inet_ntoa(k->prefix),
+			    k->prefixlen) == -1)
+				err(1, NULL);
+			printf("%-20s", s);
+			free(s);
+			printf("%3i %-15s ", k->priority,
+			    k->flags & F_CONNECTED ? "connected" :
+			    inet_ntoa(k->nexthop));
+			break;
+		case AID_INET6:
+			k6 = &p->kr.kr6;
+			if (asprintf(&s, "%s/%u", log_in6addr(&k6->prefix),
+			    k6->prefixlen) == -1)
+				err(1, NULL);
+			printf("%-20s", s);
+			free(s);
+			printf("%3i %-15s ", k6->priority,
+			    k6->flags & F_CONNECTED ? "connected" :
+			    log_in6addr(&k6->nexthop));
+			break;
+		default:
+			printf("unknown address family\n");
+			return (0);
+		}
 		if (p->kif.ifname[0]) {
-			printf("%-8s", p->kif.ifname);
-			if (p->kif.flags & IFF_UP) {
-				printf("UP");
-				ifms_type = ift2ifm(p->kif.media_type);
-				if (ifms_type != 0)
-					printf(", %s, %s",
-					    get_media_descr(ifms_type),
-					    get_linkstate(ifms_type,
-					    p->kif.link_state));
-				if (p->kif.baudrate) {
-					printf(", ");
-					print_baudrate(p->kif.baudrate);
-				}
-			}
+			char *s1;
+			if (p->kif.baudrate) {
+				if (asprintf(&s1, ", %s",
+				    get_baudrate(p->kif.baudrate,
+				    "bps")) == -1)
+					err(1, NULL);
+			} else if (asprintf(&s1, ", %s", get_linkstate(
+			    p->kif.media_type, p->kif.link_state)) == -1)
+					err(1, NULL);
+			if (asprintf(&s, "%s (%s%s)", p->kif.ifname, 
+			    p->kif.flags & IFF_UP ? "UP" : "DOWN", s1) == -1)
+				err(1, NULL);
+			printf("%-15s", s);
+			free(s1);
+			free(s);
 		}
 		printf("\n");
 		break;
@@ -898,9 +965,8 @@ show_interface_head(void)
 	    "Link state");
 }
 
-const int	ifm_status_valid_list[] = IFM_STATUS_VALID_LIST;
-const struct ifmedia_status_description
-		ifm_status_descriptions[] = IFM_STATUS_DESCRIPTIONS;
+const struct if_status_description
+		if_status_descriptions[] = LINK_STATE_DESCRIPTIONS;
 const struct ifmedia_description
 		ifm_type_descriptions[] = IFM_TYPE_DESCRIPTIONS;
 
@@ -936,36 +1002,36 @@ get_media_descr(int media_type)
 const char *
 get_linkstate(int media_type, int link_state)
 {
-	const struct ifmedia_status_description	*p;
-	int					 i;
-
-	if (link_state == LINK_STATE_UNKNOWN)
-		return ("unknown");
+	const struct if_status_description *p;
+	static char buf[8];
 
-	for (i = 0; ifm_status_valid_list[i] != 0; i++)
-		for (p = ifm_status_descriptions; p->ifms_valid != 0; p++) {
-			if (p->ifms_type != media_type ||
-			    p->ifms_valid != ifm_status_valid_list[i])
-				continue;
-			if (LINK_STATE_IS_UP(link_state))
-				return (p->ifms_string[1]);
-			return (p->ifms_string[0]);
-		}
-
-	return ("unknown link state");
+	for (p = if_status_descriptions; p->ifs_string != NULL; p++) {
+		if (LINK_STATE_DESC_MATCH(p, media_type, link_state))
+			return (p->ifs_string);
+	}
+	snprintf(buf, sizeof(buf), "[#%d]", link_state);
+	return (buf);
 }
 
-void
-print_baudrate(u_int64_t baudrate)
+const char *
+get_baudrate(u_int64_t baudrate, char *unit)
 {
+	static char bbuf[16];
+
 	if (baudrate > IF_Gbps(1))
-		printf("%llu GBit/s", baudrate / IF_Gbps(1));
+		snprintf(bbuf, sizeof(bbuf), "%llu G%s",
+		    baudrate / IF_Gbps(1), unit);
 	else if (baudrate > IF_Mbps(1))
-		printf("%llu MBit/s", baudrate / IF_Mbps(1));
+		snprintf(bbuf, sizeof(bbuf), "%llu M%s",
+		    baudrate / IF_Mbps(1), unit);
 	else if (baudrate > IF_Kbps(1))
-		printf("%llu KBit/s", baudrate / IF_Kbps(1));
+		snprintf(bbuf, sizeof(bbuf), "%llu K%s",
+		    baudrate / IF_Kbps(1), unit);
 	else
-		printf("%llu Bit/s", baudrate);
+		snprintf(bbuf, sizeof(bbuf), "%llu %s",
+		    baudrate, unit);
+
+	return (bbuf);
 }
 
 int
@@ -982,17 +1048,12 @@ show_interface_msg(struct imsg *imsg)
 		printf("%-15s", k->flags & IFF_UP ? "UP" : "");
 
 		if ((ifms_type = ift2ifm(k->media_type)) != 0)
-			printf("%s, %s", get_media_descr(ifms_type),
-			    get_linkstate(ifms_type, k->link_state));
-		else if (k->link_state == LINK_STATE_UNKNOWN)
-			printf("unknown");
-		else
-			printf("link state %u", k->link_state);
+			printf("%s, ", get_media_descr(ifms_type));
 
-		if (k->link_state != LINK_STATE_DOWN && k->baudrate > 0) {
-			printf(", ");
-			print_baudrate(k->baudrate);
-		}
+		printf("%s", get_linkstate(k->media_type, k->link_state));
+
+		if (k->link_state != LINK_STATE_DOWN && k->baudrate > 0)
+			printf(", %s", get_baudrate(k->baudrate, "Bit/s"));
 		printf("\n");
 		break;
 	case IMSG_CTL_END:
@@ -1011,7 +1072,7 @@ show_rib_summary_head(void)
 	printf(
 	    "flags: * = Valid, > = Selected, I = via IBGP, A = Announced\n");
 	printf("origin: i = IGP, e = EGP, ? = Incomplete\n\n");
-	printf("%-5s %-20s%-15s  %5s %5s %s\n", "flags", "destination",
+	printf("%-5s %-20s %-15s  %5s %5s %s\n", "flags", "destination",
 	    "gateway", "lpref", "med", "aspath origin");
 }
 
@@ -1085,7 +1146,7 @@ show_rib_summary_msg(struct imsg *imsg)
 		memcpy(&rib, imsg->data, sizeof(rib));
 
 		print_prefix(&rib.prefix, rib.prefixlen, rib.flags);
-		printf("%-15s ", log_addr(&rib.exit_nexthop));
+		printf(" %-15s ", log_addr(&rib.exit_nexthop));
 
 		printf(" %5u %5u ", rib.local_pref, rib.med);
 
@@ -1190,7 +1251,7 @@ show_rib_detail_msg(struct imsg *imsg, i
 			memcpy(&as, data, sizeof(as));
 			memcpy(&id, data + sizeof(as), sizeof(id));
 			printf("    Aggregator: %s [%s]\n", 
-			    log_as(htonl(as)), inet_ntoa(id));
+			    log_as(ntohl(as)), inet_ntoa(id));
 			break;
 		case ATTR_ORIGINATOR_ID:
 			memcpy(&id, data, sizeof(id));
@@ -1236,22 +1297,27 @@ fmt_mem(int64_t num)
 	return (buf);
 }
 
+size_t  pt_sizes[AID_MAX] = AID_PTSIZE;
+
 int
 show_rib_memory_msg(struct imsg *imsg)
 {
 	struct rde_memstats	stats;
+	size_t			pts = 0;
+	int			i;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_RIB_MEM:
 		memcpy(&stats, imsg->data, sizeof(stats));
 		printf("RDE memory statistics\n");
-		printf("%10lld IPv4 network entries using %s of memory\n",
-		    (long long)stats.pt4_cnt, fmt_mem(stats.pt4_cnt *
-		    sizeof(struct pt_entry4)));
-		if (stats.pt6_cnt != 0)
-			printf("%10lld IPv6 network entries using "
-			    "%s of memory\n", (long long)stats.pt6_cnt,
-			    fmt_mem(stats.pt6_cnt * sizeof(struct pt_entry6)));
+		for (i = 0; i < AID_MAX; i++) {
+			if (stats.pt_cnt[i] == 0)
+				continue;
+			pts += stats.pt_cnt[i] * pt_sizes[i];
+			printf("%10lld %s network entries using %s of memory\n",
+			    (long long)stats.pt_cnt[i], aid_vals[i].name,
+			    fmt_mem(stats.pt_cnt[i] * pt_sizes[i]));
+		}
 		printf("%10lld rib entries using %s of memory\n",
 		    (long long)stats.rib_cnt, fmt_mem(stats.rib_cnt *
 		    sizeof(struct rib_entry)));
@@ -1272,9 +1338,7 @@ show_rib_memory_msg(struct imsg *imsg)
 		    (long long)stats.attr_refs);
 		printf("%10lld BGP attributes using %s of memory\n",
 		    (long long)stats.attr_dcnt, fmt_mem(stats.attr_data));
-		printf("RIB using %s of memory\n", fmt_mem(
-		    stats.pt4_cnt * sizeof(struct pt_entry4) +
-		    stats.pt6_cnt * sizeof(struct pt_entry6) +
+		printf("RIB using %s of memory\n", fmt_mem(pts +
 		    stats.prefix_cnt * sizeof(struct prefix) +
 		    stats.rib_cnt * sizeof(struct rib_entry) +
 		    stats.path_cnt * sizeof(struct rde_aspath) +
@@ -1328,30 +1392,6 @@ show_community(u_char *data, u_int16_t l
 	}
 }
 
-const char *
-get_ext_subtype(u_int8_t type)
-{
-	static char etype[6];
-
-	switch (type) {
-	case EXT_COMMUNITY_ROUTE_TGT:
-		return "rt";	/* route target */
-	case EXT_CUMMUNITY_ROUTE_ORIG:
-		return "soo";	/* source of origin */
-	case EXT_COMMUNITY_OSPF_DOM_ID:
-		return "odi";	/* ospf domain id */
-	case EXT_COMMUNITY_OSPF_RTR_TYPE:
-		return "ort";	/* ospf route type */
-	case EXT_COMMUNITY_OSPF_RTR_ID:
-		return "ori";	/* ospf router id */
-	case EXT_COMMUNITY_BGP_COLLECT:
-		return "bdc";	/* bgp data collection */
-	default:
-		snprintf(etype, sizeof(etype), "[%i]", (int)type);
-		return etype;
-	}
-}
-
 void
 show_ext_community(u_char *data, u_int16_t len)
 {
@@ -1372,24 +1412,25 @@ show_ext_community(u_char *data, u_int16
 		case EXT_COMMUNITY_TWO_AS:
 			memcpy(&as2, data + i + 2, sizeof(as2));
 			memcpy(&u32, data + i + 4, sizeof(u32));
-			printf("%s %hu:%u", get_ext_subtype(subtype), as2, u32);
+			printf("%s %s:%u", log_ext_subtype(subtype),
+			    log_as(ntohs(as2)), ntohl(u32));
 			break;
 		case EXT_COMMUNITY_IPV4:
 			memcpy(&ip, data + i + 2, sizeof(ip));
 			memcpy(&u16, data + i + 6, sizeof(u16));
-			printf("%s %s:%hu", get_ext_subtype(subtype),
-			    inet_ntoa(ip), u16);
+			printf("%s %s:%hu", log_ext_subtype(subtype),
+			    inet_ntoa(ip), ntohs(u16));
 			break;
 		case EXT_COMMUNITY_FOUR_AS:
 			memcpy(&as4, data + i + 2, sizeof(as4));
 			memcpy(&u16, data + i + 6, sizeof(u16));
-			printf("%s %s:%hu", get_ext_subtype(subtype),
-			    log_as(as4), u16);
+			printf("%s %s:%hu", log_ext_subtype(subtype),
+			    log_as(ntohl(as4)), ntohs(u16));
 			break;
 		case EXT_COMMUNITY_OPAQUE:
 			memcpy(&ext, data + i, sizeof(ext));
 			ext = betoh64(ext) & 0xffffffffffffLL;
-			printf("%s 0x%llx", get_ext_subtype(subtype), ext); 
+			printf("%s 0x%llx", log_ext_subtype(subtype), ext); 
 			break;
 		default:
 			memcpy(&ext, data + i, sizeof(ext));
