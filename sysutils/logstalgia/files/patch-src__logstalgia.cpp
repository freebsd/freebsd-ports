--- ./src/logstalgia.cpp.orig	2011-10-31 23:21:18.000000000 +0100
+++ ./src/logstalgia.cpp	2011-10-31 23:21:35.000000000 +0100
@@ -392,7 +392,7 @@
             //display date
             char datestr[256];
 
-            long timestamp = le.timestamp;
+            time_t timestamp = le.timestamp;
 
             struct tm* timeinfo = localtime ( &timestamp );
             strftime(datestr, 256, "%H:%M:%S %B %d, %Y", timeinfo);
