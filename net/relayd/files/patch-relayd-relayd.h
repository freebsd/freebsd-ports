--- relayd.orig/relayd.h	2011-05-22 01:06:39.465162022 +0200
+++ relayd/relayd.h	2011-05-22 01:07:39.088200887 +0200
@@ -21,10 +21,18 @@
 #include <sys/tree.h>
 
 #include <sys/param.h>		/* MAXHOSTNAMELEN */
+#ifdef __FreeBSD__
+#include <sys/queue.h>
+#define	nitems(_a)	(sizeof((_a)) / sizeof((_a)[0]))
+#endif
 #include <limits.h>
 #include <imsg.h>
 
+#ifdef __FreeBSD__
+#define	CONF_FILE		"%%PREFIX%%/etc/relayd.conf"
+#else
 #define CONF_FILE		"/etc/relayd.conf"
+#endif
 #define RELAYD_SOCKET		"/var/run/relayd.sock"
 #define PF_SOCKET		"/dev/pf"
 #define RELAYD_USER		"_relayd"
@@ -63,7 +71,18 @@
 #define SMALL_READ_BUF_SIZE	1024
 #define ICMP_BUF_SIZE		64
 
+#ifndef __FreeBSD__
 #define SNMP_RECONNECT_TIMEOUT	{ 3, 0 }	/* sec, usec */
+#else
+#define	SIMPLEQ_HEAD		STAILQ_HEAD
+#define	SIMPLEQ_FIRST		STAILQ_FIRST
+#define	SIMPLEQ_REMOVE_HEAD	STAILQ_REMOVE_HEAD
+#define	SIMPLEQ_ENTRY		STAILQ_ENTRY
+#define	SIMPLEQ_INIT		STAILQ_INIT
+#define	SIMPLEQ_EMPTY		STAILQ_EMPTY
+#define	SIMPLEQ_NEXT		STAILQ_NEXT
+#define	SIMPLEQ_INSERT_TAIL	STAILQ_INSERT_TAIL
+#endif
 
 #if DEBUG > 1
 #define DPRINTF		log_debug
@@ -253,7 +272,9 @@
 #define F_SSLCLIENT		0x00200000
 #define F_NEEDRT		0x00400000
 #define F_MATCH			0x00800000
+#ifndef __FreeBSD__
 #define F_DIVERT		0x01000000
+#endif
 
 #define F_BITS								\
 	"\10\01DISABLE\02BACKUP\03USED\04DOWN\05ADD\06DEL\07CHANGED"	\
@@ -622,6 +643,7 @@
 };
 #define RELAY_DSTMODE_DEFAULT		RELAY_DSTMODE_ROUNDROBIN
 
+#ifndef __FreeBSD__
 struct router;
 struct netroute_config {
 	objid_t			 id;
@@ -668,6 +690,7 @@
 	struct netroute_config	nr;
 	struct router_config	rt;
 };
