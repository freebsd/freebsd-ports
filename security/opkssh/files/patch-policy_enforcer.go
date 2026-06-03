--- policy/enforcer.go.orig	2025-11-15 20:20:44 UTC
+++ policy/enforcer.go
@@ -54,7 +54,7 @@ type checkedClaims struct {
 }
 
 // The default location for policy plugins
-const pluginPolicyDir = "/etc/opk/policy.d"
+const pluginPolicyDir = "%%PREFIX%%/etc/opk/policy.d"
 
 // Validates that the server defined identity attribute matches the
 // respective claim from the identity token
