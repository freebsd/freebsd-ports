--- smf-sav.c.orig	2006-10-26 05:15:10.000000000 +0900
+++ smf-sav.c	2015-06-02 13:30:44.250725000 +0900
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
+#define CONFIG_FILE		"%%PREFIX%%/etc/smf-sav.conf"
 #define PUBLIC_NAME		"yourhost.yourdomain.tld"
 #define SAFE_CALLBACK		"postmaster@yourdomain.tld"
 #define SYSLOG_FACILITY		LOG_MAIL
