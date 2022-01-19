--- include/squid.h.orig	2021-12-07 14:15:52 UTC
+++ include/squid.h
@@ -9,6 +9,7 @@
 #ifndef SQUID_CONFIG_H
 #define SQUID_CONFIG_H
 
+#define _WITH_CPU_SET_T
 #include "autoconf.h"       /* For GNU autoconf variables */
 
 #if !defined(HAVE_SQUID)
