--- litellm/proxy/start.sh.orig	2024-02-11 03:13:21 UTC
+++ litellm/proxy/start.sh
@@ -1,2 +1,2 @@
-#!/bin/bash
-python3 proxy_cli.py
\ No newline at end of file
+#!/bin/sh
+%%PYTHON_CMD%% proxy_cli.py
