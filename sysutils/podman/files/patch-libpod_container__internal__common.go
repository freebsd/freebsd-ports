--- libpod/container_internal_common.go.orig	2026-09-29 13:04:58 UTC
+++ libpod/container_internal_common.go
@@ -193,7 +193,7 @@ func (c *Container) createInitRootfs() error {
 	}
 
 	c.config.Rootfs = tmpDir
-	c.config.RootfsOverlay = true
+	//c.config.RootfsOverlay = true
 	return nil
 }
 
