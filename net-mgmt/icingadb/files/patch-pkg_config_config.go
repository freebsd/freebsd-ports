--- pkg/config/config.go.orig	2023-09-08 17:19:58 UTC
+++ pkg/config/config.go
@@ -46,7 +46,7 @@ type Flags struct {
 	// Version decides whether to just print the version and exit.
 	Version bool `long:"version" description:"print version and exit"`
 	// Config is the path to the config file
-	Config string `short:"c" long:"config" description:"path to config file" required:"true" default:"/etc/icingadb/config.yml"`
+	Config string `short:"c" long:"config" description:"path to config file" required:"true" default:"%%PREFIX%%/etc/icinga2/icingadb.yml"`
 }
 
 // FromYAMLFile returns a new Config value created from the given YAML config file.
