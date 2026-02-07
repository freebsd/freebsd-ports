--- agent/session/shell/shell_unix.go.orig	2023-04-01 00:01:35 UTC
+++ agent/session/shell/shell_unix.go
@@ -34,7 +34,7 @@ import (
 	"github.com/aws/amazon-ssm-agent/agent/log"
 	mgsContracts "github.com/aws/amazon-ssm-agent/agent/session/contracts"
 	"github.com/aws/amazon-ssm-agent/agent/session/utility"
-	"github.com/kr/pty"
+	"github.com/creack/pty"
 )
 
 var ptyFile *os.File
