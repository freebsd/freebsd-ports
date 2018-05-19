--- vendor/github.com/karrick/godirwalk/walk.go.orig	2018-04-30 10:37:07 UTC
+++ vendor/github.com/karrick/godirwalk/walk.go
@@ -188,6 +188,10 @@ func Walk(pathname string, options *Options) error {
 		options.ErrorCallback = defaultErrorCallback
 	}
 
+	if options.ScratchBuffer == nil {
+		options.ScratchBuffer = make([]byte, 64*1024)
+	}
+
 	err = walk(pathname, dirent, options)
 	if err == filepath.SkipDir {
 		return nil // silence SkipDir for top level
