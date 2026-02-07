--- exim_monitor/em_hdr.h.orig	2019-12-08 12:53:48 UTC
+++ exim_monitor/em_hdr.h
@@ -95,6 +95,8 @@ this interface so that this kind of kludge isn't neede
 #endif
 typedef void hctx;
 
+typedef unsigned long ulong;
+
 #include "local_scan.h"
 #include "macros.h"
 #include "structs.h"
