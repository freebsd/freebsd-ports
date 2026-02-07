--- libpod/container_internal_common.go.orig	2025-06-18 16:07:27 UTC
+++ libpod/container_internal_common.go
@@ -192,7 +192,7 @@ func (c *Container) createInitRootfs() error {
 	}
 
 	c.config.Rootfs = tmpDir
-	c.config.RootfsOverlay = true
+	//c.config.RootfsOverlay = true
 	return nil
 }
 
