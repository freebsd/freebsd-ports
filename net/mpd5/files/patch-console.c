--- src/console.h.orig	2016-01-06 22:42:06.000000000 +0700
+++ src/console.h	2017-06-16 21:12:59.268715000 +0700
@@ -119,6 +119,7 @@
   extern int	ConsoleStat(Context ctx, int ac, char *av[], void *arg);
   extern Context	StdConsoleConnect(Console c);
   extern void	ConsoleShutdown(Console c);
+  extern void	ConsoleCancelCleanup(void *rwlock);
 
   extern int	UserCommand(Context ctx, int ac, char *av[], void *arg);
   extern int	UserStat(Context ctx, int ac, char *av[], void *arg);
--- src/console.c.orig	2016-01-06 22:42:06.000000000 +0700
+++ src/console.c	2017-06-16 21:54:48.919442000 +0700
@@ -175,6 +175,14 @@ ConsoleClose(Console c)
   return 0;
 }
 
+void
+ConsoleCancelCleanup(void *rwlock)
+{
+  pthread_rwlock_t p = (pthread_rwlock_t)rwlock;
+
+  RWLOCK_UNLOCK(p);
+}
+
 /*
  * ConsoleStat()
  */
@@ -192,13 +200,14 @@ ConsoleStat(Context ctx, int ac, char *a
   Printf("\tIP-Address    : %s\r\n", u_addrtoa(&c->addr,addrstr,sizeof(addrstr)));
   Printf("\tPort          : %d\r\n", c->port);
 
+  pthread_cleanup_push(ConsoleCancelCleanup, c->lock);
   RWLOCK_RDLOCK(c->lock);
   Printf("Active sessions:\r\n");
   SLIST_FOREACH(s, &c->sessions, next) {
     Printf("\tUsername: %s\tFrom: %s\r\n",
 	s->user.username, u_addrtoa(&s->peer_addr,addrstr,sizeof(addrstr)));
   }
-  RWLOCK_UNLOCK(c->lock);
+  pthread_cleanup_pop(1);
 
   Printf("Global options:\r\n");
   OptStat(ctx, &c->options, gConfList);
@@ -905,13 +914,14 @@ UserStat(Context ctx, int ac, char *av[]
     ConsoleUser		u;
 
     Printf("Configured users:\r\n");
+    pthread_cleanup_push(ConsoleCancelCleanup, gUsersLock);
     RWLOCK_RDLOCK(gUsersLock);
     ghash_walk_init(gUsers, &walk);
     while ((u = ghash_walk_next(gUsers, &walk)) !=  NULL) {
 	Printf("\tUsername: %-15s Priv: %s\r\n", u->username,
 	    ((u->priv == 2)?"admin":((u->priv == 1)?"operator":"user")));
     }
-    RWLOCK_UNLOCK(gUsersLock);
+    pthread_cleanup_pop(1);
 
     return 0;
 }
--- src/log.c.orig	2016-01-06 22:42:06.000000000 +0700
+++ src/log.c	2017-06-16 21:16:19.643625000 +0700
@@ -256,12 +256,13 @@ vLogPrintf(const char *fmt, va_list args
 #ifdef SYSLOG_FACILITY
         syslog(LOG_INFO, "%s", buf);
 #endif
+	pthread_cleanup_push(ConsoleCancelCleanup, gConsole.lock);
 	RWLOCK_RDLOCK(gConsole.lock);
 	SLIST_FOREACH(s, &gConsole.sessions, next) {
 	    if (Enabled(&s->options, CONSOLE_LOGGING))
 		s->write(s, "%s\r\n", buf);
 	}
-	RWLOCK_UNLOCK(gConsole.lock);
+	pthread_cleanup_pop(1);
 #ifdef SYSLOG_FACILITY
     } else {
         vsyslog(LOG_INFO, fmt, args);
