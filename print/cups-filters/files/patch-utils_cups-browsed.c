--- utils/cups-browsed.c.orig  2013-12-27 20:45:55.188455147 +0400
+++ utils/cups-browsed.c   2013-12-27 20:46:23.397446686 +0400
@@ -23,7 +23,6 @@
 
 #include <ctype.h>
 #include <errno.h>
-#include <ifaddrs.h>
 #if defined(__OpenBSD__)
 #include <sys/socket.h>
 #endif /* __OpenBSD__ */
@@ -33,6 +32,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <ifaddrs.h>
 #include <assert.h>
 #include <stdlib.h>
 #include <time.h>
