--- vendor/github.com/karrick/godirwalk/readdir_unix.go.orig	2018-04-30 10:37:07 UTC
+++ vendor/github.com/karrick/godirwalk/readdir_unix.go
@@ -1,4 +1,4 @@
-// +build darwin dragonfly freebsd linux nacl netbsd openbsd solaris
+// +build darwin freebsd linux netbsd openbsd
 
 package godirwalk
 
@@ -49,7 +49,7 @@ func readdirents(osDirname string, scratchBuffer []byt
 			de = (*syscall.Dirent)(unsafe.Pointer(&buf[0])) // point entry to first syscall.Dirent in buffer
 			buf = buf[de.Reclen:]                           // advance buffer
 
-			if de.Ino == 0 {
+			if direntIno(de) == 0 {
 				continue // this item has been deleted, but not yet removed from directory
 			}
 
