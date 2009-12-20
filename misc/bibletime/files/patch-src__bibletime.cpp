--- ./src/bibletime.cpp.orig	2009-12-15 13:23:36.000000000 -0500
+++ ./src/bibletime.cpp	2009-12-15 13:24:19.000000000 -0500
@@ -61,7 +61,7 @@
         const int month = date.month();
         QString splashImage(DU::getPicsDir().canonicalPath().append("/"));
 
-        if ((month >= 12 && day >= 24) || (month <= 1 && day < 6)) {
+        if ((month >= 12) || (month <= 1 && day < 6)) {
             splashImage.append("startuplogo_christmas.png");
         } else {
             splashImage.append("startuplogo.png");
