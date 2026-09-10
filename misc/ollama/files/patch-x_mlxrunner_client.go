--- x/mlxrunner/client.go.orig	1979-11-30 08:00:00 UTC
+++ x/mlxrunner/client.go
@@ -353,6 +353,8 @@ func (c *Client) Load(ctx context.Context, _ ml.System
 	switch runtime.GOOS {
 	case "linux":
 		libPathEnvVar = "LD_LIBRARY_PATH"
+	case "freebsd":
+		libPathEnvVar = "LD_LIBRARY_PATH"
 	case "windows":
 		libPathEnvVar = "PATH"
 	}
