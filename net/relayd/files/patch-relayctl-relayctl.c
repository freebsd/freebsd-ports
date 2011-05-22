--- relayctl/relayctl.c.orig	2011-05-20 11:43:53.000000000 +0200
+++ relayctl/relayctl.c	2011-05-22 11:19:50.925707539 +0200
@@ -20,6 +20,9 @@
  */
 
 #include <sys/types.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <sys/socket.h>
 #include <sys/queue.h>
 #include <sys/un.h>
@@ -141,7 +144,9 @@
 	case SHOW_HOSTS:
 	case SHOW_RDRS:
 	case SHOW_RELAYS:
+#ifndef __FreeBSD__
 	case SHOW_ROUTERS:
+#endif
 		imsg_compose(ibuf, IMSG_CTL_SHOW_SUM, 0, 0, -1, NULL, 0);
 		printf("%-4s\t%-8s\t%-24s\t%-7s\tStatus\n",
 		    "Id", "Type", "Name", "Avlblty");
@@ -222,7 +227,9 @@
 			case SHOW_HOSTS:
 			case SHOW_RDRS:
 			case SHOW_RELAYS:
+#ifndef __FreeBSD__
 			case SHOW_ROUTERS:
+#endif
 				done = show_summary_msg(&imsg, res->action);
 				break;
 			case SHOW_SESSIONS:
@@ -312,7 +319,11 @@
 	imn = monitor_lookup(imsg->hdr.type);
 	printf("%s: imsg type %u len %u peerid %u pid %d\n", imn->name,
 	    imsg->hdr.type, imsg->hdr.len, imsg->hdr.peerid, imsg->hdr.pid);
+#ifdef __FreeBSD__
+	printf("\ttimestamp: %lu, %s", (unsigned long)now, ctime(&now));
+#else
 	printf("\ttimestamp: %u, %s", now, ctime(&now));
+#endif
 	if (imn->type == -1)
 		done = 1;
 	if (imn->func != NULL)
@@ -328,8 +339,10 @@
 	struct table		*table;
 	struct host		*host;
 	struct relay		*rlay;
+#ifndef __FreeBSD__
 	struct router		*rt;
 	struct netroute		*nr;
+#endif
 	struct ctl_stats	 stats[RELAY_MAXPROC];
 	char			 name[MAXHOSTNAMELEN];
 
@@ -394,6 +407,7 @@
 		bcopy(imsg->data, &stats, sizeof(stats));
 		print_statistics(stats);
 		break;
+#ifndef __FreeBSD__
 	case IMSG_CTL_ROUTER:
 		if (!(type == SHOW_SUM || type == SHOW_ROUTERS))
 			break;
@@ -416,6 +430,7 @@
 		printf("\t%8s\troute: %s/%d\n",
 		    "", name, nr->nr_conf.prefixlen);
 		break;
+#endif
 	case IMSG_CTL_END:
 		return (1);
 	default:
@@ -557,7 +572,11 @@
 	printf("\t%8s\ttotal: %llu sessions\n"
 	    "\t%8s\tlast: %u/%us %u/h %u/d sessions\n"
 	    "\t%8s\taverage: %u/%us %u/h %u/d sessions\n",
+#ifdef __FreeBSD__
+	    "", (long long unsigned)crs.cnt,
+#else
 	    "", crs.cnt,
+#endif
 	    "", crs.last, crs.interval,
 	    crs.last_hour, crs.last_day,
 	    "", crs.avg, crs.interval,
