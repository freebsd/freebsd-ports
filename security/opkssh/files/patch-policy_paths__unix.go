--- policy/paths_unix.go.orig	2026-09-25 23:41:01 UTC
+++ policy/paths_unix.go
@@ -20,7 +20,7 @@ package policy
 package policy
 
 // GetSystemConfigBasePath returns the base path for system opkssh configuration.
-// On Unix-like systems, this is /etc/opk
+// On Unix-like systems, this is %%PREFIX%%/etc/opk
 func GetSystemConfigBasePath() string {
-	return "/etc/opk"
+	return "%%PREFIX%%/etc/opk"
 }
