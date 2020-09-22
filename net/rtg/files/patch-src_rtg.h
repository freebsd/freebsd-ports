--- src/rtg.h.orig	2003-09-25 15:56:04 UTC
+++ src/rtg.h
@@ -40,12 +40,10 @@
 #define DEFAULT_DB_DB "rtg"
 #define DEFAULT_DB_USER "snmp"
 #define DEFAULT_DB_PASS "rtgdefault"
-#define DEFAULT_SNMP_VER 1
+#define DEFAULT_SNMP_VER 2
 #define DEFAULT_SNMP_PORT 161
+#define DEFAULT_PIDFILE "/tmp/rtgpoll.pid"
 
-/* PID File */
-#define PIDFILE "/tmp/rtgpoll.pid"
-
 #define STAT_DESCRIP_ERROR 99
 #define HASHSIZE 5000
 
@@ -175,10 +173,10 @@ int add_hash_entry(target_t *);
 int hash_target_file(char *);
 
 /* Globals */
-config_t set;
-int lock;
-int waiting;
-char config_paths[CONFIG_PATHS][BUFSIZE];
-hash_t hash;
+extern config_t set;
+extern int lock;
+extern int waiting;
+extern char config_paths[CONFIG_PATHS][BUFSIZE];
+extern hash_t hash;
 
 #endif /* not _RTG_H_ */
