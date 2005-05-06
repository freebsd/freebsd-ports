--- ../ifstated-20050505.orig/ifstated.c	Thu May  5 11:51:24 2005
+++ ifstated.c	Thu May  5 12:06:07 2005
@@ -1,4 +1,5 @@
 /*	$OpenBSD: ifstated.c,v 1.21 2005/02/07 12:38:44 mcbride Exp $	*/
+/*	$Id: ifstated.c,v 1.3 2005/05/05 16:06:07 mdg Exp $	*/

 /*
  * Copyright (c) 2004 Marco Pfatschbacher <mpf@openbsd.org>
@@ -23,12 +24,15 @@
  */

 #include <sys/types.h>
+#include <sys/event.h>
 #include <sys/time.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
+#include <sys/sysctl.h>

 #include <net/if.h>
+#include <net/if_mib.h>
 #include <net/route.h>
 #include <netinet/in.h>

@@ -38,8 +42,6 @@
 #include <fcntl.h>
 #include <signal.h>
 #include <err.h>
-#include <event.h>
-#include <util.h>
 #include <unistd.h>
 #include <syslog.h>
 #include <stdarg.h>
@@ -52,15 +54,15 @@
 int	 opts = 0;
 int	 opt_debug = 0;
 int	 opt_inhibit = 0;
-char	*configfile = "/etc/ifstated.conf";
-struct event	rt_msg_ev, sighup_ev, startup_ev, sigchld_ev;
+char	*configfile = "%%PREFIX%%/etc/ifstated.conf";
+int      kq;
+struct kevent   kev;

-void	startup_handler(int, short, void *);
-void	sighup_handler(int, short, void *);
+void	startup_handler(void);
+void	sighup_handler(void);
 int	load_config(void);
 void	sigchld_handler(int, short, void *);
-void	rt_msg_handler(int, short, void *);
-void	external_handler(int, short, void *);
+void	rt_msg_handler(int fd);
 void	external_async_exec(struct ifsd_external *);
 void	check_external_status(struct ifsd_state *);
 void	external_evtimer_setup(struct ifsd_state *, int);
@@ -75,6 +77,8 @@
 void	remove_expression(struct ifsd_expression *, struct ifsd_state *);
 void	log_init(int);
 void	logit(int, const char *, ...);
+int     get_ifcount(void);
+int     get_ifmib_general(int, struct ifmibdata *);

 void
 usage(void)
@@ -89,7 +93,7 @@
 int
 main(int argc, char *argv[])
 {
-	struct timeval tv;
+	struct timespec ts;
 	int ch;

 	while ((ch = getopt(argc, argv, "dD:f:hniv")) != -1) {
@@ -136,26 +140,54 @@
 		setproctitle(NULL);
 	}

-	event_init();
+	kq = kqueue();
+
 	log_init(opt_debug);

-	signal_set(&sigchld_ev, SIGCHLD, sigchld_handler, &sigchld_ev);
-	signal_add(&sigchld_ev, NULL);
+	ts.tv_sec = 0;
+	ts.tv_nsec = 0;
+
+	EV_SET(&kev, SIGCHLD, EVFILT_SIGNAL, EV_ADD, 0, 0, (void *)sigchld_handler);
+	kevent(kq, &kev, 1, NULL, 0, &ts);

 	/* Loading the config needs to happen in the event loop */
-	tv.tv_usec = 0;
-	tv.tv_sec = 0;
-	evtimer_set(&startup_ev, startup_handler, &startup_ev);
-	evtimer_add(&startup_ev, &tv);

-	event_loop(0);
+	EV_SET(&kev, IFSD_EVTIMER_STARTUP, EVFILT_TIMER, EV_ADD|EV_ONESHOT, 0, 0, (void *)startup_handler);
+	kevent(kq, &kev, 1, NULL, 0, &ts);
+
+	/* event loop */
+	for(;;)
+	  {
+	    /* wait indefinitely for an event */
+	    kevent(kq, NULL, 0, &kev, 1, NULL);
+
+	    void (*handler)(void);
+	    void (*rt_handler)(int);
+	    if (kev.filter == EVFILT_READ)
+	      {
+		rt_handler = kev.udata;
+		rt_handler(kev.ident);
+	      }
+	    else if ((kev.filter == EVFILT_TIMER) && (kev.ident == IFSD_EVTIMER_EXTERNAL))
+	      {
+		external_async_exec((struct ifsd_external *)kev.udata);
+	      }
+	    else
+	      {
+		handler = kev.udata;
+		handler();
+	      }
+	  }
+
+	/* NOTREACHED */
 	exit(0);
 }

 void
