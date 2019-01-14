--- runconfig/config.go.orig	2015-06-08 13:34:30 UTC
+++ runconfig/config.go
@@ -132,15 +132,15 @@ type Config struct {
 
 type ContainerConfigWrapper struct {
 	*Config
-	*hostConfigWrapper
+	*HostConfigWrapper
 }
 
 func (c ContainerConfigWrapper) HostConfig() *HostConfig {
-	if c.hostConfigWrapper == nil {
+	if c.HostConfigWrapper == nil {
 		return new(HostConfig)
 	}
 
-	return c.hostConfigWrapper.GetHostConfig()
+	return c.HostConfigWrapper.GetHostConfig()
 }
 
 func DecodeContainerConfig(src io.Reader) (*Config, *HostConfig, error) {
