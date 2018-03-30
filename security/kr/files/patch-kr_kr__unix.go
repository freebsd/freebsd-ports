--- kr/kr_unix.go.orig	2018-01-09 20:17:55 UTC
+++ kr/kr_unix.go
@@ -61,12 +61,15 @@ func hasYum() bool {
 func hasYaourt() bool {
 	return exec.Command("which", "yaourt").Run() == nil
 }
+func hasPkg() bool {
+	return exec.Command("which", "pkg").Run() == nil
+}
 
 func uninstallCommand(c *cli.Context) (err error) {
 	go func() {
 		kr.Analytics{}.PostEventUsingPersistedTrackingID("kr", "uninstall", nil, nil)
 	}()
-	confirmOrFatal(os.Stderr, "Uninstall Krypton from this workstation? (same as sudo apt-get/yum remove kr)")
+	confirmOrFatal(os.Stderr, "Uninstall Krypton from this workstation? (same as sudo pkg remove kr)")
 
 	exec.Command("killall", "krd").Run()
 
@@ -87,6 +90,9 @@ func uninstallCommand(c *cli.Context) (e
 	if hasYaourt() {
 		runCommandWithUserInteraction("sudo", "yaourt", "-R", "kr")
 	}
+	if hasPkg() {
+		runCommandWithUserInteraction("sudo", "pkg", "remove", "kr")
+	}
 
 	cleanSSHConfig()
 	uninstallCodesigning()
@@ -118,6 +124,9 @@ func upgradeCommand(c *cli.Context) (err
 	if hasYaourt() {
 		runCommandWithUserInteraction("sudo", "yaourt", "-Sy", "kr")
 	}
+	if hasPkg() {
+		runCommandWithUserInteraction("sudo", "pkg", "upgrade", "kr")
+	}
 
 	return
 }
