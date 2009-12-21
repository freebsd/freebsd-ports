--- utmp.c.orig	2003-09-08 07:27:17.000000000 -0700
+++ utmp.c	2009-12-21 15:10:06.000000000 -0800
@@ -21,6 +21,9 @@
  ****************************************************************
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -70,8 +73,13 @@
  *  (won't work for login-slots)
  */
 #if (defined(sun) && defined(SVR4) && defined(GETUTENT)) || defined(HAVE_UTEMPTER)
+/* XXX FreeBSD-9 includes libutempter however if UTMP_HELPER is defined,
+       the build is broken due to utmpfd not being defined.
+*/
+#if defined(__FreeBSD_version) && __FreeBSD_version < 900004 || !defined(__FreeBSD_version)
 # define UTMP_HELPER
 #endif
+#endif
 
 
 
@@ -726,9 +734,12 @@
 char *line, *user;
 int pid;
 {
+  time_t temp;
+
   strncpy(u->ut_line, line, sizeof(u->ut_line));
   strncpy(u->ut_name, user, sizeof(u->ut_name));
-  (void)time((time_t *)&u->ut_time);
+  (void)time(&temp);
+  u->ut_time = temp;
 }
 
 static slot_t
