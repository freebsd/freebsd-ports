--- mpifileutils/src/dbz2/dbz2.c.orig	2025-02-19 22:20:52 UTC
+++ mpifileutils/src/dbz2/dbz2.c
@@ -1,7 +1,9 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__linux__)
 #include <sys/sysinfo.h>
+#endif
 #include <string.h>
 #include <sys/time.h>
 #include <sys/resource.h>
