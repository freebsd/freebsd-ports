--- vendor/github.com/containers/common/pkg/config/config_unsupported.go.orig	2025-01-20 18:22:54 UTC
+++ vendor/github.com/containers/common/pkg/config/config_unsupported.go
@@ -5,3 +5,9 @@ func selinuxEnabled() bool {
 func selinuxEnabled() bool {
 	return false
 }
+
+// Capabilities returns the capabilities parses the Add and Drop capability
+// list from the default capabilities for the container
+func (c *Config) Capabilities(user string, addCapabilities, dropCapabilities []string) ([]string, error) {
+	return nil, nil
+}
