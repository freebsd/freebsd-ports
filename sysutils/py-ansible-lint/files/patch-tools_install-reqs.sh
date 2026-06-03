--- tools/install-reqs.sh.orig	2026-04-01 07:40:07.000000000 -0700
+++ tools/install-reqs.sh	2026-04-13 07:49:45.646391000 -0700
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/usr/bin/env bash
 set -euo pipefail
 echo "Install requirements.yml ..."
 ansible-galaxy collection install -r requirements.yml -p examples/playbooks/collections
