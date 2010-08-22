--- ifstated.c.orig	2010-06-11 12:20:08.000000000 -0500
+++ ifstated.c	2010-07-30 21:55:03.045444649 -0500
@@ -26,9 +26,11 @@
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
+#include <sys/sysctl.h>
 #include <sys/wait.h>
 
 #include <net/if.h>
+#include <net/if_mib.h>
 #include <net/route.h>
 #include <netinet/in.h>
 
@@ -47,7 +49,8 @@
 
 int	 opts = 0;
 int	 opt_inhibit = 0;
-char	*configfile = "/etc/ifstated.conf";
+char	*configfile = "/usr/local/etc/ifstated.conf";
+char	*pidfile = NULL;
 struct event	rt_msg_ev, sighup_ev, startup_ev, sigchld_ev;
 
 void	startup_handler(int, short, void *);
@@ -61,6 +64,8 @@
 void	external_evtimer_setup(struct ifsd_state *, int);
 void	scan_ifstate(int, int, int);
 int	scan_ifstate_single(int, int, struct ifsd_state *);
+int	get_ifcount(void);
+int	get_ifmib_general(int row, struct ifmibdata *ifmd);
 void	fetch_state(void);
 void	usage(void);
 void	adjust_expressions(struct ifsd_expression_list *, int);
@@ -70,13 +75,14 @@
 void	do_action(struct ifsd_action *);
 void	remove_action(struct ifsd_action *, struct ifsd_state *);
 void	remove_expression(struct ifsd_expression *, struct ifsd_state *);
+void	remove_pidfile(int);
 
 void
 usage(void)
 {
 	extern char *__progname;
 
-	fprintf(stderr, "usage: %s [-dhinv] [-D macro=value] [-f file]\n",
+	fprintf(stderr, "usage: %s [-dhinv] [-D macro=value] [-f file] [-p pidfile]\n",
 	    __progname);
 	exit(1);
 }
@@ -90,7 +96,7 @@
 
 	log_init(1);
 
-	while ((ch = getopt(argc, argv, "dD:f:hniv")) != -1) {
+	while ((ch = getopt(argc, argv, "dD:f:p:hniv")) != -1) {
 		switch (ch) {
 		case 'd':
 			debug = 1;
@@ -112,6 +118,9 @@
 		case 'i':
 			opt_inhibit = 1;
 			break;
+		case 'p':
+			pidfile = optarg;
+			break;
 		case 'v':
 			if (opts & IFSD_OPT_VERBOSE)
 				opts |= IFSD_OPT_VERBOSE2;
@@ -159,7 +168,6 @@
 startup_handler(int fd, short event, void *arg)
 {
 	int rt_fd;
-	unsigned int rtfilter;
 
 	if ((rt_fd = socket(PF_ROUTE, SOCK_RAW, 0)) < 0)
 		err(1, "no routing socket");
@@ -169,11 +177,24 @@
 		exit(1);
 	}
 
-	rtfilter = ROUTE_FILTER(RTM_IFINFO);
-	if (setsockopt(rt_fd, PF_ROUTE, ROUTE_MSGFILTER,
-	    &rtfilter, sizeof(rtfilter)) == -1)         /* not fatal */
-		log_warn("startup_handler: setsockopt");
-	
+	if (pidfile != NULL) {
+		FILE* file = fopen(pidfile, "w");
+
+		if (file == NULL) {
+			log_warnx("unable to open pidfile");
+		}
+		else {
+			fprintf(file, "%ld\n", (long)getpid());
+			fclose(file);
+			log_debug("wrote pidfile %s", pidfile);
+
+			signal(SIGINT, remove_pidfile);
+			signal(SIGQUIT, remove_pidfile);
+			signal(SIGABRT, remove_pidfile);
+			signal(SIGTERM, remove_pidfile);
+		}
+	}
+
 	event_set(&rt_msg_ev, rt_fd, EV_READ|EV_PERSIST, rt_msg_handler, NULL);
 	event_add(&rt_msg_ev, NULL);
 
@@ -406,6 +427,8 @@
 	}
 }
 
+#define	LINK_STATE_IS_UP(_s)						\
+  ((_s) >= LINK_STATE_UP)
 #define	LINK_STATE_IS_DOWN(_s)						\
 	(!LINK_STATE_IS_UP((_s)) && (_s) != LINK_STATE_UNKNOWN)
 
@@ -584,6 +607,44 @@
 	}
 }
 
+int
+get_ifcount(void)
+{
+  int name[5], count;
+  size_t len;
+
+  name[0] = CTL_NET;
+  name[1] = PF_LINK;
+  name[2] = NETLINK_GENERIC;
+  name[3] = IFMIB_SYSTEM;
+  name[4] = IFMIB_IFCOUNT;
+
+  len = sizeof(int);
+
+  if (sysctl(name, 5, &count, &len, NULL, 0) != -1)
+    return(count);
+  else
+    return(-1);
+}
+
+int
+get_ifmib_general(int row, struct ifmibdata *ifmd)
+{
+  int name[6];
+  size_t len;
+
+  name[0] = CTL_NET;
+  name[1] = PF_LINK;
+  name[2] = NETLINK_GENERIC;
+  name[3] = IFMIB_IFDATA;
+  name[4] = row;
+  name[5] = IFDATA_GENERAL;
+
+  len = sizeof(*ifmd);
+
+  return sysctl(name, 6, ifmd, &len, (void *)0, 0);
+}
+
 /*
  * Fetch the current link states.
  */
@@ -593,26 +654,31 @@
 	struct ifaddrs *ifap, *ifa;
 	char *oname = NULL;
 	int sock = socket(AF_INET, SOCK_DGRAM, 0);
+        int ifcount = get_ifcount();
+        int i;
 
-	if (getifaddrs(&ifap) != 0)
+	if (getifaddrs(&ifap) != 0 || ifcount == -1)
 		err(1, "getifaddrs");
 
 	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
-		struct ifreq ifr;
-		struct if_data  ifrdat;
+		struct ifmibdata ifmd;
+		struct if_data  ifdata;
 
 		if (oname && !strcmp(oname, ifa->ifa_name))
 			continue;
 		oname = ifa->ifa_name;
 
-		strlcpy(ifr.ifr_name, ifa->ifa_name, sizeof(ifr.ifr_name));
-		ifr.ifr_data = (caddr_t)&ifrdat;
+		for (i = 1; i <= ifcount; i++)
+		  {
+		    get_ifmib_general(i, &ifmd);
+		    if (! strcmp(ifmd.ifmd_name, oname))
+		      break;
+		  }
 
-		if (ioctl(sock, SIOCGIFDATA, (caddr_t)&ifr) == -1)
-			continue;
+		ifdata = ifmd.ifmd_data;
 
 		scan_ifstate(if_nametoindex(ifa->ifa_name),
-		    ifrdat.ifi_link_state, 0);
+		    ifdata.ifi_link_state, 0);
 	}
 	freeifaddrs(ifap);
 	close(sock);
@@ -707,3 +773,13 @@
 	}
 	free(expression);
 }
+
+void
+remove_pidfile(int code)
+{
+	if ((pidfile != NULL) && unlink(pidfile)) {
+		log_warnx("could not remove pidfile");
+	}
+
+	exit(code);
+}
