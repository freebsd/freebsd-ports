--- src/cvecheck_common.h.orig	2020-07-26 11:00:55 UTC
+++ src/cvecheck_common.h
@@ -1,7 +1,9 @@
 #include <stdio.h>
 #include <libconfig.h>
 #include <string.h>
+#if !defined(__FreeBSD__)
 #include <bsd/string.h>
+#endif
 
 #ifdef _USE_SQLITE3
 #include <sqlite3.h>
