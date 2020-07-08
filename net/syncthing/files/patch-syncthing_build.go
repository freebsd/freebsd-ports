--- syncthing/build.go.orig	2020-06-02 09:38:39 UTC
+++ syncthing/build.go
@@ -404,7 +404,7 @@
 		defer shouldCleanupSyso(sysoPath)
 	}
 
-	args := []string{"install", "-v"}
+	args := []string{"install"}
 	args = appendParameters(args, tags, target.buildPkgs...)
 	runPrint(goCmd, args...)
 }
