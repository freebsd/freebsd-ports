--- command/agent/host/unix.go.orig	2024-01-15 16:55:40 UTC
+++ command/agent/host/unix.go
@@ -69,31 +69,3 @@ func (d *df) available() uint64 {
 func (d *df) available() uint64 {
 	return d.usage.Free
 }
-
-// mountedPaths produces a list of mounts
-func mountedPaths() []string {
-	partitions, err := disk.Partitions(false)
-	if err != nil {
-		return []string{err.Error()}
-	}
-
-	var paths []string
-	for _, partition := range partitions {
-		fsType := partition.Fstype
-
-		switch fsType {
-		case "autofs", "binfmt_misc", "cgroup", "debugfs",
-			"devpts", "devtmpfs",
-			"fusectl", "fuse.lxcfs",
-			"hugetlbfs", "mqueue",
-			"procfs", "pstore", "rpc_pipefs", "securityfs",
-			"sysfs", "tmpfs", "vboxsf", "ptyfs":
-			continue
-		default:
-		}
-
-		paths = append(paths, partition.Mountpoint)
-	}
-
-	return paths
-}
