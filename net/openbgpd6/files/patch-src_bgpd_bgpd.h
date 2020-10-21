--- src/bgpd/bgpd.h.orig	2020-05-19 09:24:33 UTC
+++ src/bgpd/bgpd.h
@@ -130,7 +130,8 @@ enum bgpd_process {
 	PROC_MAIN,
 	PROC_SE,
 	PROC_RDE
-} bgpd_process;
+};
+extern enum bgpd_process bgpd_process;
 
 enum reconf_action {
 	RECONF_NONE,
@@ -532,6 +533,10 @@ enum imsg_type {
 	IMSG_XON,
 	IMSG_XOFF
 };
+
+extern struct imsgbuf *ibuf_se;
+extern struct imsgbuf *ibuf_rde;
+extern struct imsgbuf *ibuf_main;
 
 struct demote_msg {
 	char		 demote_group[IFNAMSIZ];
