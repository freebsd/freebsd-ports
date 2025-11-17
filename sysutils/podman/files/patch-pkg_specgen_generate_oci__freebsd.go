pkg/specgen/generate: Fix adding host devices on FreeBSD

This was not working when emulating Linux container images on FreeBSD.
The code to handle host devices on FreeBSD relies on the container
having a devfs mount. Unfortunately, the Linux emulation code which adds
this was happening after the host device handling. This changes the
logic so that host device management happens after Linux emulation.

Signed-off-by: Doug Rabson <dfr@rabson.org>

--- pkg/specgen/generate/oci_freebsd.go.orig	2025-11-11 13:51:07 UTC
+++ pkg/specgen/generate/oci_freebsd.go
@@ -50,28 +50,6 @@ func SpecGenToOCI(ctx context.Context, s *specgen.Spec
 		g.AddAnnotation(key, val)
 	}
 
-	// Devices
-	var userDevices []spec.LinuxDevice
-	if !s.IsPrivileged() {
-		// add default devices from containers.conf
-		for _, device := range rtc.Containers.Devices.Get() {
-			if err = DevicesFromPath(&g, device, rtc); err != nil {
-				return nil, err
-			}
-		}
-		if len(compatibleOptions.HostDeviceList) > 0 && len(s.Devices) == 0 {
-			userDevices = compatibleOptions.HostDeviceList
-		} else {
-			userDevices = s.Devices
-		}
-		// add default devices specified by caller
-		for _, device := range userDevices {
-			if err = DevicesFromPath(&g, device.Path, rtc); err != nil {
-				return nil, err
-			}
-		}
-	}
-
 	g.ClearProcessEnv()
 	for name, val := range s.Env {
 		g.AddProcessEnv(name, val)
@@ -132,6 +110,28 @@ func SpecGenToOCI(ctx context.Context, s *specgen.Spec
 			},
 		)
 		configSpec.Mounts = mounts
+	}
+
+	// Devices
+	var userDevices []spec.LinuxDevice
+	if !s.IsPrivileged() {
+		// add default devices from containers.conf
+		for _, device := range rtc.Containers.Devices.Get() {
+			if err = DevicesFromPath(&g, device, rtc); err != nil {
+				return nil, err
+			}
+		}
+		if len(compatibleOptions.HostDeviceList) > 0 && len(s.Devices) == 0 {
+			userDevices = compatibleOptions.HostDeviceList
+		} else {
+			userDevices = s.Devices
+		}
+		// add default devices specified by caller
+		for _, device := range userDevices {
+			if err = DevicesFromPath(&g, device.Path, rtc); err != nil {
+				return nil, err
+			}
+		}
 	}
 
 	// BIND MOUNTS
