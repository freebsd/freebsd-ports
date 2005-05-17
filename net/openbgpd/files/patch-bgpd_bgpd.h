
$FreeBSD$

--- bgpd/bgpd.h.orig
+++ bgpd/bgpd.h
@@ -31,7 +31,7 @@
 
 #define	BGP_VERSION			4
 #define	BGP_PORT			179
-#define	CONFFILE			"/etc/bgpd.conf"
+#define	CONFFILE			"%%PREFIX%%/etc/bgpd.conf"
 #define	BGPD_USER			"_bgpd"
 #define	PEER_DESCR_LEN			32
 #define	PFTABLE_LEN			16
