--- main.go.orig	2025-09-11 18:38:37 UTC
+++ main.go
@@ -80,7 +80,7 @@ This program allows users to:
 		Short:        "Appends new rule to the policy file",
 		Long: `Add appends a new policy entry in the auth_id policy file granting SSH access to the specified email or subscriber ID (sub) or group.
 
-It first attempts to write to the system-wide file (/etc/opk/auth_id). If it lacks permissions to update this file it falls back to writing to the user-specific file (~/.opk/auth_id).
+It first attempts to write to the system-wide file (%%PREFIX%%/etc/opk/auth_id). If it lacks permissions to update this file it falls back to writing to the user-specific file (~/.opk/auth_id).
 
 Arguments:
   PRINCIPAL            The target user account (requested principal).
@@ -217,7 +217,7 @@ You should not call this command directly. It is calle
 		SilenceUsage: true,
 		Use:          "verify <PRINCIPAL> <CERT> <KEY_TYPE>",
 		Short:        "Verify an SSH key (used by sshd AuthorizedKeysCommand)",
-		Long: `Verify extracts a PK token from a base64-encoded SSH certificate and verifies it against policy. It expects an allowed provider file at /etc/opk/providers and a user policy file at either /etc/opk/auth_id or ~/.opk/auth_id.
+		Long: `Verify extracts a PK token from a base64-encoded SSH certificate and verifies it against policy. It expects an allowed provider file at %%PREFIX%%/etc/opk/providers and a user policy file at either %%PREFIX%%/etc/opk/auth_id or ~/.opk/auth_id.
 
 This command is intended to be called by sshd as an AuthorizedKeysCommand:
   https://man.openbsd.org/sshd_config#AuthorizedKeysCommand
@@ -233,8 +233,8 @@ Verification checks performed:
 
 Verification checks performed:
   1. Ensures the PK token is properly formed, signed, and issued by the specified OpenID Provider (OP).
-  2. Confirms the PK token's issue (iss) and client ID (audience) are listed in the allowed provider file (/etc/opk/providers) and the token is not expired.
-  3. Validates the identity (email or sub) in the PK token against user policies (/etc/opk/auth_id or ~/.opk/auth_id) to ensure it can assume the requested username (principal).
+  2. Confirms the PK token's issue (iss) and client ID (audience) are listed in the allowed provider file (%%PREFIX%%/etc/opk/providers) and the token is not expired.
+  3. Validates the identity (email or sub) in the PK token against user policies (%%PREFIX%%/etc/opk/auth_id or ~/.opk/auth_id) to ensure it can assume the requested username (principal).
 
 If all checks pass, Verify authorizes the SSH connection.
 
@@ -269,10 +269,10 @@ Arguments:
 			certB64Arg := args[1]
 			typArg := args[2]
 
-			providerPolicyPath := "/etc/opk/providers"
+			providerPolicyPath := "%%PREFIX%%/etc/opk/providers"
 			providerPolicy, err := policy.NewProviderFileLoader().LoadProviderPolicy(providerPolicyPath)
 			if err != nil {
-				log.Println("Failed to open /etc/opk/providers:", err)
+				log.Println("Failed to open %%PREFIX%%/etc/opk/providers:", err)
 				return err
 			}
 
@@ -301,7 +301,7 @@ Arguments:
 			}
 		},
 	}
-	verifyCmd.Flags().StringVar(&serverConfigPathArg, "config-path", "/etc/opk/config.yml", "Path to the server config file. Default: /etc/opk/config.yml.")
+	verifyCmd.Flags().StringVar(&serverConfigPathArg, "config-path", "%%PREFIX%%/etc/opk/config.yml", "Path to the server config file. Default: %%PREFIX%%/etc/opk/config.yml.")
 	rootCmd.AddCommand(verifyCmd)
 
 	clientCmd := &cobra.Command{
@@ -504,30 +504,30 @@ func detectOS() OSType {
 // detectOS determines the type of operating system.
 func detectOS() OSType {
 	// Check for RedHat-based systems
-	if _, err := os.Stat("/etc/redhat-release"); err == nil {
+	if _, err := os.Stat("%%PREFIX%%/etc/redhat-release"); err == nil {
 		return OSTypeRHEL
 	}
 
 	// Check for Debian-based systems
-	if _, err := os.Stat("/etc/debian_version"); err == nil {
+	if _, err := os.Stat("%%PREFIX%%/etc/debian_version"); err == nil {
 		return OSTypeDebian
 	}
 
 	// Check for Arch Linux
-	if _, err := os.Stat("/etc/arch-release"); err == nil {
+	if _, err := os.Stat("%%PREFIX%%/etc/arch-release"); err == nil {
 		return OSTypeArch
 	}
 
 	// Check for SUSE Linux
-	if _, err := os.Stat("/etc/SuSE-release"); err == nil {
+	if _, err := os.Stat("%%PREFIX%%/etc/SuSE-release"); err == nil {
 		return OSTypeSUSE
 	}
-	if _, err := os.Stat("/etc/SUSE-brand"); err == nil {
+	if _, err := os.Stat("%%PREFIX%%/etc/SUSE-brand"); err == nil {
 		return OSTypeSUSE
 	}
 
-	// Check for /etc/os-release which exists on most modern Linux systems
-	if content, err := os.ReadFile("/etc/os-release"); err == nil {
+	// Check for %%PREFIX%%/etc/os-release which exists on most modern Linux systems
+	if content, err := os.ReadFile("%%PREFIX%%/etc/os-release"); err == nil {
 		contentStr := string(content)
 		if strings.Contains(contentStr, "ID=rhel") ||
 			strings.Contains(contentStr, "ID=centos") ||
