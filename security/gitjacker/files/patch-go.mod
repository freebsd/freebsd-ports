--- go.mod.orig	2023-03-20 17:03:06 UTC
+++ go.mod
@@ -1,15 +1,20 @@
 module github.com/liamg/gitjacker
 
-go 1.15
+go 1.17
 
 require (
 	github.com/liamg/tml v0.3.0
 	github.com/magiconair/properties v1.8.0
 	github.com/sirupsen/logrus v1.2.0
 	github.com/spf13/cobra v1.0.0
+)
+
+require (
+	github.com/inconshreveable/mousetrap v1.0.0 // indirect
+	github.com/konsorten/go-windows-terminal-sequences v1.0.1 // indirect
+	github.com/spf13/pflag v1.0.3 // indirect
 	github.com/stretchr/testify v1.4.0 // indirect
 	golang.org/x/crypto v0.0.0-20190701094942-4def268fd1a4 // indirect
-	golang.org/x/sys v0.0.0-20190726091711-fc99dfbffb4e // indirect
-	gopkg.in/check.v1 v1.0.0-20190902080502-41f04d3bba15 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 	gopkg.in/yaml.v2 v2.2.4 // indirect
 )