-startup_handler(int fd, short event, void *arg)
+startup_handler()
 {
 	int rt_fd;
+	struct timespec ts;

 	if (load_config() != 0) {
 		logit(IFSD_LOG_NORMAL, "unable to load config");
@@ -165,18 +197,20 @@
 	if ((rt_fd = socket(PF_ROUTE, SOCK_RAW, 0)) < 0)
 		err(1, "no routing socket");

-	event_set(&rt_msg_ev, rt_fd, EV_READ|EV_PERSIST,
-	    rt_msg_handler, &rt_msg_ev);
-	event_add(&rt_msg_ev, NULL);
+	ts.tv_sec = 0;
+	ts.tv_nsec = 0;

-	signal_set(&sighup_ev, SIGHUP, sighup_handler, &sighup_ev);
-	signal_add(&sighup_ev, NULL);
+	EV_SET(&kev, rt_fd, EVFILT_READ, EV_ADD, 0, 0, (void *)rt_msg_handler);
+	kevent(kq, &kev, 1, NULL, 0, &ts);
+
+	EV_SET(&kev, SIGHUP, EVFILT_SIGNAL, EV_ADD, 0, 0, (void *)sighup_handler);
+	kevent(kq, &kev, 1, NULL, 0, &ts);

 	logit(IFSD_LOG_NORMAL, "started");
 }

 void
-sighup_handler(int fd, short event, void *arg)
+sighup_handler()
 {
 	logit(IFSD_LOG_NORMAL, "reloading config");
 	if (load_config() != 0)
@@ -207,7 +241,7 @@
 }

 void
-rt_msg_handler(int fd, short event, void *arg)
+rt_msg_handler(int fd)
 {
 	char msg[2048];
 	struct rt_msghdr *rtm = (struct rt_msghdr *)&msg;
@@ -245,22 +279,6 @@
 }

 void
-external_handler(int fd, short event, void *arg)
-{
-	struct ifsd_external *external = (struct ifsd_external *)arg;
-	struct timeval tv;
-
-	/* re-schedule */
-	tv.tv_usec = 0;
-	tv.tv_sec = external->frequency;
-	evtimer_set(&external->ev, external_handler, external);
-	evtimer_add(&external->ev, &tv);
-
-	/* execute */
-	external_async_exec(external);
-}
-
-void
 external_async_exec(struct ifsd_external *external)
 {
 	char *argp[] = {"sh", "-c", NULL, NULL};
@@ -354,23 +372,25 @@
 external_evtimer_setup(struct ifsd_state *state, int action)
 {
 	struct ifsd_external *external;
+	struct timespec ts;
+	int freq;
+
+	ts.tv_nsec = 0;
+	ts.tv_sec = 0;

 	if (state != NULL) {
 		switch (action) {
 		case IFSD_EVTIMER_ADD:
 			TAILQ_FOREACH(external,
 			    &state->external_tests, entries) {
-				struct timeval tv;

 				/* run it once right away */
 				external_async_exec(external);

 				/* schedule it for later */
-				tv.tv_usec = 0;
-				tv.tv_sec = external->frequency;
-				evtimer_set(&external->ev, external_handler,
-				    external);
-				evtimer_add(&external->ev, &tv);
+				freq = (external->frequency * 1000);
+				EV_SET(&kev, IFSD_EVTIMER_EXTERNAL, EVFILT_TIMER, EV_ADD, 0, freq, (void *)external);
+				kevent(kq, &kev, 1, NULL, 0, &ts);
 			}
 			break;
 		case IFSD_EVTIMER_DEL:
@@ -380,7 +400,9 @@
 					kill(external->pid, SIGKILL);
 					external->pid = 0;
 				}
-				evtimer_del(&external->ev);
+				freq = (external->frequency * 1000);
+				EV_SET(&kev, IFSD_EVTIMER_EXTERNAL, EVFILT_TIMER, EV_DELETE, 0, freq, (void *)external);
+				kevent(kq, &kev, 1, NULL, 0, &ts);
 			}
 			break;
 		}
@@ -504,7 +526,6 @@
 		logit(IFSD_LOG_NORMAL, "changing state to %s",
 		    conf->nextstate->name);
 		if (conf->curstate != NULL) {
-			evtimer_del(&conf->curstate->ev);
 			external_evtimer_setup(conf->curstate,
 			    IFSD_EVTIMER_DEL);
 		}
@@ -550,6 +571,48 @@
 	}
 }

+
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
+
+
 /*
  * Fetch the current link states.
  */
@@ -559,29 +622,34 @@
 	struct ifaddrs *ifap, *ifa;
 	char *oname = NULL;
 	int sock = socket(AF_INET, SOCK_DGRAM, 0);
+	int ifcount = get_ifcount();
+	int i;

-	if (getifaddrs(&ifap) != 0)
+	if (getifaddrs(&ifap) != 0 || ifcount == -1)
 		err(1, "getifaddrs");

 	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
-		struct ifreq ifr;
-		struct if_data  ifrdat;
+	        struct ifmibdata ifmd;
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
-		    ifrdat.ifi_link_state, &conf->always);
+		    ifdata.ifi_link_state, &conf->always);
 		if (conf->curstate != NULL)
 			scan_ifstate(if_nametoindex(ifa->ifa_name),
-			    ifrdat.ifi_link_state, conf->curstate);
+			    ifdata.ifi_link_state, conf->curstate);
 	}
 	freeifaddrs(ifap);
 	close(sock);
@@ -663,7 +731,6 @@
 			TAILQ_REMOVE(&state->external_tests,
 			    expression->u.external, entries);
 			free(expression->u.external->command);
-			event_del(&expression->u.external->ev);
 			free(expression->u.external);
 		}
 		break;
