--- vendor/github.com/distribution/distribution/v3/registry/storage/driver/s3-aws/s3_64bit.go.orig	2025-09-27 12:09:03 UTC
+++ vendor/github.com/distribution/distribution/v3/registry/storage/driver/s3-aws/s3_64bit.go
@@ -1,4 +1,4 @@
-//go:build !arm
+//go:build !arm && !386
 
 package s3
 
