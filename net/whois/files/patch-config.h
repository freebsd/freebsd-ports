--- config.h.orig	2020-01-09 21:40:46 UTC
+++ config.h
@@ -7,9 +7,7 @@
 #define DEFAULTSERVER   "whois.arin.net"
 
 /* Configuration file */
-/*
-#define CONFIG_FILE "/etc/whois.conf"
-*/
+#define CONFIG_FILE "%%MWHOISCONF%%"
 
 
 /* autoconf in cpp macros */
@@ -17,17 +15,12 @@
 # include <sys/param.h>
 #endif
 
-#ifdef __GLIBC__
-# define ENABLE_NLS
-#endif
-
 #ifdef __FreeBSD__
 /* which versions? */
 # define HAVE_GETOPT_LONG
 # define HAVE_GETADDRINFO
-# define ENABLE_NLS
 # ifndef LOCALEDIR
-#  define LOCALEDIR "/usr/local/share/locale"
+#  define LOCALEDIR "%%PREFIX%%/share/locale"
 # endif
 #endif
 
@@ -116,7 +109,7 @@
 
 #ifdef ENABLE_NLS
 # ifndef NLS_CAT_NAME
-#  define NLS_CAT_NAME   "whois"
+#  define NLS_CAT_NAME   "%%MWHOIS%%"
 # endif
 # ifndef LOCALEDIR
 #  define LOCALEDIR     "/usr/share/locale"
