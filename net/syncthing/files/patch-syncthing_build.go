--- syncthing/build.go.orig	2020-02-05 04:20:26 UTC
+++ syncthing/build.go
@@ -443,7 +443,7 @@ func build(target target, tags []string) {
 	}
 
 	for _, pkg := range target.buildPkgs {
-		args := []string{"build", "-v"}
+		args := []string{"build"}
 		args = appendParameters(args, tags, pkg)
 
 		runPrint(goCmd, args...)
