--- src/daemon/interfaces-bsd.c.orig	2016-06-13 06:38:49 UTC
+++ src/daemon/interfaces-bsd.c
@@ -470,7 +470,11 @@ ifbsd_macphy(struct lldpd *cfg,
 {
 #ifdef ENABLE_DOT3
 	struct ifmediareq ifmr = {};
+#ifdef HAVE_TYPEOF
 	typeof(ifmr.ifm_ulist[0]) media_list[32] = {};
+#else
+	int media_list[32] = {};
+#endif
 	ifmr.ifm_ulist = media_list;
 	ifmr.ifm_count = 32;
 	struct lldpd_port *port = &hardware->h_lport;
