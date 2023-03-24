--- go.mod.orig	2023-03-24 16:21:50 UTC
+++ go.mod
@@ -1,12 +1,19 @@
 module github.com/bcicen/slackcat
 
-go 1.16
+go 1.17
 
 require (
 	github.com/BurntSushi/toml v0.3.0
 	github.com/fatih/color v1.5.0
-	github.com/mattn/go-colorable v0.1.8 // indirect
 	github.com/skratchdot/open-golang v0.0.0-20160302144031-75fb7ed4208c
 	github.com/slack-go/slack v0.8.1
 	github.com/urfave/cli v1.20.0
+)
+
+require (
+	github.com/gorilla/websocket v1.4.2 // indirect
+	github.com/mattn/go-colorable v0.1.8 // indirect
+	github.com/mattn/go-isatty v0.0.12 // indirect
+	github.com/pkg/errors v0.8.0 // indirect
+	golang.org/x/sys v0.6.0 // indirect
 )
