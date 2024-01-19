--- libpod/container_inspect.go.orig	2024-01-07 16:19:52 UTC
+++ libpod/container_inspect.go
@@ -316,7 +316,7 @@ func (c *Container) GetSecurityOptions() []string {
 	if apparmor, ok := ctrSpec.Annotations[define.InspectAnnotationApparmor]; ok {
 		SecurityOpt = append(SecurityOpt, fmt.Sprintf("apparmor=%s", apparmor))
 	}
-	if c.config.Spec.Linux.MaskedPaths == nil {
+	if c.config.Spec.Linux != nil && c.config.Spec.Linux.MaskedPaths == nil {
 		SecurityOpt = append(SecurityOpt, "unmask=all")
 	}
 
