--- appl/ftp/ftpd/logwtmp.c.orig	2010-09-13 09:23:34.000000000 +0200
+++ appl/ftp/ftpd/logwtmp.c	2010-10-26 22:30:55.000000000 +0200
@@ -64,6 +64,7 @@
 #include <roken.h>
 #include "extern.h"
 
+#ifndef HAVE_UTMPX_H
 #ifndef WTMP_FILE
 #ifdef _PATH_WTMP
 #define WTMP_FILE _PATH_WTMP
@@ -71,6 +72,7 @@
 #define WTMP_FILE "/var/adm/wtmp"
 #endif
 #endif
+#endif
 
 #ifdef HAVE_ASL_H
 
@@ -109,11 +111,17 @@
 #ifdef WTMPX_FILE
     static int fdx;
 #endif
+#ifdef HAVE_UTMP_H
     struct utmp ut;
-#ifdef WTMPX_FILE
+#endif
+#if defined(WTMPX_FILE) || defined(HAVE_UTMPX_H)
     struct utmpx utx;
 #endif
 
+#ifdef HAVE_UTMPX_H
+    memset(&utx, 0, sizeof(struct utmpx));
+#endif
+#ifdef HAVE_UTMP_H
     memset(&ut, 0, sizeof(struct utmp));
 #ifdef HAVE_STRUCT_UTMP_UT_TYPE
     if(name[0])
@@ -130,8 +138,9 @@
     strncpy(ut.ut_host, host, sizeof(ut.ut_host));
 #endif
     ut.ut_time = time(NULL);
+#endif
 
-#ifdef WTMPX_FILE
+#if defined(WTMPX_FILE) || defined(HAVE_UTMPX_H)
     strncpy(utx.ut_line, line, sizeof(utx.ut_line));
     strncpy(utx.ut_user, name, sizeof(utx.ut_user));
     strncpy(utx.ut_host, host, sizeof(utx.ut_host));
@@ -154,15 +163,23 @@
 	utx.ut_type = DEAD_PROCESS;
 #endif
 
+#ifdef HAVE_UTMPX_H
+    pututxline(&utx);
+#endif
+
     if(!init){
+#ifdef WTMP_FILE
 	fd = open(WTMP_FILE, O_WRONLY|O_APPEND, 0);
+#endif
 #ifdef WTMPX_FILE
 	fdx = open(WTMPX_FILE, O_WRONLY|O_APPEND, 0);
 #endif
 	init = 1;
     }
     if(fd >= 0) {
+#ifdef WTMP_FILE
 	write(fd, &ut, sizeof(struct utmp)); /* XXX */
+#endif	
 #ifdef WTMPX_FILE
 	write(fdx, &utx, sizeof(struct utmpx));
 #endif	
