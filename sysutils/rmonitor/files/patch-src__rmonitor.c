--- src/rmonitor.c.orig	2015-09-18 17:10:16 UTC
+++ src/rmonitor.c
@@ -88,7 +88,7 @@ static const char rcsid[] = "$Id: rmonit
 #include <sys/vmmeter.h>
 #include <time.h>
 #include <unistd.h>
-#include <utmp.h>
+#include <utmpx.h>
 
 
 #define DEFTOL      2.5				  /* default tolerance */
@@ -294,13 +294,13 @@ void getstat ( char *stat )			  /* -----
 #define samples 2
   double lavg[samples];
   int    dbufs  = 0;
-  int    len;
+  long   len;
   int    maxf   = -1;
   int    maxp   = -1;
   int    memfre = 0;
   int    memtot = 0;
   int    memuse = 0;
-  int    nu     = -1;
+  int    nu     = 0;
   int    np     = -1;
   int    openf  = -1;
   int    pgcnt  = 0;
@@ -309,9 +309,8 @@ void getstat ( char *stat )			  /* -----
   int    pgsize = 0;
   int    slvl   = 0;
   int    vn[3];
-  int    utfd;
   time_t ct;
-  struct utmp utmprec;
+  struct utmpx *utmprec;
 
   union {
     char   buf[STRLEN];
@@ -402,14 +401,12 @@ void getstat ( char *stat )			  /* -----
 
   if (getloadavg(lavg, samples) != samples) errmsg("getloadavg");
 
-  if ((utfd = open(_PATH_UTMP, O_RDONLY)) >= 0) {
-    nu = 0;
-    while (read(utfd, &utmprec, sizeof utmprec) > 0)
-      if (*(utmprec.ut_name)) nu++;
-    if (close(utfd) < 0) errmsg("close");
+  setutxent();
+  while ((utmprec = getutxent()) != NULL) {
+    if (utmprec->ut_type == USER_PROCESS)
+      nu++;
   }
-  else
-    errmsg("open");
+  endutxent();
 
 #if __FreeBSD_version >= 420000
   snprintf(stat, STRLEN,
