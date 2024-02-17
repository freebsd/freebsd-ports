--- plugins/manx/update-shells.sh.orig	2022-08-08 23:34:48 UTC
+++ plugins/manx/update-shells.sh
@@ -1,7 +1,8 @@
-#!/bin/bash
+#!/bin/sh
 cwd=$(pwd)
 cd shells
 GOOS=windows go build -o ../payloads/manx.go-windows -ldflags="-s -w" manx.go
 GOOS=linux go build -o ../payloads/manx.go-linux -ldflags="-s -w" manx.go
 GOOS=darwin go build -o ../payloads/manx.go-darwin -ldflags="-s -w" manx.go
+GOOS=freebsd go build -o ../payloads/manx.go-freebsd -ldflags="-s -w" manx.go
 cd $cwd
