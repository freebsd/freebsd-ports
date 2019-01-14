--- runconfig/hostconfig.go.orig	2015-06-08 13:34:30 UTC
+++ runconfig/hostconfig.go
@@ -234,18 +234,18 @@ type HostConfig struct {
 func MergeConfigs(config *Config, hostConfig *HostConfig) *ContainerConfigWrapper {
 	return &ContainerConfigWrapper{
 		config,
-		&hostConfigWrapper{InnerHostConfig: hostConfig},
+		&HostConfigWrapper{InnerHostConfig: hostConfig},
 	}
 }
 
-type hostConfigWrapper struct {
+type HostConfigWrapper struct {
 	InnerHostConfig *HostConfig `json:"HostConfig,omitempty"`
 	Cpuset          string      `json:",omitempty"` // Deprecated. Exported for backwards compatibility.
 
 	*HostConfig // Deprecated. Exported to read attrubutes from json that are not in the inner host config structure.
 }
 
-func (w hostConfigWrapper) GetHostConfig() *HostConfig {
+func (w HostConfigWrapper) GetHostConfig() *HostConfig {
 	hc := w.HostConfig
 
 	if hc == nil && w.InnerHostConfig != nil {
@@ -274,7 +274,7 @@ func (w hostConfigWrapper) GetHostConfig
 func DecodeHostConfig(src io.Reader) (*HostConfig, error) {
 	decoder := json.NewDecoder(src)
 
-	var w hostConfigWrapper
+	var w HostConfigWrapper
 	if err := decoder.Decode(&w); err != nil {
 		return nil, err
 	}
