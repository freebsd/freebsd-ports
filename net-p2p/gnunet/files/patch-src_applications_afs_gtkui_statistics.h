
$FreeBSD$

--- src/applications/afs/gtkui/statistics.h.orig	Sun Jun 20 11:05:37 2004
+++ src/applications/afs/gtkui/statistics.h	Sun Jun 20 11:06:11 2004
@@ -41,6 +41,11 @@
 
 void initGTKStatistics();
  
+#define STAT_CONNECTIVITY 0
+#define STAT_CPU_LOAD 1
+#define STAT_IN_TRAFFIC 2
+#define STAT_OUT_TRAFFIC 3
+
 void doneGTKStatistics();
 
 
