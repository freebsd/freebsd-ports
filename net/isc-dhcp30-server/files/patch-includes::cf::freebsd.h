--- includes/cf/freebsd.h.orig	Wed Sep  1 19:06:36 2004
+++ includes/cf/freebsd.h	Mon May 15 09:13:18 2006
@@ -33,7 +33,7 @@
  */
 
 #include <syslog.h>
-#include <sys/types.h>
+#include <sys/param.h>
 #include <string.h>
 #include <paths.h>
 #include <errno.h>
@@ -82,7 +82,7 @@
 
 /* Time stuff... */
 #include <sys/time.h>
-#define TIME time_t
+#define TIME u_int32_t
 #define GET_TIME(x)	time ((x))
 
 #define HAVE_SA_LEN
@@ -97,6 +97,10 @@
 #define SOCKLEN_T int
 #endif
 
+#ifdef RESCUE
+#define _PATH_DHCLIENT_SCRIPT	"/rescue/dhclient-script"
+#endif
+
 #if defined (USE_DEFAULT_NETWORK)
 #  define USE_BPF
 #endif
@@ -107,6 +111,9 @@
  #endif /* HAVE_DEV_RANDOM */
 
 const char *cmds[] = {
+#ifndef RESCUE
+	/* rescue environment can't rely on these ... */
+	/* Actually, /sbin/dhclient shouldn't use these, either. */
 	"/bin/ps -axlw 2>&1",
 	"/usr/sbin/arp -an 2>&1",
 	"/usr/bin/netstat -an 2>&1",
@@ -117,10 +124,12 @@
 	"/usr/sbin/iostat  2>&1",
 	"/usr/bin/vmstat  2>&1",
 	"/usr/bin/w  2>&1",
+#endif
 	NULL
 };
 
 const char *dirs[] = {
+#ifndef RESCUE
 	"/tmp",
 	"/usr/tmp",
 	".",
@@ -130,13 +139,16 @@
 	"/var/mail",
 	"/home",
 	"/usr/home",
+#endif
 	NULL
 };
 
 const char *files[] = {
+#ifndef RESCUE
 	"/var/log/messages",
 	"/var/log/wtmp",
 	"/var/log/lastlog",
+#endif
 	NULL
 };
 #endif /* NEED_PRAND_CONF */
