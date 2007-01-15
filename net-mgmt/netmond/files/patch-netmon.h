--- netmon.h.orig	Tue Aug 26 10:00:38 2003
+++ netmon.h	Thu Dec 28 13:31:06 2006
@@ -14,6 +14,9 @@
 #include <sys/socket.h>
 #include <sys/time.h>
 #include <netinet/in.h>
+#include <pwd.h>
+#include <grp.h>
+#include <time.h>
 #ifdef	DEBUG_MEMORY
 #include <assert.h>
 #endif
@@ -77,7 +80,10 @@
 #endif
 
 #define	NETMON			"netmon"
-#define	DEFAULT_CONFIG		"/etc/netmon.conf"
+#define	DEFAULT_CONFIG		"/usr/local/etc/netmond.conf"
+#define USERNAME		"netmon"
+#define GROUPNAME		"netmon"
+#define PIDFILE_PATH		"/var/run"
 #define	DEFAULT_WATCHDOG	600	/* 10 min */
 
 #define	POLLING_MIN		30	/* 30 sec */
@@ -88,9 +94,13 @@
 typedef	struct timeval TIMEVAL;
 typedef	unsigned long oid;
 
+#define	STATE_UNKNOWN	0
 #define	STATE_UP	1
 #define	STATE_DOWN	2
+#define	STATE_DEGRADED	3
+#define	STATE_WARNING	4
 #define	BGP_ESTABLISHED	6
+#define	ENV_NORMAL	1
 #define	ENV_NOTPRESENT	5
 
 #define	OBJ_STATE	0
@@ -111,6 +121,9 @@
 #define	TYPE_ENVFAN		9
 #define	TYPE_ENVPS		10
 
+#define WHEN_PROTO		10099
+#define PIPE_PROTO		10098
+
 struct object_ent;
 struct method_ent;
 
@@ -250,6 +263,7 @@
 
 	int state;		/* current operational status (UP/DOWN/...) */
 	int prev_state;		/* previous operational status */
+	int ignore_state;       /* if =1, ignore this interface while parent object state evaluating */
 	TIMEVAL last_request;	/* last time interface requested */
 	TIMEVAL prev_request;	/* previous time interface requested */
 	TIMEVAL last_reply;	/* last time interface reply */
@@ -294,6 +308,7 @@
 	int asn;		/* AS number */
 	char *descr;		/* AS description */
 	char *datadir;		/* directory where store data */
+	int ignore_state;       /* if =1, ignore this AS while parent object state evaluating */
 	SAVE *save_list;	/* list of save methods */
 	GROUP_REF *ns_acl;	/* netstate client access list */
 
@@ -325,6 +340,7 @@
 	int type;		/* type of gauge: TYPE_ENVTEMP, etc */
 	char *descr;		/* env mon description */
 	char *datadir;		/* directory where store data */
+	int ignore_state;       /* if =1, ignore this ENV while parent object state evaluating */
 	SAVE *save_list;	/* list of save methods */
 	GROUP_REF *ns_acl;	/* netstate client access list */
 
@@ -385,13 +401,14 @@
 	struct method_ent *method;	/* session method */
 	int sock;		/* socket file descriptor */
 	struct sockaddr peer;	/* address of peer */
+	struct sockaddr me;	/* my source address  */
 	long timeout;		/* number of microseconds until first timeout */
 	int retries;		/* number of retries before timeout */
 	int (*connect) __P((struct session_ent *));
 	int (*send) __P((struct session_ent *, REQUEST *));
 	int (*recv) __P((struct session_ent *));
 	void (*read) __P((int, struct session_ent *, int));
-
+	pid_t	pid;
 	/* returned values */
 	int data_int;		/* data length or chat-script matchs */
 	char *data_ptr;		/* pointer to resulting data if any */
@@ -428,6 +445,8 @@
 	u_short	rport;		/* remote port number, 0=unused */
 	int timeout;		/* number of seconds until first timeout */
 	int retries;		/* number of retries before timeout */
+	char *when;	        /* condition string */
+	char *when_fmt;         /* message when condition is true */
 	union {
 		struct ping_param {
 			short send;	/* ICMP echo request packets to send */
@@ -530,7 +549,9 @@
 	char *descr;		/* object description */
 	char *datadir;		/* directory where store data */
 	char *address;		/* domain name or dotted IP address */
+	char *srcaddress;	/* domain name or dotted source IP address */
 	struct in_addr ip_addr;	/* ip address of peer */
+	struct in_addr ip_srcaddr; /* source ip address */
 	int polling;		/* polling period in seconds */
 	int saving;		/* saving period in seconds */
 	int sync;		/* polling counter to synchronize saving */
@@ -544,6 +565,10 @@
 
 	int state;		/* current operational status (UP/DOWN/...) */
 	int prev_state;		/* previous operational status */
+	int ignore_state;       /* if =1, ignore this obj while parent object state evaluating */
+	int mths_ok;		/* count of Ok finished methods */
+	int mths_fail;		/* count of Failed methods */
+	int smths_fail;		/* count of Failed services methods */
 	TIMEVAL last_request;	/* last time method requested */
 	TIMEVAL prev_request;	/* previous time method requested */
 	TIMEVAL last_reply;	/* last time method reply */
@@ -574,17 +599,29 @@
 
 typedef	struct config_ent {
 	char *rootdir;		/* default work directory */
+	char *chrootdir;	/* chroot directory for EXEC children */
+	char *username;		/* username for EXEC children */	
+	uid_t	uid;		/* UID for EXEC children */	
+	char *groupname;	/* groupname for EXEC children */	
+	gid_t	gid;		/* GID for EXEC children */	
 	char *timefmt;		/* strftime format of currtime for logging */
+	char *srcaddress;	/* my default source domain name or dotted IP address */
+	struct in_addr ip_srcaddr; /* my default sorce ip address  */
 	int polling;		/* default polling interval in seconds */
 	int saving;		/* default saving interval in seconds */
 	int timeout;		/* default timeout in seconds */
 	int retries;		/* default number of retries */
+	int compatibility_flag;	/*  */
 
 	int enable_traps;	/* enable SNMP traps */
 	int source_traps;	/* match src-addr and agent-addr of traps */
+	char *trap_address;	/* Trap bind address */
+	struct in_addr trap_ip_addr;	/*  */	
 
 	/* netstate server */
 	int ns_port;		/* server port number */
+	char *ns_address;	/* NetState bind address */
+	struct in_addr ns_ip_addr;	/*  */	
 	int ns_timo;		/* client timeout in seconds */
 	GROUP_REF *ns_acl;	/* netstate client access list */
 
@@ -616,6 +653,7 @@
 extern int netstate_sock;
 extern int Cflag;
 extern int syslog_initialized;
+extern int compatibility_flag;
 
 /*
  * Function prototypes
@@ -733,6 +771,19 @@
 void tcp_start __P((METHOD *));
 void tcp_stop __P((METHOD *));
 int match_expect __P((SESSION *, CHATSCRIPT *, char *));
+int tcp_connect __P((SESSION *));
+int tcp_send __P((SESSION *,REQUEST *));
+int tcp_recv __P((SESSION *));
+void tcp_close __P((int, SESSION *, int));
+
+/* pipe.c */
+int pipe_init __P((OBJECT *, METHOD *));
+void pipe_start __P((METHOD *));
+void pipe_stop __P((METHOD *));
+
+int when_init __P((OBJECT *, METHOD *));
+void when_start __P((METHOD *));
+void when_stop __P((METHOD *));
 
 /* udp.c */
 int udp_init __P((OBJECT *, METHOD *));
