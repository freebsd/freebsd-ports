--- lib_common.c.orig	2004-09-29 04:43:53 UTC
+++ lib_common.c
@@ -89,7 +89,7 @@ char *tty;
     }
     if ((tty= ttyname(2)) == NULL || strlen(tty) < 5)
     {
-    	printf("%s: Not on a valid tty\n");
+       printf("%s: Not on a valid tty\n", progname);
 	return 2;
     }
     strncpy(mydevname,tty,UT_LINESIZE+10);
@@ -141,13 +141,13 @@ int init_wstream(int mode)
  * fail.  The tty name need not be null terminated.
  */
 
-struct utmp *find_utmp(char *tty)
+struct utmpx *find_utmp(char *tty)
 {
-struct utmp tmputmp;
+struct utmpx tmputmp;
 
     strncpy(tmputmp.ut_line, tty, UT_LINESIZE);
     setutent(); /* open and/or rewind */
-    return getutline(&tmputmp);
+    return getutxline(&tmputmp);
 }
 
 
