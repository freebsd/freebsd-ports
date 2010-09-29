--- doinkd.c.orig	2010-01-25 16:06:48.000000000 -0800
+++ doinkd.c	2010-01-25 16:09:39.000000000 -0800
@@ -335,7 +335,7 @@
          if (strcmp(utmpbuf.ut_line,XDM_DEV) == 0)
          {
             /* This is the console.  Is there a real name attached? */
-            if (strlen(utmpbuf.ut_name) > 0)
+            if (strlen(utmpbuf.ut_user) > 0)
                isConsole = TRUE;                /* Yes, use it */
             else
                strcpy(console_user,"");         /* No, clear the console user */
@@ -349,10 +349,10 @@
 #endif /* SYSV */
 	 {
 	    user = &users[utmptr];
-	    (void) strncpy (tmpname, utmpbuf.ut_name, NAMELEN);
+	    (void) strncpy (tmpname, utmpbuf.ut_user, NAMELEN);
 	    tmpname[NAMELEN] = 0;
 
-	    if (!strcmp (user->uid, tmpname) && user->time_on == utmpbuf.ut_xtime)
+	    if (!strcmp (user->uid, tmpname) && user->time_on == utmpbuf.ut_tv.tv_sec)
 	    {
 	       if (new)
 		  setlimits (utmptr);
@@ -402,7 +402,7 @@
                   logfile ("Error:  could not get info on supposed user %s.",user->uid);
                else
                   getgroups_func (pswd->pw_name, user->groups, pswd->pw_gid);
-	       user->time_on = utmpbuf.ut_xtime;
+	       user->time_on = utmpbuf.ut_tv.tv_sec;
 	       setlimits (utmptr);
 	       user->next = tempus;
                chk_session_refuse(user);
