--- R/dataframeFromJava.R.orig	2026-02-17 16:02:17 UTC
+++ R/dataframeFromJava.R
@@ -35,6 +35,7 @@ dataframeFromJava <- function(df, check.names) {
   	
   	columnTypes = .jcall(df, "[S", "getColumnTypes")
   	columnNames = .jcall(df, "[S", "getColumnNames")
+	Encoding(columnNames) <- "UTF-8"
   	
   	# Init result list to contain column vectors
   	res = list()
@@ -49,7 +50,9 @@ dataframeFromJava <- function(df, check.names) {
   				},
   				
   				"String" = {
-  					as.vector(.jcall(df, "[S", "getStringColumn", jIndex))
+					v <- as.vector(.jcall(df, "[S", "getStringColumn", jIndex))
+					Encoding(v) <- "UTF-8"
+					v
   				},
   				
   				"Boolean" = {
