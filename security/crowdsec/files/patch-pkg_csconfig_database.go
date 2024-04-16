--- pkg/csconfig/database.go.orig	2024-04-24 21:31:39 UTC
+++ pkg/csconfig/database.go
@@ -76,26 +76,24 @@ func (c *Config) LoadDBConfig(inCli bool) error {
 		if c.DbConfig.UseWal == nil {
 			dbDir := filepath.Dir(c.DbConfig.DbPath)
 			isNetwork, fsType, err := types.IsNetworkFS(dbDir)
-			if err != nil {
+			switch {
+			case err != nil:
 				log.Warnf("unable to determine if database is on network filesystem: %s", err)
 				log.Warning("You are using sqlite without WAL, this can have a performance impact. If you do not store the database in a network share, set db_config.use_wal to true. Set explicitly to false to disable this warning.")
-				return nil
-			}
-			if isNetwork {
+			case isNetwork:
 				log.Debugf("database is on network filesystem (%s), setting useWal to false", fsType)
 				c.DbConfig.UseWal = ptr.Of(false)
-			} else {
+			default:
 				log.Debugf("database is on local filesystem (%s), setting useWal to true", fsType)
 				c.DbConfig.UseWal = ptr.Of(true)
 			}
 		} else if *c.DbConfig.UseWal {
 			dbDir := filepath.Dir(c.DbConfig.DbPath)
 			isNetwork, fsType, err := types.IsNetworkFS(dbDir)
-			if err != nil {
+			switch {
+			case err != nil:
 				log.Warnf("unable to determine if database is on network filesystem: %s", err)
-				return nil
-			}
-			if isNetwork {
+			case isNetwork:
 				log.Warnf("database seems to be stored on a network share (%s), but useWal is set to true. Proceed at your own risk.", fsType)
 			}
 		}
