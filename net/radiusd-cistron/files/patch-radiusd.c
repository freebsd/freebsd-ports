--- src/radiusd.c.orig	Wed Jul  2 11:39:03 2003
+++ src/radiusd.c	Sat Oct  7 20:51:28 2006
@@ -46,6 +46,7 @@
 char			*radacct_dir;
 int			log_stripped_names;
 int 			cache_passwd = 0;
+int			radius_pid;
 int			use_dbm = 0;
 int			use_wtmp = 1;
 int			use_utmp = 1;
@@ -72,7 +73,6 @@
 static int		acctfd;
 static int		spawn_flag;
 static int		acct_pid;
-static int		radius_pid;
 static int		need_reload = 0;
 static time_t		start_time;
 static AUTH_REQ		*first_request;
@@ -612,6 +612,7 @@
         if ((cl = client_find(authreq->ipaddr)) == NULL) {
                 log(L_ERR, "packet from unknown client/host: %s",
                         client_name(authreq->ipaddr));
+		authfree(authreq);
                 return -1;
         }
 	strNcpy(authreq->secret, cl->secret, sizeof(authreq->secret));
