--- modules/afsocket/afinet-dest.c.orig	2016-03-22 02:39:13.000000000 -0700
+++ modules/afsocket/afinet-dest.c	2016-03-23 22:07:14.289961000 -0700
@@ -42,7 +42,7 @@
 #endif
 
 #if ENABLE_SPOOF_SOURCE
-#include <libnet.h>
+#include <libnet11/libnet.h>
 #endif
 
 #if _GNU_SOURCE_DEFINED
