--- subcmds/configtest.go.orig	2020-11-27 21:39:52 UTC
+++ subcmds/configtest.go
@@ -4,8 +4,7 @@ import (
 	"context"
 	"flag"
 	"fmt"
-	"os"
-	"path/filepath"
+    "path/filepath"
 	"strings"
 
 	"github.com/google/subcommands"
@@ -48,8 +47,7 @@ func (*ConfigtestCmd) Usage() string {
 
 // SetFlags set flag
 func (p *ConfigtestCmd) SetFlags(f *flag.FlagSet) {
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := filepath.Join("%%ETCDIR%%", "config.toml")
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultLogDir := util.GetDefaultLogDir()
