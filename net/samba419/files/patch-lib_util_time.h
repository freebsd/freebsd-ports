--- lib/util/time.h.orig	2023-07-18 08:14:54 UTC
+++ lib/util/time.h
@@ -24,6 +24,7 @@
 #ifndef _SAMBA_TIME_H_
 #define _SAMBA_TIME_H_
 
+#include <sys/types.h>
 #include <stdbool.h>
 #include <stdint.h>
 #include <talloc.h>
