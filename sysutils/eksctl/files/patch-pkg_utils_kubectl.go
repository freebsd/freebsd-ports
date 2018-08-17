--- pkg/utils/kubectl.go.orig	2018-08-17 19:52:51 UTC
+++ pkg/utils/kubectl.go
@@ -46,22 +46,12 @@ func CheckKubectlVersion(env []string) error {
 	return nil
 }
 
-func CheckHeptioAuthenticatorAWS() error {
-	path, err := exec.LookPath("heptio-authenticator-aws")
-	if err == nil {
-		logger.Debug("heptio-authenticator-aws: %q", path)
-	} else {
-		return fmt.Errorf("heptio-authenticator-aws not installed")
-	}
-	return nil
-}
-
 func CheckAllCommands(kubeconfigPath string, isContextSet bool, contextName string, env []string) error {
 	if err := CheckKubectlVersion(env); err != nil {
 		return err
 	}
 
-	if err := CheckHeptioAuthenticatorAWS(); err != nil {
+	if err := checkAuthenticator(); err != nil {
 		return err
 	}
 
@@ -97,4 +87,18 @@ func CheckAllCommands(kubeconfigPath string, isContext
 	}
 
 	return nil
+}
+
+// checkAuthenticator checks for the authenticator binary existence.
+func checkAuthenticator() error {
+	binaries := []string{"heptio-authenticator-aws", "aws-iam-authenticator"}
+	for _, bin := range binaries {
+		path, err := exec.LookPath(bin)
+		if err == nil {
+			// binary was found
+			logger.Debug("%s: %q", bin, path)
+			return nil
+		}
+	}
+	return fmt.Errorf("neither aws-iam-authenticator nor heptio-authenticator-aws are installed")
 }
