--- server/src/main/java/org/elasticsearch/monitor/os/OsProbe.java.orig	2026-10-28 20:24:18 UTC
+++ server/src/main/java/org/elasticsearch/monitor/os/OsProbe.java
@@ -273,7 +273,7 @@ public class OsProbe {
                 return null;
             }
         } else {
-            assert Constants.MAC_OS_X;
+            assert Constants.MAC_OS_X || Constants.FREE_BSD;
             if (getSystemLoadAverage == null) {
                 return null;
             }
