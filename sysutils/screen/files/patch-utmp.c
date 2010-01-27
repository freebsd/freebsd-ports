--- utmp.c.orig	2003-09-08 07:27:17.000000000 -0700
+++ utmp.c	2010-01-26 22:27:46.000000000 -0800
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
 
 
 
@@ -590,9 +598,11 @@
 {
   u->ut_type = DEAD_PROCESS;
 #if !defined(linux) || defined(EMPTY)
+#ifndef __FreeBSD__
   u->ut_exit.e_termination = 0;
   u->ut_exit.e_exit = 0;
 #endif
+#endif
 #if !defined(sun) || !defined(SVR4)
   u->ut_user[0] = 0;	/* for Digital UNIX, kilbi@rad.rwth-aachen.de */
 #endif
@@ -618,7 +628,9 @@
 #endif /* sgi */
   strncpy(u->ut_line, line, sizeof(u->ut_line));
   u->ut_pid = pid;
+#ifndef __FreeBSD__
   (void)time((time_t *)&u->ut_time);
+#endif
 }
 
 static slot_t
@@ -630,6 +642,7 @@
 
 
 #else /* GETUTENT */
+#if defined(__FreeBSD_version) && __FreeBSD_version < 900008
 
 /*********************************************************************
  *
@@ -726,9 +739,12 @@
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
@@ -759,6 +775,7 @@
   return slot;
 }
 
+#endif	/* __FreeBSD_version */
 #endif	/* GETUTENT */
 
 
