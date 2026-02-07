--- wrt_me.c.orig	2003-05-30 15:22:35 UTC
+++ wrt_me.c
@@ -14,19 +14,19 @@ long mypos= -1;		/* offset of my entry in the wrttmp f
 
 void find_me()
 {
-struct utmp *ut;
+struct utmpx *ut;
 struct passwd *pw;
 int myuid;
 
     /* Search utmp for myself */
 
-    if ((ut= find_utmp(mytty)) == NULL || ut->ut_name[0] == '\0')
+    if ((ut= find_utmp(mytty)) == NULL || ut->ut_user[0] == '\0')
     {
 	printf("%s: Panic - Unable to find your tty (%s) in "_PATH_UTMP"\n",
 	    progname, mytty);
 	done(1);
     }
-    strncpy(myname, ut->ut_name, UT_NAMESIZE);
+    strncpy(myname, ut->ut_user, UT_NAMESIZE);
 
     /* Check if this is our real identity */
 #ifndef SLOWPASSWD
@@ -48,7 +48,7 @@ int myuid;
 
     /* Find my wrt_tmp entry */
 
-    find_wrttmp(mytty, ut->ut_time, &mywrt, &mypos);
+    find_wrttmp(mytty, ut->ut_tv.tv_sec, &mywrt, &mypos);
 }
 
 
