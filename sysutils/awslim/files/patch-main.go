--- main.go.orig	2026-10-26 05:13:31 UTC
+++ main.go
@@ -496,4 +496,4 @@ func kebabToPascal(kebab string) string {
 	return strings.Join(results, "")
 }
 
-//go:generate go run cmd/awslim-gen/main.go cmd/awslim-gen/gen.go
+//go:generate ${GO_CMD} run cmd/awslim-gen/main.go cmd/awslim-gen/gen.go
