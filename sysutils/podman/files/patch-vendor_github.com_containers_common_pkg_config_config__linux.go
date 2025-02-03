--- vendor/github.com/containers/common/pkg/config/config_linux.go.orig	2025-01-21 18:41:34 UTC
+++ vendor/github.com/containers/common/pkg/config/config_linux.go
@@ -1,6 +1,7 @@ import (
 package config
 
 import (
+	"github.com/containers/common/pkg/capabilities"
 	selinux "github.com/opencontainers/selinux/go-selinux"
 )
 
@@ -25,4 +26,22 @@ var defaultHelperBinariesDir = []string{
 	"/usr/local/lib/podman",
 	"/usr/libexec/podman",
 	"/usr/lib/podman",
+}
+
+// Capabilities returns the capabilities parses the Add and Drop capability
+// list from the default capabilities for the container
+func (c *Config) Capabilities(user string, addCapabilities, dropCapabilities []string) ([]string, error) {
+	userNotRoot := func(user string) bool {
+		if user == "" || user == "root" || user == "0" {
+			return false
+		}
+		return true
+	}
+
+	defaultCapabilities := c.Containers.DefaultCapabilities.Get()
+	if userNotRoot(user) {
+		defaultCapabilities = []string{}
+	}
+
+	return capabilities.MergeCapabilities(defaultCapabilities, addCapabilities, dropCapabilities)
 }
