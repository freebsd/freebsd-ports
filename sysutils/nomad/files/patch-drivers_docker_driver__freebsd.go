--- drivers/docker/driver_freebsd.go.orig	2021-08-06 23:51:59 UTC
+++ drivers/docker/driver_freebsd.go
@@ -0,0 +1,5 @@
+package docker
+
+func setCPUSetCgroup(path string, pid int) error {
+	return nil
+}
