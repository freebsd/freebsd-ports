--- cmd/agent/common/common_nix.go.orig	2020-10-26 08:53:53 UTC
+++ cmd/agent/common/common_nix.go
@@ -12,7 +12,6 @@ import (
 	"path/filepath"
 
 	// Init packages
-	_ "github.com/DataDog/datadog-agent/pkg/util/containers/providers/cgroup"
 )
 
 const (
