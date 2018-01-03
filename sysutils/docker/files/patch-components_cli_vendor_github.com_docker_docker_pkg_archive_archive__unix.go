--- components/cli/vendor/github.com/docker/docker/pkg/archive/archive_unix.go.orig	2017-12-27 17:03:35 UTC
+++ components/cli/vendor/github.com/docker/docker/pkg/archive/archive_unix.go
@@ -62,7 +62,7 @@ func getInodeFromStat(stat interface{}) (inode uint64,
 	s, ok := stat.(*syscall.Stat_t)
 
 	if ok {
-		inode = s.Ino
+		inode = uint64(s.Ino)
 	}
 
 	return
