--- policy/enforcer.go.orig	2026-09-25 23:41:01 UTC
+++ policy/enforcer.go
@@ -106,7 +106,7 @@ func (s *checkedClaims) UnmarshalJSON(data []byte) err
 }
 
 // GetPluginPolicyDir returns the default location for policy plugins.
-// On Unix: /etc/opk/policy.d, On Windows: %ProgramData%\opk\policy.d
+// On Unix: %%PREFIX%%/etc/opk/policy.d, On Windows: %ProgramData%\opk\policy.d
 func GetPluginPolicyDir() string {
 	return filepath.Join(GetSystemConfigBasePath(), "policy.d")
 }
