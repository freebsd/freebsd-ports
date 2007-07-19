--- bgpd/bgpd.h.orig	Thu Jul 19 12:52:38 2007
+++ bgpd/bgpd.h	Thu Jul 19 12:52:28 2007
@@ -30,9 +30,11 @@
 #include <poll.h>
 #include <stdarg.h>
 
+#define RTA_LABEL 0
+
 #define	BGP_VERSION			4
 #define	BGP_PORT			179
-#define	CONFFILE			"/etc/bgpd.conf"
+#define	CONFFILE			"%%PREFIX%%/etc/bgpd.conf"
 #define	BGPD_USER			"_bgpd"
 #define	PEER_DESCR_LEN			32
 #define	PFTABLE_LEN			16
@@ -467,12 +469,12 @@
 
 struct kroute_label {
 	struct kroute	kr;
-	char		label[RTLABEL_LEN];
+	char		label[PFTABLE_LEN];
 };
 
 struct kroute6_label {
 	struct kroute6	kr;
-	char		label[RTLABEL_LEN];
+	char		label[PFTABLE_LEN];
 };
 
 #define	F_RIB_ELIGIBLE	0x01
@@ -644,7 +646,7 @@
 		struct bgpd_addr	nexthop;
 		struct filter_community	community;
 		char			pftable[PFTABLE_LEN];
-		char			rtlabel[RTLABEL_LEN];
+		char			rtlabel[PFTABLE_LEN];
 	} action;
 	enum action_types		type;
 };
@@ -709,8 +711,8 @@
 void		 log_warnx(const char *, ...);
 void		 log_info(const char *, ...);
 void		 log_debug(const char *, ...);
-void		 fatal(const char *) __dead;
-void		 fatalx(const char *) __dead;
+void		 fatal(const char *) ;
+void		 fatalx(const char *) ;
 
 /* parse.y */
 int	 cmdline_symset(char *);
