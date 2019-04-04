--- syncthing/build.go.orig	2019-04-04 16:46:36 UTC
+++ syncthing/build.go
@@ -398,7 +398,7 @@ func build(target target, tags []string) {
 
 	rmr(target.BinaryName())
 
-	args := []string{"build", "-v"}
+	args := []string{"build"}
 	args = appendParameters(args, tags, target)
 
 	os.Setenv("GOOS", goos)
