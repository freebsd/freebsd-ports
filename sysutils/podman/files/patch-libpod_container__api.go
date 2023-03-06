--- libpod/container_api.go.orig	2023-02-23 15:59:21 UTC
+++ libpod/container_api.go
@@ -788,10 +788,12 @@ func (c *Container) Cleanup(ctx context.Context) error
 
 	// make sure all the container processes are terminated if we are running without a pid namespace.
 	hasPidNs := false
-	for _, i := range c.config.Spec.Linux.Namespaces {
-		if i.Type == spec.PIDNamespace {
-			hasPidNs = true
-			break
+	if c.config.Spec.Linux != nil {
+		for _, i := range c.config.Spec.Linux.Namespaces {
+			if i.Type == spec.PIDNamespace {
+				hasPidNs = true
+				break
+			}
 		}
 	}
 	if !hasPidNs {
