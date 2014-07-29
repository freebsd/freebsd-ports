--- rpc.dracd.c.orig	Tue Nov 21 05:22:05 2000
+++ rpc.dracd.c	Sun Apr 29 20:41:31 2001
@@ -8,7 +8,6 @@
 #include <errno.h>
 #include <syslog.h>
 #ifdef TI_RPC
-#include <netdir.h>
 #include <netconfig.h>
 #endif
 #include <stdlib.h>
@@ -35,9 +34,6 @@
 #define DB_VERSION_MAJOR 1
 #endif
 #include "drac.h"
-
-#define DBFILE "/etc/mail/dracd.db"
-#define ALFILE "/etc/mail/dracd.allow"
 
 struct net_def {
     struct net_def *nd_next;
