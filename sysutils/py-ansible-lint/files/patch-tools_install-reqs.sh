--- tools/install-reqs.sh.orig	2023-05-10 11:30:52 UTC
+++ tools/install-reqs.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/bin/env bash
 set -euo pipefail
 pushd examples/playbooks/collections >/dev/null
 MISSING=()
