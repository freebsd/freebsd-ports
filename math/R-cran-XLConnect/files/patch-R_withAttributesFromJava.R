--- R/withAttributesFromJava.R.orig	2026-02-17 16:02:17 UTC
+++ R/withAttributesFromJava.R
@@ -33,11 +33,14 @@ withAttributesFromJava <- function(jobj) {
     
     unwrapped <- jobj$getValue()
     allANames = .jcall(jobj, "[S", "getAttributeNames")
-    
+    Encoding(allANames) <- "UTF-8"
+
     if(getOption("XLConnect.setCustomAttributes")){
         for(i in seq(along = allANames)) {
-            attr(unwrapped, allANames[i]) <- jobj$getAttributeValue(allANames[i])
+            attrValue <- jobj$getAttributeValue(allANames[i])
+            Encoding(attrValue) <- "UTF-8"
+            attr(unwrapped, allANames[i]) <- attrValue
         }
     }
     unwrapped
-  }
\ No newline at end of file
+  }
