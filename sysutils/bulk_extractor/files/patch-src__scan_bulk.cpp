--- ./src/scan_bulk.cpp.orig	2013-08-18 16:39:31.000000000 +0000
+++ ./src/scan_bulk.cpp	2013-10-19 13:09:32.000000000 +0000
@@ -145,7 +145,7 @@
 		    exit(1);
 		}
 
-		uint32_t len = stoi(vals[1]);
+		uint32_t len = be13stoi(vals[1]);
 
 		// If no data for this sector, simply append this type
 		// and then continue
