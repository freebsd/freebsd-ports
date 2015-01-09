--- src/condor_sysapi/idle_time.cpp.orig	2014-11-26 11:22:10.000000000 -0600
+++ src/condor_sysapi/idle_time.cpp	2014-12-27 16:42:00.000000000 -0600
@@ -205,19 +205,28 @@
 	return;
 }
 
+#if !defined(CONDOR_UTMPX)
 #include <utmp.h>
 #define UTMP_KIND utmp
+#endif
 
 #if defined(LINUX)
 static const char *UtmpName = "/var/run/utmp";
 static const char *AltUtmpName = "/var/adm/utmp";
-#elif defined(CONDOR_FREEBSD)
+// FreeBSD 9 made a clean break from utmp to utmpx
+#elif defined(CONDOR_FREEBSD) && !defined(CONDOR_UTMPX)
 static char *UtmpName = "/var/run/utmp";
 static char *AltUtmpName = "";
-#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11)
+#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11) || defined(CONDOR_UTMPX)
 #include <utmpx.h>
+#if defined(CONDOR_UTMPX)
+#define ut_name ut_user
+static char *UtmpName = "/var/run/utx.active";
+static char *AltUtmpName = "";
+#else
 static char *UtmpName = "/etc/utmpx";
 static char *AltUtmpName = "/var/adm/utmpx";
+#endif
 #undef UTMP_KIND
 #define UTMP_KIND utmpx
 #elif defined(HPUX11)
