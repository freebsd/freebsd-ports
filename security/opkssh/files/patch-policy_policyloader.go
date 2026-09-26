--- policy/policyloader.go.orig	2026-09-25 23:41:01 UTC
+++ policy/policyloader.go
@@ -27,7 +27,7 @@ import (
 )
 
 // SystemDefaultPolicyPath is the default filepath where opkssh policy is
-// defined. On Unix: /etc/opk/auth_id, On Windows: %ProgramData%\opk\auth_id
+// defined. On Unix: %%PREFIX%%/etc/opk/auth_id, On Windows: %ProgramData%\opk\auth_id
 var SystemDefaultPolicyPath = filepath.Join(GetSystemConfigBasePath(), "auth_id")
 
 // SystemDefaultProvidersPath is the default filepath where opkssh provider
