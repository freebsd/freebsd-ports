--- cmd/xl-storage_noatime_supported.go.orig	2021-03-15 17:48:53 UTC
+++ cmd/xl-storage_noatime_supported.go
@@ -1,4 +1,4 @@
-// +build !windows,!darwin
+// +build !windows,!darwin,!freebsd
 
 /*
  * MinIO Cloud Storage, (C) 2021 MinIO, Inc.
