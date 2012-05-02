--- doinkd.c.orig	2006-05-30 00:17:44.000000000 -0700
+++ doinkd.c	2012-05-01 20:13:50.992115867 -0700
@@ -2,6 +2,7 @@
  *	Main doinkd routine contols everything.
  */
 
+#include <sys/param.h>
 #include <sys/types.h>
 
 #include <signal.h>
@@ -147,6 +148,7 @@
    FILE   *logfd;
 #ifdef HAVE_UTMPX
    struct utmpx utmpbuf;
+   struct utmpx *utmp_ptr;
 #else
    struct utmp utmpbuf;
 #endif
@@ -226,9 +228,11 @@
    (void) signal (SIGQUIT, SIG_IGN);
 
    /* Trap some error ones */
+#if 0
    (void) signal (SIGILL, core_time);
    (void) signal (SIGBUS, core_time);
    (void) signal (SIGSEGV, core_time);
+#endif
 
 #if defined(SIGTTOU) && defined(SIGTSTP)
    (void) signal (SIGTTOU, SIG_IGN);
@@ -285,11 +289,15 @@
 
       (void) time (&tempus);
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+	setutxent();
+#else
       if ((utmpfd = open (UTMP_FILE, O_RDONLY, 0)) == SYSERROR)
       {
 	 logfile ("%19.19s:  Cannot open %s.",ctime(&tempus),UTMP_FILE);
 	 exit (1);
       }
+#endif
 
       /* Set our nextcheck time to the max (sleeptime), though it may
        * be lowered in the coming for loop so that an idle tty gets
@@ -318,11 +326,15 @@
        * examine him again.
        */
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+      for (utmptr = 0, userptr = 0; utmp_ptr = getutxent();)
+#else
 #ifdef HAVE_UTMPX
       for (utmptr = 0, userptr = 0; (res = read (utmpfd, (char *) &utmpbuf, sizeof (struct utmpx))) > 0;)
 #else
       for (utmptr = 0, userptr = 0; (res = read (utmpfd, (char *) &utmpbuf, sizeof (struct utmp))) > 0;)
 #endif
+#endif __FreeBSD_version
       {
          if (utmptr >= MAXUSERS)
          {
@@ -330,6 +342,9 @@
             break;
          }
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+	 memcpy(&utmpbuf,utmp_ptr,sizeof(utmpbuf));
+#else
 #ifdef HAVE_UTMPX
 	 if (res != sizeof (struct utmpx))
 #else
@@ -339,6 +354,7 @@
 	    logfile ("Error reading utmp file, continuing.");
             break;
 	 }
+#endif
 
 	 (void) time (&tempus);
 
@@ -347,24 +363,36 @@
          if (strcmp(utmpbuf.ut_line,XDM_DEV) == 0)
          {
             /* This is the console.  Is there a real name attached? */
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+            if (strlen(utmpbuf.ut_user) > 0)
+#else
             if (strlen(utmpbuf.ut_name) > 0)
+#endif
                isConsole = TRUE;                /* Yes, use it */
             else
                strcpy(console_user,"");         /* No, clear the console user */
          }
 #endif
 
-#ifdef SYSV
+#if defined(SYSV) || (defined(__FreeBSD_version) && __FreeBSD_version >= 900007)
          if (utmpbuf.ut_type == USER_PROCESS || isConsole)
 #else /* SYSV */
 	 if (utmpbuf.ut_name[0] != NULL || isConsole)
 #endif /* SYSV */
 	 {
 	    user = &users[utmptr];
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+	    (void) strncpy (tmpname, utmpbuf.ut_user, NAMELEN);
+#else
 	    (void) strncpy (tmpname, utmpbuf.ut_name, NAMELEN);
+#endif
 	    tmpname[NAMELEN] = 0;
 
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+	    if (!strcmp (user->uid, tmpname) && user->time_on == utmpbuf.ut_tv.tv_sec)
+#else
 	    if (!strcmp (user->uid, tmpname) && user->time_on == utmpbuf.ut_xtime)
+#endif
 	    {
 	       if (new)
 		  setlimits (utmptr);
@@ -414,7 +442,11 @@
                   logfile ("Error:  could not get info on supposed user %s.",user->uid);
                else
                   getgroups_func (pswd->pw_name, user->groups, pswd->pw_gid);
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+	       user->time_on = utmpbuf.ut_tv.tv_sec;
+#else
 	       user->time_on = utmpbuf.ut_xtime;
+#endif
 	       setlimits (utmptr);
 	       user->next = tempus;
                chk_session_refuse(user);
@@ -651,7 +683,7 @@
    int grpcnt = 0;
    int tgrpcnt = 0;
    
-   if (user->mgroup != 0) {
+   if (user != NULL && user->mgroup != 0) {
      for (i = 0; i < n_users; i++) {
 	   if ( (*pusers[i]).uid == user->uid)
           who = i;
