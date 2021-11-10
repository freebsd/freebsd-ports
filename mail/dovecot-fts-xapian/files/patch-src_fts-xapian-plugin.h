--- src/fts-xapian-plugin.h.orig	2021-11-10 13:06:54 UTC
+++ src/fts-xapian-plugin.h
@@ -15,6 +15,12 @@
 #include "module-context.h"
 #include "fts-api-private.h"
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <vm/vm_param.h>
+#endif
+
 #define XAPIAN_FILE_PREFIX "xapian-indexes"
 #define XAPIAN_TERM_SIZELIMIT 245L
 #define XAPIAN_COMMIT_ENTRIES 1000000L
@@ -27,9 +33,10 @@
 
 struct fts_xapian_settings
 {
-        int verbose;
-        long lowmemory;
-        long partial,full;
+	int verbose;
+	unsigned long pagesize;
+	long lowmemory;
+	long partial,full;
 };
 
 struct fts_xapian_user {
