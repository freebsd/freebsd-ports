--- x/mlxrunner/client.go.orig	2026-04-18 04:07:37 UTC
+++ x/mlxrunner/client.go
@@ -366,6 +366,8 @@ func (c *Client) Load(ctx context.Context, _ ml.System
 	switch runtime.GOOS {
 	case "linux":
 		libPathEnvVar = "LD_LIBRARY_PATH"
+	case "freebsd":
+		libPathEnvVar = "LD_LIBRARY_PATH"
 	case "windows":
 		libPathEnvVar = "PATH"
 	}
