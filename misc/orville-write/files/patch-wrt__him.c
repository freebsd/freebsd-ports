--- wrt_him.c.orig	2004-09-29 03:32:13 UTC
+++ wrt_him.c
@@ -116,7 +116,7 @@ int rc;
 extern struct wrttmp mywrt;
 
     /* Open utmp file */
-    setutent();
+    setutxent();
 
     /* Look me up */
     find_me();
@@ -204,7 +204,7 @@ int write_me;
 int perm, hisperm= 0;
 time_t hisatime= 0;
 time_t atime;
-struct utmp *ut;
+struct utmpx *ut;
 struct wrttmp tmpwrt;
 long tmppos;
 
@@ -213,16 +213,14 @@ long tmppos;
     {
         /* Check if this is the target user, ignoring X-window lines */
         if (ut->ut_line[0] != ':' &&
-#ifdef USER_PROCESS
 	    ut->ut_type == USER_PROCESS &&
-#endif
-	    !strncmp(hisname, ut->ut_name, UT_NAMESIZE))
+	    !strncmp(hisname, ut->ut_user, UT_NAMESIZE))
 	{
 	    /* Count matches */
 	    cnt++;
 
 	    /* Find wrttmp entry */
-	    find_wrttmp(ut->ut_line, ut->ut_time, &tmpwrt, &tmppos);
+	    find_wrttmp(ut->ut_line, ut->ut_tv.tv_sec, &tmpwrt, &tmppos);
 
 	    /* Is this guy writing me? */
 	    write_me= !strncmp(tmpwrt.wrt_what,myname,UT_NAMESIZE);
@@ -283,7 +281,7 @@ long tmppos;
 
 int find_tty()
 {
-struct utmp *ut;
+struct utmpx *ut;
 
     if ((ut= find_utmp(histty)) == NULL)
 	return(1);
@@ -291,23 +289,23 @@ struct utmp *ut;
     if (*hisname != '\0')
     {
 	/* Does the name not match? */
-	if (strncmp(hisname, ut->ut_name, UT_NAMESIZE))
+	if (strncmp(hisname, ut->ut_user, UT_NAMESIZE))
 	    return(2);
     }
     else
     {
 	/* Is anyone on that line? */
-	if (*ut->ut_name == '\0')
+	if (*ut->ut_user == '\0')
 	{
 	    printf("No one logged onto %s\n",histty);
 	    wrtlog("FAIL: empty tty");
 	    done(1);
 	}
-	strncpy(hisname, ut->ut_name, UT_NAMESIZE);
+	strncpy(hisname, ut->ut_user, UT_NAMESIZE);
     }
     printf("%s to %s on %s...",what[telegram],hisname,histty);
     if (!telegram) putchar('\n');
-    find_wrttmp(histty,ut->ut_time,&hiswrt,&hispos);
+    find_wrttmp(histty,ut->ut_tv.tv_sec,&hiswrt,&hispos);
     return(0);
 }
 
@@ -321,7 +319,7 @@ struct utmp *ut;
 
 void find_answer()
 {
-struct utmp *ut;
+struct utmpx *ut;
 int slot;
 
     lseek(wstream,hispos= wrttmp_offset(slot= 0),0);
@@ -332,9 +330,9 @@ int slot;
 	{
 	    /* Found someone writing me - get his name from utmp */
 	    strncpy(histty,hiswrt.wrt_line,UT_LINESIZE);
-	    if ((ut= find_utmp(histty)) != NULL && ut->ut_name[0] != '\0')
+	    if ((ut= find_utmp(histty)) != NULL && ut->ut_user[0] != '\0')
 	    {
-		strncpy(hisname,ut->ut_name,UT_NAMESIZE);
+		strncpy(hisname,ut->ut_user,UT_NAMESIZE);
 		printf("Replying to %s on %s...",hisname,histty);
 		if (!telegram) putchar('\n');
 		return;
@@ -363,7 +361,7 @@ int nhelpers= 0;	/* Number of helpers on */
 int ahelpers= 0;	/* Number of helpers available */
 int previous;
 int slot= 0;
-struct utmp *ut;
+struct utmpx *ut;
 struct wrttmp tmpwrt;
 long tmppos;
 
@@ -387,7 +385,7 @@ long tmppos;
 	
 	/* Find the helper candidate in utmp - if he's not there skip out */
 	if ((ut= find_utmp(tmpwrt.wrt_line)) == NULL ||
-	    ut->ut_name[0] == '\0' || ut->ut_time != tmpwrt.wrt_time)
+	    ut->ut_user[0] == '\0' || ut->ut_tv.tv_sec != tmpwrt.wrt_time)
 	    continue;
 	
 	/* Reject helpers with their message permissions off */
@@ -397,14 +395,14 @@ long tmppos;
 	    {
 	    	/* Perms off - but am I in .yeswrite file? */
 	    	if (!f_exceptions || tmpwrt.wrt_except != 'y' ||
-	    	    !isuexception(ut->ut_name, 1, myname))
+	    	    !isuexception(ut->ut_user, 1, myname))
 	    	    	continue;
 	    }
 	    else
 	    {
 	    	/* Perms on - but am I in .nowrite file? */
 	    	if (f_exceptions && tmpwrt.wrt_except == 'y' &&
-	    	    isuexception(ut->ut_name, 0, myname))
+	    	    isuexception(ut->ut_user, 0, myname))
 	    	    	continue;
 	    }
         }
@@ -422,7 +420,7 @@ long tmppos;
 	ahelpers++;
 
 	/* Has he helped us before? */
-	previous= !strncmp(ut->ut_name, mywrt.wrt_last, UT_NAMESIZE);
+	previous= !strncmp(ut->ut_user, mywrt.wrt_last, UT_NAMESIZE);
 
 	/* So roll the dice to see if we will choose him */
 	if (!previous && (unsigned)RAND() > (unsigned)RAND_MAX / ahelpers)
@@ -430,7 +428,7 @@ long tmppos;
 
 	/* We chose him, so make him our helper candidate so far */
 	strncpy(histty, tmpwrt.wrt_line, UT_LINESIZE);
-	strncpy(hisname, ut->ut_name, UT_NAMESIZE);
+	strncpy(hisname, ut->ut_user, UT_NAMESIZE);
 	hiswrt= tmpwrt;
 	hispos= tmppos;
 
