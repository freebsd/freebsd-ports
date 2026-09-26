--- policy/validator.go.orig	2026-09-25 23:41:01 UTC
+++ policy/validator.go
@@ -79,7 +79,7 @@ func (v *PolicyValidator) ValidateEntry(principal, ide
 	_, exists := v.issuerMap[issuer]
 	if !exists {
 		result.Status = StatusError
-		result.Reason = "issuer not found in /etc/opk/providers"
+		result.Reason = "issuer not found in %%PREFIX%%/etc/opk/providers"
 
 		// issuer in policy file has a trailing slash, but issuer in provider file does not have a trailing slash
 		if strings.HasSuffix(issuer, "/") {
@@ -110,7 +110,7 @@ func (v *PolicyValidator) ValidateEntry(principal, ide
 		}
 
 		result.Hints = append(result.Hints,
-			fmt.Sprintf("Ensure the issuer URL (%s) is correct and matches an entry in /etc/opk/providers", issuer))
+			fmt.Sprintf("Ensure the issuer URL (%s) is correct and matches an entry in %%PREFIX%%/etc/opk/providers", issuer))
 		return result
 	}
 
