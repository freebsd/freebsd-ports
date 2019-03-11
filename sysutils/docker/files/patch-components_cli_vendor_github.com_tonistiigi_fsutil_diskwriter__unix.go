--- components/cli/vendor/github.com/tonistiigi/fsutil/diskwriter_unix.go.orig	2019-03-06 12:30:35 UTC
+++ components/cli/vendor/github.com/tonistiigi/fsutil/diskwriter_unix.go
@@ -45,7 +45,7 @@ func handleTarTypeBlockCharFifo(path str
 		mode |= syscall.S_IFBLK
 	}
 
-	if err := syscall.Mknod(path, mode, int(mkdev(stat.Devmajor, stat.Devminor))); err != nil {
+	if err := syscall.Mknod(path, mode, uint64(mkdev(stat.Devmajor, stat.Devminor))); err != nil {
 		return err
 	}
 	return nil
