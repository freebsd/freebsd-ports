--- generate.go.orig	2017-09-07 20:04:03 UTC
+++ generate.go
@@ -4,6 +4,6 @@ Copyright
 
 //go:generate rm -vf autogen/gen.go
 //go:generate mkdir -p static
-//go:generate go-bindata -pkg autogen -o autogen/gen.go ./static/... ./templates/...
+//go:generate src/github.com/jteeuwen/go-bindata/go-bindata/go-bindata -pkg autogen -o autogen/gen.go ./static/... ./templates/...
 
 package main
