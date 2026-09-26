--- policy/files/permschecker_common.go.orig	2026-09-25 23:41:01 UTC
+++ policy/files/permschecker_common.go
@@ -24,7 +24,7 @@ import (
 )
 
 // ModeSystemPerms is the expected permission bits that should be set for opkssh
-// system policy files (on Unix: /etc/opk/auth_id, /etc/opk/providers; on Windows: %ProgramData%\opk\auth_id, %ProgramData%\opk\providers).
+// system policy files (on Unix: %%PREFIX%%/etc/opk/auth_id, %%PREFIX%%/etc/opk/providers; on Windows: %ProgramData%\opk\auth_id, %ProgramData%\opk\providers).
 // This mode means that only the owner of the file can write/read to the file, but the group which
 // should be opksshuser can read the file.
 const ModeSystemPerms = fs.FileMode(0o640)
