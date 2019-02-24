--- vendor/github.com/fsouza/go-dockerclient/internal/archive/archive_unix.go.orig	2019-02-19 22:02:30 UTC
+++ vendor/github.com/fsouza/go-dockerclient/internal/archive/archive_unix.go
@@ -42,7 +42,7 @@ func getInodeFromStat(stat interface{}) 
 	s, ok := stat.(*syscall.Stat_t)
 
 	if ok {
-		inode = s.Ino
+		inode = uint64(s.Ino)
 	}
 
 	return
