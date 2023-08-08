--- plugins/sandcat/update-agents.sh.orig	2022-07-20 19:48:00 UTC
+++ plugins/sandcat/update-agents.sh
@@ -1,10 +1,11 @@
-#!/bin/bash
+#!/bin/sh
 # generates payloads for each os
 
-function build() {
+build() {
 GOOS=windows go build -o ../payloads/sandcat.go-windows -ldflags="-s -w" sandcat.go
 GOOS=linux go build -o ../payloads/sandcat.go-linux -ldflags="-s -w" sandcat.go
 GOOS=darwin go build -o ../payloads/sandcat.go-darwin -ldflags="-s -w" sandcat.go
+GOOS=freebsd go build -o ../payloads/sandcat.go-freebsd -ldflags="-s -w" sandcat.go
 }
 cd gocat && build
 cd ..
