--- main.go.orig	2026-09-25 23:46:47 UTC
+++ main.go
@@ -81,7 +81,7 @@ This program allows users to:
 		Short:        "Appends new rule to the policy file",
 		Long: `Add appends a new policy entry in the auth_id policy file granting SSH access to the specified email or subscriber ID (sub) or group.
 
-It first attempts to write to the system-wide file (/etc/opk/auth_id). If it lacks permissions to update this file it falls back to writing to the user-specific file (~/.opk/auth_id).
+It first attempts to write to the system-wide file (%%PREFIX%%/etc/opk/auth_id). If it lacks permissions to update this file it falls back to writing to the user-specific file (~/.opk/auth_id).
 
 Arguments:
   principal            The target user account (requested principal).
@@ -283,7 +283,7 @@ You should not call this command directly. It is calle
 		SilenceUsage: true,
 		Use:          "verify <principal> <cert> <key_type>",
 		Short:        "Verify an SSH key (used by sshd AuthorizedKeysCommand)",
-		Long: `Verify extracts a PK token from a base64-encoded SSH certificate and verifies it against policy. It expects an allowed provider file at /etc/opk/providers and a user policy file at either /etc/opk/auth_id or ~/.opk/auth_id.
+		Long: `Verify extracts a PK token from a base64-encoded SSH certificate and verifies it against policy. It expects an allowed provider file at %%PREFIX%%/etc/opk/providers and a user policy file at either %%PREFIX%%/etc/opk/auth_id or ~/.opk/auth_id.
 
 This command is intended to be called by sshd as an AuthorizedKeysCommand:
   https://man.openbsd.org/sshd_config#AuthorizedKeysCommand
@@ -299,8 +299,8 @@ Verification checks performed:
 
 Verification checks performed:
   1. Ensures the PK token is properly formed, signed, and issued by the specified OpenID Provider (OP).
-  2. Confirms the PK token's issue (iss) and client ID (audience) are listed in the allowed provider file (/etc/opk/providers) and the token is not expired.
-  3. Validates the identity (email or sub) in the PK token against user policies (/etc/opk/auth_id or ~/.opk/auth_id) to ensure it can assume the requested username (principal).
+  2. Confirms the PK token's issue (iss) and client ID (audience) are listed in the allowed provider file (%%PREFIX%%/etc/opk/providers) and the token is not expired.
+  3. Validates the identity (email or sub) in the PK token against user policies (%%PREFIX%%/etc/opk/auth_id or ~/.opk/auth_id) to ensure it can assume the requested username (principal).
 
 If all checks pass, Verify authorizes the SSH connection.
 
