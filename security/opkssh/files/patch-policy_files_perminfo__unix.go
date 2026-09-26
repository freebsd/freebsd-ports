--- policy/files/perminfo_unix.go.orig	2026-09-25 23:41:01 UTC
+++ policy/files/perminfo_unix.go
@@ -23,19 +23,19 @@ var RequiredPerms = struct {
 // on Unix/Linux systems.
 var RequiredPerms = struct {
 	// SystemPolicy is the system-wide policy file
-	// (e.g. /etc/opk/auth_id).
+	// (e.g. %%PREFIX%%/etc/opk/auth_id).
 	SystemPolicy PermInfo
 	// HomePolicy is the per-user policy file
 	// (e.g. ~/.opk/auth_id).
 	HomePolicy PermInfo
 	// Providers is the provider configuration file
-	// (e.g. /etc/opk/providers).
+	// (e.g. %%PREFIX%%/etc/opk/providers).
 	Providers PermInfo
 	// Config is the server configuration file
-	// (e.g. /etc/opk/config.yml).
+	// (e.g. %%PREFIX%%/etc/opk/config.yml).
 	Config PermInfo
 	// PluginsDir is the directory containing policy plugin definitions
-	// (e.g. /etc/opk/policy.d).
+	// (e.g. %%PREFIX%%/etc/opk/policy.d).
 	PluginsDir PermInfo
 	// PluginFile is an individual plugin YAML file inside the plugins
 	// directory.
