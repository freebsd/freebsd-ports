--- lib/userinfo-json.c.orig	2015-10-28 19:05:45 UTC
+++ lib/userinfo-json.c
@@ -22,6 +22,8 @@
 #endif
 #include <time.h>
 
+#include <util/macros.h>
+
 #include <lib/internal.h>
 #include <webauth/basic.h>
 #include <webauth/factors.h>
