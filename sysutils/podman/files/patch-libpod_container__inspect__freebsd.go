--- libpod/container_inspect_freebsd.go.orig	2025-01-21 18:41:34 UTC
+++ libpod/container_inspect_freebsd.go
@@ -15,10 +15,18 @@ func (c *Container) platformInspectContainerHostConfig
 	// UTS namespace mode
 	hostConfig.UTSMode = c.NamespaceMode(spec.UTSNamespace, ctrSpec)
 
+       // Devices
+       // Do not include if privileged - assumed that all devices will be
+       // included.
+       var err error
+       hostConfig.Devices, err = c.GetDevices(hostConfig.Privileged, *ctrSpec, map[string]string{})
+       if err != nil {
+               return err
+       }
+
 	// Devices
 	// Do not include if privileged - assumed that all devices will be
 	// included.
-	var err error
 	hostConfig.Devices, err = c.GetDevices(hostConfig.Privileged, *ctrSpec, map[string]string{})
 	if err != nil {
 		return err
