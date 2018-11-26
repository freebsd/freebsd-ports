--- commands/configtest.go.orig	2018-11-16 12:22:18 UTC
+++ commands/configtest.go
@@ -20,8 +20,6 @@ package commands
 import (
 	"context"
 	"flag"
-	"os"
-	"path/filepath"
 
 	"github.com/google/subcommands"
 
@@ -63,8 +61,7 @@ func (*ConfigtestCmd) Usage() string {
 
 // SetFlags set flag
 func (p *ConfigtestCmd) SetFlags(f *flag.FlagSet) {
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultLogDir := util.GetDefaultLogDir()
