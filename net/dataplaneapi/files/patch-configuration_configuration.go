--- configuration/configuration.go.orig	2026-07-03 20:15:15 UTC
+++ configuration/configuration.go
@@ -36,7 +36,7 @@ type HAProxyConfiguration struct {
 var cfg *Configuration
 
 type HAProxyConfiguration struct {
-	SpoeDir              string        `long:"spoe-dir" description:"Path to SPOE directory." default:"/etc/haproxy/spoe" group:"resources"`
+	SpoeDir              string        `long:"spoe-dir" description:"Path to SPOE directory." default:"%%PREFIX%%/etc/haproxy/spoe" group:"resources"`
 	ServiceName          string        `long:"service" description:"Name of the HAProxy service" group:"reload"`
 	HAProxy              string        `short:"b" long:"haproxy-bin" description:"Path to the haproxy binary file" default:"haproxy" group:"haproxy"`
 	UserListFile         string        `long:"userlist-file" description:"Path to the dataplaneapi userlist file. By default userlist is read from HAProxy conf. When specified userlist would be read from this file" group:"userlist"`
@@ -50,15 +50,15 @@ type HAProxyConfiguration struct {
 	ValidateFilesBefore  []string      `long:"validate-files-before" description:"A list of configuration files to be loaded before the main file for validation" group:"reload"`
 	ValidateFilesAfter   []string      `long:"validate-files-after" description:"A list of configuration files to be loaded after the main file for validation" group:"reload"`
 	BackupsDir           string        `long:"backups-dir" description:"Path to directory in which to place backup files" group:"transaction"`
-	MapsDir              string        `short:"p" long:"maps-dir" description:"Path to directory of map files managed by dataplane" default:"/etc/haproxy/maps" group:"resources"`
+	MapsDir              string        `short:"p" long:"maps-dir" description:"Path to directory of map files managed by dataplane" default:"%%PREFIX%%/etc/haproxy/maps" group:"resources"`
 	SpoeTransactionDir   string        `long:"spoe-transaction-dir" description:"Path to the SPOE transaction directory" default:"/tmp/spoe-haproxy" group:"resources"`
-	DataplaneConfig      string        `short:"f" description:"Path to the dataplane configuration file" default:"/etc/haproxy/dataplaneapi.yaml" yaml:"-"`
-	ConfigFile           string        `short:"c" long:"config-file" description:"Path to the haproxy configuration file" default:"/etc/haproxy/haproxy.cfg" group:"haproxy"`
+	DataplaneConfig      string        `short:"f" description:"Path to the dataplane configuration file" default:"%%PREFIX%%/etc/haproxy/dataplaneapi.yaml" yaml:"-"`
+	ConfigFile           string        `short:"c" long:"config-file" description:"Path to the haproxy configuration file" default:"%%PREFIX%%/etc/haproxy/haproxy.cfg" group:"haproxy"`
 	Userlist             string        `short:"u" long:"userlist" description:"Userlist in HAProxy configuration to use for API Basic Authentication" default:"controller" group:"userlist"`
 	MasterRuntime        string        `short:"m" long:"master-runtime" description:"Path to the master Runtime API socket" group:"haproxy"`
-	SSLCertsDir          string        `long:"ssl-certs-dir" description:"Path to SSL certificates directory" default:"/etc/haproxy/ssl" group:"resources"`
-	GeneralStorageDir    string        `long:"general-storage-dir" description:"Path to general storage directory" default:"/etc/haproxy/general" group:"resources"`
-	DataplaneStorageDir  string        `long:"dataplane-storage-dir" description:"Path to dataplane internal storage directory" default:"/etc/haproxy/dataplane" group:"resources"`
+	SSLCertsDir          string        `long:"ssl-certs-dir" description:"Path to SSL certificates directory" default:"%%PREFIX%%/etc/haproxy/ssl" group:"resources"`
+	GeneralStorageDir    string        `long:"general-storage-dir" description:"Path to general storage directory" default:"%%PREFIX%%/etc/haproxy/general" group:"resources"`
+	DataplaneStorageDir  string        `long:"dataplane-storage-dir" description:"Path to dataplane internal storage directory" default:"%%PREFIX%%/etc/haproxy/dataplane" group:"resources"`
 	PreferredTimeSuffix  string        `long:"time-suffix" description:"Preferred time unit to use when writing time values in configuration (nearest, none, ms, s, m, h, d)" default:"nearest" group:"haproxy"`
 	UpdateMapFilesPeriod int64         `long:"update-map-files-period" description:"Elapsed time in seconds between two maps syncing operations" default:"10" group:"resources"`
 	ReloadDelay          int           `short:"d" long:"reload-delay" description:"Minimum delay between two reloads (in s)" default:"5" group:"reload"`
