--- src/tspi/tsp_tcsi_param.c.orig	2016-11-19 03:09:49 UTC
+++ src/tspi/tsp_tcsi_param.c
@@ -13,7 +13,10 @@
 #include <stdio.h>
 
 
-#ifndef __APPLE__
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#define        HOST_NAME_MAX   MAXHOSTNAMELEN
+#elif !defined(__APPLE__)
 #include <limits.h>
 #else
 #define HOST_NAME_MAX 64
