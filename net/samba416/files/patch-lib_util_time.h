--- lib/util/time.h.orig	2022-01-24 10:26:58 UTC
+++ lib/util/time.h
@@ -27,6 +27,7 @@
 #include <stdbool.h>
 #include <stdint.h>
 #include <talloc.h>
+#include <sys/types.h>
 
 #ifndef TIME_T_MIN
 /* we use 0 here, because (time_t)-1 means error */
