--- R/xlcCall.R.orig	2026-02-17 16:02:17 UTC
+++ R/xlcCall.R
@@ -68,6 +68,7 @@ xlcCall <- function(obj, fun, ..., .recycle = TRUE, .s
 
 	if (.checkWarnings) {
 		warnings = .jcall(obj@jobj, "[S", "retrieveWarnings")
+		Encoding(warnings) <- "UTF-8"
 		for(w in warnings) warning(w, call. = FALSE)
 	}
 	
