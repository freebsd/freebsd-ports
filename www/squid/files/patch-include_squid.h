--- include/squid.h.orig	2021-05-10 02:02:34.000000000 -0700
+++ include/squid.h	2021-11-29 08:48:04.020714000 -0800
@@ -9,6 +9,7 @@
 #ifndef SQUID_CONFIG_H
 #define SQUID_CONFIG_H
 
+#define _WITH_CPU_SET_T
 #include "autoconf.h"       /* For GNU autoconf variables */
 
 #if !defined(HAVE_SQUID)
