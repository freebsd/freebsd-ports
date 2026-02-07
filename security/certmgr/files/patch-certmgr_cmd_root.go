--- certmgr/cmd/root.go.orig	2021-07-05 13:42:49 UTC
+++ certmgr/cmd/root.go
@@ -133,7 +133,7 @@ func Execute() {
 func init() {
 	cobra.OnInitialize(initConfig)
 
-	RootCmd.PersistentFlags().StringVarP(&cfgFile, "config", "f", "", "config file (default is /etc/certmgr/certmgr.yaml)")
+	RootCmd.PersistentFlags().StringVarP(&cfgFile, "config", "f", "", "config file (default is %%ETCDIR%%/certmgr.yaml)")
 	RootCmd.PersistentFlags().StringP("dir", "d", "", "either the directory containing certificate specs, or the path to the spec file you wish to operate on")
 	RootCmd.PersistentFlags().StringP("svcmgr", "m", "", fmt.Sprintf("service manager, must be one of: %s", strings.Join(storage.SupportedServiceBackends, ", ")))
 	RootCmd.PersistentFlags().DurationP("before", "t", cert.DefaultBefore, "how long before certificates expire to start renewing (in duration format)")
@@ -161,7 +161,7 @@ func initConfig() {
 		viper.SetConfigFile(cfgFile)
 	} else {
 		viper.SetConfigName("certmgr")      // name of config file (without extension)
-		viper.AddConfigPath("/etc/certmgr") // adding home directory as first search path
+		viper.AddConfigPath("%%ETCDIR%%") // adding home directory as first search path
 	}
 
 	viper.SetEnvPrefix("CERTMGR")
