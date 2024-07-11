--- libpod/kube.go.orig	2024-06-05 10:44:10 UTC
+++ libpod/kube.go
@@ -1308,7 +1308,7 @@ func generateKubeSecurityContext(c *Container) (*v1.Se
 		scHasData = true
 		sc.ReadOnlyRootFilesystem = &ro
 	}
-	if c.config.Spec.Linux.MaskedPaths == nil {
+	if c.config.Spec.Linux != nil && c.config.Spec.Linux.MaskedPaths == nil {
 		scHasData = true
 		unmask := v1.UnmaskedProcMount
 		sc.ProcMount = &unmask
