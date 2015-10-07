--- lib_common.c.orig	2010-02-02 22:34:36.829638978 -0800
+++ lib_common.c	2010-02-02 22:36:28.170798539 -0800
@@ -141,13 +141,13 @@
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
 
 
