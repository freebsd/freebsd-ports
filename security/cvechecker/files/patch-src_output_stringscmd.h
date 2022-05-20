--- src/output/stringscmd.h.orig	2020-07-26 11:00:55 UTC
+++ src/output/stringscmd.h
@@ -1,7 +1,9 @@
 #include <regex.h>
 #include <stdio.h>
 #include <string.h>
+#if !defined(__FreeBSD__)
 #include <bsd/string.h>
+#endif
 #include "../cvecheck_common.h"
 #include "../swstring.h"
 
