--- components/cli/vendor/github.com/tonistiigi/fsutil/walker_unix.go.orig	2018-01-03 19:53:04 UTC
+++ components/cli/vendor/github.com/tonistiigi/fsutil/walker_unix.go
@@ -41,7 +41,7 @@ func setUnixOpt(fi os.FileInfo, stat *Stat, path strin
 			stat.Devminor = int64(minor(uint64(s.Rdev)))
 		}
 
-		ino := s.Ino
+		ino := uint64(s.Ino)
 		if s.Nlink > 1 {
 			if oldpath, ok := seenFiles[ino]; ok {
 				stat.Linkname = oldpath
