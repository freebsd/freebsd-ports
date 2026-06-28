--- ldap/servers/slapd/back-ldbm/db-mdb/mdb_debug.c.orig	2026-06-28 09:36:14 UTC
+++ ldap/servers/slapd/back-ldbm/db-mdb/mdb_debug.c
@@ -16,7 +16,12 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#define pthread_gettid pthread_getthreadid_np
+#else
 #include <syscall.h>
+#endif
 #include <dlfcn.h>
 
 
