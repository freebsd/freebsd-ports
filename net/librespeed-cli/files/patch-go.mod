--- go.mod.orig	2023-03-24 21:32:43 UTC
+++ go.mod
@@ -1,17 +1,22 @@
 module github.com/librespeed/speedtest-cli
 
-go 1.14
+go 1.17
 
 require (
 	github.com/briandowns/spinner v1.12.0
-	github.com/cpuguy83/go-md2man/v2 v2.0.0 // indirect
-	github.com/fatih/color v1.10.0 // indirect
 	github.com/go-ping/ping v0.0.0-20210407214646-e4e642a95741
 	github.com/gocarina/gocsv v0.0.0-20210408192840-02d7211d929d
-	github.com/russross/blackfriday/v2 v2.1.0 // indirect
 	github.com/sirupsen/logrus v1.8.1
-	github.com/stretchr/testify v1.3.0 // indirect
 	github.com/urfave/cli/v2 v2.3.0
-	golang.org/x/net v0.0.0-20210421230115-4e50805a0758 // indirect
-	golang.org/x/sys v0.0.0-20210421221651-33663a62ff08 // indirect
+)
+
+require (
+	github.com/cpuguy83/go-md2man/v2 v2.0.0 // indirect
+	github.com/fatih/color v1.10.0 // indirect
+	github.com/mattn/go-colorable v0.1.8 // indirect
+	github.com/mattn/go-isatty v0.0.12 // indirect
+	github.com/russross/blackfriday/v2 v2.1.0 // indirect
+	github.com/stretchr/testify v1.3.0 // indirect
+	golang.org/x/net v0.8.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 )
