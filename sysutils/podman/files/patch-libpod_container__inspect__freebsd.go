--- libpod/container_inspect_freebsd.go.orig	2024-06-04 19:54:07 UTC
+++ libpod/container_inspect_freebsd.go
@@ -15,5 +15,14 @@ func (c *Container) platformInspectContainerHostConfig
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
 	return nil
 }
