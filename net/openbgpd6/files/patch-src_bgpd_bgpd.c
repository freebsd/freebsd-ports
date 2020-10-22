--- src/bgpd/bgpd.c.orig	2020-05-18 19:17:41 UTC
+++ src/bgpd/bgpd.c
@@ -61,6 +61,8 @@ struct rib_names	 ribnames = SIMPLEQ_HEAD_INITIALIZER(
 char			*cname;
 char			*rcname;
 
+enum bgpd_process bgpd_process;
+
 void
 sighdlr(int sig)
 {
