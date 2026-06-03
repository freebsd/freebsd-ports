--- src/sn_data.h.orig	2025-09-22 23:50:28 UTC
+++ src/sn_data.h
@@ -32,15 +32,10 @@ int HEADSIZE[]={0    ,14};		/* ppp: 4 or 0 or nothing 
 int HEADSIZE[]={0    ,14};		/* ppp: 4 or 0 or nothing */
 #endif
 
-#ifdef FREEBSD				/* ppp: 4 or 0 ? */
-/*
-#define NETDEV_NR      2
-char *NETDEV[]={"ppp","ed"};
-int HEADSIZE[]={4    ,14};
-*/
-#define NETDEV_NR      1
-char *NETDEV[]={"ed"};
-int HEADSIZE[]={14};
+#ifdef __FreeBSD__				/* ppp: 4 or 0 ? */
+#define NETDEV_NR      6
+char *NETDEV[]={"fxp","re","em","ppp","tun","lo"};
+int HEADSIZE[]={14   ,14  ,14  ,4    ,4    ,4   };
 #endif
 
 #ifdef BSDI				/* ppp: 4 or 0 ? */
@@ -203,5 +198,3 @@ unsigned int debug_cnt=0;
 FILE *debug_dev;
 unsigned int debug_cnt=0;
 #endif
-
-
