--- core/commands/storage/path/path_freebsd.go.orig	2021-01-25 10:40:26.251172000 +0100
+++ core/commands/storage/path/path_freebsd.go	2021-01-25 10:39:51.620263000 +0100
@@ -0,0 +1,12 @@
+// +build freebsd
+
+package path
+
+func volumes() ([]*volume, error) {
+	var vs []*volume
+	vs = append(vs, &volume{
+		Name:       "Root",
+		MountPoint: "/",
+	})
+	return vs, nil
+}
