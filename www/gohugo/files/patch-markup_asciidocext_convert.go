--- markup/asciidocext/convert.go.orig	2021-01-23 16:42:36 UTC
+++ markup/asciidocext/convert.go
@@ -105,7 +105,7 @@ func (a *asciidocConverter) parseArgs(ctx converter.Do
 	args = a.appendArg(args, "-b", cfg.Backend, asciidocext_config.CliDefault.Backend, asciidocext_config.AllowedBackend)
 
 	for _, extension := range cfg.Extensions {
-		if !asciidocext_config.AllowedExtensions[extension] {
+		if cfg.SafeMode != "unsafe" && !asciidocext_config.AllowedExtensions[extension] {
 			a.cfg.Logger.Errorln("Unsupported asciidoctor extension was passed in. Extension `" + extension + "` ignored.")
 			continue
 		}
