--- pkg/system/meminfo_unsupported.go.orig	2015-06-08 13:34:30 UTC
+++ pkg/system/meminfo_unsupported.go
@@ -3,5 +3,5 @@
 package system
 
 func ReadMemInfo() (*MemInfo, error) {
-	return nil, ErrNotSupportedPlatform
+	return &MemInfo{}, ErrNotSupportedPlatform
 }
