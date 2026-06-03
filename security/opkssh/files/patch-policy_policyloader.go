--- policy/policyloader.go.orig	2025-11-15 20:20:44 UTC
+++ policy/policyloader.go
@@ -29,7 +29,7 @@ import (
 
 // SystemDefaultPolicyPath is the default filepath where opkssh policy is
 // defined
-var SystemDefaultPolicyPath = filepath.FromSlash("/etc/opk/auth_id")
+var SystemDefaultPolicyPath = filepath.FromSlash("%%PREFIX%%/etc/opk/auth_id")
 
 // UserLookup defines the minimal interface to lookup users on the current
 // system
