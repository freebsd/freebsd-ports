--- src/radiusd.c.orig	Thu Mar 31 23:06:51 2005
+++ src/radiusd.c	Mon Dec 25 20:40:17 2006
@@ -48,6 +48,7 @@
 char			*radacct_dir;
 int			log_stripped_names;
 int 			cache_passwd = 0;
+int			radius_pid;
 int			use_dbm = 0;
 int			use_wtmp = 1;
 int			use_utmp = 1;
@@ -74,7 +75,6 @@
 static int		acctfd;
 static int		spawn_flag;
 static int		acct_pid;
-static int		radius_pid;
 static int		need_reload = 0;
 static time_t		start_time;
 static AUTH_REQ		*first_request;
