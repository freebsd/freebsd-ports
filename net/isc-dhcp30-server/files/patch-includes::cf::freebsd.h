--- includes/cf/freebsd.h.orig	Wed Mar  3 02:32:39 2004
+++ includes/cf/freebsd.h	Wed Mar  3 02:31:56 2004
@@ -42,7 +42,7 @@
  */
 
 #include <syslog.h>
-#include <sys/types.h>
+#include <sys/param.h>
 #include <string.h>
 #include <paths.h>
 #include <errno.h>
@@ -101,6 +101,10 @@
 #define SOCKLEN_T int
 #endif
 
+#ifdef RESCUE
+#define _PATH_DHCLIENT_SCRIPT	"/rescue/dhclient-script"
+#endif
+
 #if defined (USE_DEFAULT_NETWORK)
 #  define USE_BPF
 #endif
@@ -111,6 +115,9 @@
  #endif /* HAVE_DEV_RANDOM */
 
 const char *cmds[] = {
+#ifndef RESCUE
+	/* rescue environment can't rely on these ... */
+	/* Actually, /sbin/dhclient shouldn't use these, either. */
 	"/bin/ps -axlw 2>&1",
 	"/usr/sbin/arp -an 2>&1",
 	"/usr/bin/netstat -an 2>&1",
@@ -121,10 +128,12 @@
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
@@ -134,13 +143,16 @@
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
