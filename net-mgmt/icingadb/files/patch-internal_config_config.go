--- internal/config/config.go.orig	2025-07-14 11:25:55 UTC
+++ internal/config/config.go
@@ -56,7 +56,7 @@ type Flags struct {
 	Version bool `long:"version" description:"print version and exit"`
 
 	// Config is the path to the config file. If not provided, it defaults to DefaultConfigPath.
-	Config string `short:"c" long:"config" description:"path to config file (default: /etc/icingadb/config.yml)"`
+	Config string `short:"c" long:"config" description:"path to config file (default: %%PREFIX%%/etc/icingadb/config.yml)"`
 	// default must be kept in sync with DefaultConfigPath.
 
 	// DatabaseAutoImport results in an initial schema check and update; mostly for containerized setups.
