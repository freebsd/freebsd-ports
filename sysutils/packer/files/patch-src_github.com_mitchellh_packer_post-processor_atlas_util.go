--- src/github.com/mitchellh/packer/post-processor/atlas/util.go.orig	2014-12-10 02:57:03 UTC
+++ src/github.com/mitchellh/packer/post-processor/atlas/util.go
@@ -13,11 +13,12 @@ import (
 func longestCommonPrefix(vs []string) string {
 	// Find the shortest string
 	var shortest string
-	length := math.MaxUint32
+        var length int64
+	length = math.MaxUint32
 	for _, v := range vs {
-		if len(v) < length {
+		if int64(len(v)) < length {
 			shortest = v
-			length = len(v)
+			length = int64(len(v))
 		}
 	}
 
