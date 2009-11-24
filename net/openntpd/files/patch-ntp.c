$FreeBSD$
--- ntp.c.orig	2009-11-23 20:47:16.000000000 +0100
+++ ntp.c	2009-11-23 20:55:59.000000000 +0100
@@ -34,9 +34,14 @@
 #include "ntpd.h"
 
 #define	PFD_PIPE_MAIN	0
+#ifdef HAVE_SENSORS
 #define	PFD_HOTPLUG	1
 #define	PFD_PIPE_DNS	2
 #define	PFD_MAX		3
+#else
+#define	PFD_PIPE_DNS	1
+#define	PFD_MAX		2
+#endif
 
 volatile sig_atomic_t	 ntp_quit = 0;
 volatile sig_atomic_t	 ntp_report = 0;
@@ -72,7 +77,10 @@ pid_t
 ntp_main(int pipe_prnt[2], struct ntpd_conf *nconf, struct passwd *pw)
 {
 	int			 a, b, nfds, i, j, idx_peers, timeout;
-	int			 hotplugfd, nullfd, pipe_dns[2];
+#ifdef HAVE_SENSORS
+	int			 hotplugfd;
+#endif
+	int			 nullfd, pipe_dns[2];
 	u_int			 pfd_elms = 0, idx2peer_elms = 0;
 	u_int			 listener_cnt, new_cnt, sent_cnt, trial_cnt;
 	pid_t			 pid, dns_pid;
@@ -81,10 +89,15 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 	struct listen_addr	*la;
 	struct ntp_peer		*p;
 	struct ntp_peer		**idx2peer = NULL;
+#ifdef HAVE_SENSORS
 	struct ntp_sensor	*s, *next_s;
+#endif
 	struct timespec		 tp;
 	struct stat		 stb;
-	time_t			 nextaction, last_sensor_scan = 0;
+	time_t			 nextaction;
+#ifdef HAVE_SENSORS
+	time_t			 last_sensor_scan = 0;
+#endif
 	void			*newp;
 
 	switch (pid = fork()) {
@@ -108,7 +121,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 
 	if ((nullfd = open(_PATH_DEVNULL, O_RDWR, 0)) == -1)
 		fatal(NULL);
+#ifdef HAVE_SENSORS
 	hotplugfd = sensor_hotplugfd();
+#endif
 
 	if (socketpair(AF_UNIX, SOCK_STREAM, PF_UNSPEC, pipe_dns) == -1)
 		fatal("socketpair");
@@ -179,7 +194,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 	conf->status.precision = a;
 	conf->scale = 1;
 
+#ifdef HAVE_SENSORS
 	sensor_init();
+#endif
 
 	log_info("ntp engine ready");
 
@@ -221,8 +238,10 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 		nextaction = getmonotime() + 3600;
 		pfd[PFD_PIPE_MAIN].fd = ibuf_main->fd;
 		pfd[PFD_PIPE_MAIN].events = POLLIN;
+#ifdef HAVE_SENSORS
 		pfd[PFD_HOTPLUG].fd = hotplugfd;
 		pfd[PFD_HOTPLUG].events = POLLIN;
+#endif
 		pfd[PFD_PIPE_DNS].fd = ibuf_dns->fd;
 		pfd[PFD_PIPE_DNS].events = POLLIN;
 
@@ -278,6 +297,7 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 			}
 		}
 
+#ifdef HAVE_SENSORS
 		if (last_sensor_scan == 0 ||
 		    last_sensor_scan + SENSOR_SCAN_INTERVAL < getmonotime()) {
 			sensors_cnt = sensor_scan();
@@ -286,7 +306,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 		if (!TAILQ_EMPTY(&conf->ntp_conf_sensors) && sensors_cnt == 0 &&
 		    nextaction > last_sensor_scan + SENSOR_SCAN_INTERVAL)
 			nextaction = last_sensor_scan + SENSOR_SCAN_INTERVAL;
+#endif
 		sensors_cnt = 0;
+#ifdef HAVE_SENSORS
 		TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 			if (conf->settime && s->offsets[0].offset)
 				priv_settime(s->offsets[0].offset);
@@ -294,6 +316,7 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 			if (s->next > 0 && s->next < nextaction)
 				nextaction = s->next;
 		}
