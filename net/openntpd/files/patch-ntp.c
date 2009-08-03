$FreeBSD$
--- ntp.c.orig	2009-08-01 20:12:43.000000000 +0200
+++ ntp.c	2009-08-01 20:26:44.000000000 +0200
@@ -34,8 +34,12 @@
 #include "ntpd.h"
 
 #define	PFD_PIPE_MAIN	0
+#ifdef HAVE_SENSORS
 #define	PFD_HOTPLUG	1
 #define	PFD_MAX		2
+#else
+#define	PFD_MAX		1
+#endif
 
 volatile sig_atomic_t	 ntp_quit = 0;
 volatile sig_atomic_t	 ntp_report = 0;
@@ -69,7 +73,10 @@ pid_t
 ntp_main(int pipe_prnt[2], struct ntpd_conf *nconf, struct passwd *pw)
 {
 	int			 a, b, nfds, i, j, idx_peers, timeout;
-	int			 hotplugfd, nullfd;
+#ifdef HAVE_SENSORS
+	int			 hotplugfd;
+#endif
+	int			 nullfd;
 	u_int			 pfd_elms = 0, idx2peer_elms = 0;
 	u_int			 listener_cnt, new_cnt, sent_cnt, trial_cnt;
 	pid_t			 pid;
@@ -78,10 +85,15 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
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
@@ -105,7 +117,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 
 	if ((nullfd = open(_PATH_DEVNULL, O_RDWR, 0)) == -1)
 		fatal(NULL);
+#ifdef HAVE_SENSORS
 	hotplugfd = sensor_hotplugfd();
+#endif
 
 	if (stat(pw->pw_dir, &stb) == -1)
 		fatal("stat");
@@ -168,7 +182,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 	conf->status.precision = a;
 	conf->scale = 1;
 
+#ifdef HAVE_SENSORS
 	sensor_init();
+#endif
 
 	log_info("ntp engine ready");
 
@@ -210,8 +226,10 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 		nextaction = getmonotime() + 3600;
 		pfd[PFD_PIPE_MAIN].fd = ibuf_main->fd;
 		pfd[PFD_PIPE_MAIN].events = POLLIN;
+#ifdef HAVE_SENSORS
 		pfd[PFD_HOTPLUG].fd = hotplugfd;
 		pfd[PFD_HOTPLUG].events = POLLIN;
+#endif
 
 		i = PFD_MAX;
 		TAILQ_FOREACH(la, &conf->listen_addrs, entry) {
@@ -265,6 +283,7 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 			}
 		}
 
+#ifdef HAVE_SENSORS
 		if (last_sensor_scan == 0 ||
 		    last_sensor_scan + SENSOR_SCAN_INTERVAL < getmonotime()) {
 			sensors_cnt = sensor_scan();
@@ -273,7 +292,9 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 		if (!TAILQ_EMPTY(&conf->ntp_conf_sensors) && sensors_cnt == 0 &&
 		    nextaction > last_sensor_scan + SENSOR_SCAN_INTERVAL)
 			nextaction = last_sensor_scan + SENSOR_SCAN_INTERVAL;
+#endif
 		sensors_cnt = 0;
+#ifdef HAVE_SENSORS
 		TAILQ_FOREACH(s, &conf->ntp_sensors, entry) {
 			if (conf->settime && s->offsets[0].offset)
 				priv_settime(s->offsets[0].offset);
@@ -281,6 +302,7 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 			if (s->next > 0 && s->next < nextaction)
 				nextaction = s->next;
 		}
+#endif
 
 		if (conf->settime &&
 		    ((trial_cnt > 0 && sent_cnt == 0) ||
@@ -312,10 +334,12 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
 				ntp_quit = 1;
 		}
 
+#ifdef HAVE_SENSORS
 		if (nfds > 0 && pfd[PFD_HOTPLUG].revents & (POLLIN|POLLERR)) {
 			nfds--;
 			sensor_hotplugevent(hotplugfd);
 		}
+#endif
 
 		for (j = 1; nfds > 0 && j < idx_peers; j++)
 			if (pfd[j].revents & (POLLIN|POLLERR)) {
@@ -332,12 +356,14 @@ ntp_main(int pipe_prnt[2], struct ntpd_c
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
@@ -511,7 +537,9 @@ int
 priv_adjtime(void)
 {
 	struct ntp_peer		 *p;
+#ifdef HAVE_SENSORS
 	struct ntp_sensor	 *s;
+#endif
 	int			  offset_cnt = 0, i = 0, j;
 	struct ntp_offset	**offsets;
 	double			  offset_median;
@@ -524,11 +552,13 @@ priv_adjtime(void)
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
@@ -543,12 +573,14 @@ priv_adjtime(void)
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
 
@@ -585,11 +617,13 @@ priv_adjtime(void)
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
@@ -679,16 +713,20 @@ report_peers(int always)
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
 
 	now = time(NULL);
 	if (!always) {
@@ -718,6 +756,7 @@ report_peers(int always)
 			}
 		}
 	}
+#ifdef HAVE_SENSORS
 	if (sensors_cnt > 0) {
 		log_warnx("%u out of %u sensors valid",
 		    sensors_cnt - badsensors, sensors_cnt);
@@ -726,5 +765,6 @@ report_peers(int always)
 				log_warnx("bad sensor %s", s->device);
 		}
 	}
+#endif
 }
 
