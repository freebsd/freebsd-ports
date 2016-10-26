--- src/rtg.h.orig	2003-09-25 15:56:04 UTC
+++ src/rtg.h
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
