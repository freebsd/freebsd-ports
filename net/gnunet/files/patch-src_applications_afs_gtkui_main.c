
$FreeBSD$

--- src/applications/afs/gtkui/main.c.orig	Sun Jun 20 11:00:49 2004
+++ src/applications/afs/gtkui/main.c	Sun Jun 20 11:01:30 2004
@@ -247,22 +247,22 @@
   { "/File/Plot gnunetd stats/_Connectivity", 
     NULL,
     displayStatistics, 
-    (long) "Connectivity",
+    STAT_CONNECTIVITY,
     NULL },
   { "/File/Plot gnunetd stats/C_PU Load", 
     NULL,
     displayStatistics, 
-    (long) "CPU load",
+    STAT_CPU_LOAD,
     NULL },
   { "/File/Plot gnunetd stats/_Inbound Traffic", 
     NULL,
     displayStatistics, 
-    (long) "Inbound Traffic",
+    STAT_IN_TRAFFIC,
     NULL },
   { "/File/Plot gnunetd stats/_Outbound Traffic", 
     NULL,
     displayStatistics, 
-    (long) "Outbound Traffic",
+    STAT_OUT_TRAFFIC,
     NULL },
   { "/File/sep1",     
     NULL, 
