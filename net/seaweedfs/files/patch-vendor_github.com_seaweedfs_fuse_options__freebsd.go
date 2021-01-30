--- vendor/github.com/seaweedfs/fuse/options_freebsd.go.orig	2021-01-28 08:22:09 UTC
+++ vendor/github.com/seaweedfs/fuse/options_freebsd.go
@@ -13,10 +13,7 @@ func volumeName(name string) MountOption {
 }
 
 func daemonTimeout(name string) MountOption {
-	return func(conf *mountConfig) error {
-		conf.options["timeout"] = name
-		return nil
-	}
+	return dummyOption
 }
 
 func noAppleXattr(conf *mountConfig) error {
