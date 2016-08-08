--- src/logstalgia.cpp.orig	2011-02-15 23:52:06 UTC
+++ src/logstalgia.cpp
@@ -392,7 +392,7 @@ std::string Logstalgia::dateAtPosition(f
             //display date
             char datestr[256];
 
-            long timestamp = le.timestamp;
+            time_t timestamp = le.timestamp;
 
             struct tm* timeinfo = localtime ( &timestamp );
             strftime(datestr, 256, "%H:%M:%S %B %d, %Y", timeinfo);
