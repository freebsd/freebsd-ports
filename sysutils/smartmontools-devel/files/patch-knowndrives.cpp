
$FreeBSD$

--- knowndrives.cpp.orig
+++ knowndrives.cpp
@@ -1031,7 +1031,7 @@
     NULL, NULL, NULL, NULL
   },
   { "Western Digital Caviar SE (Serial ATA) family",
-    "^WDC WD((4|8|12|16|20|25|32)00JD|(12|16|20|25|30|32)00JS|1600AAJS)-.*$",
+    "^WDC WD((4|8|12|16|20|25|32)00[JP]D|(12|16|20|25|30|32)00JS|1600AAJS)-.*$",
     ".*",
     NULL, NULL, NULL, NULL
   },
