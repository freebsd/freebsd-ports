--- vendor/github.com/containers/common/pkg/config/config.go.orig	2025-01-20 18:22:54 UTC
+++ vendor/github.com/containers/common/pkg/config/config.go
@@ -12,7 +12,6 @@ import (
 
 	"github.com/containers/common/internal/attributedstring"
 	"github.com/containers/common/libnetwork/types"
-	"github.com/containers/common/pkg/capabilities"
 	"github.com/containers/storage/pkg/fileutils"
 	"github.com/containers/storage/pkg/unshare"
 	units "github.com/docker/go-units"
@@ -963,24 +962,6 @@ func (c *Config) GetDefaultEnvEx(envHost, httpProxy bo
 		}
 	}
 	return append(env, c.Containers.Env.Get()...)
-}
-
-// Capabilities returns the capabilities parses the Add and Drop capability
-// list from the default capabilities for the container
-func (c *Config) Capabilities(user string, addCapabilities, dropCapabilities []string) ([]string, error) {
-	userNotRoot := func(user string) bool {
-		if user == "" || user == "root" || user == "0" {
-			return false
-		}
-		return true
-	}
-
-	defaultCapabilities := c.Containers.DefaultCapabilities.Get()
-	if userNotRoot(user) {
-		defaultCapabilities = []string{}
-	}
-
-	return capabilities.MergeCapabilities(defaultCapabilities, addCapabilities, dropCapabilities)
 }
 
 // Device parses device mapping string to a src, dest & permissions string
