--- include/squid.h.orig	2023-02-28 09:10:25 UTC
+++ include/squid.h
@@ -9,6 +9,7 @@
 #ifndef SQUID_CONFIG_H
 #define SQUID_CONFIG_H
 
+#define _WITH_CPU_SET_T
 #include "autoconf.h"       /* For GNU autoconf variables */
 #include "version.h"
 