+#endif
 
 		if (conf->settime &&
 		    ((trial_cnt > 0 && sent_cnt == 0) ||
@@ -339,10 +362,12 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 				ntp_quit = 1;
 		}
 
+#ifdef HAVE_SENSORS
 		if (nfds > 0 && pfd[PFD_HOTPLUG].revents & (POLLIN|POLLERR)) {
 			nfds--;
 			sensor_hotplugevent(hotplugfd);
 		}
+#endif
 
 		for (j = PFD_MAX; nfds > 0 && j < idx_peers; j++)
 			if (pfd[j].revents & (POLLIN|POLLERR)) {
@@ -359,12 +384,14 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 					ntp_quit = 1;
 			}
 
+#ifdef HAVE_SENSORS
 		for (s = TAILQ_FIRST(&conf->ntp_sensors); s != NULL;
 		    s = next_s) {
 			next_s = TAILQ_NEXT(s, entry);
 			if (s->next <= getmonotime())
 				sensor_query(s);
 		}
+#endif
 		report_peers(ntp_report);
 		ntp_report = 0;
 	}
@@ -574,7 +601,9 @@ int
 priv_adjtime(void)
 {
 	struct ntp_peer		 *p;
+#ifdef HAVE_SENSORS
 	struct ntp_sensor	 *s;
+#endif
 	int			  offset_cnt = 0, i = 0, j;
 	struct ntp_offset	**offsets;
 	double			  offset_median;
@@ -587,11 +616,13 @@ priv_adjtime(void)
 		offset_cnt += p->weight;
 	}
 
+#ifdef HAVE_SENSORS
 	TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 		if (!s->update.good)
 			continue;
 		offset_cnt += s->weight;
 	}
+#endif
 
 	if (offset_cnt == 0)
 		return (1);
@@ -606,12 +637,14 @@ priv_adjtime(void)
 			offsets[i++] = &p->update;
 	}
 
+#ifdef HAVE_SENSORS
 	TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 		if (!s->update.good)
 			continue;
 		for (j = 0; j < s->weight; j++)
 			offsets[i++] = &s->update;
 	}
+#endif
 
 	qsort(offsets, offset_cnt, sizeof(struct ntp_offset *), offset_compare);
 
@@ -648,11 +681,13 @@ priv_adjtime(void)
 			p->reply[i].offset -= offset_median;
 		p->update.good = 0;
 	}
+#ifdef HAVE_SENSORS
 	TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 		for (i = 0; i < SENSOR_OFFSETS; i++)
 			s->offsets[i].offset -= offset_median;
 		s->update.offset -= offset_median;
 	}
+#endif
 
 	return (0);
 }
@@ -734,16 +769,20 @@ report_peers(int always)
 	u_int badpeers = 0;
 	u_int badsensors = 0;
 	struct ntp_peer *p;
+#ifdef HAVE_SENSORS
 	struct ntp_sensor *s;
+#endif
 
 	TAILQ_FOREACH(p, &conf->ntp_peers, entry) {
 		if (p->trustlevel < TRUSTLEVEL_BADPEER)
 			badpeers++;
 	}
+#ifdef HAVE_SENSORS
 	TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 		if (!s->update.good)
 			badsensors++;
 	}
+#endif
 
 	now = getmonotime();
 	if (!always) {
@@ -773,6 +812,7 @@ report_peers(int always)
 			}
 		}
 	}
+#ifdef HAVE_SENSORS
 	if (sensors_cnt > 0) {
 		log_warnx("%u out of %u sensors valid",
 		    sensors_cnt - badsensors, sensors_cnt);
@@ -781,4 +821,5 @@ report_peers(int always)
 				log_warnx("bad sensor %s", s->device);
 		}
 	}
+#endif
 }
