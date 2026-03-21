--- lib/util/time.h.orig	2025-12-12 13:34:55 UTC
+++ lib/util/time.h
@@ -24,6 +24,8 @@
 #ifndef _SAMBA_TIME_H_
 #define _SAMBA_TIME_H_
 
+#include <sys/types.h>
+
 #include <stdbool.h>
 #include <stdint.h>
 #include <talloc.h>
