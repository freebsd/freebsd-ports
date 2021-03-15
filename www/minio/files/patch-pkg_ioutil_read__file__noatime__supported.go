--- pkg/ioutil/read_file_noatime_supported.go.orig	2021-03-15 17:25:42 UTC
+++ pkg/ioutil/read_file_noatime_supported.go
@@ -1,4 +1,4 @@
-// +build !windows,!darwin
+// +build !windows,!darwin,!freebsd
 
 /*
  * MinIO Cloud Storage, (C) 2021 MinIO, Inc.
