--- ./shellinabox/launcher.c.orig	2009-11-21 23:20:39.000000000 +0100
+++ ./shellinabox/launcher.c	2010-08-12 14:11:16.296619939 +0200
@@ -495,6 +495,33 @@
   return utmp;
 }
 
+#if defined(HAVE_UPDWTMP) && !defined(HAVE_UPDWTMPX)
+#define min(a,b) ({ typeof(a) _a=(a); typeof(b) _b=(b); _a < _b ? _a : _b; })
+#define updwtmpx x_updwtmpx
+static void updwtmpx(const char *wtmpx_file, const struct utmpx *utx) {
+	struct utmp ut   = { 0 };
+	ut.ut_type       = utx->ut_type;
+	ut.ut_pid        = utx->ut_pid;
+	ut.ut_session    = utx->ut_session;
+	ut.ut_tv.tv_sec  = utx->ut_tv.tv_sec;
+	ut.ut_tv.tv_usec = utx->ut_tv.tv_usec;
+	memcpy(&ut.ut_line, &utx->ut_line,
+			min(sizeof(ut.ut_line), sizeof(utx->ut_line)));
+	memcpy(&ut.ut_id, &utx->ut_id,
+			min(sizeof(ut.ut_id), sizeof(utx->ut_id)));
+	memcpy(&ut.ut_user, &utx->ut_user,
+			min(sizeof(ut.ut_user), sizeof(utx->ut_user)));
+	memcpy(&ut.ut_host, &utx->ut_host,
+			min(sizeof(ut.ut_host), sizeof(utx->ut_host)));
+	memcpy(&ut.ut_exit, &utx->ut_exit,
+			min(sizeof(ut.ut_exit), sizeof(utx->ut_exit)));
+	memcpy(&ut.ut_addr_v6, &utx->ut_addr_v6,
+			min(sizeof(ut.ut_addr_v6), sizeof(utx->ut_addr_v6)));
+	updwtmp(wtmpx_file, &ut);
+}
+#endif
+
+
 void destroyUtmp(struct Utmp *utmp) {
   if (utmp) {
     if (utmp->pty >= 0) {
@@ -518,9 +545,12 @@
       setutxent();
       pututxline(&utmp->utmpx);
       endutxent();
+
+#if defined(HAVE_UPDWTMP) || defined(HAVE_UPDWTMPX)
       if (!utmp->useLogin) {
         updwtmpx("/var/log/wtmp", &utmp->utmpx);
       }
+#endif
       
       // Switch back to the lower privileges
       check(!setresgid(r_gid, e_gid, s_gid));
@@ -1027,7 +1057,9 @@
     setutxent();
     pututxline(&utmp->utmpx);
     endutxent();
+#if defined(HAVE_UPDWTMP) || defined(HAVE_UPDWTMPX)
     updwtmpx("/var/log/wtmp", &utmp->utmpx);
+#endif
   }
 #endif
 
@@ -1308,12 +1340,14 @@
   }
   pututxline(&utmpx);
   endutxent();
+#if defined(HAVE_UPDWTMP) || defined(HAVE_UPDWTMPX)
   if (!utmp->useLogin) {
     memset(&utmpx.ut_user, 0, sizeof(utmpx.ut_user));
     strncat(&utmpx.ut_user[0], "LOGIN", sizeof(utmpx.ut_user));
     updwtmpx("/var/log/wtmp", &utmpx);
   }
 #endif
+#endif
 
   // Create session. We might have to fork another process as PAM wants us
   // to close the session when the child terminates. And we must retain
