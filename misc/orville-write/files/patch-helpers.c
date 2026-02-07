--- helpers.c.orig	2000-02-20 17:28:08 UTC
+++ helpers.c
@@ -11,7 +11,7 @@
 
 struct hlp {
 	time_t time;			/* login time from wrttmp file */
-	char line[UT_LINESIZE];		/* ttyline occupied by a helper */
+	char line[sizeof(((struct utmpx *)0)->ut_line) -1];		/* ttyline occupied by a helper */
 	int busy;			/* is he busy? */
 	struct hlp *next;		/* next helper */
 	} *list= NULL;
@@ -27,7 +27,7 @@ struct hlp *curr, *prev;
 
     for (curr= list, prev= NULL; curr != NULL; prev= curr,curr= prev->next)
     {
-	if (!strncmp(tty, curr->line, UT_LINESIZE))
+	if (!strncmp(tty, curr->line, ((struct utmpx *)0)->ut_line -1))
 	{
 	    if (prev == NULL)
 	    	list= curr->next;
@@ -47,7 +47,7 @@ struct hlp *curr, *prev;
 int perms_on(struct wrttmp *w)
 {
 struct stat st;
-char devname[UT_LINESIZE+7];
+char devname[sizeof(((struct utmpx *)0)->ut_line) +6];
 
 #ifdef TTYPERMS
 #define MASK 022
@@ -59,7 +59,7 @@ char devname[UT_LINESIZE+7];
 
     /* Is his tty physically writable? */
 
-    sprintf(devname,"/dev/%.*s",UT_LINESIZE,w->wrt_line);
+    sprintf(devname,"/dev/%.*s",((struct utmpx *)0)->ut_line -1,w->wrt_line);
     if (stat(devname,&st))
     	return(0);
 
@@ -72,7 +72,7 @@ main(int argc, char **argv)
 FILE *fp;
 struct wrttmp w;
 struct wrthdr wt_head;
-struct utmp *u;
+struct utmpx *u;
 struct hlp *tmp;
 int i, j;
 int slot= 0;
@@ -146,7 +146,7 @@ int listthem= 1;
     if (list != NULL)
     {
     	/* Do the scan */
-	while ((u= getutent()) != NULL)
+	while ((u= getutxent()) != NULL)
     	{
 #ifdef USER_PROCESS
 	    if (u->ut_type != USER_PROCESS)
@@ -155,15 +155,15 @@ int listthem= 1;
 	    if ((tmp= findlist(u->ut_line)) != NULL)
 	    {
 	    	/* If the time stamps don't match, this isn't a real helper */
-	    	if (u->ut_time == tmp->time)
+	    	if (u->ut_tv.tv_sec == tmp->time)
 	    	{
 		    /* Found a real helper -- count and print */
 		    count++;
 
 		    if (listthem)
 			printf("%-*.*s %-*.*s%s\n",
-			    UT_NAMESIZE, UT_NAMESIZE, u->ut_name,
-			    UT_LINESIZE, UT_LINESIZE, u->ut_line,
+			    sizeof(u->ut_user)-1, sizeof(u->ut_user)-1, u->ut_user,
+			    sizeof(u->ut_line)-1, sizeof(u->ut_user)-1, u->ut_line,
 			    tmp->busy ? " [busy]" : "");
 
 	    	}
@@ -172,7 +172,7 @@ int listthem= 1;
 	    }
     	}
 
-    	endutent();
+    	endutxent();
     }
 
     if (!listthem)
