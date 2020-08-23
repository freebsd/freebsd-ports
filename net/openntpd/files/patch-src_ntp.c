--- src/ntp.c.orig	2017-06-19 13:23:10 UTC
+++ src/ntp.c
@@ -42,7 +42,7 @@
 
 volatile sig_atomic_t	 ntp_quit = 0;
 struct imsgbuf		*ibuf_main;
-struct imsgbuf		*ibuf_dns;
+static struct imsgbuf	*ibuf_dns;
 struct ntpd_conf	*conf;
 struct ctl_conns	 ctl_conns;
 u_int			 peer_cnt;
