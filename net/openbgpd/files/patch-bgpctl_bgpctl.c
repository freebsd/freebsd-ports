Index: bgpctl/bgpctl.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/bgpctl.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpctl/bgpctl.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/bgpctl.c	9 Jul 2009 17:22:12 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: bgpctl.c,v 1.134 2008/06/07 20:23:15 henning Exp $ */
+/*	$OpenBSD: bgpctl.c,v 1.142 2009/06/06 06:33:15 eric Exp $ */
 
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
@@ -89,8 +105,8 @@ usage(void)
 {
 	extern char	*__progname;
 
-	fprintf(stderr, "usage: %s [-n] [-s socket] "
-	    "command [arguments ...]\n", __progname);
+	fprintf(stderr, "usage: %s [-n] [-s socket] command [argument ...]\n",
+	    __progname);
 	exit(1);
 }
 
@@ -174,8 +190,7 @@ main(int argc, char *argv[])
 			    -1 ||
 			    imsg_add(msg, &res->af, sizeof(res->af)) == -1)
 				errx(1, "imsg_add failure");
-			if (imsg_close(ibuf, msg) < 0)
-				errx(1, "imsg_close error");
+			imsg_close(ibuf, msg);
 		} else
 			imsg_compose(ibuf, IMSG_CTL_KROUTE_ADDR, 0, 0, -1,
 			    &res->addr, sizeof(res->addr));
@@ -220,6 +235,7 @@ main(int argc, char *argv[])
 		}
 		memcpy(&ribreq.neighbor, &neighbor,
 		    sizeof(ribreq.neighbor));
+		strlcpy(ribreq.rib, res->rib, sizeof(ribreq.rib));
 		ribreq.af = res->af;
 		ribreq.flags = res->flags;
 		imsg_compose(ibuf, type, 0, 0, -1, &ribreq, sizeof(ribreq));
@@ -289,8 +305,11 @@ main(int argc, char *argv[])
 		done = 1;
 		break;
 	case NETWORK_SHOW:
+		bzero(&ribreq, sizeof(ribreq));
+		ribreq.af = res->af;
+		strlcpy(ribreq.rib, res->rib, sizeof(ribreq.rib));
 		imsg_compose(ibuf, IMSG_CTL_SHOW_NETWORK, 0, 0, -1,
-		    &res->af, sizeof(res->af));
+		    &ribreq, sizeof(ribreq));
 		show_network_head();
 		break;
 	}
@@ -410,7 +429,7 @@ fmt_peer(const char *descr, const struct
 void
 show_summary_head(void)
 {
-	printf("%-20s %-8s %-10s %-10s %-5s %-8s %s\n", "Neighbor", "AS",
+	printf("%-20s %8s %10s %10s %5s %-8s %s\n", "Neighbor", "AS",
 	    "MsgRcvd", "MsgSent", "OutQ", "Up/Down", "State/PrfRcvd");
 }
 
@@ -677,7 +696,7 @@ print_neighbor_msgstats(struct peer *p)
 }
 
 void
-print_timer(const char *name, timer_t d)
+print_timer(const char *name, time_t d)
 {
 	printf("  %-20s ", name);
 
@@ -738,7 +757,7 @@ show_fib_head(void)
 	printf("flags: * = valid, B = BGP, C = Connected, S = Static\n");
 	printf("       N = BGP Nexthop reachable via this route\n");
 	printf("       r = reject route, b = blackhole route\n\n");
-	printf("flags destination          gateway\n");
+	printf("flags prio destination          gateway\n");
 }
 
 void
@@ -801,7 +820,7 @@ show_fib_msg(struct imsg *imsg)
 		if (asprintf(&p, "%s/%u", inet_ntoa(k->prefix), k->prefixlen) ==
 		    -1)
 			err(1, NULL);
-		printf("%-20s ", p);
+		printf("%4i %-20s ", k->priority, p);
 		free(p);
 
 		if (k->nexthop.s_addr)
@@ -822,7 +841,7 @@ show_fib_msg(struct imsg *imsg)
 		if (asprintf(&p, "%s/%u", log_in6addr(&k6->prefix),
 		    k6->prefixlen) == -1)
 			err(1, NULL);
-		printf("%-20s ", p);
+		printf("%4i %-20s ", k6->priority, p);
 		free(p);
 
 		if (!IN6_IS_ADDR_UNSPECIFIED(&k6->nexthop))
@@ -1186,8 +1205,8 @@ show_rib_detail_msg(struct imsg *imsg, i
 		case ATTR_AGGREGATOR:
 			memcpy(&as, data, sizeof(as));
 			memcpy(&id, data + sizeof(as), sizeof(id));
-			printf("    Aggregator: %s [%s]\n", log_as(as),
-			   inet_ntoa(id));
+			printf("    Aggregator: %s [%s]\n", 
+			    log_as(htonl(as)), inet_ntoa(id));
 			break;
 		case ATTR_ORIGINATOR_ID:
 			memcpy(&id, data, sizeof(id));
@@ -1249,6 +1268,9 @@ show_rib_memory_msg(struct imsg *imsg)
 			printf("%10lld IPv6 network entries using "
 			    "%s of memory\n", (long long)stats.pt6_cnt,
 			    fmt_mem(stats.pt6_cnt * sizeof(struct pt_entry6)));
+		printf("%10lld rib entries using %s of memory\n",
+		    (long long)stats.rib_cnt, fmt_mem(stats.rib_cnt *
+		    sizeof(struct rib_entry)));
 		printf("%10lld prefix entries using %s of memory\n",
 		    (long long)stats.prefix_cnt, fmt_mem(stats.prefix_cnt *
 		    sizeof(struct prefix)));
@@ -1270,6 +1292,7 @@ show_rib_memory_msg(struct imsg *imsg)
 		    stats.pt4_cnt * sizeof(struct pt_entry4) +
 		    stats.pt6_cnt * sizeof(struct pt_entry6) +
 		    stats.prefix_cnt * sizeof(struct prefix) +
+		    stats.rib_cnt * sizeof(struct rib_entry) +
 		    stats.path_cnt * sizeof(struct rde_aspath) +
 		    stats.aspath_size + stats.attr_cnt * sizeof(struct attr) +
 		    stats.attr_data));
