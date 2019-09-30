--- internal/jail/jail.go.orig	2019-09-29 20:26:56 UTC
+++ internal/jail/jail.go
@@ -228,7 +228,7 @@ func handleFile(dest string, src pathAndMode) error {
 func createCharacterDevice(dest string, src pathAndMode) error {
 	unixMode := uint32(src.mode.Perm() | syscall.S_IFCHR)
 
-	return unix.Mknod(dest, unixMode, src.rdev)
+	return unix.Mknod(dest, unixMode, uint64(src.rdev))
 }
 
 func copyFile(dest, src string, perm os.FileMode) error {
