--- src/condor_sysapi/idle_time.cpp.orig	2012-01-17 10:53:14.000000000 -0600
+++ src/condor_sysapi/idle_time.cpp	2012-04-07 14:37:17.000000000 -0500
@@ -202,17 +202,22 @@
 	return;
 }
 
+// FreeBSD 9 made a clean break from utmp to utmpx
+#if !defined(CONDOR_FREEBSD9)
 #include <utmp.h>
 #define UTMP_KIND utmp
+#endif
 
 #if defined(LINUX)
 static char *UtmpName = "/var/run/utmp";
 static char *AltUtmpName = "/var/adm/utmp";
-#elif defined(CONDOR_FREEBSD)
+// FreeBSD 9 made a clean break from utmp to utmpx
+#elif defined(CONDOR_FREEBSD) && !defined(CONDOR_FREEBSD9)
 static char *UtmpName = "/var/run/utmp";
 static char *AltUtmpName = "";
-#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11)
+#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11) || defined(CONDOR_FREEBSD9)
 #include <utmpx.h>
+#define ut_name ut_user
 static char *UtmpName = "/etc/utmpx";
 static char *AltUtmpName = "/var/adm/utmpx";
 #undef UTMP_KIND
