Index: bgpctl/bgpctl.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/bgpctl.c,v
retrieving revision 1.1.1.7
retrieving revision 1.10
diff -u -p -r1.1.1.7 -r1.10
--- bgpctl/bgpctl.c	14 Feb 2010 20:20:14 -0000	1.1.1.7
+++ bgpctl/bgpctl.c	8 Dec 2012 20:17:55 -0000	1.10
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpctl.c,v 1.142 2009/06/06 06:33:15 eric Exp $ */
+/*	$OpenBSD: bgpctl.c,v 1.167 2012/11/15 19:55:08 sthen Exp $ */
 
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
@@ -37,6 +49,11 @@
 #include "log.h"
 #include "parser.h"
 #include "irrfilter.h"
+#include "mrtparser.h"
+
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
 
 enum neighbor_views {
 	NV_DEFAULT,
@@ -50,12 +67,14 @@ int		 show_summary_msg(struct imsg *, in
 int		 show_summary_terse_msg(struct imsg *, int);
 int		 show_neighbor_terse(struct imsg *);
 int		 show_neighbor_msg(struct imsg *, enum neighbor_views);
-void		 print_neighbor_capa_mp_safi(u_int8_t);
+void		 print_neighbor_capa_mp(struct peer *);
+void		 print_neighbor_capa_restart(struct peer *);
 void		 print_neighbor_msgstats(struct peer *);
 void		 print_timer(const char *, time_t);
 static char	*fmt_timeframe(time_t t);
 static char	*fmt_timeframe_core(time_t t);
 void		 show_fib_head(void);
+void		 show_fib_tables_head(void);
 void		 show_network_head(void);
 void		 show_fib_flags(u_int16_t);
 int		 show_fib_msg(struct imsg *);
@@ -65,7 +84,7 @@ void		 show_interface_head(void);
 int		 ift2ifm(int);
 const char *	 get_media_descr(int);
 const char *	 get_linkstate(int, int);
-void		 print_baudrate(u_int64_t);
+const char *	 get_baudrate(u_int64_t, char *);
 int		 show_interface_msg(struct imsg *);
 void		 show_rib_summary_head(void);
 void		 print_prefix(struct bgpd_addr *, u_int8_t, u_int8_t);
@@ -73,16 +92,25 @@ const char *	 print_origin(u_int8_t, int
 void		 print_flags(u_int8_t, int);
 int		 show_rib_summary_msg(struct imsg *);
 int		 show_rib_detail_msg(struct imsg *, int);
+void		 show_rib_brief(struct ctl_show_rib *, u_char *);
+void		 show_rib_detail(struct ctl_show_rib *, u_char *, int);
+void		 show_attr(void *, u_int16_t);
 void		 show_community(u_char *, u_int16_t);
-const char	*get_ext_subtype(u_int8_t);
 void		 show_ext_community(u_char *, u_int16_t);
 char		*fmt_mem(int64_t);
 int		 show_rib_memory_msg(struct imsg *);
 void		 send_filterset(struct imsgbuf *, struct filter_set_head *);
 static const char	*get_errstr(u_int8_t, u_int8_t);
 int		 show_result(struct imsg *);
+void		 show_mrt_dump(struct mrt_rib *, struct mrt_peer *, void *);
+void		 network_mrt_dump(struct mrt_rib *, struct mrt_peer *, void *);
+void		 show_mrt_state(struct mrt_bgp_state *, void *);
+void		 show_mrt_msg(struct mrt_bgp_msg *, void *);
+void		 mrt_to_bgpd_addr(union mrt_addr *, struct bgpd_addr *);
 
 struct imsgbuf	*ibuf;
+struct mrt_parser show_mrt = { show_mrt_dump, show_mrt_state, show_mrt_msg };
+struct mrt_parser net_mrt = { network_mrt_dump, NULL, NULL };
 
 __dead void
 usage(void)
@@ -98,7 +126,7 @@ int
 main(int argc, char *argv[])
 {
 	struct sockaddr_un	 sun;
-	int			 fd, n, done, ch, nodescr = 0;
+	int			 fd, n, done, ch, nodescr = 0, verbose = 0;
 	struct imsg		 imsg;
 	struct network_config	 net;
 	struct parse_result	*res;
@@ -128,8 +156,11 @@ main(int argc, char *argv[])
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
@@ -154,7 +185,7 @@ main(int argc, char *argv[])
 	case NONE:
 	case IRRFILTER:
 		usage();
-		/* not reached */
+		/* NOTREACHED */
 	case SHOW:
 	case SHOW_SUMMARY:
 		imsg_compose(ibuf, IMSG_CTL_SHOW_NEIGHBOR, 0, 0, -1, NULL, 0);
@@ -164,24 +195,32 @@ main(int argc, char *argv[])
 		imsg_compose(ibuf, IMSG_CTL_SHOW_TERSE, 0, 0, -1, NULL, 0);
 		break;
 	case SHOW_FIB:
-		if (!res->addr.af) {
-			struct buf	*msg;
-
-			if ((msg = imsg_create(ibuf, IMSG_CTL_KROUTE, 0, 0,
-			    sizeof(res->flags) + sizeof(res->af))) == NULL)
+		if (!res->addr.aid) {
+			struct ibuf	*msg;
+			sa_family_t	 af;
+
+			af = aid2af(res->aid);
+			if ((msg = imsg_create(ibuf, IMSG_CTL_KROUTE,
+			    res->rtableid, 0, sizeof(res->flags) +
+			    sizeof(af))) == NULL)
 				errx(1, "imsg_create failure");
 			if (imsg_add(msg, &res->flags, sizeof(res->flags)) ==
 			    -1 ||
-			    imsg_add(msg, &res->af, sizeof(res->af)) == -1)
+			    imsg_add(msg, &af, sizeof(af)) == -1)
 				errx(1, "imsg_add failure");
 			imsg_close(ibuf, msg);
 		} else
-			imsg_compose(ibuf, IMSG_CTL_KROUTE_ADDR, 0, 0, -1,
-			    &res->addr, sizeof(res->addr));
+			imsg_compose(ibuf, IMSG_CTL_KROUTE_ADDR, res->rtableid,
+			    0, -1, &res->addr, sizeof(res->addr));
 		show_fib_head();
 		break;
+	case SHOW_FIB_TABLES:
+		imsg_compose(ibuf, IMSG_CTL_SHOW_FIB_TABLES, 0, 0, -1, NULL, 0);
+		show_fib_tables_head();
+		break;
 	case SHOW_NEXTHOP:
-		imsg_compose(ibuf, IMSG_CTL_SHOW_NEXTHOP, 0, 0, -1, NULL, 0);
+		imsg_compose(ibuf, IMSG_CTL_SHOW_NEXTHOP, res->rtableid, 0, -1,
+		    NULL, 0);
 		show_nexthop_head();
 		break;
 	case SHOW_INTERFACE:
@@ -192,7 +231,7 @@ main(int argc, char *argv[])
 	case SHOW_NEIGHBOR_TIMERS:
 	case SHOW_NEIGHBOR_TERSE:
 		neighbor.show_timers = (res->action == SHOW_NEIGHBOR_TIMERS);
-		if (res->peeraddr.af || res->peerdesc[0])
+		if (res->peeraddr.aid || res->peerdesc[0])
 			imsg_compose(ibuf, IMSG_CTL_SHOW_NEIGHBOR, 0, 0, -1,
 			    &neighbor, sizeof(neighbor));
 		else
@@ -206,7 +245,7 @@ main(int argc, char *argv[])
 			memcpy(&ribreq.as, &res->as, sizeof(res->as));
 			type = IMSG_CTL_SHOW_RIB_AS;
 		}
-		if (res->addr.af) {
+		if (res->addr.aid) {
 			memcpy(&ribreq.prefix, &res->addr, sizeof(res->addr));
 			ribreq.prefixlen = res->prefixlen;
 			type = IMSG_CTL_SHOW_RIB_PREFIX;
@@ -217,15 +256,35 @@ main(int argc, char *argv[])
 			    sizeof(res->community));
 			type = IMSG_CTL_SHOW_RIB_COMMUNITY;
 		}
-		memcpy(&ribreq.neighbor, &neighbor,
-		    sizeof(ribreq.neighbor));
+		memcpy(&ribreq.neighbor, &neighbor, sizeof(ribreq.neighbor));
 		strlcpy(ribreq.rib, res->rib, sizeof(ribreq.rib));
-		ribreq.af = res->af;
+		ribreq.aid = res->aid;
 		ribreq.flags = res->flags;
 		imsg_compose(ibuf, type, 0, 0, -1, &ribreq, sizeof(ribreq));
 		if (!(res->flags & F_CTL_DETAIL))
 			show_rib_summary_head();
 		break;
+	case SHOW_MRT:
+		close(fd);
+		bzero(&ribreq, sizeof(ribreq));
+		if (res->as.type != AS_NONE)
+			memcpy(&ribreq.as, &res->as, sizeof(res->as));
+		if (res->addr.aid) {
+			memcpy(&ribreq.prefix, &res->addr, sizeof(res->addr));
+			ribreq.prefixlen = res->prefixlen;
+		}
+		if (res->community.as != COMMUNITY_UNSET &&
+		    res->community.type != COMMUNITY_UNSET)
+			memcpy(&ribreq.community, &res->community,
+			    sizeof(res->community));
+		memcpy(&ribreq.neighbor, &neighbor, sizeof(ribreq.neighbor));
+		ribreq.aid = res->aid;
+		ribreq.flags = res->flags;
+		show_mrt.arg = &ribreq;
+		if (!(res->flags & F_CTL_DETAIL))
+			show_rib_summary_head();
+		mrt_parse(res->mrtfd, &show_mrt, 1);
+		exit(0);
 	case SHOW_RIB_MEM:
 		imsg_compose(ibuf, IMSG_CTL_SHOW_RIB_MEM, 0, 0, -1, NULL, 0);
 		break;
@@ -237,12 +296,14 @@ main(int argc, char *argv[])
 		errx(1, "action==FIB");
 		break;
 	case FIB_COUPLE:
-		imsg_compose(ibuf, IMSG_CTL_FIB_COUPLE, 0, 0, -1, NULL, 0);
+		imsg_compose(ibuf, IMSG_CTL_FIB_COUPLE, res->rtableid, 0, -1,
+		    NULL, 0);
 		printf("couple request sent.\n");
 		done = 1;
 		break;
 	case FIB_DECOUPLE:
-		imsg_compose(ibuf, IMSG_CTL_FIB_DECOUPLE, 0, 0, -1, NULL, 0);
+		imsg_compose(ibuf, IMSG_CTL_FIB_DECOUPLE, res->rtableid, 0, -1,
+		    NULL, 0);
 		printf("decouple request sent.\n");
 		done = 1;
 		break;
@@ -290,12 +351,40 @@ main(int argc, char *argv[])
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
+	case NETWORK_MRT:
+		bzero(&ribreq, sizeof(ribreq));
+		if (res->as.type != AS_NONE)
+			memcpy(&ribreq.as, &res->as, sizeof(res->as));
+		if (res->addr.aid) {
+			memcpy(&ribreq.prefix, &res->addr, sizeof(res->addr));
+			ribreq.prefixlen = res->prefixlen;
+		}
+		if (res->community.as != COMMUNITY_UNSET &&
+		    res->community.type != COMMUNITY_UNSET)
+			memcpy(&ribreq.community, &res->community,
+			    sizeof(res->community));
+		memcpy(&ribreq.neighbor, &neighbor, sizeof(ribreq.neighbor));
+		ribreq.aid = res->aid;
+		ribreq.flags = res->flags;
+		net_mrt.arg = &ribreq;
+		mrt_parse(res->mrtfd, &net_mrt, 1);
+		done = 1;
+		break;
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
@@ -304,13 +393,13 @@ main(int argc, char *argv[])
 
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
 
@@ -329,6 +418,8 @@ main(int argc, char *argv[])
 				done = show_summary_terse_msg(&imsg, nodescr);
 				break;
 			case SHOW_FIB:
+			case SHOW_FIB_TABLES:
+			case NETWORK_SHOW:
 				done = show_fib_msg(&imsg);
 				break;
 			case SHOW_NEXTHOP:
@@ -356,9 +447,6 @@ main(int argc, char *argv[])
 			case SHOW_RIB_MEM:
 				done = show_rib_memory_msg(&imsg);
 				break;
-			case NETWORK_SHOW:
-				done = show_fib_msg(&imsg);
-				break;
 			case NEIGHBOR:
 			case NEIGHBOR_UP:
 			case NEIGHBOR_DOWN:
@@ -373,6 +461,10 @@ main(int argc, char *argv[])
 			case NETWORK_REMOVE:
 			case NETWORK_FLUSH:
 			case IRRFILTER:
+			case LOG_VERBOSE:
+			case LOG_BRIEF:
+			case SHOW_MRT:
+			case NETWORK_MRT:
 				break;
 			}
 			imsg_free(&imsg);
@@ -398,8 +490,8 @@ fmt_peer(const char *descr, const struct
 	}
 
 	ip = log_addr(remote_addr);
-	if (masklen != -1 && ((remote_addr->af == AF_INET && masklen != 32) ||
-	    (remote_addr->af == AF_INET6 && masklen != 128))) {
+	if (masklen != -1 && ((remote_addr->aid == AID_INET && masklen != 32) ||
+	    (remote_addr->aid == AID_INET6 && masklen != 128))) {
 		if (asprintf(&p, "%s/%u", ip, masklen) == -1)
 			err(1, NULL);
 	} else {
@@ -430,7 +522,7 @@ show_summary_msg(struct imsg *imsg, int 
 		    p->conf.remote_masklen, nodescr);
 		if (strlen(s) >= 20)
 			s[20] = 0;
-		printf("%-20s %8s %10llu %10llu %5u %-8s ",
+		printf("%-20s %8s %10" PRIu64 " %10" PRIu64 " %5u %-8s ",
 		    s, log_as(p->conf.remote_as),
 		    p->stats.msg_rcvd_open + p->stats.msg_rcvd_notification +
 		    p->stats.msg_rcvd_update + p->stats.msg_rcvd_keepalive +
@@ -492,8 +584,8 @@ show_neighbor_terse(struct imsg *imsg)
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_NEIGHBOR:
 		p = imsg->data;
-		printf("%llu %llu %llu %llu %llu %llu %llu "
-		    "%llu %llu %llu %u %u %llu %llu %llu %llu\n",
+		printf("%" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " "
+		    "%" PRIu64 " %" PRIu64 " %" PRIu64 " %u %u %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n",
 		    p->stats.msg_sent_open, p->stats.msg_rcvd_open,
 		    p->stats.msg_sent_notification,
 		    p->stats.msg_rcvd_notification,
@@ -521,13 +613,15 @@ show_neighbor_msg(struct imsg *imsg, enu
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
@@ -549,9 +643,20 @@ show_neighbor_msg(struct imsg *imsg, enu
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
+		if (p->conf.max_prefix) {
+			printf(" Max-prefix: %u", p->conf.max_prefix);
+			if (p->conf.max_prefix_restart)
+				printf(" (restart %u)",
+				    p->conf.max_prefix_restart);
+			printf("\n");
+		}
 		printf("  BGP version 4, remote router-id %s\n",
 		    inet_ntoa(ina));
 		printf("  BGP state = %s", statenames[p->state]);
@@ -563,22 +668,24 @@ show_neighbor_msg(struct imsg *imsg, enu
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
+		    p->capa.peer.grestart.restart || p->capa.peer.as4byte) {
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
-			if (p->capa.peer.restart)
-				printf("    Graceful Restart\n");
+			if (p->capa.peer.grestart.restart) {
+				printf("    Graceful Restart");
+				print_neighbor_capa_restart(p);
+				printf("\n");
+			}
 			if (p->capa.peer.as4byte)
 				printf("    4-byte AS numbers\n");
 		}
@@ -633,20 +740,38 @@ show_neighbor_msg(struct imsg *imsg, enu
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
+}
+
+void
+print_neighbor_capa_restart(struct peer *p)
+{
+	int		comma;
+	u_int8_t	i;
+
+	if (p->capa.peer.grestart.timeout)
+		printf(": Timeout: %d, ", p->capa.peer.grestart.timeout);
+	for (i = 0, comma = 0; i < AID_MAX; i++)
+		if (p->capa.peer.grestart.flags[i] & CAPA_GR_PRESENT) {
+			if (!comma &&
+			    p->capa.peer.grestart.flags[i] & CAPA_GR_RESTART)
+				printf("restarted, ");
+			if (comma)
+				printf(", ");
+			printf("%s", aid2str(i));
+			if (p->capa.peer.grestart.flags[i] & CAPA_GR_FORWARD)
+				printf(" (preserved)");
+			comma = 1;
+		}
 }
 
 void
@@ -654,17 +779,17 @@ print_neighbor_msgstats(struct peer *p)
 {
 	printf("  Message statistics:\n");
 	printf("  %-15s %-10s %-10s\n", "", "Sent", "Received");
-	printf("  %-15s %10llu %10llu\n", "Opens",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Opens",
 	    p->stats.msg_sent_open, p->stats.msg_rcvd_open);
-	printf("  %-15s %10llu %10llu\n", "Notifications",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Notifications",
 	    p->stats.msg_sent_notification, p->stats.msg_rcvd_notification);
-	printf("  %-15s %10llu %10llu\n", "Updates",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Updates",
 	    p->stats.msg_sent_update, p->stats.msg_rcvd_update);
-	printf("  %-15s %10llu %10llu\n", "Keepalives",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Keepalives",
 	    p->stats.msg_sent_keepalive, p->stats.msg_rcvd_keepalive);
-	printf("  %-15s %10llu %10llu\n", "Route Refresh",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Route Refresh",
 	    p->stats.msg_sent_rrefresh, p->stats.msg_rcvd_rrefresh);
-	printf("  %-15s %10llu %10llu\n\n", "Total",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n\n", "Total",
 	    p->stats.msg_sent_open + p->stats.msg_sent_notification +
 	    p->stats.msg_sent_update + p->stats.msg_sent_keepalive +
 	    p->stats.msg_sent_rrefresh,
@@ -673,14 +798,16 @@ print_neighbor_msgstats(struct peer *p)
 	    p->stats.msg_rcvd_rrefresh);
 	printf("  Update statistics:\n");
 	printf("  %-15s %-10s %-10s\n", "", "Sent", "Received");
-	printf("  %-15s %10llu %10llu\n", "Updates",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Updates",
 	    p->stats.prefix_sent_update, p->stats.prefix_rcvd_update);
-	printf("  %-15s %10llu %10llu\n", "Withdraws",
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "Withdraws",
 	    p->stats.prefix_sent_withdraw, p->stats.prefix_rcvd_withdraw);
+	printf("  %-15s %10" PRIu64 " %10" PRIu64 "\n", "End-of-Rib",
+	    p->stats.prefix_sent_eor, p->stats.prefix_rcvd_eor);
 }
 
 void
-print_timer(const char *name, timer_t d)
+print_timer(const char *name, time_t d)
 {
 	printf("  %-20s ", name);
 
@@ -745,6 +872,12 @@ show_fib_head(void)
 }
 
 void
+show_fib_tables_head(void)
+{
+	printf("%-5s %-20s %-8s\n", "Table", "Description", "State");
+}
+
+void
 show_network_head(void)
 {
 	printf("flags: S = Static\n");
@@ -788,56 +921,44 @@ show_fib_flags(u_int16_t flags)
 int
 show_fib_msg(struct imsg *imsg)
 {
-	struct kroute		*k;
-	struct kroute6		*k6;
+	struct kroute_full	*kf;
+	struct ktable		*kt;
 	char			*p;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_KROUTE:
 	case IMSG_CTL_SHOW_NETWORK:
-		if (imsg->hdr.len < IMSG_HEADER_SIZE + sizeof(struct kroute))
+		if (imsg->hdr.len < IMSG_HEADER_SIZE + sizeof(*kf))
 			errx(1, "wrong imsg len");
-		k = imsg->data;
+		kf = imsg->data;
 
-		show_fib_flags(k->flags);
+		show_fib_flags(kf->flags);
 
-		if (asprintf(&p, "%s/%u", inet_ntoa(k->prefix), k->prefixlen) ==
-		    -1)
+		if (asprintf(&p, "%s/%u", log_addr(&kf->prefix),
+		    kf->prefixlen) == -1)
 			err(1, NULL);
-		printf("%4i %-20s ", k->priority, p);
+		printf("%4i %-20s ", kf->priority, p);
 		free(p);
 
-		if (k->nexthop.s_addr)
-			printf("%s", inet_ntoa(k->nexthop));
-		else if (k->flags & F_CONNECTED)
-			printf("link#%u", k->ifindex);
+		if (kf->flags & F_CONNECTED)
+			printf("link#%u", kf->ifindex);
+		else
+			printf("%s", log_addr(&kf->nexthop));
 		printf("\n");
 
 		break;
-	case IMSG_CTL_KROUTE6:
-	case IMSG_CTL_SHOW_NETWORK6:
-		if (imsg->hdr.len < IMSG_HEADER_SIZE + sizeof(struct kroute6))
+	case IMSG_CTL_SHOW_FIB_TABLES:
+		if (imsg->hdr.len < IMSG_HEADER_SIZE + sizeof(*kt))
 			errx(1, "wrong imsg len");
-		k6 = imsg->data;
-
-		show_fib_flags(k6->flags);
+		kt = imsg->data;
 
-		if (asprintf(&p, "%s/%u", log_in6addr(&k6->prefix),
-		    k6->prefixlen) == -1)
-			err(1, NULL);
-		printf("%4i %-20s ", k6->priority, p);
-		free(p);
-
-		if (!IN6_IS_ADDR_UNSPECIFIED(&k6->nexthop))
-			printf("%s", log_in6addr(&k6->nexthop));
-		else if (k6->flags & F_CONNECTED)
-			printf("link#%u", k6->ifindex);
-		printf("\n");
+		printf("%5i %-20s %-8s%s\n", kt->rtableid, kt->descr,
+		    kt->fib_sync ? "coupled" : "decoupled",
+		    kt->fib_sync != kt->fib_conf ? "*" : "");
 
 		break;
 	case IMSG_CTL_END:
 		return (1);
-		break;
 	default:
 		break;
 	}
@@ -848,35 +969,70 @@ show_fib_msg(struct imsg *imsg)
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
@@ -898,9 +1054,8 @@ show_interface_head(void)
 	    "Link state");
 }
 
-const int	ifm_status_valid_list[] = IFM_STATUS_VALID_LIST;
-const struct ifmedia_status_description
-		ifm_status_descriptions[] = IFM_STATUS_DESCRIPTIONS;
+const struct if_status_description
+		if_status_descriptions[] = LINK_STATE_DESCRIPTIONS;
 const struct ifmedia_description
 		ifm_type_descriptions[] = IFM_TYPE_DESCRIPTIONS;
 
@@ -936,36 +1091,36 @@ get_media_descr(int media_type)
 const char *
 get_linkstate(int media_type, int link_state)
 {
-	const struct ifmedia_status_description	*p;
-	int					 i;
-
-	if (link_state == LINK_STATE_UNKNOWN)
-		return ("unknown");
-
-	for (i = 0; ifm_status_valid_list[i] != 0; i++)
-		for (p = ifm_status_descriptions; p->ifms_valid != 0; p++) {
-			if (p->ifms_type != media_type ||
-			    p->ifms_valid != ifm_status_valid_list[i])
-				continue;
-			if (LINK_STATE_IS_UP(link_state))
-				return (p->ifms_string[1]);
-			return (p->ifms_string[0]);
-		}
+	const struct if_status_description *p;
+	static char buf[8];
 
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
+		snprintf(bbuf, sizeof(bbuf), "%" PRIu64 " G%s",
+		    baudrate / IF_Gbps(1), unit);
 	else if (baudrate > IF_Mbps(1))
-		printf("%llu MBit/s", baudrate / IF_Mbps(1));
+		snprintf(bbuf, sizeof(bbuf), "%" PRIu64 " M%s",
+		    baudrate / IF_Mbps(1), unit);
 	else if (baudrate > IF_Kbps(1))
-		printf("%llu KBit/s", baudrate / IF_Kbps(1));
+		snprintf(bbuf, sizeof(bbuf), "%" PRIu64 " K%s",
+		    baudrate / IF_Kbps(1), unit);
 	else
-		printf("%llu Bit/s", baudrate);
+		snprintf(bbuf, sizeof(bbuf), "%" PRIu64 " %s",
+		    baudrate, unit);
+
+	return (bbuf);
 }
 
 int
@@ -982,17 +1137,12 @@ show_interface_msg(struct imsg *imsg)
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
@@ -1008,10 +1158,10 @@ show_interface_msg(struct imsg *imsg)
 void
 show_rib_summary_head(void)
 {
-	printf(
-	    "flags: * = Valid, > = Selected, I = via IBGP, A = Announced\n");
+	printf("flags: * = Valid, > = Selected, I = via IBGP, A = Announced, "
+	    "S = Stale\n");
 	printf("origin: i = IGP, e = EGP, ? = Incomplete\n\n");
-	printf("%-5s %-20s%-15s  %5s %5s %s\n", "flags", "destination",
+	printf("%-5s %-20s %-15s  %5s %5s %s\n", "flags", "destination",
 	    "gateway", "lpref", "med", "aspath origin");
 }
 
@@ -1049,26 +1199,30 @@ print_flags(u_int8_t flags, int sum)
 	char	*p = flagstr;
 
 	if (sum) {
-		if (flags & F_RIB_ANNOUNCE)
+		if (flags & F_PREF_ANNOUNCE)
 			*p++ = 'A';
-		if (flags & F_RIB_INTERNAL)
+		if (flags & F_PREF_INTERNAL)
 			*p++ = 'I';
-		if (flags & F_RIB_ELIGIBLE)
+		if (flags & F_PREF_STALE)
+			*p++ = 'S';
+		if (flags & F_PREF_ELIGIBLE)
 			*p++ = '*';
-		if (flags & F_RIB_ACTIVE)
+		if (flags & F_PREF_ACTIVE)
 			*p++ = '>';
 		*p = '\0';
 		printf("%-5s ", flagstr);
 	} else {
-		if (flags & F_RIB_INTERNAL)
+		if (flags & F_PREF_INTERNAL)
 			printf("internal");
 		else
 			printf("external");
-		if (flags & F_RIB_ELIGIBLE)
+		if (flags & F_PREF_STALE)
+			printf(", stale");
+		if (flags & F_PREF_ELIGIBLE)
 			printf(", valid");
-		if (flags & F_RIB_ACTIVE)
+		if (flags & F_PREF_ACTIVE)
 			printf(", best");
-		if (flags & F_RIB_ANNOUNCE)
+		if (flags & F_PREF_ANNOUNCE)
 			printf(", announced");
 	}
 }
@@ -1077,27 +1231,14 @@ int
 show_rib_summary_msg(struct imsg *imsg)
 {
 	struct ctl_show_rib	 rib;
-	char			*aspath;
 	u_char			*asdata;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_RIB:
 		memcpy(&rib, imsg->data, sizeof(rib));
-
-		print_prefix(&rib.prefix, rib.prefixlen, rib.flags);
-		printf("%-15s ", log_addr(&rib.exit_nexthop));
-
-		printf(" %5u %5u ", rib.local_pref, rib.med);
-
 		asdata = imsg->data;
 		asdata += sizeof(struct ctl_show_rib);
-		if (aspath_asprint(&aspath, asdata, rib.aspath_len) == -1)
-			err(1, NULL);
-		if (strlen(aspath) > 0)
-			printf("%s ", aspath);
-		free(aspath);
-
-		printf("%s\n", print_origin(rib.origin, 1));
+		show_rib_brief(&rib, asdata);
 		break;
 	case IMSG_CTL_END:
 		return (1);
@@ -1112,108 +1253,21 @@ int
 show_rib_detail_msg(struct imsg *imsg, int nodescr)
 {
 	struct ctl_show_rib	 rib;
-	struct in_addr		 id;
-	char			*aspath, *s;
-	u_char			*data;
-	u_int32_t		 as;
-	u_int16_t		 ilen, alen, ioff;
-	u_int8_t		 flags, type;
-	time_t			 now;
+	u_char			*asdata;
+	u_int16_t		 ilen;
 
 	switch (imsg->hdr.type) {
 	case IMSG_CTL_SHOW_RIB:
 		memcpy(&rib, imsg->data, sizeof(rib));
-
-		printf("\nBGP routing table entry for %s/%u\n",
-		    log_addr(&rib.prefix), rib.prefixlen);
-
-		data = imsg->data;
-		data += sizeof(struct ctl_show_rib);
-		if (aspath_asprint(&aspath, data, rib.aspath_len) == -1)
-			err(1, NULL);
-		if (strlen(aspath) > 0)
-			printf("    %s\n", aspath);
-		free(aspath);
-
-		s = fmt_peer(rib.descr, &rib.remote_addr, -1, nodescr);
-		printf("    Nexthop %s ", log_addr(&rib.exit_nexthop));
-		printf("(via %s) from %s (", log_addr(&rib.true_nexthop), s);
-		free(s);
-		id.s_addr = htonl(rib.remote_id);
-		printf("%s)\n", inet_ntoa(id));
-
-		printf("    Origin %s, metric %u, localpref %u, ",
-		    print_origin(rib.origin, 0), rib.med, rib.local_pref);
-		print_flags(rib.flags, 0);
-
-		now = time(NULL);
-		if (now > rib.lastchange)
-			now -= rib.lastchange;
-		else
-			now = 0;
-
-		printf("\n    Last update: %s ago\n",
-		    fmt_timeframe_core(now));
+		asdata = imsg->data;
+		asdata += sizeof(struct ctl_show_rib);
+		show_rib_detail(&rib, asdata, nodescr);
 		break;
 	case IMSG_CTL_SHOW_RIB_ATTR:
 		ilen = imsg->hdr.len - IMSG_HEADER_SIZE;
 		if (ilen < 3)
 			errx(1, "bad IMSG_CTL_SHOW_RIB_ATTR received");
-		data = imsg->data;
-		flags = data[0];
-		type = data[1];
-
-		/* get the attribute length */
-		if (flags & ATTR_EXTLEN) {
-			if (ilen < 4)
-				errx(1, "bad IMSG_CTL_SHOW_RIB_ATTR received");
-			memcpy(&alen, data+2, sizeof(u_int16_t));
-			alen = ntohs(alen);
-			data += 4;
-			ilen -= 4;
-		} else {
-			alen = data[2];
-			data += 3;
-			ilen -= 3;
-		}
-		/* bad imsg len how can that happen!? */
-		if (alen != ilen)
-			errx(1, "bad IMSG_CTL_SHOW_RIB_ATTR received");
-
-		switch (type) {
-		case ATTR_COMMUNITIES:
-			printf("    Communities: ");
-			show_community(data, alen);
-			printf("\n");
-			break;
-		case ATTR_AGGREGATOR:
-			memcpy(&as, data, sizeof(as));
-			memcpy(&id, data + sizeof(as), sizeof(id));
-			printf("    Aggregator: %s [%s]\n", 
-			    log_as(htonl(as)), inet_ntoa(id));
-			break;
-		case ATTR_ORIGINATOR_ID:
-			memcpy(&id, data, sizeof(id));
-			printf("    Originator Id: %s\n", inet_ntoa(id));
-			break;
-		case ATTR_CLUSTER_LIST:
-			printf("    Cluster ID List:");
-			for (ioff = 0; ioff + sizeof(id) <= ilen;
-			    ioff += sizeof(id)) {
-				memcpy(&id, data + ioff, sizeof(id));
-				printf(" %s", inet_ntoa(id));
-			}
-			printf("\n");
-			break;
-		case ATTR_EXT_COMMUNITIES:
-			printf("    Ext. communities: ");
-			show_ext_community(data, alen);
-			printf("\n");
-			break;
-		default:
-			/* ignore unknown attributes */
-			break;
-		}
+		show_attr(imsg->data, ilen);
 		break;
 	case IMSG_CTL_END:
 		printf("\n");
@@ -1225,67 +1279,128 @@ show_rib_detail_msg(struct imsg *imsg, i
 	return (0);
 }
 
-char *
-fmt_mem(int64_t num)
+void
+show_rib_brief(struct ctl_show_rib *r, u_char *asdata)
 {
-	static char	buf[16];
+	char			*aspath;
 
-	if (fmt_scaled(num, buf) == -1)
-		snprintf(buf, sizeof(buf), "%lldB", (long long)num);
+	print_prefix(&r->prefix, r->prefixlen, r->flags);
+	printf(" %-15s ", log_addr(&r->exit_nexthop));
+	printf(" %5u %5u ", r->local_pref, r->med);
 
-	return (buf);
+	if (aspath_asprint(&aspath, asdata, r->aspath_len) == -1)
+		err(1, NULL);
+	if (strlen(aspath) > 0)
+		printf("%s ", aspath);
+	free(aspath);
+
+	printf("%s\n", print_origin(r->origin, 1));
 }
 
-int
-show_rib_memory_msg(struct imsg *imsg)
+void
+show_rib_detail(struct ctl_show_rib *r, u_char *asdata, int nodescr)
 {
-	struct rde_memstats	stats;
+	struct in_addr		 id;
+	char			*aspath, *s;
+	time_t			 now;
 
-	switch (imsg->hdr.type) {
-	case IMSG_CTL_SHOW_RIB_MEM:
-		memcpy(&stats, imsg->data, sizeof(stats));
-		printf("RDE memory statistics\n");
-		printf("%10lld IPv4 network entries using %s of memory\n",
-		    (long long)stats.pt4_cnt, fmt_mem(stats.pt4_cnt *
-		    sizeof(struct pt_entry4)));
-		if (stats.pt6_cnt != 0)
-			printf("%10lld IPv6 network entries using "
-			    "%s of memory\n", (long long)stats.pt6_cnt,
-			    fmt_mem(stats.pt6_cnt * sizeof(struct pt_entry6)));
-		printf("%10lld rib entries using %s of memory\n",
-		    (long long)stats.rib_cnt, fmt_mem(stats.rib_cnt *
-		    sizeof(struct rib_entry)));
-		printf("%10lld prefix entries using %s of memory\n",
-		    (long long)stats.prefix_cnt, fmt_mem(stats.prefix_cnt *
-		    sizeof(struct prefix)));
-		printf("%10lld BGP path attribute entries using %s of memory\n",
-		    (long long)stats.path_cnt, fmt_mem(stats.path_cnt *
-		    sizeof(struct rde_aspath)));
-		printf("%10lld BGP AS-PATH attribute entries using "
-		    "%s of memory,\n\t   and holding %lld references\n",
-		    (long long)stats.aspath_cnt, fmt_mem(stats.aspath_size),
-		    (long long)stats.aspath_refs);
-		printf("%10lld BGP attributes entries using %s of memory\n",
-		    (long long)stats.attr_cnt, fmt_mem(stats.attr_cnt *
-		    sizeof(struct attr)));
-		printf("\t   and holding %lld references\n",
-		    (long long)stats.attr_refs);
-		printf("%10lld BGP attributes using %s of memory\n",
-		    (long long)stats.attr_dcnt, fmt_mem(stats.attr_data));
-		printf("RIB using %s of memory\n", fmt_mem(
-		    stats.pt4_cnt * sizeof(struct pt_entry4) +
-		    stats.pt6_cnt * sizeof(struct pt_entry6) +
-		    stats.prefix_cnt * sizeof(struct prefix) +
-		    stats.rib_cnt * sizeof(struct rib_entry) +
-		    stats.path_cnt * sizeof(struct rde_aspath) +
-		    stats.aspath_size + stats.attr_cnt * sizeof(struct attr) +
-		    stats.attr_data));
+	printf("\nBGP routing table entry for %s/%u\n",
+	    log_addr(&r->prefix), r->prefixlen);
+
+	if (aspath_asprint(&aspath, asdata, r->aspath_len) == -1)
+		err(1, NULL);
+	if (strlen(aspath) > 0)
+		printf("    %s\n", aspath);
+	free(aspath);
+
+	s = fmt_peer(r->descr, &r->remote_addr, -1, nodescr);
+	printf("    Nexthop %s ", log_addr(&r->exit_nexthop));
+	printf("(via %s) from %s (", log_addr(&r->true_nexthop), s);
+	free(s);
+	id.s_addr = htonl(r->remote_id);
+	printf("%s)\n", inet_ntoa(id));
+
+	printf("    Origin %s, metric %u, localpref %u, weight %u, ",
+	    print_origin(r->origin, 0), r->med, r->local_pref, r->weight);
+	print_flags(r->flags, 0);
+
+	now = time(NULL);
+	if (now > r->lastchange)
+		now -= r->lastchange;
+	else
+		now = 0;
+
+	printf("\n    Last update: %s ago\n", fmt_timeframe_core(now));
+}
+
+void
+show_attr(void *b, u_int16_t len)
+{
+	char		*data = b;
+	struct in_addr	 id;
+	u_int32_t	 as;
+	u_int16_t	 alen, ioff;
+	u_int8_t	 flags, type;
+
+	data = b;
+	if (len < 3)
+		errx(1, "show_attr: too short bgp attr");
+
+	flags = data[0];
+	type = data[1];
+
+	/* get the attribute length */
+	if (flags & ATTR_EXTLEN) {
+		if (len < 4)
+			errx(1, "show_attr: too short bgp attr");
+		memcpy(&alen, data+2, sizeof(u_int16_t));
+		alen = ntohs(alen);
+		data += 4;
+		len -= 4;
+	} else {
+		alen = data[2];
+		data += 3;
+		len -= 3;
+	}
+
+	/* bad imsg len how can that happen!? */
+	if (alen > len)
+		errx(1, "show_attr: bad length");
+
+	switch (type) {
+	case ATTR_COMMUNITIES:
+		printf("    Communities: ");
+		show_community(data, alen);
+		printf("\n");
+		break;
+	case ATTR_AGGREGATOR:
+		memcpy(&as, data, sizeof(as));
+		memcpy(&id, data + sizeof(as), sizeof(id));
+		printf("    Aggregator: %s [%s]\n",
+		    log_as(ntohl(as)), inet_ntoa(id));
+		break;
+	case ATTR_ORIGINATOR_ID:
+		memcpy(&id, data, sizeof(id));
+		printf("    Originator Id: %s\n", inet_ntoa(id));
+		break;
+	case ATTR_CLUSTER_LIST:
+		printf("    Cluster ID List:");
+		for (ioff = 0; ioff + sizeof(id) <= alen;
+		    ioff += sizeof(id)) {
+			memcpy(&id, data + ioff, sizeof(id));
+			printf(" %s", inet_ntoa(id));
+		}
+		printf("\n");
+		break;
+	case ATTR_EXT_COMMUNITIES:
+		printf("    Ext. communities: ");
+		show_ext_community(data, alen);
+		printf("\n");
 		break;
 	default:
+		/* ignore unknown attributes */
 		break;
 	}
-
-	return (1);
 }
 
 void
@@ -1328,30 +1443,6 @@ show_community(u_char *data, u_int16_t l
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
@@ -1372,34 +1463,101 @@ show_ext_community(u_char *data, u_int16
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
+			printf("%s 0x%" PRIx64, log_ext_subtype(subtype), ext);
 			break;
 		default:
 			memcpy(&ext, data + i, sizeof(ext));
-			printf("0x%llx", betoh64(ext)); 
+			printf("0x%" PRIx64, betoh64(ext));
 		}
 		if (i + 8 < len)
 			printf(", ");
 	}
 }
 
+char *
+fmt_mem(int64_t num)
+{
+	static char	buf[16];
+
+	if (fmt_scaled(num, buf) == -1)
+		snprintf(buf, sizeof(buf), "%lldB", (long long)num);
+
+	return (buf);
+}
+
+size_t  pt_sizes[AID_MAX] = AID_PTSIZE;
+
+int
+show_rib_memory_msg(struct imsg *imsg)
+{
+	struct rde_memstats	stats;
+	size_t			pts = 0;
+	int			i;
+
+	switch (imsg->hdr.type) {
+	case IMSG_CTL_SHOW_RIB_MEM:
+		memcpy(&stats, imsg->data, sizeof(stats));
+		printf("RDE memory statistics\n");
+		for (i = 0; i < AID_MAX; i++) {
+			if (stats.pt_cnt[i] == 0)
+				continue;
+			pts += stats.pt_cnt[i] * pt_sizes[i];
+			printf("%10lld %s network entries using %s of memory\n",
+			    (long long)stats.pt_cnt[i], aid_vals[i].name,
+			    fmt_mem(stats.pt_cnt[i] * pt_sizes[i]));
+		}
+		printf("%10lld rib entries using %s of memory\n",
+		    (long long)stats.rib_cnt, fmt_mem(stats.rib_cnt *
+		    sizeof(struct rib_entry)));
+		printf("%10lld prefix entries using %s of memory\n",
+		    (long long)stats.prefix_cnt, fmt_mem(stats.prefix_cnt *
+		    sizeof(struct prefix)));
+		printf("%10lld BGP path attribute entries using %s of memory\n",
+		    (long long)stats.path_cnt, fmt_mem(stats.path_cnt *
+		    sizeof(struct rde_aspath)));
+		printf("%10lld BGP AS-PATH attribute entries using "
+		    "%s of memory,\n\t   and holding %lld references\n",
+		    (long long)stats.aspath_cnt, fmt_mem(stats.aspath_size),
+		    (long long)stats.aspath_refs);
+		printf("%10lld BGP attributes entries using %s of memory\n",
+		    (long long)stats.attr_cnt, fmt_mem(stats.attr_cnt *
+		    sizeof(struct attr)));
+		printf("\t   and holding %lld references\n",
+		    (long long)stats.attr_refs);
+		printf("%10lld BGP attributes using %s of memory\n",
+		    (long long)stats.attr_dcnt, fmt_mem(stats.attr_data));
+		printf("RIB using %s of memory\n", fmt_mem(pts +
+		    stats.prefix_cnt * sizeof(struct prefix) +
+		    stats.rib_cnt * sizeof(struct rib_entry) +
+		    stats.path_cnt * sizeof(struct rde_aspath) +
+		    stats.aspath_size + stats.attr_cnt * sizeof(struct attr) +
+		    stats.attr_data));
+		break;
+	default:
+		break;
+	}
+
+	return (1);
+}
+
 void
 send_filterset(struct imsgbuf *i, struct filter_set_head *set)
 {
@@ -1469,6 +1627,183 @@ show_result(struct imsg *imsg)
 	return (1);
 }
 
+void
+show_mrt_dump(struct mrt_rib *mr, struct mrt_peer *mp, void *arg)
+{
+	struct ctl_show_rib		 ctl;
+	struct ctl_show_rib_request	*req = arg;
+	struct mrt_rib_entry		*mre;
+	u_int16_t			 i, j;
+
+	for (i = 0; i < mr->nentries; i++) {
+		mre = &mr->entries[i];
+		bzero(&ctl, sizeof(ctl));
+		mrt_to_bgpd_addr(&mr->prefix, &ctl.prefix);
+		ctl.prefixlen = mr->prefixlen;
+		ctl.lastchange = mre->originated;
+		mrt_to_bgpd_addr(&mre->nexthop, &ctl.true_nexthop);
+		mrt_to_bgpd_addr(&mre->nexthop, &ctl.exit_nexthop);
+		ctl.origin = mre->origin;
+		ctl.local_pref = mre->local_pref;
+		ctl.med = mre->med;
+		/* weight is not part of the mrt dump so it can't be set */
+		ctl.aspath_len = mre->aspath_len;
+
+		if (mre->peer_idx < mp->npeers) {
+			mrt_to_bgpd_addr(&mp->peers[mre->peer_idx].addr,
+			    &ctl.remote_addr);
+			ctl.remote_id = mp->peers[mre->peer_idx].bgp_id;
+		}
+
+		/* filter by neighbor */
+		if (req->neighbor.addr.aid != AID_UNSPEC &&
+		    memcmp(&req->neighbor.addr, &ctl.remote_addr,
+		    sizeof(ctl.remote_addr)) != 0) 
+			continue;
+		/* filter by AF */
+		if (req->aid && req->aid != ctl.prefix.aid)
+			return;
+		/* filter by prefix */
+		if (req->prefix.aid != AID_UNSPEC) {
+			if (!prefix_compare(&req->prefix, &ctl.prefix,
+			    req->prefixlen)) {
+				if (req->flags & F_LONGER) {
+					if (req->prefixlen > ctl.prefixlen)
+						return;
+				} else if (req->prefixlen != ctl.prefixlen)
+					return;
+			} else
+				return;
+		}
+		/* filter by AS */
+		if (req->as.type != AS_NONE &&
+		   !aspath_match(mre->aspath, mre->aspath_len,
+		   req->as.type, req->as.as))
+			continue;
+
+		if (req->flags & F_CTL_DETAIL) {
+			show_rib_detail(&ctl, mre->aspath, 1);
+			for (j = 0; j < mre->nattrs; j++)
+				show_attr(mre->attrs[j].attr,
+					mre->attrs[j].attr_len);
+		} else
+			show_rib_brief(&ctl, mre->aspath);
+	}
+}
+
+void
+network_mrt_dump(struct mrt_rib *mr, struct mrt_peer *mp, void *arg)
+{
+	struct ctl_show_rib		 ctl;
+	struct network_config		 net;
+	struct ctl_show_rib_request	*req = arg;
+	struct mrt_rib_entry		*mre;
+	struct ibuf			*msg;
+	u_int16_t			 i, j;
+
+	for (i = 0; i < mr->nentries; i++) {
+		mre = &mr->entries[i];
+		bzero(&ctl, sizeof(ctl));
+		mrt_to_bgpd_addr(&mr->prefix, &ctl.prefix);
+		ctl.prefixlen = mr->prefixlen;
+		ctl.lastchange = mre->originated;
+		mrt_to_bgpd_addr(&mre->nexthop, &ctl.true_nexthop);
+		mrt_to_bgpd_addr(&mre->nexthop, &ctl.exit_nexthop);
+		ctl.origin = mre->origin;
+		ctl.local_pref = mre->local_pref;
+		ctl.med = mre->med;
+		ctl.aspath_len = mre->aspath_len;
+
+		if (mre->peer_idx < mp->npeers) {
+			mrt_to_bgpd_addr(&mp->peers[mre->peer_idx].addr,
+			    &ctl.remote_addr);
+			ctl.remote_id = mp->peers[mre->peer_idx].bgp_id;
+		}
+
+		/* filter by neighbor */
+		if (req->neighbor.addr.aid != AID_UNSPEC &&
+		    memcmp(&req->neighbor.addr, &ctl.remote_addr,
+		    sizeof(ctl.remote_addr)) != 0) 
+			continue;
+		/* filter by AF */
+		if (req->aid && req->aid != ctl.prefix.aid)
+			return;
+		/* filter by prefix */
+		if (req->prefix.aid != AID_UNSPEC) {
+			if (!prefix_compare(&req->prefix, &ctl.prefix,
+			    req->prefixlen)) {
+				if (req->flags & F_LONGER) {
+					if (req->prefixlen > ctl.prefixlen)
+						return;
+				} else if (req->prefixlen != ctl.prefixlen)
+					return;
+			} else
+				return;
+		}
+		/* filter by AS */
+		if (req->as.type != AS_NONE &&
+		   !aspath_match(mre->aspath, mre->aspath_len,
+		   req->as.type, req->as.as))
+			continue;
+
+		bzero(&net, sizeof(net));
+		memcpy(&net.prefix, &ctl.prefix, sizeof(net.prefix));
+		net.prefixlen = ctl.prefixlen;
+		net.type = NETWORK_MRTCLONE;
+		/* XXX rtableid */
+
+		imsg_compose(ibuf, IMSG_NETWORK_ADD, 0, 0, -1,
+		    &net, sizeof(net));
+		if ((msg = imsg_create(ibuf, IMSG_NETWORK_ASPATH,
+		    0, 0, sizeof(ctl) + mre->aspath_len)) == NULL)
+			errx(1, "imsg_create failure");
+		if (imsg_add(msg, &ctl, sizeof(ctl)) == -1 ||
+		    imsg_add(msg, mre->aspath, mre->aspath_len) == -1)
+			errx(1, "imsg_add failure");
+		imsg_close(ibuf, msg);
+		for (j = 0; j < mre->nattrs; j++)
+			imsg_compose(ibuf, IMSG_NETWORK_ATTR, 0, 0, -1,
+			    mre->attrs[j].attr, mre->attrs[j].attr_len);
+		imsg_compose(ibuf, IMSG_NETWORK_DONE, 0, 0, -1, NULL, 0);
+
+		while (ibuf->w.queued) {
+			if (msgbuf_write(&ibuf->w) < 0)
+				err(1, "write error");
+		}
+	}
+}
+
+void
+show_mrt_state(struct mrt_bgp_state *ms, void *arg)
+{
+	printf("show_mrt_state\n");
+}
+
+void
+show_mrt_msg(struct mrt_bgp_msg *mm, void *arg)
+{
+	printf("show_mrt_msg\n");
+}
+
+void
+mrt_to_bgpd_addr(union mrt_addr *ma, struct bgpd_addr *ba)
+{
+	switch (ma->sa.sa_family) {
+	case AF_INET:
+	case AF_INET6:
+		sa2addr(&ma->sa, ba);
+		break;
+	case AF_VPNv4:
+		bzero(ba, sizeof(*ba));
+		ba->aid = AID_VPN_IPv4;
+		ba->vpn4.rd = ma->svpn4.sv_rd;
+		ba->vpn4.addr.s_addr = ma->svpn4.sv_addr.s_addr;
+		memcpy(ba->vpn4.labelstack, ma->svpn4.sv_label,
+		    sizeof(ba->vpn4.labelstack));
+		break;
+	}
+}
+
 /* following functions are necessary for imsg framework */
 void
 log_warnx(const char *emsg, ...)
@@ -1495,3 +1830,9 @@ fatal(const char *emsg)
 {
 	err(1, emsg);
 }
+
+void
+fatalx(const char *emsg)
+{
+	errx(1, emsg);
+}
