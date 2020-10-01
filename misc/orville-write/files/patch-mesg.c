--- mesg.c.orig	2004-09-29 04:43:14 UTC
+++ mesg.c
@@ -19,7 +19,7 @@
 char *mytty;			/* my tty name in tty?? format */
 long mypos;			/* offset of my entry in wrttmp file */
 struct wrttmp mywrt;		/* my wrttmp entry */
-struct utmp myutmp;		/* A tmp buffer for reading utmp entries */
+struct utmpx myutmp;		/* A tmp buffer for reading utmp entries */
 
 char silent= FALSE;		/* generates no output if true */
 int verbose= FALSE;		/* generate whole table of output if true */
@@ -335,7 +335,7 @@ char flag;
     }
 
     /* Close the utmp file */
-    endutent();
+    endutxent();
 
    if (f_wrthist != NULL &&
        !wassilent && (new[SMESG] == 'n' || new[SEXCP] == 'y'))
@@ -549,12 +549,12 @@ int code;
 
 void do_disconnect()
 {
-struct utmp *ut;		/* A tmp buffer for reading utmp entries */
+struct utmpx *ut;		/* A tmp buffer for reading utmp entries */
 struct wrttmp hiswrt;		/* Someone's wrttmp entry */
 int slot= 0;
 
     /* Rewind utmp file */
-    setutent();
+    setutxent();
 
     /* For each user who is writing me */
     for (;;)
@@ -564,16 +564,16 @@ int slot= 0;
 	       sizeof(struct wrttmp))
 	   break;
 
-	if (!strncmp(hiswrt.wrt_what, myutmp.ut_name, UT_NAMESIZE))
+	if (!strncmp(hiswrt.wrt_what, myutmp.ut_user, sizeof(myutmp.ut_user)))
 	{
 	    setutent();
 	    /* Check apparant writer against utmp file */
-	    while ((ut= getutent()) != NULL)
+	    while ((ut= getutxent()) != NULL)
 		if (
 #ifdef USER_PROCESS
 		    ut->ut_type == USER_PROCESS &&
 #endif
-		    !strncmp(hiswrt.wrt_line, ut->ut_line, UT_LINESIZE))
+		    !strncmp(hiswrt.wrt_line, ut->ut_line, sizeof(ut->ut_line)))
 		{
 		    /* Writer is for real: bonk him one */
 		    kill(hiswrt.wrt_pid, SIGTERM);
@@ -590,10 +590,10 @@ int slot= 0;
 
 int find_me()
 {
-struct utmp *ut;
+struct utmpx *ut;
 
     /* Find our entry in the Utmp file */
-    if ((ut= find_utmp(mytty)) == NULL || ut->ut_name[0] == '\0')
+    if ((ut= find_utmp(mytty)) == NULL || ut->ut_user[0] == '\0')
     {
 	printf("%s: Unable to find your tty (%s) in utmp file\n",
 		progname,mytty);
@@ -602,7 +602,7 @@ struct utmp *ut;
     myutmp= *ut;
 
     /* Find the entry in the wrttmp file */
-    find_wrttmp(mytty,myutmp.ut_time,&mywrt,&mypos);
+    find_wrttmp(mytty,myutmp.ut_tv.tv_sec,&mywrt,&mypos);
 }
 
 
@@ -616,13 +616,13 @@ int may_help()
 #define BUFSZ 80
 FILE *hfp;
 char buf[BUFSZ+1];
-char myname[UT_NAMESIZE+2];
+char myname[sizeof(myutmp.ut_user)+1];
 
 	if (f_helperlist == NULL || (hfp= fopen(f_helperlist,"r")) == NULL)
 		return TRUE;
 	
-	strncpy(myname,myutmp.ut_name,UT_NAMESIZE);
-	myname[UT_NAMESIZE]= '\0';
+	strncpy(myname,myutmp.ut_user,sizeof(myutmp.ut_user) -1);
+	myname[sizeof(myutmp.ut_user)]= '\0';
 	strcat(myname,"\n");
 	
 	while (fgets(buf,BUFSZ,hfp) != NULL)
@@ -645,7 +645,7 @@ int window_warning(int newmode)
 {
 struct wrthist *hist;
 struct wrttmp w;
-struct utmp *u;
+struct utmpx *u;
 long writer, writee;
 time_t now;
 int n, foundsome= 0;
@@ -669,7 +669,7 @@ FILE *fp;
 
     for (writee= 0; writee < n; writee++)
     {
-	if (hist[writee].tm > myutmp.ut_time &&
+	if (hist[writee].tm > myutmp.ut_tv.tv_sec &&
 	    now - hist[writee].tm <= f_answertel)
 	{
 	    /* Fetch "his" wrttmp entry - it may actually belong to a previous
@@ -688,12 +688,12 @@ FILE *fp;
 	    /* Fetch his utmp entry, and confirm that the current user was
 	     * already logged in there when we sent our last telegram there.
 	     */
-	    if ((u= find_utmp(w.wrt_line)) == NULL || u->ut_name[0] == '\0' ||
-	        hist[writee].tm < u->ut_time)
+	    if ((u= find_utmp(w.wrt_line)) == NULL || u->ut_user[0] == '\0' ||
+	        hist[writee].tm < u->ut_tv.tv_sec)
 	    	continue;
 
 	    /* Check if due to exceptions he may write us anyway */
-	    if (f_exceptions && newmode > 1 && maywriteme(u->ut_name, newmode))
+	    if (f_exceptions && newmode > 1 && maywriteme(u->ut_user, newmode))
 	    	continue;
 
 	    if (!foundsome)
@@ -703,8 +703,8 @@ FILE *fp;
 	        foundsome= 1;
 	    }
 	    printf("  %-*.*s %-*.*s %4.1f more minutes\n",
-	    	UT_NAMESIZE, UT_NAMESIZE, u->ut_name,
-	    	UT_LINESIZE, UT_LINESIZE, u->ut_line,
+	    	sizeof(u->ut_user) -1, sizeof(u->ut_user) -1, u->ut_user,
+	    	sizeof(u->ut_line) -1, sizeof(u->ut_line) -1, u->ut_line,
 	        (float)(f_answertel - now + hist[writee].tm)/60.0);
 	}
     }
@@ -717,7 +717,7 @@ FILE *fp;
 
 char *myhomedir()
 {
-char myname[UT_NAMESIZE+2];
+char myname[sizeof(myutmp.ut_user)+1];
 struct passwd *pw;
 char *dir, *getenv();
 
@@ -726,8 +726,8 @@ char *dir, *getenv();
 	return dir;
 
     /* If that don't work, try passwd file */
-    strncpy(myname,myutmp.ut_name,UT_NAMESIZE);
-    myname[UT_NAMESIZE]= '\0';
+    strncpy(myname,myutmp.ut_user,sizeof(myutmp.ut_user) -1);
+    myname[sizeof(myutmp.ut_user)]= '\0';
     if ((pw= getpwnam(myname)) != NULL)
     	return pw->pw_dir;
 
