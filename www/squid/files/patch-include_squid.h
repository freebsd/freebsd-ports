--- include/squid.h.orig	2024-03-04 05:45:51 UTC
+++ include/squid.h
@@ -9,6 +9,7 @@
 #ifndef SQUID_INCLUDE_SQUID_H
 #define SQUID_INCLUDE_SQUID_H
 
+#define _WITH_CPU_SET_T
 #include "autoconf.h"       /* For GNU autoconf variables */
 #include "version.h"
 
