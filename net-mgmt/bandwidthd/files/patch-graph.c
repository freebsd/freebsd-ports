--- graph.c.orig	Fri Oct 10 21:01:31 2003
+++ graph.c	Sun Nov  2 12:21:18 2003
@@ -3,6 +3,11 @@
 #include <signal.h>
 #include <string.h>
 #include <netdb.h>
+#ifdef FREEBSD
+#include <netinet/in.h>
+#include <arpa/nameser.h>
+#include <sys/types.h>
+#endif
 #include <sys/socket.h>
 #include <resolv.h>
 #include <time.h>
@@ -753,7 +758,7 @@
     // ****  Write the red day seperator bars
     // ********************************************************************
 
-    timestruct = localtime(&sample_begin);
+    timestruct = localtime((time_t *)(time_t *)&sample_begin);
     timestruct->tm_sec = 0;
     timestruct->tm_min = 0;
     timestruct->tm_hour = 0;
@@ -772,7 +777,7 @@
         gdImageLine(im, x, 0, x, YHEIGHT-YOFFSET, red);
         gdImageLine(im, x+1, 0, x+1, YHEIGHT-YOFFSET, red);
 
-        timestruct = localtime(&MarkTime);
+        timestruct = localtime((time_t *)(time_t *)&MarkTime);
         strftime(buffer, 100, "%a, %b %d", timestruct);
         gdImageString(im, gdFontSmall, x-30,  YHEIGHT-YOFFSET+10, buffer, black);        
 
@@ -786,7 +791,7 @@
     // ****  Write the tic marks
     // ********************************************************************
 
-    timestruct = localtime(&sample_begin);
+    timestruct = localtime((time_t *)(time_t *)&sample_begin);
     timestruct->tm_sec = 0;
     timestruct->tm_min = 0;
     timestruct->tm_hour = 0;
@@ -803,7 +808,7 @@
         x = (MarkTime-sample_begin)*((XWIDTH-XOFFSET)/RANGE1) + XOFFSET;
         }
 
-    timestruct = localtime(&sample_begin);
+    timestruct = localtime((time_t *)(time_t *)&sample_begin);
     timestruct->tm_sec = 0;
     timestruct->tm_min = 0;
     timestruct->tm_hour = 0;
