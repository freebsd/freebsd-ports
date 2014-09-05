--- filestate_freebsd.go.orig    1970-01-01 02:00:00.000000000 +0200
+++ filestate_freebsd.go     2014-08-15 15:56:07.164481962 +0300
@@ -0,0 +1,8 @@
+package main
+
+type FileState struct {
+  Source *string `json:"source,omitempty"`
+  Offset int64 `json:"offset,omitempty"`
+  Inode uint32 `json:"inode,omitempty"`
+  Device uint32 `json:"device,omitempty"`
+}
