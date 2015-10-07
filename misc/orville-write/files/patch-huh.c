--- huh.c.orig	2010-02-02 23:11:01.823876514 -0800
+++ huh.c	2010-02-02 23:11:54.475034412 -0800
@@ -34,13 +34,13 @@
 
 int record_on()
 {
-struct utmp *ut;
+struct utmpx *ut;
 struct wrttmp wt;
 char *tty;
 long pos;
 
     /* Open the utmp file */
-    setutent();
+    setutxent();
 
     /* Open the wrttmp file */
     if (init_wstream(O_RDONLY)) return 1;
@@ -50,13 +50,13 @@
     tty= mydevname+5;
 
     /* Find our entry in the utmp file */
-    if ((ut= find_utmp(tty)) == NULL || ut->ut_name[0] == '\0') return 1;
+    if ((ut= find_utmp(tty)) == NULL || ut->ut_user[0] == '\0') return 1;
 
     /* Find the entry in the wrttmp file */
-    find_wrttmp(tty, ut->ut_time, &wt, &pos);
+    find_wrttmp(tty, ut->ut_tv.tv_sec, &wt, &pos);
 
     /* Close utmp file */
-    endutent();
+    endutxent();
 
     return (wt.wrt_record != 'n');
 }
