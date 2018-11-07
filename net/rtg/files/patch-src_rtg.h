--- src/rtg.h.orig	2003-09-25 15:56:04 UTC
+++ src/rtg.h
@@ -40,11 +40,9 @@
 #define DEFAULT_DB_DB "rtg"
 #define DEFAULT_DB_USER "snmp"
 #define DEFAULT_DB_PASS "rtgdefault"
-#define DEFAULT_SNMP_VER 1
+#define DEFAULT_SNMP_VER 2
 #define DEFAULT_SNMP_PORT 161
-
-/* PID File */
-#define PIDFILE "/tmp/rtgpoll.pid"
+#define DEFAULT_PIDFILE "/tmp/rtgpoll.pid"
 
 #define STAT_DESCRIP_ERROR 99
 #define HASHSIZE 5000
