--- src/condor_sysapi/idle_time.cpp.bak	2012-10-24 23:10:41.000000000 -0500
+++ src/condor_sysapi/idle_time.cpp	2012-12-01 14:46:20.000000000 -0600
@@ -205,19 +205,30 @@
 	return;
 }
 
+// FreeBSD 9 made a clean break from utmp to utmpx
+#if !defined(CONDOR_FREEBSD9)
 #include <utmp.h>
 #define UTMP_KIND utmp
+#endif
 
 #if defined(LINUX)
 static const char *UtmpName = "/var/run/utmp";
 static const char *AltUtmpName = "/var/adm/utmp";
-#elif defined(CONDOR_FREEBSD)
+// FreeBSD 9 made a clean break from utmp to utmpx
+#elif defined(CONDOR_FREEBSD) && !defined(CONDOR_FREEBSD9)
 static char *UtmpName = "/var/run/utmp";
 static char *AltUtmpName = "";
-#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11)
+// FreeBSD 9 made a clean break from utmp to utmpx
+#elif defined(Solaris28) || defined(Solaris29) || defined(Solaris10) || defined(Solaris11) || defined(CONDOR_FREEBSD9)
 #include <utmpx.h>
+#if defined(CONDOR_FREEBSD9)
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
