--- R/XLConnectSettings.R.orig	2025-04-29 09:58:50 UTC
+++ R/XLConnectSettings.R
@@ -46,9 +46,6 @@ XLConnectSettings <- function(pdesc) {
 	options(XLConnect.RownameCol = ".rownames")
 
 	options(XLConnect.setCustomAttributes = FALSE)
-	
-	# Apply default POI configuration
-	configurePOI()
   
 	invisible()
 }
