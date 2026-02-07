--- components/cli/vendor/github.com/tonistiigi/fsutil/stat_unix.go.orig	2019-02-01 16:05:34 UTC
+++ components/cli/vendor/github.com/tonistiigi/fsutil/stat_unix.go
@@ -45,7 +45,7 @@ func setUnixOpt(fi os.FileInfo, stat *ty
 			stat.Devminor = int64(minor(uint64(s.Rdev)))
 		}
 
-		ino := s.Ino
+		ino := uint64(s.Ino)
 		if seenFiles != nil {
 			if s.Nlink > 1 {
 				if oldpath, ok := seenFiles[ino]; ok {
