--- lib/util/time.h.orig	2026-03-05 19:21:56 UTC
+++ lib/util/time.h
@@ -24,6 +24,8 @@
 #ifndef _SAMBA_TIME_H_
 #define _SAMBA_TIME_H_
 
+#include <sys/types.h>
+
 #include <stdbool.h>
 #include <stdint.h>
 #include <talloc.h>
