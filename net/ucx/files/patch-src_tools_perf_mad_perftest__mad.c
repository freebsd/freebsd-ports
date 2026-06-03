--- src/tools/perf/mad/perftest_mad.c.orig	2026-02-04 09:52:46 UTC
+++ src/tools/perf/mad/perftest_mad.c
@@ -20,7 +20,13 @@
 #include <unistd.h>
 #include <netdb.h>
 #include <sys/poll.h>
+#if defined(__linux__)
 #include <linux/types.h> /* __be64 */
+#else
+#include <sys/types.h>
+#include <sys/endian.h>  /* be64toh */
+typedef uint64_t __be64;
+#endif
 
 #include <infiniband/mad.h>
 #include <infiniband/umad.h>
