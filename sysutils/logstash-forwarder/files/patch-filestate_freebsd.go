--- filestate_freebsd.go.orig	2015-06-23 08:32:46 UTC
+++ filestate_freebsd.go
@@ -0,0 +1,8 @@
+package main
+
+type FileState struct {
+  Source *string `json:"source,omitempty"`
+  Offset int64 `json:"offset,omitempty"`
+  Inode uint32 `json:"inode,omitempty"`
+  Device uint32 `json:"device,omitempty"`
+}
