--- cmd/agent/common/common_nix.go.orig	2020-11-23 20:15:00 UTC
+++ cmd/agent/common/common_nix.go
@@ -12,7 +12,6 @@ import (
 	"path/filepath"
 
 	// Init packages
-	_ "github.com/DataDog/datadog-agent/pkg/util/containers/providers/cgroup"
 )
 
 const (
@@ -26,9 +25,9 @@ const (
 
 var (
 	// PyChecksPath holds the path to the python checks from integrations-core shipped with the agent
-	PyChecksPath = filepath.Join(_here, "..", "..", "checks.d")
+	PyChecksPath = filepath.Join(DefaultConfPath, "checks.d")
 	// DistPath holds the path to the folder containing distribution files
-	distPath = filepath.Join(_here, "dist")
+	distPath = filepath.Join(DefaultConfPath, "dist")
 )
 
 // GetDistPath returns the fully qualified path to the 'dist' directory
