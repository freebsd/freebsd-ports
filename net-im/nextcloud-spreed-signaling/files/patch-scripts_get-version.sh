--- scripts/get-version.sh.orig	2023-07-05 09:17:27 UTC
+++ scripts/get-version.sh
@@ -1,7 +1,6 @@
-#!/usr/bin/env bash
+#!/bin/sh
 set -e
-ROOT="$(cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd)"
-
+ROOT="$(cd "$( dirname $0 )" && pwd)"
 VERSION=
 if [ -s "$ROOT/../version.txt" ]; then
     VERSION=$(cat "$ROOT/../version.txt" | tr -d '[:space:]')
@@ -15,7 +14,7 @@ if [ -z $VERSION ] && [ -d "$ROOT/../.git" ]; then
 fi
 
 if [ -z $VERSION ]; then
-    VERSION=unknown
+    VERSION=%%PORTVERSION%%
 fi
 
 echo $VERSION
