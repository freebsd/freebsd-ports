--- subcmds/configtest.go.orig	1979-11-29 23:00:00 UTC
+++ subcmds/configtest.go
@@ -4,8 +4,6 @@ import (
 	"context"
 	"flag"
 	"fmt"
-	"os"
-	"path/filepath"
 	"strings"
 
 	"github.com/google/subcommands"
@@ -46,8 +44,7 @@ func (p *ConfigtestCmd) SetFlags(f *flag.FlagSet) {
 
 // SetFlags set flag
 func (p *ConfigtestCmd) SetFlags(f *flag.FlagSet) {
-	wd, _ := os.Getwd()
-	defaultConfPath := filepath.Join(wd, "config.toml")
+	defaultConfPath := "%%ETCDIR%%/config.toml"
 	f.StringVar(&p.configPath, "config", defaultConfPath, "/path/to/toml")
 
 	defaultLogDir := logging.GetDefaultLogDir()
