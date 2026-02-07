--- plugins/sandcat/update-agents.sh.orig	2024-02-13 17:44:40.000000000 -0500
+++ plugins/sandcat/update-agents.sh	2024-02-16 16:03:09.225623000 -0500
@@ -1,11 +1,12 @@
-#!/bin/bash
+#!/bin/sh
 # generates payloads for each os
 
-function build() {
+build() {
 GOOS=windows go build -o ../payloads/sandcat.go-windows -ldflags="-s -w" sandcat.go
 GOOS=linux go build -o ../payloads/sandcat.go-linux -ldflags="-s -w" sandcat.go
 GOOS=darwin go build -o ../payloads/sandcat.go-darwin -ldflags="-s -w" sandcat.go
 GOOS=darwin GOARCH=arm64 go build -o ../payloads/sandcat.go-darwin-arm64 -ldflags="-s -w" sandcat.go
+GOOS=freebsd go build -o ../payloads/sandcat.go-freebsd -ldflags="-s -w" sandcat.go
 }
 cd gocat && build
 cd ..
