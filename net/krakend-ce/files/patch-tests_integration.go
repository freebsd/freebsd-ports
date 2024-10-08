--- tests/integration.go.orig	1979-11-29 20:00:00 UTC
+++ tests/integration.go
@@ -25,7 +25,7 @@ var (
 )
 
 var (
-	defaultBinPath     *string = flag.String("krakend_bin_path", ".././krakend", "The default path to the krakend bin")
+	defaultBinPath     *string = flag.String("krakend_bin_path", "../../../../../bin/krakend-ce", "The default path to the krakend bin")
 	defaultSpecsPath   *string = flag.String("krakend_specs_path", "./fixtures/specs", "The default path to the specs folder")
 	defaultBackendPort *int    = flag.Int("krakend_backend_port", 8081, "The port for the mocked backend api")
 	defaultCfgPath     *string = flag.String(
