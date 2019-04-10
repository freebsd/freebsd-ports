--- common/fdlimit/fdlimit_freebsd.go.orig	2019-04-08 13:16:05 UTC
+++ common/fdlimit/fdlimit_freebsd.go
@@ -43,7 +43,7 @@ func Raise(max uint64) (uint64, error) {
 	if err := syscall.Getrlimit(syscall.RLIMIT_NOFILE, &limit); err != nil {
 		return 0, err
 	}
-	return limit.Cur, nil
+	return uint64(limit.Cur), nil
 }
 
 // Current retrieves the number of file descriptors allowed to be opened by this
