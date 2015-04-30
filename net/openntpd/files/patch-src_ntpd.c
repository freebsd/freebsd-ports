--- src/ntpd.c.orig	2015-03-25 01:18:56 UTC
+++ src/ntpd.c
@@ -53,6 +53,7 @@ const char     *ctl_lookup_option(char *
 void		show_status_msg(struct imsg *);
 void		show_peer_msg(struct imsg *, int);
 void		show_sensor_msg(struct imsg *, int);
+void		update_status(int);
 
 volatile sig_atomic_t	 quit = 0;
 volatile sig_atomic_t	 reconfig = 0;
@@ -423,6 +424,7 @@ ntpd_adjtime(double d)
 	else if (!firstadj && olddelta.tv_sec == 0 && olddelta.tv_usec == 0)
 		synced = 1;
 	firstadj = 0;
+	update_status(synced);
 	return (synced);
 }
 
