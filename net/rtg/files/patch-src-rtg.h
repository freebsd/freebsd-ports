--- src/rtg.h.orig	2010-04-21 21:26:38.587554904 +0100
+++ src/rtg.h	2010-04-21 21:31:40.436052227 +0100
@@ -42,9 +42,7 @@
 #define DEFAULT_DB_PASS "rtgdefault"
 #define DEFAULT_SNMP_VER 1
 #define DEFAULT_SNMP_PORT 161
-
-/* PID File */
-#define PIDFILE "/tmp/rtgpoll.pid"
+#define DEFAULT_PIDFILE "/tmp/rtgpoll.pid"
 
 #define STAT_DESCRIP_ERROR 99
 #define HASHSIZE 5000
