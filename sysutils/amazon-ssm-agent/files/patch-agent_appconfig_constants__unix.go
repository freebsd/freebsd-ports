--- agent/appconfig/constants_unix.go.orig	2025-12-22 20:08:01 UTC
+++ agent/appconfig/constants_unix.go
@@ -29,7 +29,7 @@ var (
 var (
 
 	// AgentExtensions specified the root folder for various kinds of downloaded content
-	AgentData = "/var/lib/amazon/ssm/"
+	AgentData = "/var/run/amazon/ssm/"
 
 	// PackageRoot specifies the directory under which packages will be downloaded and installed
 	PackageRoot = AgentData + "packages"
@@ -62,10 +62,10 @@ var (
 	DefaultDataStorePath = AgentData
 
 	// EC2ConfigDataStorePath represents the directory for storing ec2 config data
-	EC2ConfigDataStorePath = "/var/lib/amazon/ec2config/"
+	EC2ConfigDataStorePath = "/var/run/amazon/ec2config/"
 
 	// EC2ConfigSettingPath represents the directory for storing ec2 config settings
-	EC2ConfigSettingPath = "/var/lib/amazon/ec2configservice/"
+	EC2ConfigSettingPath = "/var/run/amazon/ec2configservice/"
 
 	// UpdaterArtifactsRoot represents the directory for storing update related information
 	UpdaterArtifactsRoot = AgentData + "update/"
@@ -120,9 +120,9 @@ var PowerShellPluginCommandName string
 var PowerShellPluginCommandName string
 
 // DefaultProgramFolder is the default folder for SSM
-var DefaultProgramFolder = "/etc/amazon/ssm/"
+var DefaultProgramFolder = "/usr/local/etc/amazon/ssm/"
 
-var defaultWorkerPath = "/usr/bin/"
+var defaultWorkerPath = "/usr/local/sbin/"
 var DefaultSSMAgentBinaryPath = defaultWorkerPath + "amazon-ssm-agent"
 var DefaultSSMAgentWorker = defaultWorkerPath + "ssm-agent-worker"
 var DefaultDocumentWorker = defaultWorkerPath + "ssm-document-worker"
