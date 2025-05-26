--- vendor/golang.org/x/tools/internal/gocommand/invoke.go.orig	2025-05-08 09:34:03 UTC
+++ vendor/golang.org/x/tools/internal/gocommand/invoke.go
@@ -245,7 +245,7 @@ func (i *Invocation) run(ctx context.Context, stdout, 
 		appendOverlayFlag()
 		goArgs = append(goArgs, i.Args...)
 	}
-	cmd := exec.Command("go", goArgs...)
+	cmd := exec.Command("%%GO_CMD%%", goArgs...)
 	cmd.Stdout = stdout
 	cmd.Stderr = stderr
 
