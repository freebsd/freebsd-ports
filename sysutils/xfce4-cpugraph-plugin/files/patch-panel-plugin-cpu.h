--- panel-plugin/cpu.h.orig	2005-10-09 05:19:34.000000000 -0400
+++ panel-plugin/cpu.h	2009-06-15 18:07:25.000000000 -0400
@@ -10,6 +10,7 @@
 #include <math.h>
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 
 #include <libxfce4util/libxfce4util.h>
 #include <libxfcegui4/libxfcegui4.h>
@@ -83,7 +84,7 @@
 	
 	guint m_TimeoutID; // Timeout ID for the tooltip;
 	long m_CPUUsage;
-	long *m_History;
+	int *m_History;
 	int m_Values;
 
 	int m_Orientation;
