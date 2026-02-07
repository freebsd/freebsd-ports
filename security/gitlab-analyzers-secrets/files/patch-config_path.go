--- config/path.go.orig	2025-11-15 14:06:29 UTC
+++ config/path.go
@@ -9,7 +9,7 @@ import (
 )
 
 // DefaultPathGitleaksConfig is the default path for the Gitleaks configuration file.
-const DefaultPathGitleaksConfig = "/gitleaks.toml"
+const DefaultPathGitleaksConfig = "/usr/local/share/gitlab-analyzers-secrets/gitleaks.toml"
 
 // GitleaksPassthroughTarget is the target filename for Gitleaks configuration in passthrough scenarios.
 const GitleaksPassthroughTarget = "gitleaks.toml"
