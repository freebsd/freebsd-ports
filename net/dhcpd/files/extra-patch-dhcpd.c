--- dhcpd.c.orig	2018-06-06 09:12:11 UTC
+++ dhcpd.c
@@ -74,11 +74,15 @@ u_int16_t client_port;
 struct passwd *pw;
 int log_priority;
 int log_perror = 0;
+#ifndef NO_PF
 int pfpipe[2];
+#endif /* NO_PF */
 int gotpipe = 0;
 int syncrecv;
 int syncsend;
+#ifndef NO_PF
 pid_t pfproc_pid = -1;
+#endif /* NO_PF */
 char *path_dhcpd_conf = _PATH_DHCPD_CONF;
 char *path_dhcpd_db = _PATH_DHCPD_DB;
 char *abandoned_tab = NULL;
@@ -225,6 +229,7 @@ main(int argc, char *argv[])
 	if ((pw = getpwnam("_dhcp")) == NULL)
 		error("user \"_dhcp\" not found");
 
+#ifndef NO_PF
 	/* don't go near /dev/pf unless we actually intend to use it */
 	if ((abandoned_tab != NULL) ||
 	    (changedmac_tab != NULL) ||
@@ -248,6 +253,7 @@ main(int argc, char *argv[])
 			break;
 		}
 	}
+#endif /* NO_PF */
 
 	if (udpsockmode)
 		udpsock_startup(udpaddr);
@@ -386,6 +392,7 @@ periodic_scan(void *p)
 	if (y < 1)
 		y = 1;
 
+#ifndef NO_PF
 	/* walk across all leases to find the exired ones */
 	for (n = subnets; n; n = n->next_subnet)
 		for (g = n->group; g; g = g->next)
@@ -394,6 +401,7 @@ periodic_scan(void *p)
 					if (cur_time >= l->ends)
 						if (l->ends > last_scan)
 							pfmsg('R', l);
+#endif /* NO_PF */
 
 	last_scan = cur_time;
 	add_timeout(cur_time + y, periodic_scan, NULL);
