--- go.mod.orig	2021-07-17 13:10:12 UTC
+++ go.mod
@@ -1,5 +1,7 @@
 module github.com/writeas/writeas-cli
 
+go 1.16
+
 require (
 	code.as/core/socks v1.0.0
 	github.com/atotto/clipboard v0.1.1
@@ -20,7 +22,7 @@ require (
 	github.com/writeas/web-core v0.0.0-20181111165528-05f387ffa1b3
 	golang.org/x/crypto v0.0.0-20181203042331-505ab145d0a9 // indirect
 	golang.org/x/net v0.0.0-20181217023233-e147a9138326 // indirect
-	golang.org/x/sys v0.0.0-20181213200352-4d1cda033e06 // indirect
+	golang.org/x/sys v0.0.0-20210630005230-0f9fa26af87c // indirect
 	gopkg.in/ini.v1 v1.39.3
 	gopkg.in/urfave/cli.v1 v1.20.0
 )
