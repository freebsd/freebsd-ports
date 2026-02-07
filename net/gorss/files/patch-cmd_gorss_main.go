--- cmd/gorss/main.go.orig	2023-03-23 17:07:57 UTC
+++ cmd/gorss/main.go
@@ -41,6 +41,7 @@ func main() {
 
 	dataHome := conf.DataHome()
 	configHome := conf.ConfigHome()
+	systemDataDir := conf.DataDirs()[0]
 
 	// Create dirs
 	for _, path := range []string{dataHome, configHome} {
@@ -61,7 +62,7 @@ func main() {
 			// check if default config exists, copy if not
 			_, err := os.Stat(cfg)
 			if errors.Is(err, os.ErrNotExist) {
-				internal.CopyFile(defaultConfig, cfg)
+				internal.CopyFile(fmt.Sprintf("%s/%s", systemDataDir, defaultConfig), cfg)
 			}
 		}
 	}
@@ -80,7 +81,7 @@ func main() {
 				if err := os.Mkdir(themeDir, os.ModePerm); err != nil {
 					log.Printf("Failed to create dir: %s\n", themeDir)
 				}
-				internal.CopyFile(defaultTheme, theme)
+				internal.CopyFile(fmt.Sprintf("%s/%s", systemDataDir, defaultTheme), theme)
 			}
 		}
 	}
