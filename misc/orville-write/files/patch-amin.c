--- amin.c.orig	2004-09-29 04:43:10 UTC
+++ amin.c
@@ -194,16 +194,16 @@ char *r;
 
 void locate_wrttmp(char *tty, struct wrttmp *wbuf, long *pos)
 {
-struct utmp *ut;
+struct utmpx *ut;
 
     /* Find utmp entry */
-    if ((ut= find_utmp(tty)) == NULL || ut->ut_name[0] == '\0')
+    if ((ut= find_utmp(tty)) == NULL || ut->ut_user[0] == '\0')
     {
 	printf("%s: Can't find your tty (%s) in utmp\n",progname,tty);
 	exit(1);
     }
 
-    find_wrttmp(tty, ut->ut_time, wbuf, pos);
+    find_wrttmp(tty, ut->ut_tv.tv_sec, wbuf, pos);
 }
 
 
@@ -230,7 +230,7 @@ char *shortcmd;		/* command without full pathname */
     }
 
     /* Close utmp file */
-    endutent();
+    endutxent();
 
     /* Figure out name of program being exec'ed */
     if ((shortcmd= strrchr(fullcmd,'/')) == NULL)
@@ -241,7 +241,7 @@ char *shortcmd;		/* command without full pathname */
     /* Fix my entry in wrttmp */
     newwrt= mywrt;
     newwrt.wrt_what[0]= '!';
-    strncpy(newwrt.wrt_what+1, shortcmd, UT_NAMESIZE-1);
+    strncpy(newwrt.wrt_what+1, shortcmd, sizeof(((struct utmpx *)0)->ut_user)-2);
 #ifndef TTYPERMS
     if (tmp_mesg != 's') newwrt.wrt_mesg= tmp_mesg;
 #endif
