--- smf-sav.c.orig	Wed Oct 25 23:15:10 2006
+++ smf-sav.c	Wed Aug 29 15:54:13 2007
@@ -20,11 +20,7 @@
 #endif
 
 #include <arpa/inet.h>
-#if __linux__ || __sun__
 #include <arpa/nameser.h>
-#else
-#include <bind/arpa/nameser.h>
-#endif
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
@@ -33,20 +29,12 @@
 #endif
 #include <grp.h>
 #include <libmilter/mfapi.h>
-#if __linux__ || __sun__
 #include <netdb.h>
-#else
-#include <bind/netdb.h>
-#endif
 #include <netinet/in.h>
 #include <pthread.h>
 #include <pwd.h>
 #include <regex.h>
-#if __linux__ || __sun__
 #include <resolv.h>
-#else
-#include <bind/resolv.h>
-#endif
 #include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -68,7 +56,7 @@
 #define hash_size(x)		((unsigned long) 1 << x)
 #define hash_mask(x)		(hash_size(x) - 1)
 
-#define CONFIG_FILE		"/etc/mail/smfs/smf-sav.conf"
+#define CONFIG_FILE		"/usr/local/etc/smfsav.conf"
 #define PUBLIC_NAME		"yourhost.yourdomain.tld"
 #define SAFE_CALLBACK		"postmaster@yourdomain.tld"
 #define SYSLOG_FACILITY		LOG_MAIL
@@ -81,9 +69,9 @@
 #define TO_PASS_TTL		3600
 #define TO_TEMPFAIL_TTL		300
 #define TO_FAIL_TTL		3600
-#define WORK_SPACE		"/var/run/smfs"
-#define OCONN			"unix:" WORK_SPACE "/smf-sav.sock"
-#define USER			"smfs"
+#define WORK_SPACE		"/var/run/smfsav"
+#define OCONN			"unix:" WORK_SPACE "/smfsav.sock"
+#define USER			"smfsav"
 
 #define DNS_RETRANS		7
 #define DNS_RETRY		4