+#endif
 
 /* initially control.h */
 struct control_sock {
@@ -753,12 +776,18 @@
 	IMSG_HOST_STATUS,	/* notifies from hce to pfe */
 	IMSG_SYNC,
 	IMSG_NATLOOK,
+#ifndef __FreeBSD__
 	IMSG_DEMOTE,
+#endif
 	IMSG_STATISTICS,
 	IMSG_SCRIPT,
+#ifndef __FreeBSD__
 	IMSG_SNMPSOCK,
+#endif
 	IMSG_BINDANY,
+#ifndef __FreeBSD__
 	IMSG_RTMSG,		/* from pfe to parent */
+#endif
 	IMSG_CFG_TABLE,		/* configuration from parent */
 	IMSG_CFG_HOST,
 	IMSG_CFG_RDR,
@@ -826,14 +855,18 @@
 	u_int32_t		 sc_flags;
 	const char		*sc_conffile;
 	struct pfdata		*sc_pf;
+#ifndef __FreeBSD__
 	int			 sc_rtsock;
 	int			 sc_rtseq;
+#endif
 	int			 sc_tablecount;
 	int			 sc_rdrcount;
 	int			 sc_protocount;
 	int			 sc_relaycount;
+#ifndef __FreeBSD__
 	int			 sc_routercount;
 	int			 sc_routecount;
+#endif
 	struct timeval		 sc_interval;
 	struct timeval		 sc_timeout;
 	struct table		 sc_empty_table;
@@ -843,8 +876,10 @@
 	struct rdrlist		*sc_rdrs;
 	struct protolist	*sc_protos;
 	struct relaylist	*sc_relays;
+#ifndef __FreeBSD__
 	struct routerlist	*sc_rts;
 	struct netroutelist	*sc_routes;
+#endif
 	u_int16_t		 sc_prefork_relay;
 	char			 sc_demote_group[IFNAMSIZ];
 	u_int16_t		 sc_id;
@@ -852,10 +887,11 @@
 	struct event		 sc_statev;
 	struct timeval		 sc_statinterval;
 
+#ifndef __FreeBSD__
 	int			 sc_snmp;
 	struct event		 sc_snmpto;
 	struct event		 sc_snmpev;
-
+#endif
 	int			 sc_has_icmp;
 	int			 sc_has_icmp6;
 	struct ctl_icmp_event	 sc_icmp_send;
@@ -923,10 +959,12 @@
 u_int64_t
 	 check_table(struct relayd *, struct rdr *, struct table *);
 
+#ifndef __FreeBSD__
 /* pfe_route.c */
 void	 init_routes(struct relayd *);
 void	 sync_routes(struct relayd *, struct router *);
 int	 pfe_route(struct relayd *, struct ctl_netroute *);
+#endif
 
 /* hce.c */
 pid_t	 hce(struct privsep *, struct privsep_proc *);
@@ -943,8 +981,10 @@
 void	 relay_session(struct rsession *);
 int	 relay_from_table(struct rsession *);
 int	 relay_socket_af(struct sockaddr_storage *, in_port_t);
+#ifndef __FreeBSD__
 in_port_t
 	 relay_socket_getport(struct sockaddr_storage *);
+#endif
 int	 relay_cmp_af(struct sockaddr_storage *,
 		 struct sockaddr_storage *);
 
@@ -986,8 +1026,10 @@
 struct host	*host_find(struct relayd *, objid_t);
 struct table	*table_find(struct relayd *, objid_t);
 struct rdr	*rdr_find(struct relayd *, objid_t);
+#ifndef __FreeBSD__
 struct netroute	*route_find(struct relayd *, objid_t);
 struct router	*router_find(struct relayd *, objid_t);
+#endif
 struct host	*host_findbyname(struct relayd *, const char *);
 struct table	*table_findbyname(struct relayd *, const char *);
 struct table	*table_findbyconf(struct relayd *, struct table *);
@@ -1035,11 +1077,13 @@
 void		 pn_unref(u_int16_t);
 void		 pn_ref(u_int16_t);
 
+#ifndef __FreeBSD__
 /* snmp.c */
 void	 snmp_init(struct relayd *, enum privsep_procid);
 int	 snmp_setsock(struct relayd *, enum privsep_procid);
 int	 snmp_getsock(struct relayd *, struct imsg *);
 void	 snmp_hosttrap(struct relayd *, struct table *, struct host *);
+#endif
 
 /* shuffle.c */
 void		shuffle_init(struct shuffle *);
@@ -1092,9 +1136,11 @@
 int	 config_setrdr(struct relayd *, struct rdr *);
 int	 config_getrdr(struct relayd *, struct imsg *);
 int	 config_getvirt(struct relayd *, struct imsg *);
+#ifndef __FreeBSD__
 int	 config_setrt(struct relayd *, struct router *);
 int	 config_getrt(struct relayd *, struct imsg *);
 int	 config_getroute(struct relayd *, struct imsg *);
+#endif
 int	 config_setproto(struct relayd *env, struct protocol *);
 int	 config_getproto(struct relayd *, struct imsg *);
 int	 config_setprotonode(struct relayd *, enum privsep_procid,
@@ -1102,3 +1148,9 @@
 int	 config_getprotonode(struct relayd *, struct imsg *);
 int	 config_setrelay(struct relayd *env, struct relay *);
 int	 config_getrelay(struct relayd *, struct imsg *);
+
+#ifdef __FreeBSD__
+#if __FreeBSD_version < 800041
+u_int32_t	arc4random_uniform(u_int32_t upper_bound);
+#endif
+#endif
